/**
 ******************************************************************************
 * @file    Heap.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-16
 * @brief   堆模板头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include "Compare.h"

using namespace std;

template<class T, class Compare = Greater<T>>
class Heap{
private:
    vector<T>* heap;

public:
    Heap() = default;
    Heap(T* l, T* r);
    explicit Heap(string& filepath);
    void makeHeap();
    void insert(T val);
    T& top();
    void pop();
    ~Heap();

private:
    void adjustUp(int thisNode);
    void adjustDown(int thisNode);

    friend ostream& operator<< (ostream& out, Heap<T, Compare>& tar){
        for (auto &i : *(tar.heap)) {
            out << i << " ";
        }
        out << endl;
    }

};

/**
  * @brief  此析构函数释放堆
  * @param None
  * @retval None
  */
template<class T, class Compare>
Heap<T, Compare>::~Heap() {
    delete heap;
}

/**
  * @brief  此构造函数通过外部文件输入创建大顶堆或小顶堆
  * @param filepath 外部文件路径
  * @retval None
  */
  template<class T, class Compare>
Heap<T, Compare>::Heap(string &filepath) {
    ifstream ifs;
    ifs.open(filepath, ios::in);
    if (ifs.is_open()){
        auto* tmp = new vector<T>;
        while (!ifs.eof()){
            T val;
            ifs >> val;
            tmp->push_back(val);
        }
        heap = tmp;
        makeHeap();
    }
    else{
        cout << "文件打开失败" << endl;
    }
}

/**
  * @brief  此构造函数根据输入数组的地址范围创建堆
  * @param l 输入数组左边界
  * @param r 输入数组右边界
  * @retval None
  */
template<class T, class Compare>
Heap<T, Compare>::Heap(T *l, T *r) {
    auto* tmp = new vector<T>;
    for (T* i = l; i < r; ++i) {
        tmp->push_back(*i);
    }
    heap = tmp;
    makeHeap();  // 建堆
}

/**
  * @brief  此函数构建大顶堆或小顶堆
  * @param None
  * @retval None
  */
template<class T, class Compare>
void Heap<T, Compare>::makeHeap() {
    for (int i = (heap->size() - 2) / 2; i >= 0; --i) {  // 从最后一个非叶子节点，调整到根节点
        adjustDown(i);
    }
}

/**
  * @brief  此函数从上向下调整节点
  * @param thisNode 起始节点
  * @retval None
  */
template<class T, class Compare>
void Heap<T, Compare>::adjustDown(int thisNode) {
    Compare cmp;
    int child = thisNode * 2 + 1;  // 找到左孩子
    while (child < heap->size()){
        if(child + 1 < heap->size() && cmp((*heap)[child], (*heap)[child+1])){  // 选出最大或最小的孩子
            ++child;
        }

        if(cmp((*heap)[thisNode], (*heap)[child])){  // 符合条件向上调整
            swap((*heap)[thisNode], (*heap)[child]);  // 交换
            thisNode = child;
            child = child * 2 + 1;  // 比较下一个父节点
        }
        else break;
    }
}

/**
  * @brief  此函数从下向上调整节点
  * @param thisNode 起始节点
  * @retval None
  */
template<class T, class Compare>
void Heap<T, Compare>::adjustUp(int thisNode) {
    Compare cmp;
    int parent = (thisNode - 1) / 2;  // 插入节点的父节点
    while (parent >= 0){
        if(cmp((*heap)[parent], (*heap)[thisNode])){
            swap((*heap)[parent], (*heap)[thisNode]);  // 交换
            thisNode = parent;
            parent = (parent - 1) / 2;
        }
        else break;
    }
}

/**
  * @brief  此函数向堆插入节点并调整
  * @param val 插入的数
  * @retval None
  */
template<class T, class Compare>
void Heap<T, Compare>::insert(T val) {
    heap->push_back(val);
    adjustUp(heap->size()-1);
}

/**
  * @brief  此函数获取堆顶元素
  * @param None
  * @retval 返回堆顶元素的引用
  */
template<class T, class Compare>
T& Heap<T, Compare>::top() {
    return heap->front();
}

/**
  * @brief  此函数弹出堆顶元素并调整堆
  * @param None
  * @retval None
  */
template<class T, class Compare>
void Heap<T, Compare>::pop() {
    swap(heap->front(), heap->back());  // 调换前后两个数，方便pop
    heap->pop_back();
    makeHeap();  // 重新建堆
}
