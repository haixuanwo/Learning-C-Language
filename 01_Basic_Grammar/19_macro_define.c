
#include <stdio.h>

/**
 * @brief 宏定义是在预处理阶段，在代码编译之前，对代码进行替换，以达到代码的条件编译的目的。
 */

#define MAX(a,b) ((a)>(b)?(a):(b))
#define VALUE 100

int main(int argc, char* argv[])
{
    // 1、宏定义表达式与值
    int a = MAX(123, 456);
    printf("MAX(123, 456) = %d\n", a);

    int b = VALUE;
    printf("VALUE = %d\n", b);

    // 2、宏定义的条件编译
    #ifdef VALUE
        printf("1 --- VALUE is defined\n");
    #else
        printf("1 --- VALUE is NOT defined\n");
    #endif

    // 3、宏定义的取消
    #undef VALUE
    #ifdef VALUE
        printf("2 --- VALUE is defined\n");
    #else
        printf("2 --- VALUE is NOT defined\n");
    #endif

    return 0;
}
