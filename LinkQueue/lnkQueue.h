/**
  ******************************************************************************
  * @file    lnkQueue.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-16
  * @brief   链式队列模板
  ******************************************************************************
  */

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class lnkQueue {
private:
    Node<T>* head, * tail;  // 头节点，尾节点
    int len = 0;  // 链队长度

public:
    lnkQueue();
    ~lnkQueue();
    int size();
    void push(T val);
    bool empty();
    void pop();
    T& front();
    T& back();

private:
    void init();

    // 下面定义一些不能在类外定义的函数
public:
    /**
      * @brief  此函数重载<<运算符
      * @param[in] out ostream的引用
      * @param[in] a 要操作的类对象
      * @retval 返回ostream的引用
      */
    friend ostream& operator<< (ostream& out, lnkQueue<T>& a) {
        if (a.empty()) {
            out << "空队" << endl;
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
lnkQueue<T>::lnkQueue() {
    init();
}

/**
  * @brief  此函数为析构函数，清除所有的节点
  * @param None
  * @retval None
  */
template<class T>
lnkQueue<T>::~lnkQueue() {
    Node<T>* tmp;  // 定义指向结点的指针
    while (head != NULL) {
        tmp = head;  // tmp指向当前结点
        head = head->next;  // head指向下一结点
        delete tmp;  // 删除当前结点
    }
}

/**
  * @brief  此函数获取链队的长度
  * @param None
  * @retval 返回链队长度
  */
template<class T>
int lnkQueue<T>::size() {
    return len;
}

/**
  * @brief  此函数向链队追加一个元素
  * @param[in] val 追加元素的值
  * @retval None
  */
template<class T>
void lnkQueue<T>::push(T val) {
    Node<T>* temp, * pre;  // 插入节点
    temp = new Node<T>(val, tail);  // temp后驱更新为tail
    pre = tail->next;  // 获取末节点
    tail->next = temp;  // 将尾结点指向新插入节点
    pre->next = temp;  // 前末节点的后驱更新为新插入节点
    ++len;  // 长度+1
    cout << "入队成功" << endl;
}

/**
  * @brief  此函数获取链队是否为空的判断
  * @param None
  * @retval true 链队为空
  * @retval false 链队非空
  */
template<class T>
bool lnkQueue<T>::empty() {
    return !size();
}

/**
  * @brief  此函数删除链队第一个元素
  * @param None
  * @retval None
  */
template<class T>
void lnkQueue<T>::pop() {
    if(empty()){
        cout << "队空" << endl;
        return;
    }
    Node<T>* temp;  // temp为删除节点
    temp = head->next;
    head->next = temp->next;  // 更新头节点为temp的前驱
    delete temp;
    --len;
    cout << "出队成功" << endl;
}

/**
  * @brief  此函数返回链队首元素的引用
  * @param None
  * @retval 返回链队首元素的引用
  */
template<class T>
T& lnkQueue<T>::front() {
    return (head->next)->data;
}

/**
  * @brief  此函数返回链队末元素的引用
  * @param None
  * @retval 返回链队末元素的引用
  */
template<class T>
T& lnkQueue<T>::back() {
    return (tail->next)->data;
}

/**
  * @brief  此函数初始化链表的变量
  * @param None
  * @retval None
  */
template<class T>
void lnkQueue<T>::init() {
    len = 0;  // 初始化长度为0
    head = new Node<T>;  // 创建头结点
    tail = new Node<T>;  // 创建尾结点
    head->next = tail;  // 头结点指向尾指针
    tail->next = head;  // 尾结点指向头指针
}
