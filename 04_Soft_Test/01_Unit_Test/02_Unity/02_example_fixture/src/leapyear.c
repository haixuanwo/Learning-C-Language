/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-14 18:14:38
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-14 18:14:46
 * @Description: file content
 */

#include "leapyear.h"

/**
 * @brief 是否为闰年
 *
 * @param year
 * @return true
 * @return false
 */
bool isLeapYear(int year)
{
    bool flag = false; // 默认值为平年

    /* 400 整数倍；4 整数倍而非 100 整数倍 */
    if ((0 == (year % 400)) || ((0 != (year % 100)) && (0 == year % 4)))
    {
        flag = true;
    }

    return flag;
}
