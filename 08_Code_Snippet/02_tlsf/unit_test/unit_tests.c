/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-12 21:44:08
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-15 17:31:10
 * @Description: file content
 */

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "fixture/unity_fixture.h"


TEST_GROUP(circularBufferTest);
TEST_SETUP(circularBufferTest)
{
    // printf("TEST_SETUP ---\n");
}

TEST_TEAR_DOWN(circularBufferTest)
{
    // printf("TEST_TEAR_DOWN ---\n");
}

TEST(circularBufferTest, producerConsumer)
{
    // TEST_ASSERT_NOT_NULL(cb);
    // TEST_ASSERT_TRUE(consumer_init(cb, data_destination_func));
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
