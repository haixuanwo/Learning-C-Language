/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-12 10:44:18
 * @Description: file content
 */

#include <stdio.h>
#include <unistd.h>

/**
 * @brief枚举是自定义的数据类型，用于定义一组具有名称的整数常量
 *
 * 1、enum的值默认从0开始
 * 2、可在定义时赋初值
 * 3、之后的enum值为之前值加1
 */
enum type
{
    TYPE_0,         // 默认为0，后续成员值为前一个成员值加1
    TYPE_1,
    TYPE_2,
    TYPE_3 = 100,   // 赋初值100，后续成员值为前一个成员值加1
    TYPE_4,
    TYPE_5,
};

void test_type()
{
    printf("TYPE_0[%d]\n", TYPE_0);
    printf("TYPE_1[%d]\n", TYPE_1);
    printf("TYPE_2[%d]\n", TYPE_2);
    printf("TYPE_3[%d]\n", TYPE_3);
    printf("TYPE_4[%d]\n", TYPE_4);
    printf("TYPE_5[%d]\n", TYPE_5);
}

void test_switch1(enum type printType)
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


int main(int argc, char *argv[])
{
    test_type();
    test_switch1(100);
    return 0;
}
