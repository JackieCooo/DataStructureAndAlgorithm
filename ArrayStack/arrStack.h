/**
  ******************************************************************************
  * @file    arrStack.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-09
  * @brief   ˳��ջģ��
  ******************************************************************************
=  */

#pragma once

#include <iostream>

using namespace std;

template <class T>
class arrStack {
private:
    T* st = NULL;  // �洢˳��ջ��ʵ��
    int  maxSize = 0;  // ˳��ջʵ������󳤶�
    int  curLen = 0;  // ˳��ջʵ���ĵ�ǰ����

public:
    arrStack();
    explicit arrStack(int size);
    ~arrStack();
    int size();
    bool empty();
    void push(T val);
    void pop();
    T& top();

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
    friend ostream& operator<< (ostream& out, arrStack<T>& a) {
        if (a.empty()) {
            out << "��ջ��" << endl;
            return out;
        }
        for (int i = 0; i < a.size(); i++) {
            out << a.st[i] << "  ";
        }
        out << endl;
        return out;
    }

};

/**
  * @brief  �˹��캯����ʼ�������
  * @param None
  * @retval None
  */
template<class T>
arrStack<T>::arrStack() = default;

/**
  * @brief  �˹��캯����ʼ�������
  * @param[in] size ˳������󳤶�
  * @retval None
  */
template<class T>
arrStack<T>::arrStack(int size) {
    maxSize = size;
    st = new T[maxSize];  // ������������
    curLen = 0;
}

/**
  * @brief  �������������˳�ǰ�ͷŶ���˳��ջ
  * @param None
  * @retval None
  */
template<class T>
arrStack<T>::~arrStack<T>() {
    delete[] st;
}

/**
  * @brief  �˺�����ȡ˳��ջĿǰ�Ĵ�С
  * @param None
  * @retval curLen ˳��ջĿǰ�Ĵ�С
  */
template<class T>
int arrStack<T>::size() {
    return curLen;
}

/**
  * @brief  �˺�������˳��ջ�Ƿ�Ϊ�յ��ж�
  * @param None
  * @retval true ˳��ջΪ��
  * @retval false ˳��ջ��Ϊ��
  */
template<class T>
bool arrStack<T>::empty() {
    if (curLen > 0) {
        return false;
    }
    return true;
}

/**
  * @brief  �˺�����ջ��ѹ��һ��Ԫ��
  * @param[in] val ѹ���Ԫ��
  * @retval None
  */
template<class T>
void arrStack<T>::push(T val) {
    if (curLen == 0){  // ����Ϊ0���½�����Ϊ1��˳��ջ
        resize(1);
    }
    if (curLen >= maxSize) {  // ��˳��,ջ�Ŀռ䲻�㣬����Ϊ֮ǰ����
        resize(maxSize*2);
    }
    st[curLen++] = val;
    cout << "ѹջ�ɹ���" << endl;
}

/**
  * @brief  �˺�������ջ��Ԫ��
  * @param None
  * @retval None
  */
template<class T>
void arrStack<T>::pop() {
    if (empty()) {
        cout << "��ջ" << endl;
        return;
    }
    --curLen;
    cout << "��ջ�ɹ�" << endl;
}

/**
  * @brief  �˺�����ȡջ��Ԫ�ص�����
  * @param None
  * @retval None
  */
template<class T>
T& arrStack<T>::top() {
    return st[curLen-1];
}

/**
  * @brief  �˺�����������˳��ջ�Ŀռ��С
  * @param[in] s ���մ�С
  * @retval None
  */
template<class T>
void arrStack<T>::resize(int s) {
    T tempArr[curLen];  // ��ʱ����
    for(int i = 0; i < curLen; i++){  // ԭ����ֵ���Ƶ���ʱ����
        tempArr[i] = st[i];
    }
    delete [] st;
    st = new T[s];
    maxSize = s;
    for(int i = 0; i < curLen; i++){  // ��ʱ�����ֵ���Ƶ�������
        st[i] = tempArr[i];
    }
}
