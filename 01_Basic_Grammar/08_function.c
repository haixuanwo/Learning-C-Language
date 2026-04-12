/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-12 09:56:10
 * @Description: file content
 */

#include <stdio.h>
#include <unistd.h>
#include <time.h>

/**
 * @brief 函数是一个功能的单元，它接受输入，进行处理，然后输出结果。
 * 可以没有参数或多个参数，可以有返回值或没有返回值。
 */

/**
 * @brief 不带参数与返回值的函数
 */
void show()
{
    printf("hello world\n");
}

/**
 * @brief 带参数与返回值的函数
 * @param a
 * @param b
 * @return int
 */
int add(int a, int b)
{
    return (a+b);
}

int main(int argc, char *argv[])
{
    show();

    int c = add(100, 200);
    printf("100 + 200 = %d\n", c);

    return 0;
}
