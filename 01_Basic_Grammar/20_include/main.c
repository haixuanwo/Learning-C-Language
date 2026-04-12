
#include <stdio.h>
#include "add.h"
#include "sub.h"

/**
 * @brief 包含头文件后，就可以使用其中申明的函数了
 */

int main(int argc, char *argv[])
{
    int num1 = 100;
    int num2 = 200;

    printf("num1[%d] + num2[%d] = %d\n", num1, num2, add(num1, num2));
    printf("num1[%d] - num2[%d] = %d\n", num1, num2, sub(num1, num2));
    return 0;
}
