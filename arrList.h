/**
  ******************************************************************************
  * @file    arrList.h
  * @author  Jackie
  * @version V1.2
  * @date    2021-04-08
  * @brief   ˳���ģ��
  ******************************************************************************
=  */

#pragma once

#include <iostream>

using namespace std;

template <class T>
class arrList{
private:
    T* arr = NULL;  // �洢˳����ʵ��
    int  maxSize = 0;  // ˳���ʵ������󳤶�
    int  curLen = 0;  // ˳���ʵ���ĵ�ǰ����
public:
    arrList();
    explicit arrList(int size);
    arrList(int size, T val);
    ~arrList();
    void clear();
    int size();
    bool empty();
    void push_back(T val);
    void insert(int p, T val);
    void erase(int p);
    void resize(int s);
    int getPos(T val);
    T& front();
    T& back();
    T* begin();
    T* end();
    arrList<T>& operator= (arrList<T> a);
    T& operator[] (int index);

// ���涨��һЩ���������ⶨ��ĺ���
public:
    /**
      * @brief  �˺�������<<��ʹcout��ֱ�������������
      * @param[in] out ostream������
      * @param[in] a Ҫ����������
      * @retval ����ostream&������
      */
    friend ostream& operator<< (ostream& out, arrList<T>& a){
        if (a.curLen == 0) {
            out << "�ձ�" << endl;
            return out;
        }
        for (int i = 0; i < a.curLen; i++) {
            out << a.arr[i] << "  ";
        }
        out << endl;
        return out;
    }
    /**
      * @brief  �˺�������>>��ʹ����ֱ�ӻ�ȡ��Ļ�����ֵ����Ϊ���鸳ֵ
      * @param[in] in istream������
      * @param[in] a Ҫ��ֵ��Ԫ��
      * @retval ����istream������
      */
    friend istream& operator>> (istream& in, T& a){
        in >> a;
        return in;
    }
};

/**
  * @brief  �˹��캯����ʼ�������
  * @param None
  * @retval None
  */
template<class T>
arrList<T>::arrList()  = default;

/**
  * @brief  �˹��캯����ʼ�������
  * @param[in] size ˳������󳤶�
  * @retval None
  */
template<class T>
arrList<T>::arrList(int size) {
    maxSize = size;
    arr = new T[maxSize];  // ������������
    curLen = 0;
}

/**
  * @brief  �˹��캯����ʼ�������
  * @param[in] size ˳������󳤶�
  * @param[in] val ҪΪ����Ԫ�ظ���ֵ
  * @retval None
  */
template<class T>
arrList<T>::arrList(int size, T val){
    maxSize = curLen = size;
    arr = new T[maxSize];  // ������������
    for (int i = 0; i < curLen; ++i) {
        arr[i] = val;
    }
}

/**
  * @brief  �������������˳�ǰ�ͷŶ�������
  * @param None
  * @retval None
  */
template<class T>
arrList<T>::~arrList<T>() {
    delete [] arr;
}

/**
  * @brief  �˺������˳�������Ԫ��
  * @param None
  * @retval None
  */
template<class T>
void arrList<T>::clear() {  //��˳���洢�������������Ϊ�ձ�
    delete[] arr;
    curLen = maxSize = 0;
    cout << "˳����������" << endl;
}

/**
  * @brief  �˺�����ȡ˳���Ŀǰ�Ĵ�С
  * @param None
  * @retval curLen ˳���Ŀǰ�Ĵ�С
  */
template<class T>
int arrList<T>::size() {
    return curLen;
}

/**
  * @brief  �˺�������˳����Ƿ�Ϊ�յ��ж�
  * @param None
  * @retval true ˳���Ϊ��
  * @retval false ˳���Ϊ��
  */
template<class T>
bool arrList<T>::empty() {
    if (curLen > 0) {
        return false;
    }
    return true;
}

/**
  * @brief  �˺����ڱ�β׷��һ��Ԫ��
  * @param[in] val Ҫ׷�ӵ�Ԫ��
  * @retval None
  */
template<class T>
void arrList<T>::push_back(T val) {
    if(maxSize == 0){  // ˳���ռ�Ϊ0������һ����СΪ1�Ŀռ�
        arr = new T[1];
        maxSize = 1;
    }
    if (curLen >= maxSize) {  // ��˳���ı��ÿռ䲻�㣬������Ϊ֮ǰ������
        resize(maxSize*2);
    }
    arr[curLen++] = val;
    cout << "׷�Ӳ����ɹ���" << endl;
}

/**
  * @brief  �˺�����ָ���±�ǰ����һ��Ԫ��
  * @param[in] val Ҫ�����Ԫ��
  * @param[in] p ����λ�ã�Ԫ���±꣩
  * @retval None
  */
template<class T>
void arrList<T>::insert(int p, T val) {
    if (p > curLen - 1 || p < 0) {
        cout << "λ�ô���" << endl;
        return;
    }
    else if(maxSize == 0){
        arr = new T[1];
        maxSize = 1;
    }
    else if(curLen >= maxSize) {  // ��������������ռ䣬��������
        resize(maxSize*2);
    }
    for (int i = curLen; i >= p + 1; i--) {  // �����������ȫ��������һλ
        arr[i] = arr[i-1];
    }
    arr[p] = val;
    curLen++;
    cout << "��������ɹ���" << endl;
}

/**
  * @brief  �˺�����ɾ��ָ��λ�õ�һ��Ԫ��
  * @param[in] p ɾ��λ�ã�Ԫ���±꣩
  * @retval None
  */
template<class T>
void arrList<T>::erase(int p) {
    if (p < 0 || p > curLen - 1) {
        cout << "λ�ô���" << endl;
        return;
    }
    for (int i = p; i < curLen - 1; i++) {
        arr[i] = arr[i + 1];
    }
    curLen--;
    cout << "ɾ�������ɹ���" << endl;
}

/**
  * @brief  �˺�����������˳���Ŀռ��С
  * @param[in] s ���մ�С
  * @retval None
  */
template<class T>
void arrList<T>::resize(int s) {
    T tempArr[curLen];
    for(int i = 0; i < curLen; i++){
        tempArr[i] = arr[i];
    }
    delete [] arr;
    arr = new T[s];
    maxSize = s;
    for(int i = 0; i < curLen; i++){
        arr[i] = tempArr[i];
    }
}

/**
  * @brief  �˺�����ȡָ��Ԫ�ص��±꣨��Ҫ�����ͬԪ�أ������ҵ��ĵ�һ��Ԫ���±꣩
  * @param[in] val Ҫ���ҵ�Ԫ��
  * @retval ����Ԫ���±�
  */
template<class T>
int arrList<T>::getPos(T val) {
    if (empty()) {
        cout << "��գ�" << endl;
        return -1;
    }
    for (int i = 0; i < curLen; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    cout << "Ԫ�ز����ڣ�" << endl;
    return -1;
}

/**
  * @brief  �˺�������˳����һ��Ԫ�ص�����
  * @param None
  * @retval None
  */
template<class T>
T& arrList<T>::front() {
    return arr[0];
}

/**
  * @brief  �˺�������˳������һ��Ԫ�ص�����
  * @param None
  * @retval None
  */
template<class T>
T& arrList<T>::back() {
    return arr[curLen-1];
}

/**
  * @brief  �˺�������˳����һ��Ԫ�ص�ָ��
  * @param None
  * @retval None
  */
template<class T>
T* arrList<T>::begin() {
    return arr;
}

/**
  * @brief  �˺�������˳������һ��Ԫ�ص�ָ��
  * @param None
  * @retval None
  */
template<class T>
T* arrList<T>::end() {
    return arr+curLen;
}

/**
  * @brief  �˺�������=������һ��˳����Ƶ���ǰ˳���
  * @param[in] a ��Դ˳���
  * @retval ���ص�ǰ����������
  */
template<class T>
arrList<T>& arrList<T>::operator= (arrList<T> a){
    int s = a.size();
    if(maxSize >= s){
        clear();
        for (int i = 0; i < s; ++i) {
            arr[i] = a.arr[i];
        }
    }
    else cout << "Ŀ������ռ䲻��" << endl;
    return *this;
}

/**
  * @brief  �˺�������[]��ʹ��������������һ�����±����Ԫ��
  * @param[in] index Ԫ���±�
  * @retval ����ָ�����Ԫ�ص�����
  */
template<class T>
T& arrList<T>::operator[] (int index){
    if(index < curLen) return arr[index];
    else{
        cout << "����Խ��" << endl;
        return arr[0];
    }
}
