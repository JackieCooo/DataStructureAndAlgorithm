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
  * Github��https://github.com/JackieCooo/arrStack
  * ���ƣ�https://gitee.com/JackieCoo/arrStack
  ******************************************************************************
  */

#include <iostream>
#include "arrStack.h"

using namespace std;

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
    // �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
#else  // ����Ϊ���Դ���
    arrStack<int>* ptr;
    ptr = nullptr;
    int choice;
    int value;
    while (true) {
        cout << "��ѡ��(0�˳�, 1��ʾ, 2ջ��, 3ѹջ, 4��ջ, 5�鿴ջ��Ԫ��, 6����, 7����):";

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
                cout << "ջ��:" << ptr->size() << endl;
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
                if (ptr->empty()){
                    cout << "��ջ" << endl;
                    break;
                }
                else cout << "ջ��Ԫ�أ�" << ptr->top() << endl;
                break;
            }
            case 6: {
                if (ptr != nullptr) {
                    delete ptr;
                    ptr = nullptr;
                }
                ptr = new arrStack<int>;
                cout << "�����ɹ�" << endl;
                break;
            }
            case 7: {
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
