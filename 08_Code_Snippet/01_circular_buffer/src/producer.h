
#ifndef PRODUCER_H
#define PRODUCER_H

#include "circular_buffer.h"

typedef int (*data_source_t)(unsigned char* data, int len);

/**
 * @brief 初始化生产者
 *
 * @param cb            环形缓存
 * @param data_source   数据源回调函数
 * @return true
 * @return false
 */
bool producer_init(TS_CircularBuffer *cb, data_source_t data_source);

/**
 * @brief 去初始化
 */
void producer_deinit();

#endif /* PRODUCER_H */
