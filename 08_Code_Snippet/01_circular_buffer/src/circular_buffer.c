/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-15 11:27:21
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-15 14:36:07
 * @Descricirrition: file conte
 */

/*
 * @Author: Clark (Optimized)
 * @Description: 线程安全的高性能环形缓冲区 (支持批量读写、超时、非阻塞)
 */

#include "circular_buffer.h"
#include <time.h>
// #define _POSIX_C_SOURCE 200112L

// ========== 内部辅助工具函数 (调用前需持有锁) ==========

// 获取当前已有的数据长度
static int _ts_cb_len(TS_CircularBuffer *cb) {
    if (cb->full) return cb->max_size;
    if (cb->head >= cb->tail) return cb->head - cb->tail;
    return cb->max_size + cb->head - cb->tail;
}

// 获取当前剩余空间长度
static int _ts_cb_unused(TS_CircularBuffer *cb) {
    return cb->max_size - _ts_cb_len(cb);
}

// ========== 核心API实现 ==========

// 初始化
TS_CircularBuffer* ts_cb_init(int size) {
    if (size <= 0) return NULL;
    TS_CircularBuffer *cb = (TS_CircularBuffer*)malloc(sizeof(TS_CircularBuffer));
    if (!cb) return NULL;

    cb->buffer = (unsigned char*)malloc(size);
    if (!cb->buffer) {
        free(cb);
        return NULL;
    }

    cb->max_size = size;
    cb->head = 0;
    cb->tail = 0;
    cb->full = false;

    pthread_mutex_init(&cb->mutex, NULL);
    pthread_cond_init(&cb->cond_not_empty, NULL);
    pthread_cond_init(&cb->cond_not_full, NULL);

    printf("[CB] Init Success! Size: %d\n", size);
    return cb;
}

// 销毁
void ts_cb_free(TS_CircularBuffer *cb) {
    if (!cb) return;
    pthread_mutex_destroy(&cb->mutex);
    pthread_cond_destroy(&cb->cond_not_empty);
    pthread_cond_destroy(&cb->cond_not_full);
    free(cb->buffer);
    free(cb);
    printf("[CB] Free Success!\n");
}

// 批量写入（核心逻辑：支持阻塞、超时、非阻塞）
// timeout_ms: -1 为阻塞，0 为非阻塞，>0 为超时时间
int ts_cb_write(TS_CircularBuffer *cb, const unsigned char *data, int len, int timeout_ms) {
    if (!cb || !data || len <= 0) return 0;

    pthread_mutex_lock(&cb->mutex);

    // 1. 等待空间（如果是阻塞/超时模式）
    while (cb->full) {
        if (timeout_ms == 0) { // 非阻塞模式
            pthread_mutex_unlock(&cb->mutex);
            return 0;
        } else if (timeout_ms < 0) { // 阻塞模式
            pthread_cond_wait(&cb->cond_not_full, &cb->mutex);
        } else { // 超时模式
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            ts.tv_sec += timeout_ms / 1000;
            ts.tv_nsec += (timeout_ms % 1000) * 1000000;
            if (ts.tv_nsec >= 1000000000) { ts.tv_sec++; ts.tv_nsec -= 1000000000; }

            int res = pthread_cond_timedwait(&cb->cond_not_full, &cb->mutex, &ts);
            if (res == ETIMEDOUT) {
                pthread_mutex_unlock(&cb->mutex);
                return 0;
            }
        }
    }

    // 2. 执行批量拷贝 (处理环形回绕)
    int available = _ts_cb_unused(cb);
    int to_write = (len < available) ? len : available;

    if (to_write > 0) {
        int first_part = cb->max_size - cb->head;
        if (to_write <= first_part) {
            memcpy(&cb->buffer[cb->head], data, to_write);
        } else {
            memcpy(&cb->buffer[cb->head], data, first_part);
            memcpy(cb->buffer, &data[first_part], to_write - first_part);
        }
        cb->head = (cb->head + to_write) % cb->max_size;
        if (cb->head == cb->tail) cb->full = true;

        pthread_cond_broadcast(&cb->cond_not_empty);
    }

    pthread_mutex_unlock(&cb->mutex);
    return to_write;
}

// 批量读取（核心逻辑：支持阻塞、超时、非阻塞）
int ts_cb_read(TS_CircularBuffer *cb, unsigned char *out_buf, int len, int timeout_ms) {
    if (!cb || !out_buf || len <= 0) return 0;

    pthread_mutex_lock(&cb->mutex);

    // 1. 等待数据
    while (!cb->full && (cb->head == cb->tail)) {
        if (timeout_ms == 0) {
            pthread_mutex_unlock(&cb->mutex);
            return 0;
        } else if (timeout_ms < 0) {
            pthread_cond_wait(&cb->cond_not_empty, &cb->mutex);
        } else {
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            ts.tv_sec += timeout_ms / 1000;
            ts.tv_nsec += (timeout_ms % 1000) * 1000000;
            if (ts.tv_nsec >= 1000000000) { ts.tv_sec++; ts.tv_nsec -= 1000000000; }

            if (pthread_cond_timedwait(&cb->cond_not_empty, &cb->mutex, &ts) == ETIMEDOUT) {
                pthread_mutex_unlock(&cb->mutex);
                return 0;
            }
        }
    }

    // 2. 执行批量读取 (处理环形回绕)
    int current_len = _ts_cb_len(cb);
    int to_read = (len < current_len) ? len : current_len;

    if (to_read > 0) {
        int first_part = cb->max_size - cb->tail;
        if (to_read <= first_part) {
            memcpy(out_buf, &cb->buffer[cb->tail], to_read);
        } else {
            memcpy(out_buf, &cb->buffer[cb->tail], first_part);
            memcpy(&out_buf[first_part], cb->buffer, to_read - first_part);
        }
        cb->tail = (cb->tail + to_read) % cb->max_size;
        cb->full = false;

        pthread_cond_broadcast(&cb->cond_not_full);
    }

    pthread_mutex_unlock(&cb->mutex);
    return to_read;
}
