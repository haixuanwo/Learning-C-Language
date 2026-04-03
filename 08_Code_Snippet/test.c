
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 10;
    int b = a + 5;    // 断点设置在这一行
    int c = b * 2;

    printf("%d\n", c);
}
