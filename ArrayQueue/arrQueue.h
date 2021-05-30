/**
  ******************************************************************************
  * @file    arrQueue.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-09
  * @brief   ˳��ѭ������ģ��
  ******************************************************************************
=  */

#pragma once

#include <iostream>

using namespace std;

template <class T>
class arrQueue{
private:
    T* qu = NULL;  // �洢˳��ѭ�����е�ʵ��
    int  maxSize = 0;  // ˳��ѭ������ʵ������󳤶�
    int  curLen = 0;  // ˳��ѭ������ʵ���ĵ�ǰ����
    int head = 0;  // ���е�ͷ��
    int tail = 0;  // ���е�β��

public:
    arrQueue();
    explicit arrQueue(int size);
    ~arrQueue();
    int size();
    bool empty();
    void push(T val);
    void pop();
    T& front();
    T& back();

private:
    void resize(int s);

// ���涨��һЩ���������ⶨ��ĺ���
public:
    /**
      * @brief  �˺�������<<��ʹcout��ֱ�������������
      * @param[in] out ostream������
      * @param[in] a Ҫ����������
      * @retval ����ostream&������
      */
    friend ostream& operator<< (ostream& out, arrQueue<T>& a){
        if (a.size() == 0) {
            out << "�ն��У�" << endl;
            return out;
        }
        for (int i = 0, j = a.head; i < a.curLen; i++) {
            out << a.qu[j++] << " ";
            if (j == a.maxSize) j = 0;  // ��ֹԽ��
        }
        out << endl;
        return out;
    }

    /**
      * @brief  �˺�������<<��ʹcout��ֱ���������һ��Ԫ��
      * @param[in] out ostream������
      * @param[in] a Ҫ�����Ԫ��
      * @retval ����ostream&������
      */
    friend ostream& operator<< (ostream& out, T& a){
        out << a << endl;
        return out;
    }

};

/**
  * @brief  �˹��캯����ʼ�������
  * @param None
  * @retval None
  */
template<class T>
arrQueue<T>::arrQueue()  = default;

/**
  * @brief  �˹��캯����ʼ�������
  * @param[in] size ˳������󳤶�
  * @retval None
  */
template<class T>
arrQueue<T>::arrQueue(int size) {
    maxSize = size;
    qu = new T[maxSize];  // ������������
    curLen = 0;
}

/**
  * @brief  �������������˳�ǰ�ͷŶ�������
  * @param None
  * @retval None
  */
template<class T>
arrQueue<T>::~arrQueue<T>() {
    delete [] qu;
}

/**
  * @brief  �˺�����ȡ˳���Ŀǰ�Ĵ�С
  * @param None
  * @retval curLen ˳���Ŀǰ�Ĵ�С
  */
template<class T>
int arrQueue<T>::size() {
    return curLen;
}

/**
  * @brief  �˺�������˳����Ƿ�Ϊ�յ��ж�
  * @param None
  * @retval true ˳���Ϊ��
  * @retval false ˳���Ϊ��
  */
template<class T>
bool arrQueue<T>::empty() {
    if (curLen) return false;
    return true;
}

/**
  * @brief  �˺����ڱ�β׷��һ��Ԫ��
  * @param[in] val Ҫ׷�ӵ�Ԫ��
  * @retval None
  */
template<class T>
void arrQueue<T>::push(T val) {
    if(maxSize == 0){  // ���пռ�Ϊ0������һ����СΪ1�Ŀռ�
        qu = new T[1];
        maxSize = 1;
    }
    else if (curLen >= maxSize) {  // �����еı��ÿռ䲻�㣬������Ϊ֮ǰ������
        resize(maxSize*2);
    }
    qu[tail++] = val;  // ��β��׷��
    ++curLen;  // ����+1
    if(tail == maxSize) tail = 0;  // β��Խ��
    cout << "��ӳɹ���" << endl;
}

/**
  * @brief  �˺�����������ͷ��Ԫ��
  * @param None
  * @retval None
  */
template<class T>
void arrQueue<T>::pop() {
    if(size() == 0){
        cout << "�ն���" << endl;
        return;
    }
    ++head;  // ͷ������
    if (head == maxSize) head = 0;  // ͷԽ��
    --curLen;  // ����-1
    cout << "�����гɹ�" << endl;
}

/**
  * @brief  �˺�����������˳���Ŀռ��С
  * @param[in] s ���մ�С
  * @retval None
  */
template<class T>
void arrQueue<T>::resize(int s) {
    T tempArr[curLen];
    for(int i = 0, j = head; i < curLen; i++){
        tempArr[i] = qu[j++];
        if(j == maxSize) j = 0;  // ��ֹԽ��
    }
    delete [] qu;
    qu = new T[s];
    maxSize = s;
    for(int i = 0; i < curLen; i++){
        qu[i] = tempArr[i];
    }
    head = 0; // ����head��λ��
    tail = curLen;  // ����tail��λ��
}

/**
  * @brief  �˺�������˳����һ��Ԫ�ص�����
  * @param None
  * @retval None
  */
template<class T>
T& arrQueue<T>::front() {
    return qu[head];
}

/**
  * @brief  �˺�������˳������һ��Ԫ�ص�����
  * @param None
  * @retval None
  */
template<class T>
T& arrQueue<T>::back() {
    return qu[(head+curLen)%maxSize-1];
}
