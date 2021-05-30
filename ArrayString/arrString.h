/**
  ******************************************************************************
  * @file    arrString.h
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-16
  * @brief   ˳��ģ��
  ******************************************************************************
  */

#pragma once

#include <iostream>

using namespace std;

class arrString {
    friend ostream& operator<< (ostream& out, arrString& a);
    friend istream& operator>> (istream& in, char& a);

private:
    char* str = nullptr;  // �洢˳�򴮵�ʵ��
    int  maxSize = 0;  // ˳��ʵ������󳤶ȣ���󳤶Ȱ�����ֹ��
    int curLen = 0;  // ˳��ʵ���ĵ�ǰ����

public:
    arrString();
    explicit arrString(const char *s);
    arrString(arrString &s);
    arrString(arrString &s, int p);
    arrString(int size, char val);
    ~arrString();
    void clear();
    int size();
    bool empty();
    void push_back(char val);
    arrString& erase(int p, int np);
    void resize(int s);
    void resize(int s, char val);
    int find(char val, int p);
    int rfind(char val, int p);
    arrString& append(const char *s);
    arrString substr(int p, int np);
    char* c_str();
    char& front();
    char& back();
    char* begin();
    char* end();
    arrString& operator= (arrString a);
    arrString& operator= (const char *s);
    char& operator[] (int index);
    arrString& operator+= (arrString& s);
    arrString& operator+= (const char* s);
    arrString& operator+= (char val);

};