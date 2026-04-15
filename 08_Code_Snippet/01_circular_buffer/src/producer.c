

#include "producer.h"
#include "common.h"
#include <pthread.h>

typedef struct Producer {
    Status status;
    pthread_t th;
    TS_CircularBuffer *cb;  // 环形缓存
    data_source_t data_source; // 数据源
}Producer;

// 1. 生产者线程函数
static void* producer_func(void* arg)
{
    Producer *producer = (Producer *)arg;

    unsigned char data[64] = {0};

    while (RUN == producer->status)
    {
        int len = producer->data_source(data, sizeof(data));
        if (len <= 0)
        {
            continue;
        }

        int wn = ts_cb_write(producer->cb, data, len, -1); // 阻塞写
        usleep(1000000); // 1秒
    }

    producer->status = STOPED;
    return NULL;
}

static Producer g_producer;

/**
 * @brief 初始化生产者
 *
 * @param cb            环形缓存
 * @param data_source   数据源回调函数
 * @return true
 * @return false
 */
bool producer_init(TS_CircularBuffer *cb, data_source_t data_source)
{
    g_producer.cb = cb;
    g_producer.data_source = data_source;
    g_producer.status = RUN;

    int ret = pthread_create(&g_producer.th, NULL, producer_func, &g_producer);
    if (ret != 0)
    {
        printf("pthread_create failed, ret = %d\n", ret);
        return false;
    }

    printf("T --- %s %d success\n", __FUNCTION__, __LINE__);
    return true;
}

/**
 * @brief 去初始化
 */
void producer_deinit()
{
    g_producer.status = STOPING;
    pthread_join(g_producer.th, NULL);
    printf("T --- %s %d success\n", __FUNCTION__, __LINE__);
}
