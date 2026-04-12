/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-12 10:42:46
 * @Description: file content
 */
#include <stdio.h>
#include <string.h>

/**
 * @brief 结构体是自定义的数据类型，
 *      可以包含已知的任意数据类型为成员变量
 */
struct Person
{
    char name[20];    // 姓名
    int age;          // 年龄
    char gender;      // 性别
};

int main(int argc, char *argv[])
{
    struct Person person1;
    person1.age = 20;
    strcpy(person1.name, "Clark");
    person1.gender = 'M';
    printf("name: %s, age: %d, gender: %c\n", person1.name, person1.age, person1.gender);

    struct Person person2 = {
        "Tom", 25, 'M'
    };
    printf("name: %s, age: %d, gender: %c\n", person2.name, person2.age, person2.gender);

    struct Person person3 = {
        .name = "Jerry",
        .age = 30,
        .gender = 'M'
    };
    printf("name: %s, age: %d, gender: %c\n", person3.name, person3.age, person3.gender);

    return 0;
}
