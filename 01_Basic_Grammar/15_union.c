/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-12 10:47:31
 * @Description: file content
 */
#include <stdio.h>
#include <string.h>

// 联合体是特殊的数据类型，它允许多个不同类型的成员共享同一块内存空间。
// 与结构体不同，联合体所有成员共用内存，因此同时只能存储一个成员的值。
union Data {
    int i;
    float f;
    char str[20];
};

int main(int argc, char *argv[])
{
    // ========== 1. union 基本使用 ==========
    printf("=== Union 基本示例 ===\n");
    union Data data;

    // 三个数据成员的起始地址都是一样的，修改任何一个成员的数据，都会改变其他成员
    printf("Data addr i[%p], f[%p], str[%p]\n\n", &data.i, &data.f, &data.str);  // 垃圾值

    // 存储整数
    data.i = 10;
    printf("data.i: %d\n", data.i);
    printf("data.f: %f\n", data.f);  // 垃圾值
    printf("data.str: %s\n\n", data.str);  // 垃圾值

    // 存储浮点数（覆盖整数）
    data.f = 3.14;
    printf("data.f: %f\n", data.f);
    printf("data.i: %d\n\n", data.i);  // 被破坏

    // 存储字符串（覆盖浮点数）
    strcpy(data.str, "Hello");
    printf("data.str: %s\n", data.str);
    printf("data.i: %d\n", data.i);    // 被破坏
    printf("data.f: %f\n\n", data.f);  // 被破坏


    // ========== 2. union 的大小 ==========
    printf("=== Union 大小 ===\n");
    printf("int 大小: %zu\n", sizeof(int));
    printf("float 大小: %zu\n", sizeof(float));
    printf("char[20] 大小: %zu\n", sizeof(char[20]));
    printf("union Data 大小: %zu\n", sizeof(union Data));  // 20（最大成员的大小）
    printf("\n");

    return 0;
}
