/**
 ******************************************************************************
 * @file    Node.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-04-23
 * @brief   二叉搜索树节点类模板
 ******************************************************************************
 */

#pragma once

#include <iostream>

using namespace std;

template<class T>
class Node{
public:
    T data;
    Node *leftChild, *rightChild, *parent;

public:
    Node();
    Node(T data, Node *leftChild, Node *rightChild, Node<T>* parent);

};

/**
  * @brief  此函数为构造函数
  * @param None
  * @retval None
  */
template<class T>
Node<T>::Node() {
    leftChild = nullptr;
    rightChild = nullptr;
    parent = nullptr;
}

/**
  * @brief  此函数为构造函数
  * @param None
  * @retval None
  */
template<class T>
Node<T>::Node(T data, Node<T> *leftChild, Node<T> *rightChild, Node<T>* parent){
    this->data = data;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
    this->parent = parent;
}
