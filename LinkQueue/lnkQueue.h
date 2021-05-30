/**
  ******************************************************************************
  * @file    lnkQueue.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-16
  * @brief   ��ʽ����ģ��
  ******************************************************************************
  */

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class lnkQueue {
private:
    Node<T>* head, * tail;  // ͷ�ڵ㣬β�ڵ�
    int len = 0;  // ���ӳ���

public:
    lnkQueue();
    ~lnkQueue();
    int size();
    void push(T val);
    bool empty();
    void pop();
    T& front();
    T& back();

private:
    void init();

    // ���涨��һЩ���������ⶨ��ĺ���
public:
    /**
      * @brief  �˺�������<<�����
      * @param[in] out ostream������
      * @param[in] a Ҫ�����������
      * @retval ����ostream������
      */
    friend ostream& operator<< (ostream& out, lnkQueue<T>& a) {
        if (a.empty()) {
            out << "�ն�" << endl;
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
lnkQueue<T>::lnkQueue() {
    init();
}

/**
  * @brief  �˺���Ϊ����������������еĽڵ�
  * @param None
  * @retval None
  */
template<class T>
lnkQueue<T>::~lnkQueue() {
    Node<T>* tmp;  // ����ָ�����ָ��
    while (head != NULL) {
        tmp = head;  // tmpָ��ǰ���
        head = head->next;  // headָ����һ���
        delete tmp;  // ɾ����ǰ���
    }
}

/**
  * @brief  �˺�����ȡ���ӵĳ���
  * @param None
  * @retval �������ӳ���
  */
template<class T>
int lnkQueue<T>::size() {
    return len;
}

/**
  * @brief  �˺���������׷��һ��Ԫ��
  * @param[in] val ׷��Ԫ�ص�ֵ
  * @retval None
  */
template<class T>
void lnkQueue<T>::push(T val) {
    Node<T>* temp, * pre;  // ����ڵ�
    temp = new Node<T>(val, tail);  // temp��������Ϊtail
    pre = tail->next;  // ��ȡĩ�ڵ�
    tail->next = temp;  // ��β���ָ���²���ڵ�
    pre->next = temp;  // ǰĩ�ڵ�ĺ�������Ϊ�²���ڵ�
    ++len;  // ����+1
    cout << "��ӳɹ�" << endl;
}

/**
  * @brief  �˺�����ȡ�����Ƿ�Ϊ�յ��ж�
  * @param None
  * @retval true ����Ϊ��
  * @retval false ���ӷǿ�
  */
template<class T>
bool lnkQueue<T>::empty() {
    return !size();
}

/**
  * @brief  �˺���ɾ�����ӵ�һ��Ԫ��
  * @param None
  * @retval None
  */
template<class T>
void lnkQueue<T>::pop() {
    if(empty()){
        cout << "�ӿ�" << endl;
        return;
    }
    Node<T>* temp;  // tempΪɾ���ڵ�
    temp = head->next;
    head->next = temp->next;  // ����ͷ�ڵ�Ϊtemp��ǰ��
    delete temp;
    --len;
    cout << "���ӳɹ�" << endl;
}

/**
  * @brief  �˺�������������Ԫ�ص�����
  * @param None
  * @retval ����������Ԫ�ص�����
  */
template<class T>
T& lnkQueue<T>::front() {
    return (head->next)->data;
}

/**
  * @brief  �˺�����������ĩԪ�ص�����
  * @param None
  * @retval ��������ĩԪ�ص�����
  */
template<class T>
T& lnkQueue<T>::back() {
    return (tail->next)->data;
}

/**
  * @brief  �˺�����ʼ������ı���
  * @param None
  * @retval None
  */
template<class T>
void lnkQueue<T>::init() {
    len = 0;  // ��ʼ������Ϊ0
    head = new Node<T>;  // ����ͷ���
    tail = new Node<T>;  // ����β���
    head->next = tail;  // ͷ���ָ��βָ��
    tail->next = head;  // β���ָ��ͷָ��
}
