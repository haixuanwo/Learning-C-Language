/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-11 17:08:11
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-11 17:08:28
 * @Description: file content
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int age = 0;
    float score = 0.0F;
    char grade = '\0';

    printf("请输入年龄、分数和等级 (空格隔开): ");
    // %d 整数, %f 浮点数, %c 字符
    scanf("%d %f %c", &age, &score, &grade);
    printf("数据录入成功：年龄 %d，分数 %.1f，等级 %c\n", age, score, grade);

    char name[20] = {0};
    printf("请输入姓名: ");
    scanf("%s", name);
    printf("姓名: %s\n", name);

    return 0;
}
