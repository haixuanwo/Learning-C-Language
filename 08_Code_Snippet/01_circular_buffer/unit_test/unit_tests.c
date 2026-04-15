/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-12 21:44:08
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-15 16:32:39
 * @Description: file content
 */

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "fixture/unity_fixture.h"

#include "circular_buffer.h"
#include "producer.h"
#include "consumer.h"

TEST_GROUP(circularBufferTest);
TEST_SETUP(circularBufferTest)
{
    // printf("TEST_SETUP ---\n");
}

TEST_TEAR_DOWN(circularBufferTest)
{
    // printf("TEST_TEAR_DOWN ---\n");
}

int get_data_func(unsigned char *data, int size)
{
    // 产生当前的时间
    time_t now;
    time(&now);

    int len = sizeof(now);
    printf("T --- get_data_func now[%ld] len[%d]\n", now, len);
    memcpy(data, &now, len);
    return len;
}

int data_destination_func(unsigned char* data, int len)
{
    time_t now = *((time_t *)data);
    printf("T --- data_destination_func now[%ld] len[%d]\n", now, len);
}

TEST(circularBufferTest, producerConsumer)
{
    TS_CircularBuffer *cb = ts_cb_init(20);
    TEST_ASSERT_NOT_NULL(cb);

    TEST_ASSERT_TRUE(producer_init(cb, &get_data_func));
    TEST_ASSERT_TRUE(consumer_init(cb, data_destination_func));

    sleep(10);

    producer_deinit();
    consumer_deinit();
    ts_cb_free(cb);
}

TEST(circularBufferTest, commonYear)
{
    // TEST_ASSERT_FALSE(isLeapYear(1999));
    // TEST_ASSERT_FALSE(isLeapYear(2100));
}

TEST_GROUP_RUNNER(circularBufferTest)
{
    RUN_TEST_CASE(circularBufferTest, producerConsumer);
    // RUN_TEST_CASE(circularBufferTest, commonYear);
}

static void RunAllTests()
{
    RUN_TEST_GROUP(circularBufferTest);
}

int main(int argc, char* argv[])
{
    return UnityMain(argc, (const char**)argv, RunAllTests);
}
