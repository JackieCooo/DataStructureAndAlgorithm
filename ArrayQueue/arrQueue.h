/**
  ******************************************************************************
  * @file    arrQueue.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-09
  * @brief   顺序循环队列模板
  ******************************************************************************
=  */

#pragma once

#include <iostream>

using namespace std;

template <class T>
class arrQueue{
private:
    T* qu = NULL;  // 存储顺序循环队列的实例
    int  maxSize = 0;  // 顺序循环队列实例的最大长度
    int  curLen = 0;  // 顺序循环队列实例的当前长度
    int head = 0;  // 队列的头部
    int tail = 0;  // 队列的尾部

public:
    arrQueue();
    explicit arrQueue(int size);
    ~arrQueue();
    int size();
    bool empty();
    void push(T val);
    void pop();
    T& front();
    T& back();

private:
    void resize(int s);

// 下面定义一些不能在类外定义的函数
public:
    /**
      * @brief  此函数重载<<，使cout能直接输出整个数组
      * @param[in] out ostream的引用
      * @param[in] a 要输出的类对象
      * @retval 返回ostream&的引用
      */
    friend ostream& operator<< (ostream& out, arrQueue<T>& a){
        if (a.size() == 0) {
            out << "空队列！" << endl;
            return out;
        }
        for (int i = 0, j = a.head; i < a.curLen; i++) {
            out << a.qu[j++] << " ";
            if (j == a.maxSize) j = 0;  // 防止越界
        }
        out << endl;
        return out;
    }

    /**
      * @brief  此函数重载<<，使cout能直接输出其中一个元素
      * @param[in] out ostream的引用
      * @param[in] a 要输出的元素
      * @retval 返回ostream&的引用
      */
    friend ostream& operator<< (ostream& out, T& a){
        out << a << endl;
        return out;
    }

};

/**
  * @brief  此构造函数初始化类对象
  * @param None
  * @retval None
  */
template<class T>
arrQueue<T>::arrQueue()  = default;

/**
  * @brief  此构造函数初始化类对象
  * @param[in] size 顺序表的最大长度
  * @retval None
  */
template<class T>
arrQueue<T>::arrQueue(int size) {
    maxSize = size;
    qu = new T[maxSize];  // 堆区创建数组
    curLen = 0;
}

/**
  * @brief  此析构函数在退出前释放堆区队列
  * @param None
  * @retval None
  */
template<class T>
arrQueue<T>::~arrQueue<T>() {
    delete [] qu;
}

/**
  * @brief  此函数获取顺序表目前的大小
  * @param None
  * @retval curLen 顺序表目前的大小
  */
template<class T>
int arrQueue<T>::size() {
    return curLen;
}

/**
  * @brief  此函数返回顺序表是否为空的判断
  * @param None
  * @retval true 顺序表为空
  * @retval false 顺序表不为空
  */
template<class T>
bool arrQueue<T>::empty() {
    if (curLen) return false;
    return true;
}

/**
  * @brief  此函数在表尾追加一个元素
  * @param[in] val 要追加的元素
  * @retval None
  */
template<class T>
void arrQueue<T>::push(T val) {
    if(maxSize == 0){  // 队列空间为0，开辟一个大小为1的空间
        qu = new T[1];
        maxSize = 1;
    }
    else if (curLen >= maxSize) {  // 若队列的备用空间不足，则扩充为之前的两倍
        resize(maxSize*2);
    }
    qu[tail++] = val;  // 往尾部追加
    ++curLen;  // 长度+1
    if(tail == maxSize) tail = 0;  // 尾部越界
    cout << "入队成功！" << endl;
}

/**
  * @brief  此函数弹出队列头部元素
  * @param None
  * @retval None
  */
template<class T>
void arrQueue<T>::pop() {
    if(size() == 0){
        cout << "空队列" << endl;
        return;
    }
    ++head;  // 头部后移
    if (head == maxSize) head = 0;  // 头越界
    --curLen;  // 长度-1
    cout << "出队列成功" << endl;
}

/**
  * @brief  此函数重新设置顺序表的空间大小
  * @param[in] s 最终大小
  * @retval None
  */
template<class T>
void arrQueue<T>::resize(int s) {
    T tempArr[curLen];
    for(int i = 0, j = head; i < curLen; i++){
        tempArr[i] = qu[j++];
        if(j == maxSize) j = 0;  // 防止越界
    }
    delete [] qu;
    qu = new T[s];
    maxSize = s;
    for(int i = 0; i < curLen; i++){
        qu[i] = tempArr[i];
    }
    head = 0; // 更新head的位置
    tail = curLen;  // 更新tail的位置
}

/**
  * @brief  此函数返回顺序表第一个元素的引用
  * @param None
  * @retval None
  */
template<class T>
T& arrQueue<T>::front() {
    return qu[head];
}

/**
  * @brief  此函数返回顺序表最后一个元素的引用
  * @param None
  * @retval None
  */
template<class T>
T& arrQueue<T>::back() {
    return qu[(head+curLen)%maxSize-1];
}
