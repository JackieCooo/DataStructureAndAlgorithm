/**
  ******************************************************************************
  * @file    arrList.h
  * @author  Jackie
  * @version V1.2
  * @date    2021-04-08
  * @brief   顺序表模板
  ******************************************************************************
=  */

#pragma once

#include <iostream>

using namespace std;

template <class T>
class arrList{
private:
    T* arr = NULL;  // 存储顺序表的实例
    int  maxSize = 0;  // 顺序表实例的最大长度
    int  curLen = 0;  // 顺序表实例的当前长度
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

// 下面定义一些不能在类外定义的函数
public:
    /**
      * @brief  此函数重载<<，使cout能直接输出整个数组
      * @param[in] out ostream的引用
      * @param[in] a 要输出的类对象
      * @retval 返回ostream&的引用
      */
    friend ostream& operator<< (ostream& out, arrList<T>& a){
        if (a.curLen == 0) {
            out << "空表！" << endl;
            return out;
        }
        for (int i = 0; i < a.curLen; i++) {
            out << a.arr[i] << "  ";
        }
        out << endl;
        return out;
    }
    /**
      * @brief  此函数重载>>，使类能直接获取屏幕输入的值，并为数组赋值
      * @param[in] in istream的引用
      * @param[in] a 要赋值的元素
      * @retval 返回istream的引用
      */
    friend istream& operator>> (istream& in, T& a){
        in >> a;
        return in;
    }
};

/**
  * @brief  此构造函数初始化类对象
  * @param None
  * @retval None
  */
template<class T>
arrList<T>::arrList()  = default;

/**
  * @brief  此构造函数初始化类对象
  * @param[in] size 顺序表的最大长度
  * @retval None
  */
template<class T>
arrList<T>::arrList(int size) {
    maxSize = size;
    arr = new T[maxSize];  // 堆区创建数组
    curLen = 0;
}

/**
  * @brief  此构造函数初始化类对象
  * @param[in] size 顺序表的最大长度
  * @param[in] val 要为所有元素赋的值
  * @retval None
  */
template<class T>
arrList<T>::arrList(int size, T val){
    maxSize = curLen = size;
    arr = new T[maxSize];  // 堆区创建数组
    for (int i = 0; i < curLen; ++i) {
        arr[i] = val;
    }
}

/**
  * @brief  此析构函数在退出前释放堆区数组
  * @param None
  * @retval None
  */
template<class T>
arrList<T>::~arrList<T>() {
    delete [] arr;
}

/**
  * @brief  此函数清除顺序表所有元素
  * @param None
  * @retval None
  */
template<class T>
void arrList<T>::clear() {  //将顺序表存储的内容清除，成为空表
    delete[] arr;
    curLen = maxSize = 0;
    cout << "顺序表已清除！" << endl;
}

/**
  * @brief  此函数获取顺序表目前的大小
  * @param None
  * @retval curLen 顺序表目前的大小
  */
template<class T>
int arrList<T>::size() {
    return curLen;
}

/**
  * @brief  此函数返回顺序表是否为空的判断
  * @param None
  * @retval true 顺序表为空
  * @retval false 顺序表不为空
  */
template<class T>
bool arrList<T>::empty() {
    if (curLen > 0) {
        return false;
    }
    return true;
}

/**
  * @brief  此函数在表尾追加一个元素
  * @param[in] val 要追加的元素
  * @retval None
  */
template<class T>
void arrList<T>::push_back(T val) {
    if(maxSize == 0){  // 顺序表空间为0，开辟一个大小为1的空间
        arr = new T[1];
        maxSize = 1;
    }
    if (curLen >= maxSize) {  // 若顺序表的备用空间不足，则扩充为之前的两倍
        resize(maxSize*2);
    }
    arr[curLen++] = val;
    cout << "追加操作成功！" << endl;
}

/**
  * @brief  此函数在指定下标前插入一个元素
  * @param[in] val 要插入的元素
  * @param[in] p 插入位置（元素下标）
  * @retval None
  */
template<class T>
void arrList<T>::insert(int p, T val) {
    if (p > curLen - 1 || p < 0) {
        cout << "位置错误！" << endl;
        return;
    }
    else if(maxSize == 0){
        arr = new T[1];
        maxSize = 1;
    }
    else if(curLen >= maxSize) {  // 插入后若超过最大空间，扩容数组
        resize(maxSize*2);
    }
    for (int i = curLen; i >= p + 1; i--) {  // 插入点后面的数全部往后移一位
        arr[i] = arr[i-1];
    }
    arr[p] = val;
    curLen++;
    cout << "插入操作成功！" << endl;
}

/**
  * @brief  此函数在删除指定位置的一个元素
  * @param[in] p 删除位置（元素下标）
  * @retval None
  */
template<class T>
void arrList<T>::erase(int p) {
    if (p < 0 || p > curLen - 1) {
        cout << "位置错误！" << endl;
        return;
    }
    for (int i = p; i < curLen - 1; i++) {
        arr[i] = arr[i + 1];
    }
    curLen--;
    cout << "删除操作成功！" << endl;
}

/**
  * @brief  此函数重新设置顺序表的空间大小
  * @param[in] s 最终大小
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
  * @brief  此函数获取指定元素的下标（若要多个相同元素，返回找到的第一个元素下标）
  * @param[in] val 要查找的元素
  * @retval 返回元素下标
  */
template<class T>
int arrList<T>::getPos(T val) {
    if (empty()) {
        cout << "表空！" << endl;
        return -1;
    }
    for (int i = 0; i < curLen; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    cout << "元素不存在！" << endl;
    return -1;
}

/**
  * @brief  此函数返回顺序表第一个元素的引用
  * @param None
  * @retval None
  */
template<class T>
T& arrList<T>::front() {
    return arr[0];
}

/**
  * @brief  此函数返回顺序表最后一个元素的引用
  * @param None
  * @retval None
  */
template<class T>
T& arrList<T>::back() {
    return arr[curLen-1];
}

/**
  * @brief  此函数返回顺序表第一个元素的指针
  * @param None
  * @retval None
  */
template<class T>
T* arrList<T>::begin() {
    return arr;
}

/**
  * @brief  此函数返回顺序表最后一个元素的指针
  * @param None
  * @retval None
  */
template<class T>
T* arrList<T>::end() {
    return arr+curLen;
}

/**
  * @brief  此函数重载=，把另一个顺序表复制到当前顺序表
  * @param[in] a 来源顺序表
  * @retval 返回当前类对象的引用
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
    else cout << "目标数组空间不足" << endl;
    return *this;
}

/**
  * @brief  此函数重载[]，使类对象可以像数组一样用下标操作元素
  * @param[in] index 元素下标
  * @retval 返回指向这个元素的引用
  */
template<class T>
T& arrList<T>::operator[] (int index){
    if(index < curLen) return arr[index];
    else{
        cout << "数组越界" << endl;
        return arr[0];
    }
}
