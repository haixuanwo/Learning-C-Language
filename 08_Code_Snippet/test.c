/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-15 20:08:52
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-22 19:33:34
 * @Description: file content
 */
#include <stdio.h>
#include <stdlib.h> // 必须包含此头文件以使用 malloc 和 free


int main()
{
    int *ptr = (int*)malloc(10);
#if 0
    int n, i;
    int *ptr;

    printf("请输入要存储的元素个数: ");
    scanf("%d", &n);

    // 1. 分配内存
    // sizeof(int) 确保跨平台兼容性
    ptr = (int*)malloc(n * sizeof(int));

    // 2. 检查分配是否成功
    if (ptr == NULL) {
        printf("内存分配失败！\n");
        exit(1); // 异常退出
    }

    printf("内存分配成功，请输入 %d 个整数：\n", n);

    // 3. 使用内存
    for (i = 0; i < n; ++i) {
        scanf("%d", &ptr[i]);
    }

    printf("输入的元素为: ");
    for (i = 0; i < n; ++i) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // 4. 释放内存
    // 使用完动态内存后必须释放，防止内存泄漏
    free(ptr);
    ptr = NULL; // 良好的习惯：将指针置空，避免野指针
#endif
    return 0;
}

