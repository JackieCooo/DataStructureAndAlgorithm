/**
  ******************************************************************************
  * @file    lnkList.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-07
  * @brief   ������ģ��
  ******************************************************************************
  */

#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class lnkList {
private:
    Node<T> *head, *tail;  // ͷ�ڵ㣬β�ڵ�
    int len = 0;  // ������

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

    // ���涨��һЩ���������ⶨ��ĺ���
public:
    /**
      * @brief  �˺�������<<�����
      * @param[in] out ostream������
      * @param[in] a Ҫ�����������
      * @retval ����ostream������
      */
    friend ostream& operator<< (ostream& out, lnkList<T>& a){
        if(!a.size()){
            out << "�ձ�" << endl;
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
      * @brief  �˺�������>>�����
      * @param[in] in istream������
      * @param[in] a Ҫ�����������
      * @retval ����istream������
      */
    friend istream& operator>> (istream& in, T& a){
        in >> a;
        return in;
    }

};

/**
  * @brief  �˺���Ϊ���캯��
  * @param None
  * @retval None
  */
template<class T>
lnkList<T>::lnkList() {
    init();
}

/**
  * @brief  �˹��캯������һ�����ȵ�����
  * @param[in] n ������������
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
  * @brief  �˹��캯������һ�����ȵ���������ͬ��ֵ
  * @param[in] n Ҫ��������ĳ���
  * @param[in] val Ҫ����ֵ
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
  * @brief  �˺���Ϊ����������������еĽڵ�
  * @param None
  * @retval None
  */
template<class T>
lnkList<T>::~lnkList() {
    Node<T> *tmp;  // ����ָ�����ָ��
    while(head != NULL){
        tmp = head;  // tmpָ��ǰ���
        head = head->next;  // headָ����һ���
        delete tmp;  // ɾ����ǰ���
    }
}

/**
  * @brief  �˺��������������Ԫ��
  * @param None
  * @retval None
  */
template<class T>
void lnkList<T>::clear(){
    Node<T> *tmp, *nex;  // tmpΪ��ɾ���ڵ㣬nexΪtmp�ĺ�������ֹɾ��tmp���޷��ҵ�����
    tmp = head->next;
    for (int i = 0; i < size(); ++i) {
        nex = tmp->next;  // ��ȡtmp����
        delete tmp;  // ɾ��tmp
        tmp = nex;  // ��ǰ��������tmp
    }
    len = 0;
    head->next = tail;
    tail->next = head;
}

/**
  * @brief  �˺�����ȡ����ĳ���
  * @param None
  * @retval ����������
  */
template<class T>
int lnkList<T>::size() {
    return len;
}

/**
  * @brief  �˺���������׷��һ��Ԫ��
  * @param[in] val ׷��Ԫ�ص�ֵ
  * @retval None
  */
template<class T>
void lnkList<T>::push_back(T val) {
    Node<T> *temp, *pre;  // ����ڵ�
    temp = new Node<T>(val, tail);  // temp��������Ϊtail
    pre = tail->next;  // ��ȡĩ�ڵ�
    tail->next = temp;  // ��β���ָ���²���ڵ�
    pre->next = temp;  // ǰĩ�ڵ�ĺ�������Ϊ�²���ڵ�
    ++len;  // ����+1
    cout << "׷�ӳɹ�" << endl;
}

/**
  * @brief  �˺���������ָ��λ�ò���һ��Ԫ��
  * @param[in] p �����λ�ã�0 <= p <= len��
  * @param[in] val ����Ԫ�ص�ֵ
  * @retval None
  */
template<class T>
void lnkList<T>::insert(int p, T val) {
    Node<T> *pre, *temp;  // tempΪ������ڵ㣬preΪ����λ�õ�ǰһ���ڵ�

    if (p < 0 || p > size()) {  // ������ͷ���ǰ��β�ڵ���ֵ
        cout << "λ�ô���" << endl;
        return;
    }
    else if(p == size()){  // ����ǰ�����
        push_back(val);
        return;
    }
    else if(p == 0){  // ����������
        push_front(val);
        return;
    }
    else{
        pre = getNode(p-1);  // ��ȡ����λ�õ�ǰһ���ڵ�
        temp = new Node<T>(val, pre->next);  // temp����һ���ڵ�����Ϊpre����һ���ڵ�
        pre->next = temp;
        ++len;  // ����+1
        cout << "׷�ӳɹ�" << endl;
    }
}

/**
  * @brief  �˺���ɾ������ָ��λ�õ�һ��Ԫ��
  * @param[in] p ɾ��Ԫ�ص�λ�ã�0 <= p < len��
  * @retval None
  */
template<class T>
void lnkList<T>::erase(int p) {
    if(empty()){
        cout << "��գ�" << endl;
        return;
    }

    if(p < 0 || p >= size()){
        cout << "ɾ��λ�ô���" << endl;
        return;
    }
    else if(p == 0){  // ɾ����һ���ڵ�
        pop_front();
        return;
    }
    else if(p == size()-1){  // ɾ��β�ڵ�
        pop_back();
        return;
    }
    else{
        Node<T> *temp, *pre;  // tempΪҪɾ���Ľڵ㣬preΪҪɾ���ڵ��ǰһ���ڵ�

        pre = getNode(p-1);  // ��ȡpre�ڵ�
        temp = pre->next;  // ��Ҫɾ���Ľڵ㸳��temp
        pre->next = temp->next;
        delete temp;
        --len;  // ����-1
        cout << "ɾ���ɹ�" << endl;
    }
}

/**
  * @brief  �˺���ɾ���������һ��Ԫ��
  * @param None
  * @retval None
  */
template<class T>
void lnkList<T>::pop_back() {
    if(empty()){
        cout << "��գ�" << endl;
        return;
    }

    Node<T> *pre, *temp;
    temp = tail->next;  // ��ȡĩ�ڵ�
    pre = getNode(size()-1);  // ��ȡĩ�ڵ�ǰ���ڵ�
    pre->next = tail;  // ǰĩ�ڵ�ǰ���ڵ����Ϊĩ�ڵ�
    tail->next = pre;  // β�ڵ����Ϊpre
    delete temp;
    --len;
    cout << "ɾ���ɹ�" << endl;
}

/**
  * @brief  �˺�����ȡ�����Ƿ�Ϊ�յ��ж�
  * @param None
  * @retval true ����Ϊ��
  * @retval false ����ǿ�
  */
template<class T>
bool lnkList<T>::empty() {
    return !size();
}

/**
  * @brief  �˺���ɾ�������һ��Ԫ��
  * @param None
  * @retval None
  */
template<class T>
void lnkList<T>::pop_front() {
    Node<T> *temp;  // tempΪɾ���ڵ�
    temp = head->next;
    head->next = temp->next;  // ����ͷ�ڵ�Ϊtemp��ǰ��
    delete temp;
    --len;
    cout << "ɾ���ɹ�" << endl;
}

/**
  * @brief  �˺�����������ǰ��׷��һ��Ԫ��
  * @param[in] val ׷��Ԫ�ص�ֵ
  * @retval None
  */
template<class T>
void lnkList<T>::push_front(T val) {
    Node<T> *temp;  // tempΪ����ڵ�
    temp = new Node<T>(val, head->next);
    head->next = temp;  // ����ͷ�ڵ�
    ++len;
    cout << "����ɹ�" << endl;
}

/**
  * @brief  �˺�����ȡ����Ԫ�ص�λ�ã������ҵ��ĵ�һ��Ԫ�ص�λ�ã�
  * @param[in] val ҪѰ�ҵ�Ԫ��
  * @retval ���ض�ӦԪ�ص�λ�ã��Ҳ�������-1
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
  * @brief  �˺������������һ��Ԫ�ص�����
  * @param None
  * @retval ���������һ��Ԫ�ص�����
  */
template<class T>
T& lnkList<T>::front() {
    return (head->next)->data;
}

/**
  * @brief  �˺��������������һ��Ԫ�ص�����
  * @param None
  * @retval �����������һ��Ԫ�ص�����
  */
template<class T>
T& lnkList<T>::back() {
    return (tail->next)->data;
}

/**
  * @brief  �˺������������һ��Ԫ�ص�ָ��
  * @param None
  * @retval ���������һ��Ԫ�ص�ָ��
  */
template<class T>
T* lnkList<T>::begin() {
    return head->next;
}

/**
  * @brief  �˺��������������һ��Ԫ�ص�ָ��
  * @param None
  * @retval �����������һ��Ԫ�ص�ָ��
  */
template<class T>
T* lnkList<T>::end() {
    return tail->next;
}

/**
  * @brief  �˺�������=�������������������ĸ���
  * @param[in] a Ҫ���Ƶ�����
  * @retval ���ص�ǰ���������
  */
template<class T>
lnkList<T>& lnkList<T>::operator=(lnkList<T> a) {
    clear();  // ���ԭ��������
    Node<T> *temp;
    temp = a.head->next;
    for (int i = 0; i < a.size(); ++i) {
        push_back(temp->data);
        temp = temp->next;
    }
}

/**
  * @brief  �˺�������[]���������ȡ����ָ��λ��Ԫ�ص�����
  * @param[in] p Ԫ�ص�λ��
  * @retval ��������ָ��Ԫ�ص�����
  */
template<class T>
T& lnkList<T>::operator[](int p){
    if(p < 0 || p > size()-1){
        cout << "λ�ô���" << endl;
        return head->next->data;
    }
    Node<T> *res;
    res = getNode(p);  // ��ȡָ���ڵ�
    return res->data;
}

/**
  * @brief  �˺�����ȡ����ָ��λ�õĽڵ�ָ��
  * @param[in] p Ԫ��λ��
  * @retval ��������ָ��λ�ýڵ��ָ��
  */
template<class T>
Node<T>* lnkList<T>::getNode(int p) {
    if(p < 0 || p > size()) return head;  // Խ�緵��ͷ�ڵ�
    Node<T> *temp;
    temp = head->next;
    for(int i = 0; i < p; i++){
        temp = temp->next;
    }
    return temp;
}

/**
  * @brief  �˺�����ʼ������ı���
  * @param None
  * @retval None
  */
template<class T>
void lnkList<T>::init() {
    len = 0;  // ��ʼ������Ϊ0
    head = new Node<T>;  // ����ͷ���
    tail = new Node<T>;  // ����β���
    head->next = tail;  // ͷ���ָ��βָ��
    tail->next = head;  // β���ָ��ͷָ��
}
