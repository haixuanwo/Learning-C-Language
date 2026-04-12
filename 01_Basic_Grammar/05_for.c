/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-11 17:10:53
 * @Description: file content
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // for (;;)与while(1)一样，都可以实现无限循环

    // 循环5次
    for (int i = 0; i < 5; i++)
    {
        printf("for: hello world\n");
        sleep(1);
    }

    return 0;
}
