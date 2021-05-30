/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-05-21
  * @brief   ������
  ******************************************************************************
  * @attention
  * C++��׼��C++20
  * IDE��Clion 2021.1
  * .exe�ļ���cmake-build-debug�ļ���
  * ʹ���ⲿ�ļ�������ʱע��.exe�ļ���·��
  *
  * �������ϴ���Github�����ƣ���ע�պ����
  * Github��https://github.com/JackieCooo/Tree
  * ���ƣ�https://gitee.com/JackieCoo/Tree
  ******************************************************************************
  */

#include <iostream>
#include "Tree.h"

using namespace std;

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
    // �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
    Tree<int, 3> tree;
    string s = "../ExternImportExample.txt";
    tree.createTree(s);
    tree.printTree();
#else  // ����Ϊ���Դ���
    Tree<int, 3> tree;
    int choice;
    while (true) {
        cout << "��ѡ��(0�˳�, 1���, 2����, 3������):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // ����
                cout << "�ټ���" << endl;
                system("pause");  // ��ͣ
                exit(0);  // �˳�����
            }
            case 1: {
                tree.clear();
                break;
            }
            case 2: {
                cout << "ѡ�����ķ�ʽ: " << endl;
                cout << "1. ��������" << endl;
                cout << "2. �ⲿ�ļ�����" << endl;
                int val;
                cin >> val;
                if(val == 1) {
                    tree.createTree();
                    cout << "�����ɹ�" << endl;
                }
                else if(val == 2){
                    cout << "�������ļ�·��: ";
                    string filepath;
                    cin >> filepath;
                    tree.createTree(filepath);
                    cout << "�����ɹ�" << endl;
                }
                break;
            }
            case 3: {
                tree.printTree();
                break;
            }
            default: cout << "ѡ�����" << endl;
        }
    }
#endif
    return 0;
}
