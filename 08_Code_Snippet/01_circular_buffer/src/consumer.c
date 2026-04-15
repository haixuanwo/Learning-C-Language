
#include "consumer.h"
#include "common.h"
#include <pthread.h>

typedef struct Consumer {
    Status status;
    pthread_t th;
    TS_CircularBuffer *cb;  // 环形缓存
    data_destination_t data_destination; // 数据源
}Consumer;

// 1. 生产者线程函数
static void* consumer_func(void* arg)
{
    Consumer *consumer = (Consumer *)arg;

    unsigned char data[64] = {0};

    while (RUN == consumer->status)
    {
        int rn = ts_cb_read(consumer->cb, data, sizeof(data), 500); // 超时读 500ms
        if (rn <= 0)
        {
            printf("T --- ts_cb_read fail rn[%d]\n", rn);
            continue;
        }

        int len = consumer->data_destination(data, sizeof(data));
        if (len <= 0)
        {
            printf("T --- data_destination fail rn[%d]\n", len);
            continue;
        }
    }

    consumer->status = STOPED;
    return NULL;
}

static Consumer g_consumer;

/**
 * @brief 初始化消费者
 *
 * @param cb                环形缓存
 * @param data_destination  数据消费回调函数
 * @return true
 * @return false
 */
bool consumer_init(TS_CircularBuffer *cb, data_destination_t data_destination)
{
    g_consumer.cb = cb;
    g_consumer.data_destination = data_destination;
    g_consumer.status = RUN;

    int ret = pthread_create(&g_consumer.th, NULL, consumer_func, &g_consumer);
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
void consumer_deinit()
{
    g_consumer.status = STOPING;
    pthread_join(g_consumer.th, NULL);
    printf("T --- %s %d success\n", __FUNCTION__, __LINE__);
}
