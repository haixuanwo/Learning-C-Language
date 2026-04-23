
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define SIZE_OF_ARRAY(arr) (sizeof(arr) / sizeof(arr[0]))

int binary_search(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; // Not found
}

// ----------------------------------------------------------------------------
// 单元测试

// 1. 基本功能测试
void test_basic_function()
{
    // （1）目标在数组中间
    int arr[] = {1,3,5,7,9};
    int target = 5;//  → 返回 2

    assert(2 == binary_search(arr, SIZE_OF_ARRAY(arr), target));

    // （2）目标在数组开头
    target = 1; // → 返回 0
    assert(0 == binary_search(arr, SIZE_OF_ARRAY(arr), target));

    // （3）目标在数组结尾
    target = 9; //→ 返回 4
    assert(4 == binary_search(arr, SIZE_OF_ARRAY(arr), target));

    printf("test_basic_function pass\n");
}

// 2. 边界情况
void test_edge_case()
{
    // （1）数组只有一个元素且匹配
    int arr[] = {42};
    int target = 42; //  → 返回 0
    assert(0 == binary_search(arr, SIZE_OF_ARRAY(arr), target));

    // （2）数组只有一个元素但不匹配
    target = 7; // → 返回 -1
    assert(-1 == binary_search(arr, SIZE_OF_ARRAY(arr), target));

    // （3）数组为空
    int arr1[] = {};
    int size = 0;
    target = 2; // → 任意值 → 返回 -1（注意：实现中 right = -1，循环不进入，返回 -1）
    assert(-1 == binary_search(arr1, size, target));
    printf("test_edge_case pass\n");
}


// 3. 不存在目标值
void test_not_exist_target()
{
    // （1）目标小于所有元素
    int arr[] = {10,20,30};
    int  target = 5; //  → 返回 -1
    assert(-1 == binary_search(arr, SIZE_OF_ARRAY(arr), target));

    // （2）目标大于所有元素
    target = 35; //  → 返回 -1
    assert(-1 == binary_search(arr, SIZE_OF_ARRAY(arr), target));

    // （3）目标在数值区间但不存在
    int arr1[] = {2,4,6,8};
    target = 5; // → 返回 -1
    assert(-1 == binary_search(arr1, SIZE_OF_ARRAY(arr1), target));

    printf("test_not_exist_target pass\n");
}

// 4. 重复元素
void test_repeat_element()
{
    // （重复元素返回任意匹配索引（通常要求返回第一个找到的，但实现未明确）
    int arr[] = {1,2,2,2,3};
    int target = 2; //  → 可能返回 1、2 或 3，测试中应接受其中一个
    assert(1 == binary_search(arr, SIZE_OF_ARRAY(arr), target) || 2 == binary_search(arr, SIZE_OF_ARRAY(arr), target) || 3 == binary_search(arr, SIZE_OF_ARRAY(arr), target));

    printf("test_repeat_element pass\n");
}

// 5. 大 / 负 / 零值
void test_big_negative_zero()
{
    // （1）包含负数
    int arr[] = {-10,-5,0,5,10};
    int target = -5; // → 返回 1
    assert(1 == binary_search(arr, SIZE_OF_ARRAY(arr), target));

    // （2）目标为零
    int arr1[] = {-3,-1,0,1,3};
    target = 0; // → 返回 2
    assert(2 == binary_search(arr, SIZE_OF_ARRAY(arr), target));


    // （3）大数值（检查溢出，你的 mid 计算已防溢出）
    int arr2[] = {INT_MIN, -1, 0, 1, INT_MAX};
    target = INT_MAX; // → 返回 4
    assert(4 == binary_search(arr2, SIZE_OF_ARRAY(arr2), target));

    target = INT_MIN; // → 返回 0
    assert(0 == binary_search(arr2, SIZE_OF_ARRAY(arr2), target));

    printf("test_big_negative_zero pass\n");
}


// 6. 奇偶长度数组
void test_odd_even_length()
{
    // （1）偶数长度
    int arr[] = {1,2,3,4};
    int target = 3; // → 返回 2
    assert(2 == binary_search(arr, SIZE_OF_ARRAY(arr), target));

    // （2）奇数长度
    int arr1[] = {1,2,3};
    target = 2; // → 返回 1
    assert(1 == binary_search(arr1, SIZE_OF_ARRAY(arr1), target));

    printf("test_odd_even_length pass\n");
}


int main(int argc, char *argv[])
{
    test_basic_function();
    test_edge_case();
    test_not_exist_target();
    test_repeat_element();
    test_big_negative_zero();
    test_odd_even_length();

    return 0;
}
