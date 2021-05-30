/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0.1
  * @date    2021-04-08
  * @brief   ������
  ******************************************************************************
  * @attention
  * C++��׼��C++20
  * IDE��Clion 2020.2
  * .exe�ļ���cmake-build-debug�ļ���
  *
  * �������ϴ���Github�����ƣ���ע�պ����
  * Github��https://github.com/JackieCooo/arrList
  * ���ƣ�https://gitee.com/JackieCoo/arrList
  ******************************************************************************
  */

#include <iostream>
#include "arrList.h"

using namespace std;

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
// �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
    arrList<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout << vec;
#else  // ����Ϊ���Դ���
    arrList<int> vec(1000);
    int choice;
    int p;
    int value;
    while(true) {
        cout << "��ѡ��(0�˳�, 1���, 2��ʾ, 3��, 4����, 5׷��, 6ɾ��, 7����, 8�޸�, 9��λ):";
        cin >> choice;
        switch (choice) {
            case 0:{
                system("cls");  // ����
                cout << "�ټ���" << endl;
                system("pause");  // ��ͣ
                exit(0);  // �˳�����
            }
            case 1:{
                vec.clear();
                break;
            }
            case 2:{
                cout << vec;
                break;
            }
            case 3:{
                cout << "��:" << vec.size() << endl;
                break;
            }
            case 4:{
                cout << "λ��:";
                cin >> p;
                cout << "Ԫ��:";
                cin >> value;
                vec.insert(p, value);
                break;
            }
            case 5: {
                printf("Ԫ��:");
                cin >> value;
                vec.push_back(value);
                break;
            }
            case 6: {
                cout << "λ��:";
                cin >> p;
                vec.erase(p);
                break;
            }
            case 7: {
                cout << "λ��:";
                cin >> p;
                cout << "Ԫ��Ϊ��" << vec[p] << endl;
                break;
            }
            case 8: {
                cout << "λ��:";
                cin >> p;
                cout << "Ԫ��:";
                cin >> vec[p];
                break;
            }
            case 9: {
                cout << "Ԫ��:";
                cin >> value;
                cout << "Ԫ��λ��Ϊ:" << vec.getPos(value) << endl;
                break;
            }
            default: cout << "ѡ�����" << endl;
        }
    }
#endif
    return 0;
}
