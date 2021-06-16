/**
 ******************************************************************************
 * @file    Compare.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-16
 * @brief   排序仿函数模板头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>

using namespace std;

template<class T>
class Lesser{
public:
    /**
      * @brief  此函数重载()，返回对a<b的判断
      * @param a 第一个数
      * @param b 第二个数
      * @retval true a<b
      * @retval false a>=b
      */
    bool operator() (const T& a, const T& b){
        return a < b;
    }
};

template<class T>
class Greater{
public:
    /**
      * @brief  此函数重载()，返回对a>b的判断
      * @param a 第一个数
      * @param b 第二个数
      * @retval true a>b
      * @retval false a<=b
      */
    bool operator() (const T& a, const T& b){
        return a > b;
    }
};
