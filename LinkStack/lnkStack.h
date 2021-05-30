/**
  ******************************************************************************
  * @file    lnkStack.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-09
  * @brief   ��ʽջģ��
  ******************************************************************************
  */

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class lnkStack {
private:
    Node<T>* head, * tail;  // ͷ�ڵ㣬β�ڵ�
    int len = 0;  // ��ʽջ����

public:
    lnkStack();
    explicit lnkStack(int n);
    ~lnkStack();
    int size();
    void push(T val);
    void pop();
    bool empty();
    T& top();

private:
    Node<T>* getNode(int p);
    void init();

    // ���涨��һЩ���������ⶨ��ĺ���
public:
    /**
      * @brief  �˺�������<<�����
      * @param[in] out ostream������
      * @param[in] a Ҫ�����������
      * @retval ����ostream������
      */
    friend ostream& operator<< (ostream& out, lnkStack<T>& a) {
        if (a.empty()) {
            out << "��ջ" << endl;
            return out;
        }
        Node<T>* pos;
        pos = a.head->next;
        for (int i = 0; i < a.size(); ++i) {
            out << pos->data << " ";
            pos = pos->next;
        }
        out << endl;
        return out;
    }

};

/**
  * @brief  �˺���Ϊ���캯��
  * @param None
  * @retval None
  */
template<class T>
lnkStack<T>::lnkStack() {
    init();
}

/**
  * @brief  �˹��캯������һ�����ȵ���ʽջ
  * @param[in] n ��������ʽջ����
  * @retval None
  */
template<class T>
lnkStack<T>::lnkStack(int n) {
    init();
    for (int i = 0; i < n; ++i) {
        push(0);
    }
}

/**
  * @brief  �˺���Ϊ����������������еĽڵ�
  * @param None
  * @retval None
  */
template<class T>
lnkStack<T>::~lnkStack() {
    Node<T>* tmp;  // ����ָ�����ָ��
    while (head != NULL) {
        tmp = head;  // tmpָ��ǰ���
        head = head->next;  // headָ����һ���
        delete tmp;  // ɾ����ǰ���
    }
}

/**
  * @brief  �˺�����ȡ��ʽջ�ĳ���
  * @param None
  * @retval ����������
  */
template<class T>
int lnkStack<T>::size() {
    return len;
}

/**
  * @brief  �˺�������ʽջѹ��һ��Ԫ��
  * @param[in] val ׷��Ԫ�ص�ֵ
  * @retval None
  */
template<class T>
void lnkStack<T>::push(const T val) {
    Node<T>* temp, * pre;  // ����ڵ�
    temp = new Node<T>(val, tail);  // temp��������Ϊtail
    pre = tail->next;  // ��ȡĩ�ڵ�
    tail->next = temp;  // ��β���ָ���²���ڵ�
    pre->next = temp;  // ǰĩ�ڵ�ĺ�������Ϊ�²���ڵ�
    ++len;  // ����+1
    cout << "׷�ӳɹ�" << endl;
}

/**
  * @brief  �˺���������ʽջ���һ��Ԫ��
  * @param None
  * @retval None
  */
template<class T>
void lnkStack<T>::pop() {
    if (empty()) {
        cout << "��գ�" << endl;
        return;
    }

    Node<T>* pre, * temp;
    temp = tail->next;  // ��ȡĩ�ڵ�
    pre = getNode(size() - 1);  // ��ȡĩ�ڵ�ǰ���ڵ�
    pre->next = tail;  // ǰĩ�ڵ�ǰ���ڵ����Ϊĩ�ڵ�
    tail->next = pre;  // β�ڵ����Ϊpre
    delete temp;
    --len;
    cout << "ɾ���ɹ�" << endl;
}

/**
  * @brief  �˺�����ȡ��ʽջ�Ƿ�Ϊ�յ��ж�
  * @param None
  * @retval true ����Ϊ��
  * @retval false ����ǿ�
  */
template<class T>
bool lnkStack<T>::empty() {
    return !size();
}

/**
  * @brief  �˺���������ʽջ���һ��Ԫ�ص�����
  * @param None
  * @retval ������ʽջ���һ��Ԫ�ص�����
  */
template<class T>
T& lnkStack<T>::top() {
    return (tail->next)->data;
}

/**
  * @brief  �˺�����ȡ��ʽջָ��λ�õĽڵ�ָ��
  * @param[in] p Ԫ��λ��
  * @retval ��������ָ��λ�ýڵ��ָ��
  */
template<class T>
Node<T>* lnkStack<T>::getNode(int p) {
    if (p < 0 || p > size()) return head;  // Խ�緵��ͷ�ڵ�
    Node<T>* temp;
    temp = head->next;
    for (int i = 0; i < p; i++) {
        temp = temp->next;
    }
    return temp;
}

/**
  * @brief  �˺�����ʼ����ʽջ�ı���
  * @param None
  * @retval None
  */
template<class T>
void lnkStack<T>::init() {
    len = 0;  // ��ʼ������Ϊ0
    head = new Node<T>;  // ����ͷ���
    tail = new Node<T>;  // ����β���
    head->next = tail;  // ͷ���ָ��βָ��
    tail->next = head;  // β���ָ��ͷָ��
}
