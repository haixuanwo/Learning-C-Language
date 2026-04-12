/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-12 10:35:27
 * @Description: file content
 */
#include <stdio.h>
#include <string.h>

/**
 * @brief 字符串是一系列字符组成的序列，并且以空字符 '\0' 作为结束标志
 */


// 1、定义字符串与输出输入
void test1()
{
    char str[] = "hello world";     // 定义一个字符串，字符串以空字符'\0'结尾

    printf("str: %s\n", str);       // 打印一个字符串
    puts(str);                      // 打印一个字符串，与printf差异是会自动换行
    fputs(str, stdout);             // 打印一个字符串，不会自动换行，需指定输出到stdout

    char buffer[64];
    printf("请输入字符串: ");
    fgets(buffer, sizeof(buffer), stdin);  // 输入一个字符串，与scanf差异是会自动换行
    fputs(buffer, stdout);
}


void test2()
{
    // 1. strncpy - 字符串复制
    char str1[64] = {0};
    char str2[] = "Copy this string";

    size_t len = strlen(str2);
    printf("strlen[%lu]\n", len); // 获取字符串长度，不包括结束标志'\0'

    strncpy(str1, str2, len);
    printf("str1[%s]\n str2[%s]\n", str1, str2);

    // 2. strncmp - 字符串比较
    char str3[] = "apple";
    char str4[] = "apple";
    int result = strncmp(str3, str4, strlen(str4));
    printf("2. strncmp: \"%s\" vs \"%s\" = %d\n", str3, str4, result);
}


int main(int argc, char const *argv[])
{
    test1();

    test2();

    return 0;
}
