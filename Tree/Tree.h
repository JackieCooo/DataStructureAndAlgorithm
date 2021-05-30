/**
 ******************************************************************************
 * @file    Tree.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-05-21
 * @brief   ��ģ��ͷ�ļ�
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
    Node<T> *root = nullptr;  // ���ڵ�

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
    queue< Node<T>* > q;  // ��Ŵ���չ�ڵ�
    if(root != nullptr) q.push(root);
    while(cin >> val){  // ��ȡֱ��EOF
        if(root == nullptr){  // ���ڵ�Ϊ��
            root = new Node<T>(val);
            q.push(root);
        }
        else{
            Node<T>* tar = q.front();
            if(tar->children.size() >= k_size){  // �����Ӵ��ڵ���k�����¸��ڵ�
                q.pop();
                tar = q.front();  // ���¸��׽ڵ�
            }
            auto* tmp = new Node<T>(val, tar);
            tar->children.push_back(tmp);  // ���Ӽ��븸�ڵ�
            q.push(tmp);  // ������ѹ����
        }
    }
}

template<class T, int k_size>
void Tree<T, k_size>::createTree(string &filepath) {
    ifstream ifs;
    ifs.open(filepath, ios::in);
    if(ifs.is_open()){
        queue< Node<T>* > q;  // ��Ŵ���չ�ڵ�
        if(root != nullptr) q.push(root);
        while(!ifs.eof()){  // ��ȡ���ļ�β
            T val;
            ifs >> val;
            if(root == nullptr){  // ���ڵ�Ϊ��
                root = new Node<T>(val);
                q.push(root);
            }
            else{
                Node<T>* tar = q.front();
                if(tar->children.size() >= k_size){  // �����Ӵ��ڵ���k�����¸��ڵ�
                    q.pop();
                    tar = q.front();  // ���¸��ڵ�
                }
                auto* tmp = new Node<T>(val, tar);
                tar->children.push_back(tmp);  // ���Ӽ��븸�ڵ�
                q.push(tmp);  // ������ѹ����
            }
        }
    }
    else{
        cout << "�ļ���ʧ��" << endl;
    }
}

template<class T, int k_size>
void Tree<T, k_size>::deleteTree(Node<T> *t) {
    if(t->children.empty()){
        delete t;
        return;
    }
    for(auto i = t->children.begin(); i != t->children.end(); i++){  // �������к���
        deleteTree(*i);
    }
    delete t;
}

template<class T, int k_size>
void Tree<T, k_size>::printTree() {
    if(root == nullptr) {
        cout << "����" << endl;
        return;
    }
    cout << "ǰ�����Ϊ��";
    preorderTraversal(root);
    cout << endl;
    cout << "�������Ϊ��";
    postorderTraversal(root);
    cout << endl;
    cout << "�������Ϊ��";
    levelTraversal(root);
    cout << endl;
}

template<class T, int k_size>
void Tree<T, k_size>::preorderTraversal(Node<T> *t) {
    cout << t->data << " ";
    if(t->children.empty()){  // ��ǰ�ڵ�ΪҶ�ڵ�
        return;
    }
    for(auto i = t->children.begin(); i != t->children.end(); i++){
        preorderTraversal(*i);
    }
}

template<class T, int k_size>
void Tree<T, k_size>::postorderTraversal(Node<T> *t) {
    if(t->children.empty()){  // ��ǰ�ڵ�ΪҶ�ڵ�
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
        if(tmp->children.empty()) continue;  // ��ǰ�ڵ�ΪҶ�ڵ�
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
