/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-11 17:01:32
 * @Description: file content
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @description: 有符号整型、无符号整型、浮点型、布尔型数据类型示例
 */

int main(int argc, char *argv[])
{
    // 1、有符号整型，存正负整数
    char character1 = 'a';
    short num1 = 10;
    int num2 = -12;
    long num3 = -13L;
    long long num4 = 100LL;

    printf("character1[%c]\n", character1);
    printf("num1[%d]\n", num1);
    printf("num2[%d]\n", num2);
    printf("num3[%ld]\n", num3);
    printf("num4[%lld]\n", num4);

    // 2、无符号整型，存正整数
    unsigned char character2 = 'b';
    unsigned short num5 = 10U;
    unsigned int num6 = 12U;
    unsigned long num7 = 13UL;
    unsigned long long num8 = 100ULL;

    printf("character2[%c]\n", character2);
    printf("num5[%u]\n", num5);
    printf("num6[%u]\n", num6);
    printf("num7[%lu]\n", num7);
    printf("num8[%llu]\n", num8);

    // 3、浮点型，存小数
    float num9 = 3.3F;
    double num10 = 5.6;         // 默认double
    long double num11 = 7.8L;

    printf("num9[%f]\n", num9);
    printf("num10[%lf]\n", num10);
    printf("num11[%Lf]\n", num11);

    // 4、布尔类型true（定义为 1）和false（定义为0）
    bool flag = true;
    printf("flag[%d]\n", flag);

    return 0;
}
