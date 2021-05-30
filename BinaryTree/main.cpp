/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-23
  * @brief   ������
  ******************************************************************************
  * @attention
  * C++��׼��C++20
  * IDE��Clion 2021.1
  * .exe�ļ���cmake-build-debug�ļ���
  *
  * �������ϴ���Github�����ƣ���ע�պ����
  * Github��https://github.com/JackieCooo/BinaryTree
  * ���ƣ�https://gitee.com/JackieCoo/BinaryTree
  ******************************************************************************
  */

#include <iostream>
#include "BinaryTree.h"

using namespace std;

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
    // �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
    int preorder[] = {1, 2, 4, 0, 0, 0, 3, 5, 0, 7, 0, 0, 6, 8, 0, 0, 9, 0, 0};

    BinaryTree BTree;
    BTree.creatBTreeWithPreorderTraversal(preorder);
    cout << "�����ɹ�" << endl;
    cout << "ǰ�����Ϊ��" << endl;
    BTree.printBTreeWithPreorderTraversal();
    cout << endl << "�������Ϊ��" << endl;
    BTree.printBTreeWithInorderTraversal();
    cout << endl << "�������Ϊ��" << endl;
    BTree.printBTreeWithPostorderTraversal();
    cout << endl << "�������Ϊ��" << endl;
    BTree.printBTreeWithLevelTraversal();

#else  // ����Ϊ���Դ���
    BinaryTree BTree;
    int choice;
    while (true) {
        cout << "��ѡ��(0�˳�, 1���, 2���������, 3ǰ�����������, 4�������������, 5�������������, 6�������������):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // ����
                cout << "�ټ���" << endl;
                system("pause");  // ��ͣ
                exit(0);  // �˳�����
            }
            case 1: {
                BTree.clear();
                break;
            }
            case 2: {
                cout << "��ǰ���������������ڵ㣨�ڵ�Ϊ����0��ʾ����" << endl;
                BTree.creatBTreeWithPreorderTraversal();
                break;
            }
            case 3: {
                BTree.printBTreeWithPreorderTraversal();
                break;
            }
            case 4: {
                BTree.printBTreeWithInorderTraversal();
                break;
            }
            case 5: {
                BTree.printBTreeWithPostorderTraversal();
                break;
            }
            case 6: {
                BTree.printBTreeWithLevelTraversal();
                break;
            }
            default: cout << "ѡ�����" << endl;
        }
    }
#endif
    return 0;
}
