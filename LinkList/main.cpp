/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-07
  * @brief   ������
  ******************************************************************************
  * @attention
  * C++��׼��C++20
  * IDE��Clion 2020.2
  * .exe�ļ���cmake-build-debug�ļ���
  *
  * �������ϴ���Github�����ƣ���ע�պ����
  * Github��https://github.com/JackieCooo/lnkList
  * ���ƣ�https://gitee.com/JackieCoo/lnkList
  ******************************************************************************
  */

#include <iostream>
#include "lnkList.h"

using namespace std;

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
    // �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
    lnkList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
#else  // ����Ϊ���Դ���
    lnkList<int> *ptr;
    ptr = nullptr;
    int choice;
    int p;
    int value;
    while (true) {
        cout << "��ѡ��(0�˳�, 1���, 2��ʾ, 3��, 4����, 5׷��, 6ɾ��, 7����, 8�޸�, 9��λ, 10����, 11����):";

        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // ����
                cout << "�ټ���" << endl;
                system("pause");  // ��ͣ
                exit(0);  // �˳�����
            }
            case 1: {
                ptr->clear();
                break;
            }
            case 2: {
                cout << *ptr;
                break;
            }
            case 3: {
                cout << "��:" << ptr->size() << endl;
                break;
            }
            case 4: {
                cout << "λ��:";
                cin >> p;
                cout << "Ԫ��:";
                cin >> value;
                ptr->insert(p, value);
                break;
            }
            case 5: {
                printf("Ԫ��:");
                cin >> value;
                ptr->push_back(value);
                break;
            }
            case 6: {
                cout << "λ��:";
                cin >> p;
                ptr->erase(p);
                break;
            }
            case 7: {
                cout << "λ��:";
                cin >> p;
                cout << "Ԫ��Ϊ��" << (*ptr)[p] << endl;
                break;
            }
            case 8: {
                cout << "λ��:";
                cin >> p;
                cout << "Ԫ��:";
                cin >> (*ptr)[p];
    //            (*ptr)[p] = value;
                break;
            }
            case 9: {
                cout << "Ԫ��:";
                cin >> value;
                cout << "Ԫ��λ��Ϊ:" << ptr->getPos(value) << endl;
                break;
            }
            case 10: {
                if (ptr != nullptr){
                    delete ptr;
                    ptr = nullptr;
                }
                ptr = new lnkList<int>;
                cout << "�����ɹ�" << endl;
                break;
            }
            case 11:{
                delete ptr;
                ptr = nullptr;
                cout << "ɾ���ɹ�" << endl;
                break;
            }
            default: cout << "ѡ�����" << endl;
        }
    }
#endif
    exit(0);
}
