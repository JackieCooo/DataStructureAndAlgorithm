/**
  ******************************************************************************
  * @file    arrStack.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-09
  * @brief   顺序栈模板
  ******************************************************************************
=  */

#pragma once

#include <iostream>

using namespace std;

template <class T>
class arrStack {
private:
    T* st = NULL;  // 存储顺序栈的实例
    int  maxSize = 0;  // 顺序栈实例的最大长度
    int  curLen = 0;  // 顺序栈实例的当前长度

public:
    arrStack();
    explicit arrStack(int size);
    ~arrStack();
    int size();
    bool empty();
    void push(T val);
    void pop();
    T& top();

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
    friend ostream& operator<< (ostream& out, arrStack<T>& a) {
        if (a.empty()) {
            out << "空栈！" << endl;
            return out;
        }
        for (int i = 0; i < a.size(); i++) {
            out << a.st[i] << "  ";
        }
        out << endl;
        return out;
    }

};

/**
  * @brief  此构造函数初始化类对象
  * @param None
  * @retval None
  */
template<class T>
arrStack<T>::arrStack() = default;

/**
  * @brief  此构造函数初始化类对象
  * @param[in] size 顺序表的最大长度
  * @retval None
  */
template<class T>
arrStack<T>::arrStack(int size) {
    maxSize = size;
    st = new T[maxSize];  // 堆区创建数组
    curLen = 0;
}

/**
  * @brief  此析构函数在退出前释放堆区顺序栈
  * @param None
  * @retval None
  */
template<class T>
arrStack<T>::~arrStack<T>() {
    delete[] st;
}

/**
  * @brief  此函数获取顺序栈目前的大小
  * @param None
  * @retval curLen 顺序栈目前的大小
  */
template<class T>
int arrStack<T>::size() {
    return curLen;
}

/**
  * @brief  此函数返回顺序栈是否为空的判断
  * @param None
  * @retval true 顺序栈为空
  * @retval false 顺序栈不为空
  */
template<class T>
bool arrStack<T>::empty() {
    if (curLen > 0) {
        return false;
    }
    return true;
}

/**
  * @brief  此函数往栈顶压入一个元素
  * @param[in] val 压入的元素
  * @retval None
  */
template<class T>
void arrStack<T>::push(T val) {
    if (curLen == 0){  // 长度为0，新建长度为1的顺序栈
        resize(1);
    }
    if (curLen >= maxSize) {  // 若顺序,栈的空间不足，扩充为之前两倍
        resize(maxSize*2);
    }
    st[curLen++] = val;
    cout << "压栈成功！" << endl;
}

/**
  * @brief  此函数弹出栈顶元素
  * @param None
  * @retval None
  */
template<class T>
void arrStack<T>::pop() {
    if (empty()) {
        cout << "空栈" << endl;
        return;
    }
    --curLen;
    cout << "弹栈成功" << endl;
}

/**
  * @brief  此函数获取栈顶元素的引用
  * @param None
  * @retval None
  */
template<class T>
T& arrStack<T>::top() {
    return st[curLen-1];
}

/**
  * @brief  此函数重新设置顺序栈的空间大小
  * @param[in] s 最终大小
  * @retval None
  */
template<class T>
void arrStack<T>::resize(int s) {
    T tempArr[curLen];  // 临时数组
    for(int i = 0; i < curLen; i++){  // 原来的值复制到临时数组
        tempArr[i] = st[i];
    }
    delete [] st;
    st = new T[s];
    maxSize = s;
    for(int i = 0; i < curLen; i++){  // 临时数组的值复制到新数组
        st[i] = tempArr[i];
    }
}
