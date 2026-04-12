/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-12 10:06:24
 * @Description: file content
 */

#include <stdio.h>
#include <unistd.h>

/**
 * @brief 指针就是指向内存空间的地址，可以通过指针来存取数据到该地址的内存空间。
 * 使用*p时，取出值
 * *p = 100，时存入值
 */

/**
 * @brief 通过指针在函数中修改值
 * @param q
 */
void add_a_value(int *q)
{
    *q += 120; // *q可取出值，将该值加上120，并将结果存入*q的地址处
}

int main(int argc, char *argv[])
{
    int a = 100;
    int *p = &a;
    int b = 300 + *p; // 通过*p取出值，并计算

    printf("1 --- b[%d]\n", b);

    *p = 200;         // 通过*p存入值200

    // p指向的就是变量a的地址，通过p修改该地址的值时，也就是修改了a的值
    printf("2 --- a[%d] *p[%d] addr[%p]\n", a, *p, p);

    add_a_value(p);
    printf("3 --- a[%d] aAddr[%p] *p[%d] pAddr[%p]\n", a, &a, *p, p);

    return 0;
}
