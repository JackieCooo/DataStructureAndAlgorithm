/**
 ******************************************************************************
 * @file    indexNode.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-13
 * @brief   索引表节点类头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>

using namespace std;

template<class T>
class IndexNode{
public:
    T maxIndex;
    T* start;
    T* end;

public:
    IndexNode(T maxIndex, T* start, T* end) : maxIndex(maxIndex), start(start), end(end) {};
};
