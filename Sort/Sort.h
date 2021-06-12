/**
 ******************************************************************************
 * @file    Sort.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-08
 * @brief   排序模板头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "Compare.h"
#include "Heap.h"

using namespace std;

template<class T, class Compare = Greater<T> >
class Sort{
public:
    void bubbleSort(T* l, T* r);
    void shellSort(T* l, T* r);
    void heapSort(T* l, T* r);
    void quickSort(T* l, T* r);
    void bucketSort(T* l, T* r);
    void mergeSort(T* l, T* r);

private:
    void _quick_sort(int left, int right, T* begin);
    void _merge_sort(int left, int right, T* begin);
    void _merge(int left, int middle, int right, T* begin);

};

/**
  * @brief  此函数对给定数组范围进行冒泡排序
  * @param l 左边界
  * @param r 右边界
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::bubbleSort(T *l, T *r) {
    Compare cmp;
    for (auto i = l; i != r ; ++i) {
        for (auto j = i+1; j < r; ++j) {
            if(cmp(*i, *j)){
                swap(*i, *j);
            }
        }
    }
}

/**
  * @brief  此函数对给定数组范围进行希尔排序
  * @param l 左边界
  * @param r 右边界
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::shellSort(T *l, T *r) {
    Compare cmp;
    int gap = (r-l) / 2;  // 初始化步长
    while(gap){
        for (int i = gap; i < r-l; ++i) {  // 总共排序的次数
            int j;
            T tmp = *(l+i);  // 插入元素
            for (j = i-gap; j >= 0 && cmp(*(l+j), tmp); j -= gap) {  // 寻找插入位置，找不到就维持原位
                *(l+j+gap) = *(l+j);  // 前面的元素后退
            }
            *(l+j+gap) = tmp;  // 插入
        }
        gap /= 2;
    }
}

/**
  * @brief  此函数对给定数组范围进行堆排序
  * @param l 左边界
  * @param r 右边界
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::heapSort(T *l, T *r) {
    Heap<T, Compare> h(l, r);
    for (int i = 0; i < r-l; ++i) {
        *(l+i) = h.top();
        h.pop();
    }
}

/**
  * @brief  此函数对给定数组范围进行快速排序
  * @param l 左边界
  * @param r 右边界
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::quickSort(T *l, T *r) {
    _quick_sort(l-l, r-l-1, l);
}

/**
  * @brief  此函数为快速排序的递归实现
  * @param left 左边界
  * @param right 右边界
  * @param begin 原排序区间首指针
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::_quick_sort(int left, int right, T* begin) {
    if(left >= right) return;
    Compare cmp;
    int i = left;
    int j = right;
    T baseNum = *(begin+i);  // 基准数
    while (i < j) {  // 遍历至i < j
        while ((cmp(*(begin+j), baseNum) || baseNum == *(begin+j)) && i < j){  // j不符合条件，就一直向前
            --j;
        }
        while ((cmp(baseNum, *(begin+i)) || baseNum == *(begin+i)) && i < j){  // i不符合条件，就一直向后
            ++i;
        }
        if(i < j){
            swap(*(begin+i), *(begin+j));  // 交换
        }
    }
    *(begin+left) = *(begin+i);  // 基准数归位
    *(begin+i) = baseNum;
    _quick_sort(left, i-1, begin);  // 递归基准数左边
    _quick_sort(i+1, right, begin);  // 递归基准数右边
}

/**
  * @brief  此函数对给定数组范围进行桶排序
  * @param l 左边界
  * @param r 右边界
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::bucketSort(T *l, T *r) {
    Compare cmp;
    T maxNum = *(max_element(l, r));  // 找到最大的数
    int bits = ceil(log10(maxNum));  // 得出最大数的位数
    int gap = floor(sqrt(bits));  // 得出分割位置
    vector< vector<T> > bucket(floor(maxNum / pow(10, bits-1)) + 1);  // 得出桶的数量，并初始化桶
    for (T* i = l; i != r; ++i) {  // 把数放入桶中
        int p = (*i) / pow(10, gap);
        bucket[p].push_back(*i);
    }
    for (int i = 0; i < bucket.size(); ++i) {  // 每个桶进行排序，升序
        sort(bucket[i].begin(), bucket[i].end());
    }
    int t = 0;
    if(typeid(cmp) == typeid(Greater<T>)){  // 升序
        for (auto &i : bucket){  // 替换原来的数
            for (auto &j : i){
                *(l+(t++)) = j;
            }
        }
    }
    else{  // 降序
        for (auto i = bucket.rbegin(); i != bucket.rend() ; ++i) {  // 替换原来的数
            for (auto j = (*i).rbegin(); j != (*i).rend(); ++j) {
                *(l+(t++)) = *j;
            }
        }
    }
}

/**
  * @brief  此函数对给定数组范围进行归并排序
  * @param l 左边界
  * @param r 右边界
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::mergeSort(T *l, T *r) {
    _merge_sort(l-l, r-l-1, l);
}

/**
  * @brief  此函数为归并排序的拆分过程函数
  * @param left 左边界
  * @param right 右边界
  * @param begin 原排序区间首指针
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::_merge_sort(int left, int right, T *begin) {
    if(left == right){
        return;
    }
    int middle = (left + right) / 2;  // 左右对半分
    _merge_sort(left, middle, begin);  // 递归左半边
    _merge_sort(middle+1, right, begin);  // 递归右半边
    _merge(left, middle, right, begin);  // 合并
}

/**
  * @brief  此函数为归并排序的合并过程函数
  * @param left 左边界
  * @param right 右边界
  * @param middle 中间点
  * @param begin 原排序区间首指针
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::_merge(int left, int middle, int right, T *begin) {
    Compare cmp;
    vector<T> tmp;  // 临时数组存放结果
    int j = left, k = middle+1;
    while (j <= middle && k <= right){
        if(cmp(*(begin+j), *(begin+k))){
            tmp.push_back(*(begin+k));
            ++k;
        }
        else{
            tmp.push_back(*(begin+j));
            ++j;
        }
    }
    // 把剩下的数压数组
    while (j <= middle){
        tmp.push_back(*(begin+j));
        ++j;
    }
    while (k <= right){
        tmp.push_back(*(begin+k));
        ++k;
    }
    for (int i = 0; i < tmp.size(); ++i) {  // 替换原来的数组
        *(begin+left+i) = tmp[i];
    }
}
