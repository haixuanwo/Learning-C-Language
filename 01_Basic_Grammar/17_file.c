/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-12 10:52:41
 * @Description: file content
 */

#include <stdio.h>
#include <unistd.h>

/**
 * @brief 文件，常见的文件test.txt, 二进制文件test.bin, mp4文件test.mp4, pdf、world文件等
 * fopen 打开一个文件
 * fwrite 写入数据到文件
 * fread 从文件读取数据
 * fclose 关闭文件
 */

unsigned int totalScore = 110;

int main()
{
    FILE *fp;
    fp = fopen("test.txt", "r+");
    if (fp == NULL)
    {
        fp = fopen("test.txt", "w+");
        if (NULL == fp)
        {
            printf("Error! opening file\n");
            return -1;
        }
    }

    size_t len = fwrite(&totalScore, 1, sizeof(unsigned int), fp);
    printf("fwrite len[%lu]\n", len);

    int result = fseek(fp, 0, SEEK_SET); // 从起始位置，移动到起始点
    printf("fseek result[%d]\n", result);

    unsigned int temp = 0;
    len = fread(&temp, 1, sizeof(unsigned int), fp);
    printf("fread len[%lu]\n", len);


    printf("fread temp[%u]\n", temp);

    fclose(fp);
    return 0;
}
