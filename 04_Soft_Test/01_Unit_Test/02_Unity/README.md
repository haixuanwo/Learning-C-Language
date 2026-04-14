<!--
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-12 11:59:42
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-14 18:28:26
 * @Description: file content
-->


Unity 是一个轻量级的测试框架，它使用 C 语言实现，代码本身很小，不到 200K。由
于 Unity 的代码中大多数是宏定义，所以实际编译后的代码会更小，比较适合在嵌入式测
试应用


https://www.throwtheswitch.org/

https://github.com/ThrowTheSwitch/Unity.git

示例使用的版本：Jan 1 11:53:54 2025 tag: v2.6.1


# 一、断言
## 1 布尔类型比较
TEST_ASSERT(condition)          condition 必须为真
TEST_ASSERT_TRUE(condition)     condition 必须为真
TEST_ASSERT_UNLESS(condition)   condition 必须为假
TEST_ASSERT_FALSE(condition)    condition 必须为假


## 2 指针比较
TEST_ASSERT_NULL(pointer) pointer 必须为空指针
TEST_ASSERT_NOT_NULL(pointer) pointer 必须为非空指针
TEST_ASSERT_EQUAL_PTR(expected, actual) 指针 actual 必须和 expected 相等
TEST_ASSERT_EQUAL_PTR_ARRAY(expected,actual, num_elements)expected 和 actual 都是有 num_elements 个元素的指针数组，要求每个对应的元素相等
TEST_ASSERT_EACH_EQUAL_PTR(expected,actual, num_elements)expected 是指针，actual 是有 num_elements 个元素的指针数组，要求 actual 中的每个元素都和 expected 相等

## 3 整数比较
TEST_ASSERT_EQUAL_INT(expected, actual)
TEST_ASSERT_EQUAL(expected, actual)         两个数均为 int 类型
TEST_ASSERT_EQUAL_INTn(expected, actual)    两个数均为 n 位有符号整数
TEST_ASSERT_EQUAL_UINT(expected, actual)
TEST_ASSERT_EQUAL_HEX(expected, actual)     两个数均为 uint 类型
TEST_ASSERT_EQUAL_UINTn(expected, actual)
TEST_ASSERT_EQUAL_HEXn(expected, actual)    两个数均为 n 位无符号整数
TEST_ASSERT_NOT_EQUAL(expected, actual)     两个数均为整数，不限位数

TEST_ASSERT_BITS(mask, expected, actual)    mask&actual 必须和 mask&expected 相等
TEST_ASSERT_BITS_HIGH(mask, actual)         mask&actual 必须和 mask 相等
TEST_ASSERT_BITS_LOW(mask, actual)          mask&actual  必须为 0
TEST_ASSERT_BIT_HIGH(bit, actual)           actual 的第 bit 位必须为 1
TEST_ASSERT_BIT_LOW(bit, actual)            actual 的第 bit 位必须为 0

TEST_ASSERT_GREATER_THAN(threshold, actual)
TEST_ASSERT_GREATER_THAN_INT(threshold, actual)     两个数均为 int 类型
TEST_ASSERT_GREATER_THAN_INTn(threshold, actual)    两个数均为 n 位有符号整数
TEST_ASSERT_GREATER_THAN_UINT(threshold, actual)
TEST_ASSERT_GREATER_THAN_HEX(threshold, actual)     两个数均为 uint 类型
TEST_ASSERT_GREATER_THAN_UINTn(threshold, actual)
TEST_ASSERT_GREATER_THAN_HEXn(threshold, actual)    两个数均为 n 位无符号整数

TEST_ASSERT_LESS_THAN(threshold, actual)
TEST_ASSERT_LESS_THAN_INT(threshold, actual)        两个数均为 int 类型
TEST_ASSERT_LESS_THAN_INTn(threshold, actual)       两个数均为 n 位有符号整数
TEST_ASSERT_LESS_THAN_UINT(threshold, actual)
TEST_ASSERT_LESS_THAN_HEX(threshold, actual)        两个数均为 uint 类型
TEST_ASSERT_LESS_THAN_UINTn(threshold, actual)
TEST_ASSERT_LESS_THAN_HEXn(threshold, actual)       两个数均为 n 位无符号整数

TEST_ASSERT_GREATER_OR_EQUAL (threshold, actual)
TEST_ASSERT_GREATER_OR_EQUAL_INT(threshold, actual)     两个数均为 int 类型
TEST_ASSERT_GREATER_OR_EQUAL_INTn(threshold, actual)    两个数均为 n 位有符号整数
TEST_ASSERT_GREATER_OR_EQUAL_UINT(threshold, actual)
TEST_ASSERT_GREATER_OR_EQUAL_HEX(threshold, actual)     两个数均为 uint 类型
TEST_ASSERT_GREATER_OR_EQUAL_UINTn(threshold, actual)
TEST_ASSERT_GREATER_OR_EQUAL_HEXn(threshold, actual)    两个数均为 n 位无符号整数

TEST_ASSERT_LESS_OR_EQUAL (threshold, actual)
TEST_ASSERT_LESS_OR_EQUAL_INT(threshold, actual)        两个数均为 int 类型
TEST_ASSERT_LESS_OR_EQUAL_INTn(threshold, actual)       两个数均为 n 位有符号整数
TEST_ASSERT_LESS_OR_EQUAL_UINT(threshold, actual)
TEST_ASSERT_LESS_OR_EQUAL_HEX(threshold, actual)        两个数均为 uint 类型

TEST_ASSERT_LESS_OR_EQUAL_UINTn(threshold, actual)
TEST_ASSERT_LESS_OR_EQUAL_HEXn(threshold, actual)       两个数均为 n 位无符号整数

TEST_ASSERT_INT_WITHIN(delta, expected, actual)         三个数均为 int 类型
TEST_ASSERT_INTn_WITHIN(delta, expected, actual)        三个数均为 n 位有符号整数
TEST_ASSERT_UINT_WITHIN(delta, expected, actual)
TEST_ASSERT_HEX_WITHIN(delta, expected, actual)         三个数均为 uint 类型
TEST_ASSERT_UINTn_WITHIN(delta, expected, actual)
TEST_ASSERT_HEXn_WITHIN(delta, expected, actual)        三个数均为 n 位无符号整数

TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, num_elements)     数组类型为 int
TEST_ASSERT_EQUAL_INTn_ARRAY(expected, actual, num_elements)    数组类型为 n 位有符号整数
TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, num_elements)
TEST_ASSERT_EQUAL_HEX_ARRAY (expected, actual, num_elements)    数组类型为 uint
TEST_ASSERT_EQUAL_UINTn_ARRAY(expected, actual, num_elements)
TEST_ASSERT_EQUAL_HEXn_ARRAY (expected, actual, num_elements)   数组类型为 n 位无符号整数

TEST_ASSERT_EACH_EQUAL_INT(expected, actual, num_elements)      数组类型为 int
TEST_ASSERT_EACH_EQUAL_INTn(expected, actual, num_elements)     数组类型为 n 位有符号整数
TEST_ASSERT_EACH_EQUAL_UINT(expected, actual, num_elements)
TEST_ASSERT_EACH_EQUAL_HEX(expected, actual, num_elements)      数组类型为 uint
TEST_ASSERT_EACH_EQUAL_UINTn(expected, actual, num_elements)
TEST_ASSERT_EACH_EQUAL_HEXn(expected, actual, num_elements)     数组类型为 n 位无符号整数

## 4 字符串
TEST_ASSERT_EQUAL_STRING(expected, actual)                      字符串 actual 必须和 expected 相等
TEST_ASSERT_EQUAL_STRING_LEN(expected, actual,len)              两个字符串的前 len 个字符相等
TEST_ASSERT_EQUAL_STRING_ARRAY(expected,actual, num_elements)   actual 和 expected 均为字符串数组每个数组中包含 num_elements 个字符串两个数组中的每个字符串都必须相等
TEST_ASSERT_EACH_EQUAL_STRING(expected, actual,num_elements)    actual 为包含 num_elements 个字符串的数组actual中的每字符串都必须和字符串expected相等

## 5 浮点数比较
TEST_ASSERT_EQUAL_FLOAT(expected, actual) 单精度
TEST_ASSERT_EQUAL_DOUBLE(expected, actual) 双精度
TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual) 单精度
TEST_ASSERT_DOUBLE_WITHIN(delta, expected, actual) 双精度
TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, actual, num_elements) 单精度
TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected, actual, num_elements) 双精度
TEST_ASSERT_EACH_EQUAL_FLOAT(expected, actual, num_elements) 单精度
TEST_ASSERT_EACH_EQUAL_DOUBLE(expected, actual, num_elements) 双精度
TEST_ASSERT_FLOAT_IS_INF(actual)
TEST_ASSERT_DOUBLE_IS_INF(actual)
actual 为正无穷
TEST_ASSERT_FLOAT_IS_NEG_INF(actual)
TEST_ASSERT_DOUBLE_IS_NEG_INF(actual)
actual 为负无穷
TEST_ASSERT_FLOAT_IS_NAN(actual)
TEST_ASSERT_DOUBLE_IS_NAN(actual)
actual 为无效值
（比如负数开根）
TEST_ASSERT_FLOAT_IS_DETERMINATE(actual)
TEST_ASSERT_DOUBLE_IS_DETERMINATE(actual)
actual 为正常值
TEST_ASSERT_FLOAT_IS_NOT_INF(actual)
TEST_ASSERT_DOUBLE_IS_NOT_INF(actual)
actual 不为正无穷
TEST_ASSERT_FLOAT_IS_NOT_NEG_INF(actual)
TEST_ASSERT_DOUBLE_IS_NOT_NEG_INF(actual)
actual 不为负无穷
TEST_ASSERT_FLOAT_IS_NOT_NAN(actual)
TEST_ASSERT_DOUBLE_IS_NOT_NAN(actual)
actual 不为无效值
TEST_ASSERT_FLOAT_IS_NOT_DETERMINATE(actual)
TEST_ASSERT_DOUBLE_IS_NOT_DETERMINATE(actual)
actual 不为正常值

## 6 内存比较
TEST_ASSERT_EQUAL_MEMORY(expected, actual, len)                     两段内存的内容必须相同，起始地址分别为expected 和 actual，长度均为 len
TEST_ASSERT_EQUAL_MEMORY_ARRAY(expected, actual, len, num_elements) expected 和 actual 中均有 num_elements 个大小为 len 的内存块，要求每个对应的块的内容相同
TEST_ASSERT_EACH_EQUAL_MEMORY(expected,actual, len, num_elements)   expected 为一个大小为 len 的内存块actual 为 num_elements 个大小为 len 的内存块要求 actual 中每一块的内容都和 expected 相同


# 二、移植
unity_internals.h 文件的开始处加入如下的宏定义。
#define UNITY_INCLUDE_CONFIG_H
加入该宏定义后，Unity就会自动包含头文件unity_config.h并使用其中的内容

## 1、整数宽度
默认32
#define UNITY_INT_WIDTH 32
#define UNITY_LONG_WIDTH 32
#define UNITY_POINTER_WIDTH 32

## 2、默认32位
64位支持
#define UNITY_SUPPORT_64

## 3、解除float支持
解除对 float 类型的支持
#define UNITY_EXCLUDE_FLOAT

## 4、默认不支持double
添加支持
#define UNITY_INCLUDE_DOUBLE

## 5、浮点数判断误差定义
#define UNITY_FLOAT_PRECISION (0.00001f)
#define UNITY_DOUBLE_PRECISION (1e-12)

## 6、字符输出函数声明
Unity 默认使用 stdio 库中的 putchar 函数输出测试的各种信息，但是在嵌入式平台的测
试中，有时候需要对输出信息进行重定向，所以就需要重新指定一个输出函数，使用以下
的宏定义可以指定输出函数。
#define UNITY_OUTPUT_CHAR(a) output_char(a)






