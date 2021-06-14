/**
 ******************************************************************************
 * @file    Index.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-12
 * @brief   索引模板头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "indexNode.h"
#include "hashMap.h"

using namespace std;

/**
  * @brief  此函数在输入的数组范围内进行顺序索引
  * @param l 索引左边界
  * @param r 索引右边界
  * @param val 要查找的数
  * @retval 返回指向原来数组的数的指针，找不到返回空指针
  */
template<class T>
T* sequentialIndex(T* l, T* r, T val){
    for (T* i = l; i != r && *i <= val; ++i) {
        if(*i == val) return i;
    }
    return nullptr;
}

/**
  * @brief  此函数在输入的数组范围内进行二分索引
  * @param l 索引左边界
  * @param r 索引右边界
  * @param val 要查找的数
  * @retval 返回指向原来数组的数的指针，找不到返回空指针
  */
template<class T>
T* binaryIndex(T* l, T* r, T val){
    int left  = l-l;
    int right = r-l-1;
    int p;
    while (true){
        p = (right + left) / 2;  // 二分
        if(*(l+p) == val) return l+p;
        if(!p || p == r-l-1) break;
        if(*(l+p) < val){  // 往右边搜
            left = p+1;  // 更新左边界
        }
        else{  // 往左边搜
            right = p-1;  // 更新右边界
        }
    }
    return nullptr;
}

/**
  * @brief  此函数在输入的数组范围内进行块索引
  * @param l 索引左边界
  * @param r 索引右边界
  * @param val 要查找的数
  * @retval 返回指向原来数组的数的指针，找不到返回空指针
  */
template<class T>
T* blockIndex(T* l, T* r, T val){
    vector<IndexNode<T>> indexTable;  // 索引表
    int block = (r-l) / 10 + 1;  // 确定块数量，每个块有10个数
    for (int i = 0; i < block; ++i) {  // 初始化索引表
        T* tmpNum = max_element(l+i*10, r-(l+(i+1)*10) >= 0 ? l+(i+1)*10 : r);  // 找出最大索引
        IndexNode<T> tmp(*tmpNum, l+i*10, r-(l+(i+1)*10) >= 0 ? l+(i+1)*10 : r);
        indexTable.push_back(tmp);
    }
    for (int i = 0; i < indexTable.size(); ++i) {  // 顺序查找块
        if(indexTable[i].maxIndex >= val){
            for (T* j = indexTable[i].start; j != indexTable[i].end && *j <= val; ++j) {  // 顺序查找块内数据
                if(*j == val){
                    return j;
                }
            }
            return nullptr;
        }
    }
    return nullptr;
}

/**
  * @brief  此函数在输入的数组范围内进行哈希索引
  * @param l 索引左边界
  * @param r 索引右边界
  * @param val 要查找的数
  * @retval 返回指向原来数组的数的指针，找不到返回空指针
  */
template<class T>
T* hashIndex(T* l, T* r, T val){
    auto* h = new HashMap<T>(r-l);
    for (T* i = l; i != r; ++i) {  // 逐个数压入哈希表
        h->insert(i);
    }
    return h->find(val);  // 查找数
}

/*template<class T>
T* binary_index(int left, int right, T* begin){
    int p = (right)
    if (*(begin + ))
}*/
