/**
  ******************************************************************************
  * @file    lnkStack.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-09
  * @brief   链式栈模板
  ******************************************************************************
  */

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class lnkStack {
private:
    Node<T>* head, * tail;  // 头节点，尾节点
    int len = 0;  // 链式栈长度

public:
    lnkStack();
    explicit lnkStack(int n);
    ~lnkStack();
    int size();
    void push(T val);
    void pop();
    bool empty();
    T& top();

private:
    Node<T>* getNode(int p);
    void init();

    // 下面定义一些不能在类外定义的函数
public:
    /**
      * @brief  此函数重载<<运算符
      * @param[in] out ostream的引用
      * @param[in] a 要操作的类对象
      * @retval 返回ostream的引用
      */
    friend ostream& operator<< (ostream& out, lnkStack<T>& a) {
        if (a.empty()) {
            out << "空栈" << endl;
            return out;
        }
        Node<T>* pos;
        pos = a.head->next;
        for (int i = 0; i < a.size(); ++i) {
            out << pos->data << " ";
            pos = pos->next;
        }
        out << endl;
        return out;
    }

};

/**
  * @brief  此函数为构造函数
  * @param None
  * @retval None
  */
template<class T>
lnkStack<T>::lnkStack() {
    init();
}

/**
  * @brief  此构造函数创建一定长度的链式栈
  * @param[in] n 创建的链式栈长度
  * @retval None
  */
template<class T>
lnkStack<T>::lnkStack(int n) {
    init();
    for (int i = 0; i < n; ++i) {
        push(0);
    }
}

/**
  * @brief  此函数为析构函数，清除所有的节点
  * @param None
  * @retval None
  */
template<class T>
lnkStack<T>::~lnkStack() {
    Node<T>* tmp;  // 定义指向结点的指针
    while (head != NULL) {
        tmp = head;  // tmp指向当前结点
        head = head->next;  // head指向下一结点
        delete tmp;  // 删除当前结点
    }
}

/**
  * @brief  此函数获取链式栈的长度
  * @param None
  * @retval 返回链表长度
  */
template<class T>
int lnkStack<T>::size() {
    return len;
}

/**
  * @brief  此函数向链式栈压入一个元素
  * @param[in] val 追加元素的值
  * @retval None
  */
template<class T>
void lnkStack<T>::push(const T val) {
    Node<T>* temp, * pre;  // 插入节点
    temp = new Node<T>(val, tail);  // temp后驱更新为tail
    pre = tail->next;  // 获取末节点
    tail->next = temp;  // 将尾结点指向新插入节点
    pre->next = temp;  // 前末节点的后驱更新为新插入节点
    ++len;  // 长度+1
    cout << "追加成功" << endl;
}

/**
  * @brief  此函数弹出链式栈最后一个元素
  * @param None
  * @retval None
  */
template<class T>
void lnkStack<T>::pop() {
    if (empty()) {
        cout << "表空！" << endl;
        return;
    }

    Node<T>* pre, * temp;
    temp = tail->next;  // 获取末节点
    pre = getNode(size() - 1);  // 获取末节点前驱节点
    pre->next = tail;  // 前末节点前驱节点更新为末节点
    tail->next = pre;  // 尾节点更新为pre
    delete temp;
    --len;
    cout << "删除成功" << endl;
}

/**
  * @brief  此函数获取链式栈是否为空的判断
  * @param None
  * @retval true 链表为空
  * @retval false 链表非空
  */
template<class T>
bool lnkStack<T>::empty() {
    return !size();
}

/**
  * @brief  此函数返回链式栈最后一个元素的引用
  * @param None
  * @retval 返回链式栈最后一个元素的引用
  */
template<class T>
T& lnkStack<T>::top() {
    return (tail->next)->data;
}

/**
  * @brief  此函数获取链式栈指定位置的节点指针
  * @param[in] p 元素位置
  * @retval 返回链表指定位置节点的指针
  */
template<class T>
Node<T>* lnkStack<T>::getNode(int p) {
    if (p < 0 || p > size()) return head;  // 越界返回头节点
    Node<T>* temp;
    temp = head->next;
    for (int i = 0; i < p; i++) {
        temp = temp->next;
    }
    return temp;
}

/**
  * @brief  此函数初始化链式栈的变量
  * @param None
  * @retval None
  */
template<class T>
void lnkStack<T>::init() {
    len = 0;  // 初始化长度为0
    head = new Node<T>;  // 创建头结点
    tail = new Node<T>;  // 创建尾结点
    head->next = tail;  // 头结点指向尾指针
    tail->next = head;  // 尾结点指向头指针
}
