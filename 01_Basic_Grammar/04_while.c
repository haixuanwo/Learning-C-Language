/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2025-04-11 21:32:24
 * @Description: file content
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // 一直循环隔一秒打印
    while (1)
    {
        printf("hello world\n");
        sleep(1);
    }

    return 0;
}
