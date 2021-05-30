/**
 ******************************************************************************
 * @file    Node.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-05-21
 * @brief   节点类
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <list>
#include "Tree.h"

using namespace std;

template<class T>
class Node{
public:
    T data;
    Node *parent = nullptr;
    list< Node<T>* > children;

public:
    Node() = default;
    Node(T data, Node<T>* parent, list< Node<T>* >& children) : data(data), parent(parent), children(children) {};
    Node(T data, Node<T>* parent) : data(data), parent(parent) {};
    explicit Node(T data) : data(data) {};
};
