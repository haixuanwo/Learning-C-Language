/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-12 21:44:08
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-14 18:52:35
 * @Description: file content
 */

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "add.h"
#include "leapyear.h"
#include "fixture/unity_fixture.h"

TEST_GROUP(IsLeapYearTest);
TEST_SETUP(IsLeapYearTest)
{
    printf("TEST_SETUP ---\n");
}

TEST_TEAR_DOWN(IsLeapYearTest)
{
    printf("TEST_TEAR_DOWN ---\n");
}

TEST(IsLeapYearTest, leapYear)
{
    TEST_ASSERT_TRUE(isLeapYear(2000));
    TEST_ASSERT_TRUE(isLeapYear(1996));
}

TEST(IsLeapYearTest, commonYear)
{
    TEST_ASSERT_FALSE(isLeapYear(1999));
    TEST_ASSERT_FALSE(isLeapYear(2100));
}

TEST_GROUP_RUNNER(IsLeapYearTest)
{
    RUN_TEST_CASE(IsLeapYearTest, leapYear);
    RUN_TEST_CASE(IsLeapYearTest, commonYear);
}

static void RunAllTests()
{
    RUN_TEST_GROUP(IsLeapYearTest);
}

int main(int argc, char* argv[])
{
    return UnityMain(argc, (const char**)argv, RunAllTests);
}
