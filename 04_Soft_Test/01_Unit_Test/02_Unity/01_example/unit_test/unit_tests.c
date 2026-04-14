/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-12 21:44:08
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-13 20:19:30
 * @Description: file content
 */

#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "add.h"

int counter;

void setUp(void)
{
    /* This is run before EACH TEST */
    counter = 0x5a5a;
    printf("T --- %d\n", counter);
}

void tearDown(void)
{
    counter = 0;
    printf("T --- %d\n", counter);
}

void txh_test(void)
{
    TEST_ASSERT_TRUE(3 == add(1, 2));
    TEST_ASSERT_EQUAL_INT(4, add(2, 2));
    TEST_ASSERT_EQUAL_INT(6, add(4, 2));
}

void txh_test1(void)
{
    TEST_ASSERT_TRUE(3 == add(1.0, 2.0));
    TEST_ASSERT_EQUAL_INT(4000000000, add(2000000000, 2000000000)); // 越界了
}

int main(int argc, const char* argv[])
{
    RUN_TEST(txh_test);
    RUN_TEST(txh_test1);
    return 0;
}
