/**
  ******************************************************************************
  * @file    arrString.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-16
  * @brief   ˳��ģ��
  ******************************************************************************
  */

#include <iostream>
#include "arrString.h"

using namespace std;

/**
  * @brief  �˹��캯����ʼ�������
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
  * @brief  �˹��캯��ʹ��c�����ַ�����ʼ�������
  * @param[in] s �ַ���ָ��
  * @retval None
  */
arrString::arrString(const char* s) {
    for (; *s != '\0'; s++) {
        push_back(*s);
    }
}

/**
  * @brief  �˹��캯����ʼ������󣬴���һ����n���ַ�val���ִ�
  * @param[in] size ˳�򴮵���󳤶�
  * @param[in] val �ַ�
  * @retval None
  */
arrString::arrString(int size, char val) {
    for (int i = 0; i < size; i++) {
        push_back(val);
    }
}

/**
  * @brief  �˹��캯��ʹ�ÿ��������ʼ�������
  * @param[in] s ��Ҫ�����������
  * @retval None
  */
arrString::arrString(arrString& s) {
    for (char i : s) {
        push_back(i);
    }
}

/**
  * @brief  �˹��캯��ʹ�ÿ��������ʼ�������pΪ�ӵڼ���λ�ÿ�ʼ����
  * @param[in] s ��Ҫ�����������
  * @param[in] p ��ʼλ��
  * @retval None
  */
arrString::arrString(arrString& s, int p) {
    if(p < 0 || p > s.size()-1){
        cout << "λ�ô���" << endl;
    }
    else{
        for (int i = p; i < s.size(); i++) {
            push_back(s[i]);
        }
    }
}

/**
  * @brief  �������������˳�ǰ�ͷŶ�������
  * @param None
  * @retval None
  */
arrString::~arrString() {
    delete[] str;
}

/**
  * @brief  �˺������˳������Ԫ��
  * @param None
  * @retval None
  */
void arrString::clear() {  //��˳���洢�������������Ϊ�ձ�
    delete[] str;
    curLen = maxSize = 0;
    str = new char[1];
    str[0] = '\0';
    cout << "˳���������" << endl;
}

/**
  * @brief  �˺�����ȡ˳��Ŀǰ�Ĵ�С
  * @param None
  * @retval curLen ˳��Ŀǰ�Ĵ�С
  */
int arrString::size() {
    return curLen;
}

/**
  * @brief  �˺�������˳���Ƿ�Ϊ�յ��ж�
  * @param None
  * @retval true ˳��Ϊ��
  * @retval false ˳�򴮲�Ϊ��
  */
bool arrString::empty() {
    return !size();
}

/**
  * @brief  �˺����ڴ�β׷��һ���ַ�
  * @param[in] val Ҫ׷�ӵ��ַ�
  * @retval None
  */
void arrString::push_back(char val) {
    if(maxSize == 0){  // ˳�򴮿ռ�Ϊ0�����ٿռ䣬����ֹ��
        str = new char[2];
        str[0] = '\0';
        maxSize = 2;
        curLen = 0;
    }
    if (curLen+1 >= maxSize) {  // ��˳�򴮵ı��ÿռ䲻�㣬������Ϊ֮ǰ������
        resize(curLen * 2);
    }
    str[curLen++] = val;
    str[curLen] = '\0';
    cout << "׷�Ӳ����ɹ���" << endl;
}

/**
  * @brief  �˺���ɾ��p�Ժ󣨰���p����np���ַ�
  * @param[in] p ɾ����ʼλ�ã�Ԫ���±꣩
  * @param[in] np ɾ��Ԫ�ظ���
  * @retval �����޸ĺ�������
  */
arrString& arrString::erase(int p, int np) {
    if (p < 0 || p > curLen - 1 || np + p > curLen - 1 || np < 0) {
        cout << "λ�ô���" << endl;
        return *this;
    }
    for (int i = np + p + 1; i <= curLen; i++) {  // ֱ�ӽ�p+np�������Ԫ�طŵ�ǰ��
        str[i-np+p-1] = str[i];
    }
    curLen -= np + 1;  // ���³���
    cout << "ɾ�������ɹ���" << endl;
    return *this;
}

/**
  * @brief  �˺�����������˳�򴮵Ŀռ��С
  * @param[in] s ���մ�С
  * @retval None
  */
void arrString::resize(int s) {
    if(s < curLen){
        char *tempArr;
        tempArr = new char[s+1];  // Ԥ��һ��λ����ֹ��
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
    tempArr = new char[s+1];  // Ԥ��һ��λ����ֹ��
    for (int i = 0; i < maxSize; i++) {  // ����ֹ��һ������
        tempArr[i] = str[i];
    }
    delete[] str;
    str = tempArr;
    maxSize = s + 1;
}

/**
  * @brief  �˺�����������˳�򴮵Ŀռ��С������val������Ŀռ�
  * @param[in] s ���մ�С
  * @param[in] val Ҫ����Ԫ��
  * @retval None
  */
void arrString::resize(int s, char val) {
    if(s < curLen){
        char *tempArr;
        tempArr = new char[s+1];  // Ԥ��һ��λ����ֹ��
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
    tempArr = new char[s+1];  // Ԥ��һ��λ����ֹ��
    for (int i = 0; i < curLen; i++) {
        tempArr[i] = str[i];
    }
    for(int i = curLen; i < s; i++){  // ����Ŀռ���val
        tempArr[i] = val;
    }
    tempArr[s] = '\0';
    delete[] str;
    str = tempArr;
    maxSize = s + 1;
    curLen = s;
}

/**
  * @brief  �˺�����p��ʼ������ָ��Ԫ�ص��±꣨��Ҫ�����ͬԪ�أ������ҵ��ĵ�һ��Ԫ���±꣩
  * @param[in] val Ҫ���ҵ�Ԫ��
  * @param[in] p ��ʼ���ҵ�λ��
  * @retval ����Ԫ���±�
  */
int arrString::find(char val, int p) {
    if (empty()) {
        cout << "��գ�" << endl;
        return -1;
    }
    if (p < 0 || p > curLen - 1) {
        cout << "λ�ô���" << endl;
        return -1;
    }
    for (int i = p; i < curLen; i++) {
        if (str[i] == val) {
            return i;
        }
    }
    cout << "Ԫ�ز����ڣ�" << endl;
    return -1;
}

/**
  * @brief  �˺�����p��ʼ��ǰ����ָ��Ԫ�ص��±꣨��Ҫ�����ͬԪ�أ������ҵ��ĵ�һ��Ԫ���±꣩
  * @param[in] val Ҫ���ҵ�Ԫ��
  * @param[in] p ��ʼ���ҵ�λ��
  * @retval ����Ԫ���±�
  */
int arrString::rfind(char val, int p) {
    if (empty()) {
        cout << "��գ�" << endl;
        return -1;
    }
    if (p < 0 || p > curLen - 1) {
        cout << "λ�ô���" << endl;
        return -1;
    }
    for (int i = p; i >= 0; i--) {
        if (str[i] == val) {
            return i;
        }
    }
    cout << "Ԫ�ز����ڣ�" << endl;
    return -1;
}

/**
  * @brief  �˺�����˳�򴮺�׷����һ���ַ���
  * @param[in] s �ַ���ָ��
  * @retval �����޸ĺ�������
  */
arrString& arrString::append(const char *s) {
    for(; *s != '\0'; s++){
        push_back(*s);
    }
    return *this;
}

/**
  * @brief  �˺���ȡ��p����np���ַ�
  * @param[in] p ��ʼλ��
  * @param[in] np ȡ�����ٸ��ַ�
  * @retval ����ȡ����˳��
  */
arrString arrString::substr(int p, int np) {
    if (p < 0 || p > curLen - 1 || np + p > curLen - 1 || np < 0) {
        cout << "λ�ô���" << endl;
        return *this;
    }
    arrString newStr;
    for(int i = p; i <= np + p; i++){
        newStr.push_back(str[i]);
    }
    return newStr;
}

/**
  * @brief  �˺�������c���Ե��ַ���
  * @param None
  * @retval �����ַ���ָ��
  */
char* arrString::c_str() {
    return str;
}

/**
  * @brief  �˺�������˳�򴮵�һ��Ԫ�ص�����
  * @param None
  * @retval None
  */
char& arrString::front() {
    return str[0];
}

/**
  * @brief  �˺�������˳�����һ��Ԫ�ص�����
  * @param None
  * @retval None
  */
char& arrString::back() {
    return str[curLen - 1];
}

/**
  * @brief  �˺�������˳�򴮵�һ��Ԫ�ص�ָ��
  * @param None
  * @retval None
  */
char* arrString::begin() {
    return str;
}

/**
  * @brief  �˺�������˳�����һ��Ԫ�ص�ָ��
  * @param None
  * @retval None
  */
char* arrString::end() {
    return str + curLen;
}

/**
  * @brief  �˺�������=������һ��˳�򴮸��Ƶ���ǰ˳��
  * @param[in] a ��Դ˳��
  * @retval ���ص�ǰ����������
  */
arrString& arrString::operator= (arrString a) {
    clear();
    for (char i : a) {
        push_back(i);
    }
    return *this;
}

/**
  * @brief  �˺�������=����һ���ַ������Ƶ���ǰ˳��
  * @param[in] s ��Դ�ַ���
  * @retval ���ص�ǰ����������
  */
arrString& arrString::operator= (const char* s) {
    clear();
    for(; *s != '\0'; s++){
        push_back(*s);
    }
    return *this;
}

/**
  * @brief  �˺�������[]��ʹ��������������һ�����±����Ԫ��
  * @param[in] index Ԫ���±�
  * @retval ����ָ�����Ԫ�ص�����
  */
char& arrString::operator[] (int index) {
    if (index < curLen) return str[index];
    else {
        cout << "Խ��" << endl;
        return str[0];
    }
}

/**
  * @brief  �˺�������+=�������ʹ�����׷����һ�������
  * @param[in] s Ҫ׷�ӵ������
  * @retval �����޸ĺ������������
  */
arrString& arrString::operator+= (arrString &s) {
    for (char i : s) {
        push_back(i);
    }
    return *this;
}

/**
  * @brief  �˺�������+=�������ʹ�����׷��һ���ַ���
  * @param[in] s Ҫ׷�ӵ��ַ���
  * @retval �����޸ĺ������������
  */
arrString& arrString::operator+= (const char* s) {
    for (; *s != '\0'; ++s) {
        push_back(*s);
    }
    return *this;
}

/**
  * @brief  �˺�������+=�������ʹ�����׷��һ���ַ�
  * @param[in] val Ҫ׷�ӵ��ַ�
  * @retval �����޸ĺ������������
  */
arrString& arrString::operator+= (char val) {
    push_back(val);
    return *this;
}

/**
  * @brief  �˺�������<<��ʹcout��ֱ���������˳��
  * @param[in] out ostream������
  * @param[in] a Ҫ����������
  * @retval ����ostream&������
  */
ostream& operator<< (ostream& out, arrString& a) {
    if (a.curLen == 0) {
        out << "�ձ�" << endl;
        return out;
    }
    for (int i = 0; i < a.curLen; i++) {
        out << a.str[i];
    }
    out << endl;
    return out;
}
/**
  * @brief  �˺�������>>��ʹ����ֱ�ӻ�ȡ��Ļ�����ֵ����Ϊ˳������һ��Ԫ�ظ�ֵ
  * @param[in] in istream������
  * @param[in] a Ҫ��ֵ��Ԫ��
  * @retval ����istream������
  */
istream& operator>> (istream& in, char& a) {
    in >> a;
    return in;
}
