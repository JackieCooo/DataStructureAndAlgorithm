/**
 ******************************************************************************
 * @file    hashMap.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-13
 * @brief   哈希表头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

template<class T>
class HashMap{
#define maxLength 10007  // 哈希表的最大索引

private:
    vector< list<T*>* >* hashTable = nullptr;  // 哈希表
    int hash_size = 0;  // 哈希表长

public:
    HashMap() = default;
    explicit HashMap(int n);
    T* find(T val);
    void insert(T* val);
    void erase(T val);
    void clear();
    ~HashMap();

private:
    int _get_prime(int n);
    bool _is_prime(int n);
    int _hash_key(T n);
};

/**
  * @brief  此构造函数根据数组大小创建哈希表
  * @param n 输入数组大小
  * @retval None
  */
template<class T>
HashMap<T>::HashMap(int n) {
    hashTable = new vector< list<T*>* >;
    hash_size = _get_prime(n+1);
    hashTable->resize(hash_size);  // 开空间
}

/**
  * @brief  此函数获取哈希表的开辟空间大小
  * @param n 输入数组大小
  * @retval 返回一个小于maxLength的素数作为哈希表的表长
  */
template<class T>
int HashMap<T>::_get_prime(int n) {
    for (; n <= maxLength; ++n){  // 找到小于maxLength的一个素数
        if (_is_prime(n)) return n;
    }
    return maxLength;
}

/**
  * @brief  此函数判断一个数是否为素数
  * @param n 一个整数
  * @retval false 此数不是素数
  * @retval true 此数是素数
  */
template<class T>
bool HashMap<T>::_is_prime(int n) {
    for (int i = 2; i < ceil(sqrt(n)); ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

/**
  * @brief  此析构函数释放哈希表
  * @param None
  * @retval None
  */
template<class T>
HashMap<T>::~HashMap() {
    clear();
}

/**
  * @brief  此函数查找哈希表中的数据
  * @param val 要查找的数据
  * @retval 返回指向原数组的数的指针，找不到返回空指针
  */
template<class T>
T* HashMap<T>::find(T val) {
    int p = _hash_key(val);  // 获取哈希值
    if((*hashTable)[p] != nullptr) {  // 哈希表对应元素非空，遍历链表
        for (auto i = ((*hashTable)[p])->begin(); i != ((*hashTable)[p])->end(); ++i) {
            if (**i == val) return *i;
        }
    }
    return nullptr;
}

/**
  * @brief  此函数获取数据在哈希表中的索引值
  * @param n 输入数据
  * @retval 返回数据在哈希表中的索引值
  */
template<class T>
int HashMap<T>::_hash_key(T n) {
    return n % hash_size;
}

/**
  * @brief  此函数往哈希表中插入数据
  * @param val 输入数据
  * @retval None
  */
template<class T>
void HashMap<T>::insert(T* val) {
    if (find(*val) != nullptr) return;  // 哈希表中已有该元素，不插入
    int p = _hash_key(*val);
    if ((*hashTable)[p] == nullptr){  // 链表空，新建链表并插入
        auto* tmp = new list<T*>;
        tmp->push_back(val);
        (*hashTable)[p] = tmp;
    }
    else{
        ((*hashTable)[p])->push_back(val);
    }
}

/**
  * @brief  此函数获在哈希表中删除一个数据
  * @param val 要删除的数据
  * @retval None
  */
template<class T>
void HashMap<T>::erase(T val) {
    int p = _hash_key(val);  // 获取哈希值
    if((*hashTable)[p] != nullptr) {  // 哈希表对应元素非空，遍历链表
        for (auto i = ((*hashTable)[p])->begin(); i != ((*hashTable)[p])->end(); ++i) {
            if (**i == val) {
                ((*hashTable)[p])->erase(i);  // 删除节点
                return;
            }
        }
    }
}

/**
  * @brief  此函数清空哈希表
  * @param None
  * @retval None
  */
template<class T>
void HashMap<T>::clear() {
    for (auto &i : *hashTable) {
        if(i != nullptr){
            delete i;
        }
    }
    delete hashTable;
    hash_size = 0;
}
