/**
 ******************************************************************************
 * @file    Heap.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-09
 * @brief   堆模板头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Compare.h"

using namespace std;

template<class T, class Compare = Greater<T>>
class Heap{
private:
    vector<T>* heap;

public:
    Heap() = default;
    Heap(T* l, T* r);
    void makeHeap();
    void push(T val);
    T& top();
    void pop();
    ~Heap();

private:
    void adjustUp(int thisNode);
    void adjustDown(int thisNode);

};

template<class T, class Compare>
Heap<T, Compare>::~Heap() {
    delete heap;
}

template<class T, class Compare>
Heap<T, Compare>::Heap(T *l, T *r) {
    auto* tmp = new vector<T>;
    for (T* i = l; i < r; ++i) {
        tmp->push_back(*i);
    }
    heap = tmp;
    makeHeap();  // 建堆
}

template<class T, class Compare>
void Heap<T, Compare>::makeHeap() {
    for (int i = (heap->size() - 2) / 2; i >= 0; --i) {  // 从最后一个非叶子节点，调整到根节点
        adjustDown(i);
    }
}

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

template<class T, class Compare>
void Heap<T, Compare>::push(T val) {
    heap->push_back(val);
    adjustUp(heap->size()-1);
}

template<class T, class Compare>
T& Heap<T, Compare>::top() {
    return heap->front();
}

template<class T, class Compare>
void Heap<T, Compare>::pop() {
    swap(heap->front(), heap->back());  // 调换前后两个数，方便pop
    heap->pop_back();
    makeHeap();  // 重新建堆
}
