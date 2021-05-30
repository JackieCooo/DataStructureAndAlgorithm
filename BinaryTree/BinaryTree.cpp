/**
 ******************************************************************************
 * @file    BinaryTree.cpp
 * @author  Jackie
 * @version V1.0
 * @date    2021-04-23
 * @brief   二叉树模板
 ******************************************************************************
 */

#include <iostream>
#include "BinaryTree.h"

using namespace std;

/**
  * @brief  此函数为构造函数
  * @param None
  * @retval None
  */
BinaryTree::BinaryTree() {
    root = nullptr;
}

/**
  * @brief  此函数使用数组来创建二叉树，基于前序遍历
  * @param[in] num 数组首地址
  * @retval None
  */
void BinaryTree::creatBTreeWithPreorderTraversal(const int *num){
    int i = 0;  // 用于遍历输入数组
    root = createBTree(root, num, i);
}

/**
  * @brief  此函数为使用数组来创建二叉树的递归实现，基于前序遍历
  * @param[in] BT 当前节点地址
  * @param[in] num 数组首地址
  * @param[in] index 数组下标
  * @retval 返回创建后当前节点的地址
  */
Node* BinaryTree::createBTree(Node *BT, const int *num, int& index) {
    if(num[index] == 0){  // 输入为0,则此节点为空
        return nullptr;
    }
    else{
        BT = new Node;
        BT->data = num[index];
        BT->leftChild = createBTree(BT->leftChild, num, ++index);  // 先处理左子树
        BT->rightChild = createBTree(BT->rightChild, num, ++index);  // 后处理右子树
        return BT;
    }
}

/**
  * @brief  此函数对二叉树进行前序遍历并输出
  * @param None
  * @retval None
  */
void BinaryTree::printBTreeWithPreorderTraversal() {
    if(root == nullptr) {
        cout << "空树" << endl;
        return;
    }

    preorderTraversal(root);
}

/**
  * @brief  此函数为对二叉树进行前序遍历并输出的递归实现
  * @param[in] BT 当前节点
  * @retval None
  */
void BinaryTree::preorderTraversal(Node *BT) {
    if(BT == nullptr){  // 节点为空，返回上一级
        return;
    }
    else{
        cout << BT->data << " ";
        preorderTraversal(BT->leftChild);  // 先遍历左子树
        preorderTraversal(BT->rightChild);  // 后遍历右子树
    }
}

/**
  * @brief  此函数对二叉树进行中序遍历并输出
  * @param None
  * @retval None
  */
void BinaryTree::printBTreeWithInorderTraversal() {
    if(root == nullptr) {
        cout << "空树" << endl;
        return;
    }

    inorderTraversal(root);
}

/**
  * @brief  此函数为对二叉树进行中序遍历并输出的递归实现
  * @param[in] BT 当前节点
  * @retval None
  */
void BinaryTree::inorderTraversal(Node *BT) {
    if(BT == nullptr){  // 节点为空，返回上一级
        return;
    }
    else{
        preorderTraversal(BT->leftChild);  // 先遍历左子树
        cout << BT->data << " ";
        preorderTraversal(BT->rightChild);  // 后遍历右子树
    }
}

/**
  * @brief  此函数对二叉树进行前序遍历并输出
  * @param None
  * @retval None
  */
void BinaryTree::printBTreeWithPostorderTraversal() {
    if(root == nullptr) {
        cout << "空树" << endl;
        return;
    }

    postorderTraversal(root);
}

/**
  * @brief  此函数为对二叉树进行后序遍历并输出的递归实现
  * @param[in] BT 当前节点
  * @retval None
  */
void BinaryTree::postorderTraversal(Node *BT) {
    if(BT == nullptr){  // 节点为空，返回上一级
        return;
    }
    else{
        postorderTraversal(BT->leftChild);  // 先遍历左子树
        postorderTraversal(BT->rightChild);  // 后遍历右子树
        cout << BT->data << " ";
    }
}

/**
  * @brief  此函数对二叉树进行层序遍历并输出
  * @param None
  * @retval None
  */
void BinaryTree::printBTreeWithLevelTraversal() {
    if(root == nullptr) {
        cout << "空树" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){  // bfs遍历节点
        Node* tmp = q.front();
        cout << tmp->data << " ";
        // 节点存在的话，入队列
        if(tmp->leftChild != nullptr) q.push(tmp->leftChild);
        if(tmp->rightChild != nullptr) q.push(tmp->rightChild);
        q.pop();
    }
}

/**
  * @brief  此函数对二叉树进行前序遍历并删除所有节点
  * @param[in] BT 当前节点
  * @retval None
  */
void BinaryTree::deleteBinaryTree(Node *BT) {
    if(BT == nullptr){
        return;
    }

    deleteBinaryTree(BT->leftChild);
    deleteBinaryTree(BT->rightChild);
    delete BT;
}

/**
  * @brief  此函数为析构函数
  * @param None
  * @retval None
  */
BinaryTree::~BinaryTree() {
    deleteBinaryTree(root);
}

/**
  * @brief  此函数判断二叉树是否为空
  * @param None
  * @retval true 二叉树为空
  * @retval false 二叉树非空
  */
bool BinaryTree::empty() {
    if(root == nullptr) return true;
    return false;
}

/**
  * @brief  此函数对二叉树进行清除
  * @param None
  * @retval None
  */
void BinaryTree::clear() {
    deleteBinaryTree(root);
    root = nullptr;
}

/**
  * @brief  此函数创建二叉树，基于前序遍历
  * @param None
  * @retval None
  */
void BinaryTree::creatBTreeWithPreorderTraversal() {
    root = createBTree(root);
}

/**
  * @brief  此函数对二叉树进行创建的递归实现，基于前序遍历
  * @param[in] BT 当前节点
  * @retval 返回创建后当前节点的地址
  */
Node* BinaryTree::createBTree(Node *BT) {
    int val;
    cin >> val;
    if(val == 0){
        return nullptr;
    }

    BT = new Node;
    BT->data = val;
    BT->leftChild = createBTree(BT->leftChild);
    BT->rightChild = createBTree(BT->rightChild);
    return BT;
}
