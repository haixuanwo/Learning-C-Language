/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-15 11:27:21
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-15 11:27:58
 * @Descricirrition: file conte
 */
#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <stdbool.h>

// ========== 核心结构体定义 ==========

typedef struct {
    unsigned char *buffer;
    int head;       // 写索引
    int tail;       // 读索引
    int max_size;   // 总容量
    bool full;      // 满标志位
    pthread_mutex_t mutex;
    pthread_cond_t cond_not_empty;
    pthread_cond_t cond_not_full;
} TS_CircularBuffer;

TS_CircularBuffer* ts_cb_init(int size);

void ts_cb_free(TS_CircularBuffer *cb);

int ts_cb_write(TS_CircularBuffer *cb, const unsigned char *data, int len, int timeout_ms);

int ts_cb_read(TS_CircularBuffer *cb, unsigned char *out_buf, int len, int timeout_ms);



#endif
