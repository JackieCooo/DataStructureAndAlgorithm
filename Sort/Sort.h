/**
 ******************************************************************************
 * @file    Sort.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-08
 * @brief   ����ģ��ͷ�ļ�
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
  * @brief  �˺����Ը������鷶Χ����ð������
  * @param l ��߽�
  * @param r �ұ߽�
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
  * @brief  �˺����Ը������鷶Χ����ϣ������
  * @param l ��߽�
  * @param r �ұ߽�
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::shellSort(T *l, T *r) {
    Compare cmp;
    int gap = (r-l) / 2;  // ��ʼ������
    while(gap){
        for (int i = gap; i < r-l; ++i) {  // �ܹ�����Ĵ���
            int j;
            T tmp = *(l+i);  // ����Ԫ��
            for (j = i-gap; j >= 0 && cmp(*(l+j), tmp); j -= gap) {  // Ѱ�Ҳ���λ�ã��Ҳ�����ά��ԭλ
                *(l+j+gap) = *(l+j);  // ǰ���Ԫ�غ���
            }
            *(l+j+gap) = tmp;  // ����
        }
        gap /= 2;
    }
}

/**
  * @brief  �˺����Ը������鷶Χ���ж�����
  * @param l ��߽�
  * @param r �ұ߽�
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
  * @brief  �˺����Ը������鷶Χ���п�������
  * @param l ��߽�
  * @param r �ұ߽�
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::quickSort(T *l, T *r) {
    _quick_sort(l-l, r-l-1, l);
}

/**
  * @brief  �˺���Ϊ��������ĵݹ�ʵ��
  * @param left ��߽�
  * @param right �ұ߽�
  * @param begin ԭ����������ָ��
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::_quick_sort(int left, int right, T* begin) {
    if(left >= right) return;
    Compare cmp;
    int i = left;
    int j = right;
    T baseNum = *(begin+i);  // ��׼��
    while (i < j) {  // ������i < j
        while ((cmp(*(begin+j), baseNum) || baseNum == *(begin+j)) && i < j){  // j��������������һֱ��ǰ
            --j;
        }
        while ((cmp(baseNum, *(begin+i)) || baseNum == *(begin+i)) && i < j){  // i��������������һֱ���
            ++i;
        }
        if(i < j){
            swap(*(begin+i), *(begin+j));  // ����
        }
    }
    *(begin+left) = *(begin+i);  // ��׼����λ
    *(begin+i) = baseNum;
    _quick_sort(left, i-1, begin);  // �ݹ��׼�����
    _quick_sort(i+1, right, begin);  // �ݹ��׼���ұ�
}

/**
  * @brief  �˺����Ը������鷶Χ����Ͱ����
  * @param l ��߽�
  * @param r �ұ߽�
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::bucketSort(T *l, T *r) {
    Compare cmp;
    T maxNum = *(max_element(l, r));  // �ҵ�������
    int bits = ceil(log10(maxNum));  // �ó��������λ��
    int gap = floor(sqrt(bits));  // �ó��ָ�λ��
    vector< vector<T> > bucket(floor(maxNum / pow(10, bits-1)) + 1);  // �ó�Ͱ������������ʼ��Ͱ
    for (T* i = l; i != r; ++i) {  // ��������Ͱ��
        int p = (*i) / pow(10, gap);
        bucket[p].push_back(*i);
    }
    for (int i = 0; i < bucket.size(); ++i) {  // ÿ��Ͱ������������
        sort(bucket[i].begin(), bucket[i].end());
    }
    int t = 0;
    if(typeid(cmp) == typeid(Greater<T>)){  // ����
        for (auto &i : bucket){  // �滻ԭ������
            for (auto &j : i){
                *(l+(t++)) = j;
            }
        }
    }
    else{  // ����
        for (auto i = bucket.rbegin(); i != bucket.rend() ; ++i) {  // �滻ԭ������
            for (auto j = (*i).rbegin(); j != (*i).rend(); ++j) {
                *(l+(t++)) = *j;
            }
        }
    }
}

/**
  * @brief  �˺����Ը������鷶Χ���й鲢����
  * @param l ��߽�
  * @param r �ұ߽�
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::mergeSort(T *l, T *r) {
    _merge_sort(l-l, r-l-1, l);
}

/**
  * @brief  �˺���Ϊ�鲢����Ĳ�ֹ��̺���
  * @param left ��߽�
  * @param right �ұ߽�
  * @param begin ԭ����������ָ��
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::_merge_sort(int left, int right, T *begin) {
    if(left == right){
        return;
    }
    int middle = (left + right) / 2;  // ���Ҷ԰��
    _merge_sort(left, middle, begin);  // �ݹ�����
    _merge_sort(middle+1, right, begin);  // �ݹ��Ұ��
    _merge(left, middle, right, begin);  // �ϲ�
}

/**
  * @brief  �˺���Ϊ�鲢����ĺϲ����̺���
  * @param left ��߽�
  * @param right �ұ߽�
  * @param middle �м��
  * @param begin ԭ����������ָ��
  * @retval None
  */
template<class T, class Compare>
void Sort<T, Compare>::_merge(int left, int middle, int right, T *begin) {
    Compare cmp;
    vector<T> tmp;  // ��ʱ�����Ž��
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
    // ��ʣ�µ���ѹ����
    while (j <= middle){
        tmp.push_back(*(begin+j));
        ++j;
    }
    while (k <= right){
        tmp.push_back(*(begin+k));
        ++k;
    }
    for (int i = 0; i < tmp.size(); ++i) {  // �滻ԭ��������
        *(begin+left+i) = tmp[i];
    }
}
