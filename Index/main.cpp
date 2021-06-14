/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-06-12
  * @brief   ������
  ******************************************************************************
  * @attention
  * C++��׼��C++20
  * IDE��Clion 2021.1
  * .exe�ļ���cmake-build-debug�ļ���
  * ���ú���ʱ��֤�����Ѿ���������
  *
  * �������ϴ���Github�����ƣ���ע�պ����
  * Github��https://github.com/JackieCooo/DataStructureAndAlgorithm/Index
  * ���ƣ�https://gitee.com/JackieCoo/DataStructureAndAlgorithm/Index
  ******************************************************************************
  */

#include <iostream>
#include "Index.h"

using namespace std;

int num[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
    // �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
//    int* res = sequentialIndex(num, num+11, 6);
    int* res = binaryIndex(num, num+11, 0);
//    int* res = blockIndex(num, num+11, 1);
//    auto* res = hashIndex(num, num+11, 6);
    if(res != nullptr) {
        cout << *res << endl;
    }
    else {
        cout << "�޴�����" << endl;
    }
#else  // ����Ϊ���Դ���
    int choice;
    while (true) {
        cout << "��ѡ��(0�˳�, 1˳������, 2��������, 3������, 4��ϣ����):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // ����
                cout << "�ټ���" << endl;
                system("pause");  // ��ͣ
                exit(0);  // �˳�����
            }
            case 1: {
                cout << "������ҵ���: ";
                cin >> choice;
                auto* res = sequentialIndex(num, num+11, choice);
                if (res != nullptr){
                    cout << *res << endl;
                }
                else{
                    cout << "�޴�����" << endl;
                }
                break;
            }
            case 2: {
                cout << "������ҵ���: ";
                cin >> choice;
                auto* res = binaryIndex(num, num+11, choice);
                if (res != nullptr){
                    cout << *res << endl;
                }
                else{
                    cout << "�޴�����" << endl;
                }
                break;
            }
            case 3: {
                cout << "������ҵ���: ";
                cin >> choice;
                auto* res = blockIndex(num, num+11, choice);
                if (res != nullptr){
                    cout << *res << endl;
                }
                else{
                    cout << "�޴�����" << endl;
                }
                break;
            }
            case 4: {
                cout << "������ҵ���: ";
                cin >> choice;
                auto* res = hashIndex(num, num+11, choice);
                if (res != nullptr){
                    cout << *res << endl;
                }
                else{
                    cout << "�޴�����" << endl;
                }
                break;
            }
            default: cout << "ѡ�����" << endl;
        }
    }
#endif
    return 0;
}
