
#ifndef CONSUMER_H
#define CONSUMER_H

#include "circular_buffer.h"

typedef int (*data_destination_t)(unsigned char* data, int len);

/**
 * @brief 初始化消费者
 *
 * @param cb                环形缓存
 * @param data_destination  数据消费回调函数
 * @return true
 * @return false
 */
bool consumer_init(TS_CircularBuffer *cb, data_destination_t data_destination);

/**
 * @brief 去初始化
 */
void consumer_deinit();

#endif
