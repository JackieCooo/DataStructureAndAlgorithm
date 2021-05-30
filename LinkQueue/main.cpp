/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-16
  * @brief   ������
  ******************************************************************************
  * @attention
  * C++��׼��C++20
  * IDE��Clion 2019.3
  * .exe�ļ���cmake-build-debug�ļ���
  *
  * �������ϴ���Github�����ƣ���ע�պ����
  * Github��https://github.com/JackieCooo/lnkQueue
  * ���ƣ�https://gitee.com/JackieCoo/lnkQueue
  ******************************************************************************
  */

#include <iostream>
#include "lnkQueue.h"

using namespace std;

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
    // �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
    lnkQueue<int> q;

#else  // ����Ϊ���Դ���
    lnkQueue<int>* ptr;
    ptr = nullptr;
    int choice;
    int value;
    while (true) {
        cout << "��ѡ��(0�˳�, 1��ʾ, 2�ӳ�, 3���, 4����, 5�鿴����, 6�鿴��β, 7����, 8����):";

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
                cout << "�ӳ�:" << ptr->size() << endl;
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
                cout << "��βԪ��Ϊ��" << ptr->back() << endl;
                break;
            }
            case 7: {
                if (ptr != nullptr) {
                    delete ptr;
                    ptr = nullptr;
                }
                ptr = new lnkQueue<int>;
                cout << "�����ɹ�" << endl;
                break;
            }
            case 8: {
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
