/**
 ******************************************************************************
 * @file    binSearchTree.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-04-23
 * @brief   二叉搜索树模板
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
  * @brief  此函数为构造函数
  * @param None
  * @retval None
  */
template<class T>
binSearchTree<T>::binSearchTree() {
    root = nullptr;
}

/**
  * @brief  此函数通过键盘输入创建二叉搜索树
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
  * @brief  此函数通过数组创建二叉搜索树
  * @param arr 数组首地址
  * @param n 数组大小
  * @retval None
  */
template<class T>
void binSearchTree<T>::createTree(T *arr, int n) {
    for (int i = 0; i < n; ++i) {
        insert(arr[i]);
    }
}

/**
  * @brief  此函数通过外部文件创建二叉搜索树
  * @param filePath 外部文件地址
  * @retval None
  */
template<class T>
void binSearchTree<T>::createTree(string &filePath) {
    fstream ifs;
    ifs.open(filePath, ios::in);  // 只读方式打开
    if(ifs.is_open()){  // 检查是否成功打开
        while(!ifs.eof()){  // 读取直至文件尾
            T val;
            ifs >> val;
            insert(val);
        }
    }
    else{
        cout << "文件打开失败" << endl;
    }
}

/**
  * @brief  此函数输出二叉搜索树
  * @param None
  * @retval None
  */
template<class T>
void binSearchTree<T>::printBinarySearchTree() {
    if(root == nullptr) {
        cout << "空树" << endl;
        return;
    }

    cout << "前序遍历：";
    preorderTraversal(root);
    cout << endl << "中序遍历：";
    inorderTraversal(root);
    cout << endl << "后序遍历：";
    postorderTraversal(root);
    cout << endl << "层序遍历：";
    levelTraversal(root);
    cout << endl;
}

/**
  * @brief  此函数为对二叉树进行前序遍历并输出的递归实现
  * @param[in] bst 当前节点
  * @retval None
  */
template<class T>
void binSearchTree<T>::preorderTraversal(Node<T> *bst) {
    if(bst == nullptr){  // 节点为空，返回上一级
        return;
    }
    else{
        cout << bst->data << " ";
        preorderTraversal(bst->leftChild);  // 先遍历左子树
        preorderTraversal(bst->rightChild);  // 后遍历右子树
    }
}

/**
  * @brief  此函数插入一个元素到二叉搜索树中
  * @param data 插入的元素
  * @retval None
  */
template<class T>
void binSearchTree<T>::insert(T data) {
    if(root == nullptr){  // 根节点为空
        root = new Node<T>(data, nullptr, nullptr, nullptr);
    }
    else{
        Node<T>* tmp = root;
        while (true){
            if(data < tmp->data){  // 小于当前节点，往左遍历
                if(tmp->leftChild == nullptr){  // 后驱节点为空，新建节点
                    tmp->leftChild = new Node<T>(data, nullptr, nullptr, tmp);
                    break;
                }
                else{
                    tmp = tmp->leftChild;
                }
            }
            else{  // 大于当前节点，往右遍历
                if(tmp->rightChild == nullptr){  // 后驱节点为空，新建节点
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
  * @brief  此函数插入一个节点到二叉搜索树中
  * @param tar 插入的节点
  * @retval None
  */
template<class T>
void binSearchTree<T>::insert(Node<T>* tar) {
    if(root == nullptr){  // 根节点为空
        root = tar;
    }
    else{
        Node<T>* tmp = root;
        while (true){
            if(tar->data < tmp->data){  // 小于当前节点，往左遍历
                if(tmp->leftChild == nullptr){  // 后驱节点为空，插入节点
                    tmp->leftChild = tar;
                    tar->parent = tmp;  // 更新插入节点的父亲
                    break;
                }
                else{
                    tmp = tmp->leftChild;
                }
            }
            else{  // 大于当前节点，往右遍历
                if(tmp->rightChild == nullptr){  // 后驱节点为空，新建节点
                    tmp->rightChild = tar;
                    tar->parent = tmp;  // 更新插入节点的父亲
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
  * @brief  此函数找到二叉搜索树中一个子树的最小索引
  * @param tar 子树的根节点
  * @retval 返回最小索引的节点
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
  * @brief  此函数找到二叉搜索树中一个子树的最大索引
  * @param tar 子树的根节点
  * @retval 返回最大索引的节点
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
  * @brief  此函数删除二叉搜索树的一个节点
  * @param tar 要删除的节点
  * @retval None
  */
template<class T>
void binSearchTree<T>::erase(Node<T>* tar) {
    if(tar->leftChild == nullptr){  // 如果左孩子不存在，则右子树直接往上替换
        transplant(tar, tar->rightChild);
    }
    else if(tar->rightChild == nullptr){  // 如果右孩子不存在，则左子树直接往上替换
        transplant(tar, tar->leftChild);
    }
    else{  // 如果左孩子和右孩子都存在
        Node<T>* tmp = minElement(tar->rightChild);  // 寻找以删除节点右孩子为根节点的子树的最小节点，此节点为替换节点
        if(tmp->parent != tar){  // 替换节点的父亲不是删除节点，要处理替换节点的孩子及其本身；因为替换节点不存在左孩子，所以只需要处理右孩子
            transplant(tmp, tmp->rightChild);  // 用替换节点的右子树替代它自己
            tmp->rightChild = tar->rightChild;  // 替换节点的右子树指向删除节点的右子树
            tmp->rightChild->parent = tmp;  // 替换节点的右孩子的父亲更新为替换节点
        }
        transplant(tar, tmp);  // 正式替换
        tmp->leftChild = tar->leftChild;  // 处理删除节点的左子树
        tmp->leftChild->parent = tmp;
    }
    delete tar;  // 删除节点
}

/**
  * @brief  此函数用一个子树替换另一个子树
  * @param u 被替换的子树
  * @param v 新子树
  * @retval None
  */
template<class T>
void binSearchTree<T>::transplant(Node<T>* u, Node<T>* v){
    if(u->parent == nullptr){  // u为根节点
        root = v;
    }
    else if(u == u->parent->leftChild){  // u为左孩子
        u->parent->leftChild = v;
    }
    else{  // u为右孩子
        u->parent->rightChild = v;
    }

    if(v != nullptr){  // 更新新节点的父节点
        v->parent = u->parent;
    }
}

/**
  * @brief  此函数查找二叉搜索树中的元素
  * @param val 要查找的元素
  * @retval 返回找到的节点，若没找到返回空指针
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
  * @brief  此函数删除二叉搜索树中的一个元素
  * @param val 要删除的元素
  * @retval None
  */
template<class T>
void binSearchTree<T>::erase(T val) {
    if(empty()) {
        cout << "空树" << endl;
        return;
    }

    Node<T>* tmp = search(val);
    if(tmp == nullptr){
        cout << "不存在节点" << endl;
        return;
    }
    erase(tmp);
}

/**
  * @brief  此函数为对二叉树进行中序遍历并输出的递归实现
  * @param[in] bst 当前节点
  * @retval None
  */
template<class T>
void binSearchTree<T>::inorderTraversal(Node<T> *bst) {
    if(bst == nullptr){  // 节点为空，返回上一级
        return;
    }
    else{
        preorderTraversal(bst->leftChild);  // 先遍历左子树
        cout << bst->data << " ";
        preorderTraversal(bst->rightChild);  // 后遍历右子树
    }
}

/**
  * @brief  此函数为对二叉树进行后序遍历并输出的递归实现
  * @param[in] bst 当前节点
  * @retval None
  */
template<class T>
void binSearchTree<T>::postorderTraversal(Node<T> *bst) {
    if(bst == nullptr){  // 节点为空，返回上一级
        return;
    }
    else{
        postorderTraversal(bst->leftChild);  // 先遍历左子树
        postorderTraversal(bst->rightChild);  // 后遍历右子树
        cout << bst->data << " ";
    }
}

/**
  * @brief  此函数为对二叉树进行中序遍历并输出的递归实现
  * @param bst 当前节点
  * @retval None
  */
template<class T>
void binSearchTree<T>::levelTraversal(Node<T> *bst) {
    queue<Node<T>*> q;
    q.push(bst);
    while(!q.empty()){  // bfs遍历节点
        Node<T>* tmp = q.front();
        cout << tmp->data << " ";
        // 节点存在的话，入队列
        if(tmp->leftChild != nullptr) q.push(tmp->leftChild);
        if(tmp->rightChild != nullptr) q.push(tmp->rightChild);
        q.pop();
    }
}

/**
  * @brief  此函数删除二叉搜索树或其子树
  * @param bst 二叉搜索树或其子树的根节点
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
  * @brief  此函数为析构函数
  * @param None
  * @retval None
  */
template<class T>
binSearchTree<T>::~binSearchTree() {
    deleteTree(root);
}

/**
  * @brief  此函数判断二叉搜索树或其子树是否为空
  * @param bst 二叉搜索树或其子树的根节点
  * @retval true 二叉搜索树或其子树为空
  * @retval false 二叉搜索树或其子树非空
  */
template<class T>
bool binSearchTree<T>::empty(Node<T> *bst) {
    if(bst == nullptr) return true;
    return false;
}

/**
  * @brief  此函数判断二叉搜索树是否为空
  * @param bst 二叉搜索树的根节点
  * @retval true 二叉搜索树为空
  * @retval false 二叉搜索树非空
  */
template<class T>
bool binSearchTree<T>::empty() {
    if(root == nullptr) return true;
    return false;
}

/**
  * @brief  此函数清除二叉搜索树所有元素
  * @param None
  * @retval None
  */
template<class T>
void binSearchTree<T>::clear() {
    deleteTree(root);
    root = nullptr;
}

/**
  * @brief  此函数获取二叉搜索树最小索引
  * @param None
  * @retval None
  */
template<class T>
Node<T>* binSearchTree<T>::getMinimum() {
    if(empty()) {
        cout << "空树" << endl;
        return nullptr;
    }

    return minElement(root);
}

/**
  * @brief  此函数获取二叉搜索树最大索引
  * @param None
  * @retval None
  */
template<class T>
Node<T>* binSearchTree<T>::getMaximum() {
    if(empty()) {
        cout << "空树" << endl;
        return nullptr;
    }

    return maxElement(root);
}
