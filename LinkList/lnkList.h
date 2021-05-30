/**
  ******************************************************************************
  * @file    lnkList.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-07
  * @brief   单链表模板
  ******************************************************************************
  */

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class lnkList {
private:
    Node<T> *head, *tail;  // 头节点，尾节点
    int len = 0;  // 链表长度

public:
    lnkList();
    explicit lnkList(int n);
    lnkList(int n, int val);
    ~lnkList();
    void clear();
    int size();
    void push_back(T val);
    void insert(int p, T val);
    void erase(int p);
    void pop_back();
    bool empty();
    void pop_front();
    void push_front(T val);
    int getPos(T val);
    T& front();
    T& back();
    T* begin();
    T* end();
    lnkList<T>& operator=(lnkList<T> a);
    T& operator[](int p);

private:
    Node<T>* getNode(int p);
    void init();

    // 下面定义一些不能在类外定义的函数
public:
    /**
      * @brief  此函数重载<<运算符
      * @param[in] out ostream的引用
      * @param[in] a 要操作的类对象
      * @retval 返回ostream的引用
      */
    friend ostream& operator<< (ostream& out, lnkList<T>& a){
        if(!a.size()){
            out << "空表" << endl;
            return out;
        }
        Node<T> *pos;
        pos = a.head->next;
        for (int i = 0; i < a.size(); ++i) {
            out << pos->data << " ";
            pos = pos->next;
        }
        out << endl;
        return out;
    }
    /**
      * @brief  此函数重载>>运算符
      * @param[in] in istream的引用
      * @param[in] a 要操作的类对象
      * @retval 返回istream的引用
      */
    friend istream& operator>> (istream& in, T& a){
        in >> a;
        return in;
    }

};

/**
  * @brief  此函数为构造函数
  * @param None
  * @retval None
  */
template<class T>
lnkList<T>::lnkList() {
    init();
}

/**
  * @brief  此构造函数创建一定长度的链表
  * @param[in] n 创建的链表长度
  * @retval None
  */
template<class T>
lnkList<T>::lnkList(int n) {
    init();
    for (int i = 0; i < n; ++i) {
        push_back(0);
    }
}

/**
  * @brief  此构造函数创建一定长度的链表并赋相同的值
  * @param[in] n 要创建链表的长度
  * @param[in] val 要赋的值
  * @retval None
  */
template<class T>
lnkList<T>::lnkList(int n, int val) {
    init();
    for (int i = 0; i < n; ++i) {
        push_back(val);
    }
}

/**
  * @brief  此函数为析构函数，清除所有的节点
  * @param None
  * @retval None
  */
template<class T>
lnkList<T>::~lnkList() {
    Node<T> *tmp;  // 定义指向结点的指针
    while(head != NULL){
        tmp = head;  // tmp指向当前结点
        head = head->next;  // head指向下一结点
        delete tmp;  // 删除当前结点
    }
}

/**
  * @brief  此函数清除链表所有元素
  * @param None
  * @retval None
  */
template<class T>
void lnkList<T>::clear(){
    Node<T> *tmp, *nex;  // tmp为待删除节点，nex为tmp的后驱，防止删除tmp后无法找到后驱
    tmp = head->next;
    for (int i = 0; i < size(); ++i) {
        nex = tmp->next;  // 获取tmp后驱
        delete tmp;  // 删除tmp
        tmp = nex;  // 将前后驱赋给tmp
    }
    len = 0;
    head->next = tail;
    tail->next = head;
}

/**
  * @brief  此函数获取链表的长度
  * @param None
  * @retval 返回链表长度
  */
template<class T>
int lnkList<T>::size() {
    return len;
}

/**
  * @brief  此函数向链表追加一个元素
  * @param[in] val 追加元素的值
  * @retval None
  */
template<class T>
void lnkList<T>::push_back(T val) {
    Node<T> *temp, *pre;  // 插入节点
    temp = new Node<T>(val, tail);  // temp后驱更新为tail
    pre = tail->next;  // 获取末节点
    tail->next = temp;  // 将尾结点指向新插入节点
    pre->next = temp;  // 前末节点的后驱更新为新插入节点
    ++len;  // 长度+1
    cout << "追加成功" << endl;
}

/**
  * @brief  此函数往链表指定位置插入一个元素
  * @param[in] p 插入的位置（0 <= p <= len）
  * @param[in] val 插入元素的值
  * @retval None
  */
template<class T>
void lnkList<T>::insert(int p, T val) {
    Node<T> *pre, *temp;  // temp为待插入节点，pre为插入位置的前一个节点

    if (p < 0 || p > size()) {  // 不能往头结点前或尾节点后插值
        cout << "位置错误" << endl;
        return;
    }
    else if(p == size()){  // 在最前面插入
        push_back(val);
        return;
    }
    else if(p == 0){  // 在最后面插入
        push_front(val);
        return;
    }
    else{
        pre = getNode(p-1);  // 获取插入位置的前一个节点
        temp = new Node<T>(val, pre->next);  // temp的下一个节点设置为pre的下一个节点
        pre->next = temp;
        ++len;  // 长度+1
        cout << "追加成功" << endl;
    }
}

/**
  * @brief  此函数删除链表指定位置的一个元素
  * @param[in] p 删除元素的位置（0 <= p < len）
  * @retval None
  */
template<class T>
void lnkList<T>::erase(int p) {
    if(empty()){
        cout << "表空！" << endl;
        return;
    }

    if(p < 0 || p >= size()){
        cout << "删除位置错误" << endl;
        return;
    }
    else if(p == 0){  // 删除第一个节点
        pop_front();
        return;
    }
    else if(p == size()-1){  // 删除尾节点
        pop_back();
        return;
    }
    else{
        Node<T> *temp, *pre;  // temp为要删除的节点，pre为要删除节点的前一个节点

        pre = getNode(p-1);  // 获取pre节点
        temp = pre->next;  // 将要删除的节点赋给temp
        pre->next = temp->next;
        delete temp;
        --len;  // 长度-1
        cout << "删除成功" << endl;
    }
}

/**
  * @brief  此函数删除链表最后一个元素
  * @param None
  * @retval None
  */
template<class T>
void lnkList<T>::pop_back() {
    if(empty()){
        cout << "表空！" << endl;
        return;
    }

    Node<T> *pre, *temp;
    temp = tail->next;  // 获取末节点
    pre = getNode(size()-1);  // 获取末节点前驱节点
    pre->next = tail;  // 前末节点前驱节点更新为末节点
    tail->next = pre;  // 尾节点更新为pre
    delete temp;
    --len;
    cout << "删除成功" << endl;
}

/**
  * @brief  此函数获取链表是否为空的判断
  * @param None
  * @retval true 链表为空
  * @retval false 链表非空
  */
template<class T>
bool lnkList<T>::empty() {
    return !size();
}

/**
  * @brief  此函数删除链表第一个元素
  * @param None
  * @retval None
  */
template<class T>
void lnkList<T>::pop_front() {
    Node<T> *temp;  // temp为删除节点
    temp = head->next;
    head->next = temp->next;  // 更新头节点为temp的前驱
    delete temp;
    --len;
    cout << "删除成功" << endl;
}

/**
  * @brief  此函数在链表最前面追加一个元素
  * @param[in] val 追加元素的值
  * @retval None
  */
template<class T>
void lnkList<T>::push_front(T val) {
    Node<T> *temp;  // temp为插入节点
    temp = new Node<T>(val, head->next);
    head->next = temp;  // 更新头节点
    ++len;
    cout << "插入成功" << endl;
}

/**
  * @brief  此函数获取链表元素的位置（返回找到的第一个元素的位置）
  * @param[in] val 要寻找的元素
  * @retval 返回对应元素的位置，找不到返回-1
  */
template<class T>
int lnkList<T>::getPos(T val) {
    Node<T> *temp;
    temp = head;
    for (int i = 0; i < size(); ++i) {
        temp = temp->next;
        if (temp->data == val){
            return i;
        }
    }
    return -1;
}

/**
  * @brief  此函数返回链表第一个元素的引用
  * @param None
  * @retval 返回链表第一个元素的引用
  */
template<class T>
T& lnkList<T>::front() {
    return (head->next)->data;
}

/**
  * @brief  此函数返回链表最后一个元素的引用
  * @param None
  * @retval 返回链表最后一个元素的引用
  */
template<class T>
T& lnkList<T>::back() {
    return (tail->next)->data;
}

/**
  * @brief  此函数返回链表第一个元素的指针
  * @param None
  * @retval 返回链表第一个元素的指针
  */
template<class T>
T* lnkList<T>::begin() {
    return head->next;
}

/**
  * @brief  此函数返回链表最后一个元素的指针
  * @param None
  * @retval 返回链表最后一个元素的指针
  */
template<class T>
T* lnkList<T>::end() {
    return tail->next;
}

/**
  * @brief  此函数重载=运算符，完成两个链表间的复制
  * @param[in] a 要复制的链表
  * @retval 返回当前链表的引用
  */
template<class T>
lnkList<T>& lnkList<T>::operator=(lnkList<T> a) {
    clear();  // 清除原来的链表
    Node<T> *temp;
    temp = a.head->next;
    for (int i = 0; i < a.size(); ++i) {
        push_back(temp->data);
        temp = temp->next;
    }
}

/**
  * @brief  此函数重载[]运算符，获取链表指定位置元素的引用
  * @param[in] p 元素的位置
  * @retval 返回链表指定元素的引用
  */
template<class T>
T& lnkList<T>::operator[](int p){
    if(p < 0 || p > size()-1){
        cout << "位置错误" << endl;
        return head->next->data;
    }
    Node<T> *res;
    res = getNode(p);  // 获取指定节点
    return res->data;
}

/**
  * @brief  此函数获取链表指定位置的节点指针
  * @param[in] p 元素位置
  * @retval 返回链表指定位置节点的指针
  */
template<class T>
Node<T>* lnkList<T>::getNode(int p) {
    if(p < 0 || p > size()) return head;  // 越界返回头节点
    Node<T> *temp;
    temp = head->next;
    for(int i = 0; i < p; i++){
        temp = temp->next;
    }
    return temp;
}

/**
  * @brief  此函数初始化链表的变量
  * @param None
  * @retval None
  */
template<class T>
void lnkList<T>::init() {
    len = 0;  // 初始化长度为0
    head = new Node<T>;  // 创建头结点
    tail = new Node<T>;  // 创建尾结点
    head->next = tail;  // 头结点指向尾指针
    tail->next = head;  // 尾结点指向头指针
}
