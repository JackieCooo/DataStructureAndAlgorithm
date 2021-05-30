/**
 ******************************************************************************
 * @file    binSearchTree.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-04-23
 * @brief   ����������ģ��
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "Node.h"

using namespace std;

template<class T>
class binSearchTree{
private:
    Node<T> *root;

public:
    binSearchTree();
    void createTree();
    void createTree(T* arr, int n);
    void createTree(string& filePath);
    void printBinarySearchTree();
    void insert(T data);
    void insert(Node<T>* tar);
    void erase(T val);
    void erase(Node<T>* tar);
    Node<T>* getMinimum();
    Node<T>* getMaximum();
    Node<T>* search(T val);
    bool empty(Node<T>* bst);
    bool empty();
    void clear();
    ~binSearchTree();

private:
    void preorderTraversal(Node<T> *bst);
    void transplant(Node<T>* u, Node<T>* v);
    void inorderTraversal(Node<T>* bst);
    void postorderTraversal(Node<T>* bst);
    void levelTraversal(Node<T>* bst);
    void deleteTree(Node<T>* bst);
    Node<T>* maxElement(Node<T>* tar);
    Node<T>* minElement(Node<T>* tar);

};

/**
  * @brief  �˺���Ϊ���캯��
  * @param None
  * @retval None
  */
template<class T>
binSearchTree<T>::binSearchTree() {
    root = nullptr;
}

/**
  * @brief  �˺���ͨ���������봴������������
  * @param None
  * @retval None
  */
template<class T>
void binSearchTree<T>::createTree() {
    T val;
    while(cin >> val){
        insert(val);
    }
}

/**
  * @brief  �˺���ͨ�����鴴������������
  * @param arr �����׵�ַ
  * @param n �����С
  * @retval None
  */
template<class T>
void binSearchTree<T>::createTree(T *arr, int n) {
    for (int i = 0; i < n; ++i) {
        insert(arr[i]);
    }
}

/**
  * @brief  �˺���ͨ���ⲿ�ļ���������������
  * @param filePath �ⲿ�ļ���ַ
  * @retval None
  */
template<class T>
void binSearchTree<T>::createTree(string &filePath) {
    fstream ifs;
    ifs.open(filePath, ios::in);  // ֻ����ʽ��
    if(ifs.is_open()){  // ����Ƿ�ɹ���
        while(!ifs.eof()){  // ��ȡֱ���ļ�β
            T val;
            ifs >> val;
            insert(val);
        }
    }
    else{
        cout << "�ļ���ʧ��" << endl;
    }
}

/**
  * @brief  �˺����������������
  * @param None
  * @retval None
  */
template<class T>
void binSearchTree<T>::printBinarySearchTree() {
    if(root == nullptr) {
        cout << "����" << endl;
        return;
    }

    cout << "ǰ�������";
    preorderTraversal(root);
    cout << endl << "���������";
    inorderTraversal(root);
    cout << endl << "���������";
    postorderTraversal(root);
    cout << endl << "���������";
    levelTraversal(root);
    cout << endl;
}

/**
  * @brief  �˺���Ϊ�Զ���������ǰ�����������ĵݹ�ʵ��
  * @param[in] bst ��ǰ�ڵ�
  * @retval None
  */
template<class T>
void binSearchTree<T>::preorderTraversal(Node<T> *bst) {
    if(bst == nullptr){  // �ڵ�Ϊ�գ�������һ��
        return;
    }
    else{
        cout << bst->data << " ";
        preorderTraversal(bst->leftChild);  // �ȱ���������
        preorderTraversal(bst->rightChild);  // �����������
    }
}

/**
  * @brief  �˺�������һ��Ԫ�ص�������������
  * @param data �����Ԫ��
  * @retval None
  */
template<class T>
void binSearchTree<T>::insert(T data) {
    if(root == nullptr){  // ���ڵ�Ϊ��
        root = new Node<T>(data, nullptr, nullptr, nullptr);
    }
    else{
        Node<T>* tmp = root;
        while (true){
            if(data < tmp->data){  // С�ڵ�ǰ�ڵ㣬�������
                if(tmp->leftChild == nullptr){  // �����ڵ�Ϊ�գ��½��ڵ�
                    tmp->leftChild = new Node<T>(data, nullptr, nullptr, tmp);
                    break;
                }
                else{
                    tmp = tmp->leftChild;
                }
            }
            else{  // ���ڵ�ǰ�ڵ㣬���ұ���
                if(tmp->rightChild == nullptr){  // �����ڵ�Ϊ�գ��½��ڵ�
                    tmp->rightChild = new Node<T>(data, nullptr, nullptr, tmp);
                    break;
                }
                else{
                    tmp = tmp->rightChild;
                }
            }
        }
    }
}

/**
  * @brief  �˺�������һ���ڵ㵽������������
  * @param tar ����Ľڵ�
  * @retval None
  */
template<class T>
void binSearchTree<T>::insert(Node<T>* tar) {
    if(root == nullptr){  // ���ڵ�Ϊ��
        root = tar;
    }
    else{
        Node<T>* tmp = root;
        while (true){
            if(tar->data < tmp->data){  // С�ڵ�ǰ�ڵ㣬�������
                if(tmp->leftChild == nullptr){  // �����ڵ�Ϊ�գ�����ڵ�
                    tmp->leftChild = tar;
                    tar->parent = tmp;  // ���²���ڵ�ĸ���
                    break;
                }
                else{
                    tmp = tmp->leftChild;
                }
            }
            else{  // ���ڵ�ǰ�ڵ㣬���ұ���
                if(tmp->rightChild == nullptr){  // �����ڵ�Ϊ�գ��½��ڵ�
                    tmp->rightChild = tar;
                    tar->parent = tmp;  // ���²���ڵ�ĸ���
                    break;
                }
                else{
                    tmp = tmp->rightChild;
                }
            }
        }
    }
}

/**
  * @brief  �˺����ҵ�������������һ����������С����
  * @param tar �����ĸ��ڵ�
  * @retval ������С�����Ľڵ�
  */
template<class T>
Node<T>* binSearchTree<T>::minElement(Node<T> *tar) {
    Node<T>* res = tar;
    while (res->leftChild != nullptr){
        res = res->leftChild;
    }
    return res;
}

/**
  * @brief  �˺����ҵ�������������һ���������������
  * @param tar �����ĸ��ڵ�
  * @retval ������������Ľڵ�
  */
template<class T>
Node<T>* binSearchTree<T>::maxElement(Node<T> *tar) {
    Node<T>* res = tar;
    while (res->rightChild != nullptr){
        res = res->rightChild;
    }
    return res;
}

/**
  * @brief  �˺���ɾ��������������һ���ڵ�
  * @param tar Ҫɾ���Ľڵ�
  * @retval None
  */
template<class T>
void binSearchTree<T>::erase(Node<T>* tar) {
    if(tar->leftChild == nullptr){  // ������Ӳ����ڣ���������ֱ�������滻
        transplant(tar, tar->rightChild);
    }
    else if(tar->rightChild == nullptr){  // ����Һ��Ӳ����ڣ���������ֱ�������滻
        transplant(tar, tar->leftChild);
    }
    else{  // ������Ӻ��Һ��Ӷ�����
        Node<T>* tmp = minElement(tar->rightChild);  // Ѱ����ɾ���ڵ��Һ���Ϊ���ڵ����������С�ڵ㣬�˽ڵ�Ϊ�滻�ڵ�
        if(tmp->parent != tar){  // �滻�ڵ�ĸ��ײ���ɾ���ڵ㣬Ҫ�����滻�ڵ�ĺ��Ӽ��䱾����Ϊ�滻�ڵ㲻�������ӣ�����ֻ��Ҫ�����Һ���
            transplant(tmp, tmp->rightChild);  // ���滻�ڵ��������������Լ�
            tmp->rightChild = tar->rightChild;  // �滻�ڵ��������ָ��ɾ���ڵ��������
            tmp->rightChild->parent = tmp;  // �滻�ڵ���Һ��ӵĸ��׸���Ϊ�滻�ڵ�
        }
        transplant(tar, tmp);  // ��ʽ�滻
        tmp->leftChild = tar->leftChild;  // ����ɾ���ڵ��������
        tmp->leftChild->parent = tmp;
    }
    delete tar;  // ɾ���ڵ�
}

/**
  * @brief  �˺�����һ�������滻��һ������
  * @param u ���滻������
  * @param v ������
  * @retval None
  */
template<class T>
void binSearchTree<T>::transplant(Node<T>* u, Node<T>* v){
    if(u->parent == nullptr){  // uΪ���ڵ�
        root = v;
    }
    else if(u == u->parent->leftChild){  // uΪ����
        u->parent->leftChild = v;
    }
    else{  // uΪ�Һ���
        u->parent->rightChild = v;
    }

    if(v != nullptr){  // �����½ڵ�ĸ��ڵ�
        v->parent = u->parent;
    }
}

/**
  * @brief  �˺������Ҷ����������е�Ԫ��
  * @param val Ҫ���ҵ�Ԫ��
  * @retval �����ҵ��Ľڵ㣬��û�ҵ����ؿ�ָ��
  */
template<class T>
Node<T>* binSearchTree<T>::search(T val) {
    Node<T>* res = root;
    while(true){
        if(res->data == val) return res;
        else if(res == nullptr) return nullptr;
        else{
            if(val < res->data) res = res->leftChild;
            else res = res->rightChild;
        }
    }
}

/**
  * @brief  �˺���ɾ�������������е�һ��Ԫ��
  * @param val Ҫɾ����Ԫ��
  * @retval None
  */
template<class T>
void binSearchTree<T>::erase(T val) {
    if(empty()) {
        cout << "����" << endl;
        return;
    }

    Node<T>* tmp = search(val);
    if(tmp == nullptr){
        cout << "�����ڽڵ�" << endl;
        return;
    }
    erase(tmp);
}

/**
  * @brief  �˺���Ϊ�Զ����������������������ĵݹ�ʵ��
  * @param[in] bst ��ǰ�ڵ�
  * @retval None
  */
template<class T>
void binSearchTree<T>::inorderTraversal(Node<T> *bst) {
    if(bst == nullptr){  // �ڵ�Ϊ�գ�������һ��
        return;
    }
    else{
        preorderTraversal(bst->leftChild);  // �ȱ���������
        cout << bst->data << " ";
        preorderTraversal(bst->rightChild);  // �����������
    }
}

/**
  * @brief  �˺���Ϊ�Զ��������к������������ĵݹ�ʵ��
  * @param[in] bst ��ǰ�ڵ�
  * @retval None
  */
template<class T>
void binSearchTree<T>::postorderTraversal(Node<T> *bst) {
    if(bst == nullptr){  // �ڵ�Ϊ�գ�������һ��
        return;
    }
    else{
        postorderTraversal(bst->leftChild);  // �ȱ���������
        postorderTraversal(bst->rightChild);  // �����������
        cout << bst->data << " ";
    }
}

/**
  * @brief  �˺���Ϊ�Զ����������������������ĵݹ�ʵ��
  * @param bst ��ǰ�ڵ�
  * @retval None
  */
template<class T>
void binSearchTree<T>::levelTraversal(Node<T> *bst) {
    queue<Node<T>*> q;
    q.push(bst);
    while(!q.empty()){  // bfs�����ڵ�
        Node<T>* tmp = q.front();
        cout << tmp->data << " ";
        // �ڵ���ڵĻ��������
        if(tmp->leftChild != nullptr) q.push(tmp->leftChild);
        if(tmp->rightChild != nullptr) q.push(tmp->rightChild);
        q.pop();
    }
}

/**
  * @brief  �˺���ɾ��������������������
  * @param bst �������������������ĸ��ڵ�
  * @retval None
  */
template<class T>
void binSearchTree<T>::deleteTree(Node<T> *bst) {
    if(bst == nullptr){
        return;
    }

    deleteTree(bst->leftChild);
    deleteTree(bst->rightChild);
    delete bst;
}

/**
  * @brief  �˺���Ϊ��������
  * @param None
  * @retval None
  */
template<class T>
binSearchTree<T>::~binSearchTree() {
    deleteTree(root);
}

/**
  * @brief  �˺����ж϶������������������Ƿ�Ϊ��
  * @param bst �������������������ĸ��ڵ�
  * @retval true ������������������Ϊ��
  * @retval false �������������������ǿ�
  */
template<class T>
bool binSearchTree<T>::empty(Node<T> *bst) {
    if(bst == nullptr) return true;
    return false;
}

/**
  * @brief  �˺����ж϶����������Ƿ�Ϊ��
  * @param bst �����������ĸ��ڵ�
  * @retval true ����������Ϊ��
  * @retval false �����������ǿ�
  */
template<class T>
bool binSearchTree<T>::empty() {
    if(root == nullptr) return true;
    return false;
}

/**
  * @brief  �˺��������������������Ԫ��
  * @param None
  * @retval None
  */
template<class T>
void binSearchTree<T>::clear() {
    deleteTree(root);
    root = nullptr;
}

/**
  * @brief  �˺�����ȡ������������С����
  * @param None
  * @retval None
  */
template<class T>
Node<T>* binSearchTree<T>::getMinimum() {
    if(empty()) {
        cout << "����" << endl;
        return nullptr;
    }

    return minElement(root);
}

/**
  * @brief  �˺�����ȡ�����������������
  * @param None
  * @retval None
  */
template<class T>
Node<T>* binSearchTree<T>::getMaximum() {
    if(empty()) {
        cout << "����" << endl;
        return nullptr;
    }

    return maxElement(root);
}
