/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-12 09:50:03
 * @Description: file content
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int type = 3;
    switch (type)
    {
        case 1:
        {
            printf("case : 1\n");
            break;
        }
        case 2:
        {
            printf("case : 2\n");
            break;
        }
        case 3: // 匹配到type等于3
        {
            printf("case : 3\n");
            break;
        }
        default: // type匹配不到所有的情况，就执行default
        {
            printf("default\n");
            break;
        }
    }

    return 0;
}
