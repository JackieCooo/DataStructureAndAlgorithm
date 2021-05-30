/**
  ******************************************************************************
  * @file    Node.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-09
  * @brief   �ڵ���
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
  * @brief  �˺���Ϊ���캯��
  * @param None
  * @retval None
  */
template<class T>
Node<T>::Node() = default;

/**
  * @brief  �˺���Ϊ���캯����ͬʱΪ�ڵ㸳ֵ
  * @param[in] data �ڵ㱣���ֵ
  * @param[in] next ��һ���ڵ��ָ��
  * @retval None
  */
template<class T>
Node<T>::Node(T data, Node<T>*next) {
    this->data = data;
    this->next = next;
}
