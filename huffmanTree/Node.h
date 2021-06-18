/**
 ******************************************************************************
 * @file    Node.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-17
 * @brief   哈夫曼树节点头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>

using namespace std;

class Node{
public:
    int weight;
    char data;
    Node* leftChild;
    Node* rightChild;

public:
    Node() = default;
    Node(char data, int weight, Node* leftChild, Node* rightChild) : data(data), weight(weight), leftChild(leftChild), rightChild(rightChild) {};

};
