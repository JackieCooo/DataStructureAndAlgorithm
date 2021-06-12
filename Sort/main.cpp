/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-06-08
  * @brief   ������
  ******************************************************************************
  * @attention
  * C++��׼��C++20
  * IDE��Clion 2021.1
  * .exe�ļ���cmake-build-debug�ļ���
  * ���鲻Ҫ�Ը������������е�����ʽ��֧��
  *
  * �������ϴ���Github�����ƣ���ע�պ����
  * Github��https://github.com/JackieCooo/DataStructureAndAlgorithm/Sort
  * ���ƣ�https://gitee.com/JackieCoo/DataStructureAndAlgorithm/Sort
  ******************************************************************************
  */

#include <iostream>
#include <random>
#include <ctime>
#include "Sort.h"
#include "Compare.h"

using namespace std;

int num[11] = {5, 38, 43, 19, 55, 21, 41, 10, 32, 14, 1};

/**
  * @brief  �˺�������������num����
  * @param None
  * @retval None
  */
void resetNum() {
    default_random_engine engine(time(nullptr));
    uniform_int_distribution<unsigned> u(0, 100);
    for (auto &i : num) {
        i = u(engine);
    }
}

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
    // �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
    Sort<int, Greater<int>> s;
//    s.bubbleSort(num, num+11);
//    s.shellSort(num, num+11);
//    s.heapSort(num, num+11);
//    s.quickSort(num, num+11);
//    s.bucketSort(num, num+11);
//    s.mergeSort(num, num+11);
    for (auto &i : num) {
        cout << i << " ";
    }
#else  // ����Ϊ���Դ���
    Sort<int, Greater<int>> sort;
    int choice;
    while (true) {
        cout << "��ѡ��(0�˳�, 1ð������, 2ϣ������, 3������, 4��������, 5Ͱ����, 6�鲢����):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // ����
                cout << "�ټ���" << endl;
                system("pause");  // ��ͣ
                exit(0);  // �˳�����
            }
            case 1: {
                cout << "ð������ǰΪ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.bubbleSort(num, num+11);
                cout << "ð�������Ϊ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            case 2: {
                cout << "ϣ������ǰΪ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.shellSort(num, num+11);
                cout << "ϣ�������Ϊ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            case 3: {
                cout << "������ǰΪ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.heapSort(num, num+11);
                cout << "�������Ϊ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            case 4: {
                cout << "��������ǰΪ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.quickSort(num, num+11);
                cout << "���������Ϊ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            case 5: {
                cout << "Ͱ����ǰΪ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.bucketSort(num, num+11);
                cout << "Ͱ�����Ϊ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            case 6: {
                cout << "�鲢����ǰΪ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.mergeSort(num, num+11);
                cout << "�鲢�����Ϊ: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            default: cout << "ѡ�����" << endl;
        }
    }
#endif
    return 0;
}
