/**
 ******************************************************************************
 * @file    Tree.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-05-21
 * @brief   树模板头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <queue>
#include <fstream>
#include <string>
#include "Node.h"

using namespace std;

template<class T, int k_size>
class Tree{
private:
    Node<T> *root = nullptr;  // 根节点

public:
    Tree() = default;
    void createTree();
    void createTree(string& filepath);
    void printTree();
    void clear();
    ~Tree();

private:
    void deleteTree(Node<T>* t);
    void preorderTraversal(Node<T>* t);
    void postorderTraversal(Node<T>* t);
    void levelTraversal(Node<T>* t);

};

template<class T, int k_size>
Tree<T, k_size>::~Tree() {
    deleteTree(root);
}

template<class T, int k_size>
void Tree<T, k_size>::createTree() {
    T val;
    queue< Node<T>* > q;  // 存放待扩展节点
    if(root != nullptr) q.push(root);
    while(cin >> val){  // 读取直至EOF
        if(root == nullptr){  // 根节点为空
            root = new Node<T>(val);
            q.push(root);
        }
        else{
            Node<T>* tar = q.front();
            if(tar->children.size() >= k_size){  // 若孩子大于等于k，更新父节点
                q.pop();
                tar = q.front();  // 更新父亲节点
            }
            auto* tmp = new Node<T>(val, tar);
            tar->children.push_back(tmp);  // 孩子加入父节点
            q.push(tmp);  // 将孩子压队列
        }
    }
}

template<class T, int k_size>
void Tree<T, k_size>::createTree(string &filepath) {
    ifstream ifs;
    ifs.open(filepath, ios::in);
    if(ifs.is_open()){
        queue< Node<T>* > q;  // 存放待扩展节点
        if(root != nullptr) q.push(root);
        while(!ifs.eof()){  // 读取至文件尾
            T val;
            ifs >> val;
            if(root == nullptr){  // 根节点为空
                root = new Node<T>(val);
                q.push(root);
            }
            else{
                Node<T>* tar = q.front();
                if(tar->children.size() >= k_size){  // 若孩子大于等于k，更新父节点
                    q.pop();
                    tar = q.front();  // 更新父节点
                }
                auto* tmp = new Node<T>(val, tar);
                tar->children.push_back(tmp);  // 孩子加入父节点
                q.push(tmp);  // 将孩子压队列
            }
        }
    }
    else{
        cout << "文件打开失败" << endl;
    }
}

template<class T, int k_size>
void Tree<T, k_size>::deleteTree(Node<T> *t) {
    if(t->children.empty()){
        delete t;
        return;
    }
    for(auto i = t->children.begin(); i != t->children.end(); i++){  // 遍历所有孩子
        deleteTree(*i);
    }
    delete t;
}

template<class T, int k_size>
void Tree<T, k_size>::printTree() {
    if(root == nullptr) {
        cout << "空树" << endl;
        return;
    }
    cout << "前序遍历为：";
    preorderTraversal(root);
    cout << endl;
    cout << "后序遍历为：";
    postorderTraversal(root);
    cout << endl;
    cout << "层序遍历为：";
    levelTraversal(root);
    cout << endl;
}

template<class T, int k_size>
void Tree<T, k_size>::preorderTraversal(Node<T> *t) {
    cout << t->data << " ";
    if(t->children.empty()){  // 当前节点为叶节点
        return;
    }
    for(auto i = t->children.begin(); i != t->children.end(); i++){
        preorderTraversal(*i);
    }
}

template<class T, int k_size>
void Tree<T, k_size>::postorderTraversal(Node<T> *t) {
    if(t->children.empty()){  // 当前节点为叶节点
        cout << t->data << " ";
        return;
    }
    for(auto i = t->children.begin(); i != t->children.end(); i++){
        postorderTraversal(*i);
    }
    cout << t->data << " ";
}

template<class T, int k_size>
void Tree<T, k_size>::levelTraversal(Node<T> *t) {
    queue< Node<T>* > q;
    q.push(t);
    while(!q.empty()){  // bfs
        Node<T>* tmp = q.front();
        cout << tmp->data << " ";
        q.pop();
        if(tmp->children.empty()) continue;  // 当前节点为叶节点
        for(auto i = tmp->children.begin(); i != tmp->children.end(); i++){
            q.push(*i);
        }
    }
}

template<class T, int k_size>
void Tree<T, k_size>::clear(){
    deleteTree(root);
    root = nullptr;
}
