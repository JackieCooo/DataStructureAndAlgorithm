/**
 ******************************************************************************
 * @file    Compare.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-09
 * @brief   排序仿函数模板头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>

using namespace std;

template<class T>
class Lesser{
public:
    bool operator() (const T& a, const T& b){
        return a < b;
    }
};

template<class T>
class Greater{
public:
    bool operator() (const T& a, const T& b){
        return a > b;
    }
};
