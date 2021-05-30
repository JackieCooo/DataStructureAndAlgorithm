/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-09
  * @brief   ������
  ******************************************************************************
  * @attention
  * C++��׼��C++20
  * IDE��Clion 2020.2
  * .exe�ļ���cmake-build-debug�ļ���
  *
  * �������ϴ���Github�����ƣ���ע�պ����
  * Github��https://github.com/JackieCooo/arrQueue
  * ���ƣ�https://gitee.com/JackieCoo/arrQueue
  ******************************************************************************
  */

#include <iostream>
#include "arrQueue.h"
#include <queue>

using namespace std;

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
    // �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
    arrQueue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.push(5);
    cout << q;
#else  // ����Ϊ���Դ���
    arrQueue<int> *ptr;
    ptr = nullptr;
    int choice;
    int value;
    while (true) {
        cout << "��ѡ��(0�˳�, 1��ʾ, 2���г���, 3���, 4����, 5�鿴����, 6�鿴��β, 7����, 8����):";

        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // ����
                cout << "�ټ���" << endl;
                system("pause");  // ��ͣ
                exit(0);  // �˳�����
            }
            case 1: {
                cout << *ptr;
                break;
            }
            case 2: {
                cout << "���г���:" << ptr->size() << endl;
                break;
            }
            case 3: {
                printf("Ԫ��:");
                cin >> value;
                ptr->push(value);
                break;
            }
            case 4: {
                ptr->pop();
                break;
            }
            case 5: {
                cout << "����Ԫ��Ϊ��" << ptr->front() << endl;
                break;
            }
            case 6: {
                cout << "��ĩԪ��Ϊ��" << ptr->back() << endl;
                break;
            }
            case 7: {
                if (ptr != nullptr){
                    delete ptr;
                    ptr = nullptr;
                }
                ptr = new arrQueue<int>;
                cout << "�����ɹ�" << endl;
                break;
            }
            case 8:{
                delete ptr;
                ptr = nullptr;
                cout << "ɾ���ɹ�" << endl;
                break;
            }
            default: cout << "ѡ�����" << endl;
        }
    }
#endif
    return 0;
}
