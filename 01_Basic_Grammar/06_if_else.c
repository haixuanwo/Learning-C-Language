/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2025-04-11 21:39:54
 * @Description: file content
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int a = 100;

    // 如果100等于a，则输出"1 --- a == 100"
    if (100 == a)
    {
        printf("1 --- a == 100\n");
    }

    // ------------------------------------------
    if (20 == a)
    {
        printf("a == 20\n");
    }
    else if (100 == a)
    {
        printf("2 --- a == 100\n");
    }

    // -----------------------------------------
    if (20 == a)
    {
        printf("a == 20\n");
    }
    else if (200 == a)
    {
        printf("a == 200\n");
    }
    else
    {
        printf("3 --- a == 100\n");
    }

    return 0;
}
