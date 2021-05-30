/**
 ******************************************************************************
 * @file    BinaryTree.cpp
 * @author  Jackie
 * @version V1.0
 * @date    2021-04-23
 * @brief   ������ģ��
 ******************************************************************************
 */

#include <iostream>
#include "BinaryTree.h"

using namespace std;

/**
  * @brief  �˺���Ϊ���캯��
  * @param None
  * @retval None
  */
BinaryTree::BinaryTree() {
    root = nullptr;
}

/**
  * @brief  �˺���ʹ������������������������ǰ�����
  * @param[in] num �����׵�ַ
  * @retval None
  */
void BinaryTree::creatBTreeWithPreorderTraversal(const int *num){
    int i = 0;  // ���ڱ�����������
    root = createBTree(root, num, i);
}

/**
  * @brief  �˺���Ϊʹ�������������������ĵݹ�ʵ�֣�����ǰ�����
  * @param[in] BT ��ǰ�ڵ��ַ
  * @param[in] num �����׵�ַ
  * @param[in] index �����±�
  * @retval ���ش�����ǰ�ڵ�ĵ�ַ
  */
Node* BinaryTree::createBTree(Node *BT, const int *num, int& index) {
    if(num[index] == 0){  // ����Ϊ0,��˽ڵ�Ϊ��
        return nullptr;
    }
    else{
        BT = new Node;
        BT->data = num[index];
        BT->leftChild = createBTree(BT->leftChild, num, ++index);  // �ȴ���������
        BT->rightChild = createBTree(BT->rightChild, num, ++index);  // ����������
        return BT;
    }
}

/**
  * @brief  �˺����Զ���������ǰ����������
  * @param None
  * @retval None
  */
void BinaryTree::printBTreeWithPreorderTraversal() {
    if(root == nullptr) {
        cout << "����" << endl;
        return;
    }

    preorderTraversal(root);
}

/**
  * @brief  �˺���Ϊ�Զ���������ǰ�����������ĵݹ�ʵ��
  * @param[in] BT ��ǰ�ڵ�
  * @retval None
  */
void BinaryTree::preorderTraversal(Node *BT) {
    if(BT == nullptr){  // �ڵ�Ϊ�գ�������һ��
        return;
    }
    else{
        cout << BT->data << " ";
        preorderTraversal(BT->leftChild);  // �ȱ���������
        preorderTraversal(BT->rightChild);  // �����������
    }
}

/**
  * @brief  �˺����Զ���������������������
  * @param None
  * @retval None
  */
void BinaryTree::printBTreeWithInorderTraversal() {
    if(root == nullptr) {
        cout << "����" << endl;
        return;
    }

    inorderTraversal(root);
}

/**
  * @brief  �˺���Ϊ�Զ����������������������ĵݹ�ʵ��
  * @param[in] BT ��ǰ�ڵ�
  * @retval None
  */
void BinaryTree::inorderTraversal(Node *BT) {
    if(BT == nullptr){  // �ڵ�Ϊ�գ�������һ��
        return;
    }
    else{
        preorderTraversal(BT->leftChild);  // �ȱ���������
        cout << BT->data << " ";
        preorderTraversal(BT->rightChild);  // �����������
    }
}

/**
  * @brief  �˺����Զ���������ǰ����������
  * @param None
  * @retval None
  */
void BinaryTree::printBTreeWithPostorderTraversal() {
    if(root == nullptr) {
        cout << "����" << endl;
        return;
    }

    postorderTraversal(root);
}

/**
  * @brief  �˺���Ϊ�Զ��������к������������ĵݹ�ʵ��
  * @param[in] BT ��ǰ�ڵ�
  * @retval None
  */
void BinaryTree::postorderTraversal(Node *BT) {
    if(BT == nullptr){  // �ڵ�Ϊ�գ�������һ��
        return;
    }
    else{
        postorderTraversal(BT->leftChild);  // �ȱ���������
        postorderTraversal(BT->rightChild);  // �����������
        cout << BT->data << " ";
    }
}

/**
  * @brief  �˺����Զ��������в�����������
  * @param None
  * @retval None
  */
void BinaryTree::printBTreeWithLevelTraversal() {
    if(root == nullptr) {
        cout << "����" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){  // bfs�����ڵ�
        Node* tmp = q.front();
        cout << tmp->data << " ";
        // �ڵ���ڵĻ��������
        if(tmp->leftChild != nullptr) q.push(tmp->leftChild);
        if(tmp->rightChild != nullptr) q.push(tmp->rightChild);
        q.pop();
    }
}

/**
  * @brief  �˺����Զ���������ǰ�������ɾ�����нڵ�
  * @param[in] BT ��ǰ�ڵ�
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
  * @brief  �˺���Ϊ��������
  * @param None
  * @retval None
  */
BinaryTree::~BinaryTree() {
    deleteBinaryTree(root);
}

/**
  * @brief  �˺����ж϶������Ƿ�Ϊ��
  * @param None
  * @retval true ������Ϊ��
  * @retval false �������ǿ�
  */
bool BinaryTree::empty() {
    if(root == nullptr) return true;
    return false;
}

/**
  * @brief  �˺����Զ������������
  * @param None
  * @retval None
  */
void BinaryTree::clear() {
    deleteBinaryTree(root);
    root = nullptr;
}

/**
  * @brief  �˺�������������������ǰ�����
  * @param None
  * @retval None
  */
void BinaryTree::creatBTreeWithPreorderTraversal() {
    root = createBTree(root);
}

/**
  * @brief  �˺����Զ��������д����ĵݹ�ʵ�֣�����ǰ�����
  * @param[in] BT ��ǰ�ڵ�
  * @retval ���ش�����ǰ�ڵ�ĵ�ַ
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
