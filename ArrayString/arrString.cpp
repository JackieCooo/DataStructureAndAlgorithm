/**
  ******************************************************************************
  * @file    arrString.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-16
  * @brief   顺序串模板
  ******************************************************************************
  */

#include <iostream>
#include "arrString.h"

using namespace std;

/**
  * @brief  此构造函数初始化类对象
  * @param None
  * @retval None
  */
arrString::arrString() {
    str = new char[2];
    str[0] = '\0';
    maxSize = 2;
    curLen = 0;
}

/**
  * @brief  此构造函数使用c语言字符串初始化类对象
  * @param[in] s 字符串指针
  * @retval None
  */
arrString::arrString(const char* s) {
    for (; *s != '\0'; s++) {
        push_back(*s);
    }
}

/**
  * @brief  此构造函数初始化类对象，创建一个有n个字符val的字串
  * @param[in] size 顺序串的最大长度
  * @param[in] val 字符
  * @retval None
  */
arrString::arrString(int size, char val) {
    for (int i = 0; i < size; i++) {
        push_back(val);
    }
}

/**
  * @brief  此构造函数使用拷贝构造初始化类对象
  * @param[in] s 需要拷贝的类对象
  * @retval None
  */
arrString::arrString(arrString& s) {
    for (char i : s) {
        push_back(i);
    }
}

/**
  * @brief  此构造函数使用拷贝构造初始化类对象，p为从第几个位置开始复制
  * @param[in] s 需要拷贝的类对象
  * @param[in] p 开始位置
  * @retval None
  */
arrString::arrString(arrString& s, int p) {
    if(p < 0 || p > s.size()-1){
        cout << "位置错误" << endl;
    }
    else{
        for (int i = p; i < s.size(); i++) {
            push_back(s[i]);
        }
    }
}

/**
  * @brief  此析构函数在退出前释放堆区数组
  * @param None
  * @retval None
  */
arrString::~arrString() {
    delete[] str;
}

/**
  * @brief  此函数清除顺序串所有元素
  * @param None
  * @retval None
  */
void arrString::clear() {  //将顺序表存储的内容清除，成为空表
    delete[] str;
    curLen = maxSize = 0;
    str = new char[1];
    str[0] = '\0';
    cout << "顺序串已清除！" << endl;
}

/**
  * @brief  此函数获取顺序串目前的大小
  * @param None
  * @retval curLen 顺序串目前的大小
  */
int arrString::size() {
    return curLen;
}

/**
  * @brief  此函数返回顺序串是否为空的判断
  * @param None
  * @retval true 顺序串为空
  * @retval false 顺序串不为空
  */
bool arrString::empty() {
    return !size();
}

/**
  * @brief  此函数在串尾追加一个字符
  * @param[in] val 要追加的字符
  * @retval None
  */
void arrString::push_back(char val) {
    if(maxSize == 0){  // 顺序串空间为0，开辟空间，放终止符
        str = new char[2];
        str[0] = '\0';
        maxSize = 2;
        curLen = 0;
    }
    if (curLen+1 >= maxSize) {  // 若顺序串的备用空间不足，则扩充为之前的两倍
        resize(curLen * 2);
    }
    str[curLen++] = val;
    str[curLen] = '\0';
    cout << "追加操作成功！" << endl;
}

/**
  * @brief  此函数删除p以后（包括p）的np个字符
  * @param[in] p 删除起始位置（元素下标）
  * @param[in] np 删除元素个数
  * @retval 返回修改后的类对象
  */
arrString& arrString::erase(int p, int np) {
    if (p < 0 || p > curLen - 1 || np + p > curLen - 1 || np < 0) {
        cout << "位置错误！" << endl;
        return *this;
    }
    for (int i = np + p + 1; i <= curLen; i++) {  // 直接将p+np后的所有元素放到前面
        str[i-np+p-1] = str[i];
    }
    curLen -= np + 1;  // 更新长度
    cout << "删除操作成功！" << endl;
    return *this;
}

/**
  * @brief  此函数重新设置顺序串的空间大小
  * @param[in] s 最终大小
  * @retval None
  */
void arrString::resize(int s) {
    if(s < curLen){
        char *tempArr;
        tempArr = new char[s+1];  // 预留一个位给终止符
        for(int i = 0; i < s; i++){
            tempArr[i] = str[i];
        }
        tempArr[s] = '\0';
        delete[] str;
        str = tempArr;
        curLen = s;
        maxSize = s + 1;
        return;
    }
    else if(s == curLen) return;

    char *tempArr;
    tempArr = new char[s+1];  // 预留一个位给终止符
    for (int i = 0; i < maxSize; i++) {  // 把终止符一并复制
        tempArr[i] = str[i];
    }
    delete[] str;
    str = tempArr;
    maxSize = s + 1;
}

/**
  * @brief  此函数重新设置顺序串的空间大小，并用val填充多出的空间
  * @param[in] s 最终大小
  * @param[in] val 要填充的元素
  * @retval None
  */
void arrString::resize(int s, char val) {
    if(s < curLen){
        char *tempArr;
        tempArr = new char[s+1];  // 预留一个位给终止符
        for(int i = 0; i < s; i++){
            tempArr[i] = str[i];
        }
        tempArr[s] = '\0';
        delete[] str;
        str = tempArr;
        curLen = s;
        maxSize = s + 1;
        return;
    }
    else if(s == curLen) return;

    char *tempArr;
    tempArr = new char[s+1];  // 预留一个位给终止符
    for (int i = 0; i < curLen; i++) {
        tempArr[i] = str[i];
    }
    for(int i = curLen; i < s; i++){  // 多余的空间填val
        tempArr[i] = val;
    }
    tempArr[s] = '\0';
    delete[] str;
    str = tempArr;
    maxSize = s + 1;
    curLen = s;
}

/**
  * @brief  此函数从p开始向后查找指定元素的下标（若要多个相同元素，返回找到的第一个元素下标）
  * @param[in] val 要查找的元素
  * @param[in] p 开始查找的位置
  * @retval 返回元素下标
  */
int arrString::find(char val, int p) {
    if (empty()) {
        cout << "表空！" << endl;
        return -1;
    }
    if (p < 0 || p > curLen - 1) {
        cout << "位置错误！" << endl;
        return -1;
    }
    for (int i = p; i < curLen; i++) {
        if (str[i] == val) {
            return i;
        }
    }
    cout << "元素不存在！" << endl;
    return -1;
}

/**
  * @brief  此函数从p开始向前查找指定元素的下标（若要多个相同元素，返回找到的第一个元素下标）
  * @param[in] val 要查找的元素
  * @param[in] p 开始查找的位置
  * @retval 返回元素下标
  */
int arrString::rfind(char val, int p) {
    if (empty()) {
        cout << "表空！" << endl;
        return -1;
    }
    if (p < 0 || p > curLen - 1) {
        cout << "位置错误！" << endl;
        return -1;
    }
    for (int i = p; i >= 0; i--) {
        if (str[i] == val) {
            return i;
        }
    }
    cout << "元素不存在！" << endl;
    return -1;
}

/**
  * @brief  此函数在顺序串后追加另一个字符串
  * @param[in] s 字符串指针
  * @retval 返回修改后的类对象
  */
arrString& arrString::append(const char *s) {
    for(; *s != '\0'; s++){
        push_back(*s);
    }
    return *this;
}

/**
  * @brief  此函数取出p后面np个字符
  * @param[in] p 开始位置
  * @param[in] np 取出多少个字符
  * @retval 返回取出的顺序串
  */
arrString arrString::substr(int p, int np) {
    if (p < 0 || p > curLen - 1 || np + p > curLen - 1 || np < 0) {
        cout << "位置错误！" << endl;
        return *this;
    }
    arrString newStr;
    for(int i = p; i <= np + p; i++){
        newStr.push_back(str[i]);
    }
    return newStr;
}

/**
  * @brief  此函数返回c语言的字符串
  * @param None
  * @retval 返回字符串指针
  */
char* arrString::c_str() {
    return str;
}

/**
  * @brief  此函数返回顺序串第一个元素的引用
  * @param None
  * @retval None
  */
char& arrString::front() {
    return str[0];
}

/**
  * @brief  此函数返回顺序串最后一个元素的引用
  * @param None
  * @retval None
  */
char& arrString::back() {
    return str[curLen - 1];
}

/**
  * @brief  此函数返回顺序串第一个元素的指针
  * @param None
  * @retval None
  */
char* arrString::begin() {
    return str;
}

/**
  * @brief  此函数返回顺序串最后一个元素的指针
  * @param None
  * @retval None
  */
char* arrString::end() {
    return str + curLen;
}

/**
  * @brief  此函数重载=，把另一个顺序串复制到当前顺序串
  * @param[in] a 来源顺序串
  * @retval 返回当前类对象的引用
  */
arrString& arrString::operator= (arrString a) {
    clear();
    for (char i : a) {
        push_back(i);
    }
    return *this;
}

/**
  * @brief  此函数重载=，把一个字符串复制到当前顺序串
  * @param[in] s 来源字符串
  * @retval 返回当前类对象的引用
  */
arrString& arrString::operator= (const char* s) {
    clear();
    for(; *s != '\0'; s++){
        push_back(*s);
    }
    return *this;
}

/**
  * @brief  此函数重载[]，使类对象可以像数组一样用下标操作元素
  * @param[in] index 元素下标
  * @retval 返回指向这个元素的引用
  */
char& arrString::operator[] (int index) {
    if (index < curLen) return str[index];
    else {
        cout << "越界" << endl;
        return str[0];
    }
}

/**
  * @brief  此函数重载+=运算符，使其可以追加另一个类对象
  * @param[in] s 要追加的类对象
  * @retval 返回修改后的类对象的引用
  */
arrString& arrString::operator+= (arrString &s) {
    for (char i : s) {
        push_back(i);
    }
    return *this;
}

/**
  * @brief  此函数重载+=运算符，使其可以追加一个字符串
  * @param[in] s 要追加的字符串
  * @retval 返回修改后的类对象的引用
  */
arrString& arrString::operator+= (const char* s) {
    for (; *s != '\0'; ++s) {
        push_back(*s);
    }
    return *this;
}

/**
  * @brief  此函数重载+=运算符，使其可以追加一个字符
  * @param[in] val 要追加的字符
  * @retval 返回修改后的类对象的引用
  */
arrString& arrString::operator+= (char val) {
    push_back(val);
    return *this;
}

/**
  * @brief  此函数重载<<，使cout能直接输出整个顺序串
  * @param[in] out ostream的引用
  * @param[in] a 要输出的类对象
  * @retval 返回ostream&的引用
  */
ostream& operator<< (ostream& out, arrString& a) {
    if (a.curLen == 0) {
        out << "空表！" << endl;
        return out;
    }
    for (int i = 0; i < a.curLen; i++) {
        out << a.str[i];
    }
    out << endl;
    return out;
}
/**
  * @brief  此函数重载>>，使类能直接获取屏幕输入的值，并为顺序串其中一个元素赋值
  * @param[in] in istream的引用
  * @param[in] a 要赋值的元素
  * @retval 返回istream的引用
  */
istream& operator>> (istream& in, char& a) {
    in >> a;
    return in;
}
