<!--
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-10 21:50:07
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-11 17:37:35
 * @Description: file content
-->



# 使用C语言实现程序软件7步骤
- 1 定义程序目标
- 2 设计程序
- 3 编写代码
- 4 编译
- 5 运行程序
- 6 测试和调试
- 7 维护和修改代码

# 语法

## 1 基本数据类型
  char, short, int, long, long long,
  unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long,
  float, double, long double
  bool

## 2 格式化输入和输出
  printf
  scanf

## 3 运算符
    =, +, -, *, /, %
    ++, --,
    +=, -=, /=, %=
    >, <, >=, <=, ==,!=
    &&, ||,!
    &, |, ^, ~, <<, >>

## 4 循环
    while, for, do while
    continue, break

## 5 分支和跳转
    if, else if
    switch, case
    goto

## 6 输入输出
    getchar, putchar

## 7 函数
    void func(void)
    {

    }

    typedef void (*FuncPtr)(void);

## 8 数组与指针
    char x = 'a';
    char *p = NULL;
    p = &x;

    int a[5] = {1, 2, 3, 4, 5};

## 9 字符串
    char str[] = "hello world";
    gets, puts, fputs,
    strlen, strcat, strncat, strcmp, strcpy, strncpy, sprintf

## 10 存储类别、链接、管理
    作用域， 存储期，
    const, static, volatile, restrict, _Atomic
    malloc, calloc, relloc, free,
    memcpy, memmove, memcmp, memset,

## 11 结构
    struct, enum, union, typedef
    链表

## 12_文件输入输出
    fopen, fwrite, fread, fseek, fclose, ftell, fgetpos, fsetpos, feof
    fprintf, fscanf, fgets, fputs
    ungetc, fflush,

## 13_预处理，宏替换
    #define, #undef, #include,#ifndef, #endif
    #line, #error, #pragma, _Noreturn
    exit(), atexit()
    qsort
    assert, _Static_assert


## 15_头文件
    #include "test.h"
