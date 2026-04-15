/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-15 11:27:21
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-15 14:59:50
 * @Descricirrition: file conte
 */

#include <stdio.h>
#include "circular_buffer.h"


// 1. 生产者线程函数
void* producer(void* arg) {
    TS_CircularBuffer *cb = (TS_CircularBuffer*)arg;
    unsigned char data[5];
    for(int i = 0; i < 10; i++) {
        memset(data, i, sizeof(data));
        int wn = ts_cb_write(cb, data, sizeof(data), -1); // 阻塞写
        printf("[P] Wrote %d bytes (val: %d)\n", wn, i);
        usleep(100000); // 100ms
    }
    return NULL;
}

// 2. 消费者线程函数
void* consumer(void* arg) {
    TS_CircularBuffer *cb = (TS_CircularBuffer*)arg;
    unsigned char out[3];
    for(int i = 0; i < 15; i++) {
        int rn = ts_cb_read(cb, out, sizeof(out), 500); // 超时读 500ms
        if(rn > 0) {
            printf("[C] Read %d bytes (val: %d)\n", rn, out[0]);
        } else {
            printf("[C] Read Timeout!\n");
        }
        usleep(150000); // 150ms，比生产者慢
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    printf("--- Start Optimized Circular Buffer Test ---\n");
    TS_CircularBuffer *my_cb = ts_cb_init(20);

    // 测试 A: 并发读写测试
    pthread_t p_tid, c_tid;
    pthread_create(&p_tid, NULL, producer, my_cb);
    pthread_create(&c_tid, NULL, consumer, my_cb);

    pthread_join(p_tid, NULL);
    pthread_join(c_tid, NULL);

    // 测试 B: 非阻塞模式测试
    printf("\n--- Test Non-blocking ---\n");
    unsigned char dummy[20] = {0xFF};
    int wn = ts_cb_write(my_cb, dummy, 20, 0); // 填满
    printf("Non-block write 20 bytes: %d\n", wn);

    int fail_wn = ts_cb_write(my_cb, dummy, 1, 0); // 应该失败
    printf("Non-block write 1 more byte (expect 0): %d\n", fail_wn);

    ts_cb_free(my_cb);
    return 0;
}
