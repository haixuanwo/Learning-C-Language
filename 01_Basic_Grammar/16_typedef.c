/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2025-04-26 09:31:26
 * @Description: file content
 */

#include <stdio.h>
#include <unistd.h>

/**
 * @brief typedef 关键字，用于为现有的数据类型创建别名
 */

/**
 * 1、enum的值默认从0开始
 * 2、可在定义时赋初值
 * 3、之后的enum值为之前值加1
 */
typedef enum
{
    TYPE_0,
    TYPE_1,
    TYPE_2,
    TYPE_3 = 100,
    TYPE_4,
    TYPE_5,
}MyType;

void test_type()
{
    printf("TYPE_0[%d]\n", TYPE_0);
    printf("TYPE_1[%d]\n", TYPE_1);
    printf("TYPE_2[%d]\n", TYPE_2);
    printf("TYPE_3[%d]\n", TYPE_3);
    printf("TYPE_4[%d]\n", TYPE_4);
    printf("TYPE_5[%d]\n", TYPE_5);
}

void test_switch1(MyType printType)
{
    switch (printType)
    {
        case TYPE_1:
        {
            printf("case : 1\n");
            break;
        }
        case TYPE_2:
        {
            printf("case : 2\n");
            break;
        }
        case TYPE_3:
        {
            printf("case : 3\n");
            break;
        }
        default:
        {
            printf("default\n");
            break;
        }
    }
}

typedef int myInt;
typedef char myChar;
typedef unsigned long myUL;

void test_typedef()
{
    myInt a = 110;
    myChar b = 'x';
    myUL c = 110120;

    printf("a[%d]\n", a);
    printf("b[%c]\n", b);
    printf("c[%lu]\n", c);
}

int main(int argc, char *argv[])
{
    test_type();
    test_switch1(100);
    test_typedef();

    return 0;
}
