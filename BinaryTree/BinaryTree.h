/**
 ******************************************************************************
 * @file    BinaryTree.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-04-23
 * @brief   二叉树模板头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <queue>
#include "Node.h"

using namespace std;

class BinaryTree{
private:
    Node *root;  // 根节点

public:
    BinaryTree();
    void creatBTreeWithPreorderTraversal(const int *num);
    void creatBTreeWithPreorderTraversal();
    void printBTreeWithPreorderTraversal();
    void printBTreeWithInorderTraversal();
    void printBTreeWithPostorderTraversal();
    void printBTreeWithLevelTraversal();
    bool empty();
    void clear();
    ~BinaryTree();

private:
    Node* createBTree(Node *BT, const int *num, int& index);
    Node* createBTree(Node *BT);
    void preorderTraversal(Node* BT);
    void inorderTraversal(Node* BT);
    void postorderTraversal(Node* BT);
    void deleteBinaryTree(Node* BT);

};