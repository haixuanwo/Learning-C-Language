/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-11 17:08:11
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-12 09:48:29
 * @Description: file content
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 100;
    int b = 200;
    int c = a + b;
    int d = a*b;
    int e = a - b;
    int f = b/a;

    printf("a[%d]\n", a);
    printf("b[%d]\n", b);
    printf("c[%d]\n", c);
    printf("d[%d]\n", d);
    printf("e[%d]\n", f);

    // 取余数
    int g = 10 % 4; // 余数为2
    printf("g[%d]\n", g);

    return 0;
}
