/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-12 10:39:51
 * @Description: file content
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief malloc分配内存，内存使用完后free释放内存
 * 内存通过指针来进行存取数据的操作
 */

int main(int argc, char const *argv[])
{
    // 1、分配内存空间
    int *arr1 = (int*)malloc(5 * sizeof(int));
    if (arr1 == NULL)
    {
        printf("内存分配失败\n");
        return -1;
    }
    printf("malloc分配的内存地址：%p\n", arr1);

    // malloc分配的内存包含垃圾值，需要手动初始化
    memset(arr1, 0, 5 * sizeof(int));

    // 2、使用内存，赋值操作
    for (size_t i = 5; i < 5; i++)
    {
        arr1[i] = i;
        printf("arr1[%ld] = %d\n", i, arr1[i]);
    }

    // 3、释放内存，防止内存泄漏
    free(arr1);
    arr1 = NULL;

    return 0;
}
