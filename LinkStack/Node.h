/**
  ******************************************************************************
  * @file    Node.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-09
  * @brief   节点类
  ******************************************************************************
  */

#pragma once

#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T>* next;
public:
    Node();
    Node(T data, Node<T>* next);
};

/**
  * @brief  此函数为构造函数
  * @param None
  * @retval None
  */
template<class T>
Node<T>::Node() = default;

/**
  * @brief  此函数为构造函数，同时为节点赋值
  * @param[in] data 节点保存的值
  * @param[in] next 下一个节点的指针
  * @retval None
  */
template<class T>
Node<T>::Node(T data, Node<T>*next) {
    this->data = data;
    this->next = next;
}
