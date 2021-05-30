/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-05-01
  * @brief   ������
  ******************************************************************************
  * @attention
  * C++��׼��C++20
  * IDE��Clion 2021.1
  * .exe�ļ���cmake-build-debug�ļ���
  * ExternImportExample.txt�ļ�Ϊ�ⲿ�ļ�����������������ģ��
  * ͨ���ⲿ�ļ���������������ʱ����ʹ�����·����ע��.exe�ļ���·��
  *
  * �������ϴ���Github�����ƣ���ע�պ����
  * Github��https://github.com/JackieCooo/BinarySearchTree
  * ���ƣ�https://gitee.com/JackieCoo/BinarySearchTree
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include "binSearchTree.h"

using namespace std;

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
// �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
    binSearchTree<int> BST;
    string filepath = "../ExternImportExample.txt";
    BST.createTree(filepath);
    BST.printBinarySearchTree();

    BST.erase(6);
    cout << "ɾ���ڵ��Ϊ��" << endl;
    BST.printBinarySearchTree();

    Node<int>* tmp = BST.getMinimum();
    cout << "��С����Ϊ��" << tmp->data << endl;

    tmp = BST.getMaximum();
    cout << "�������Ϊ��" << tmp->data << endl;

#else  // ����Ϊ���Դ���
    binSearchTree<int> BST;
    int choice;
    while(true) {
        cout << "��ѡ��(0�˳�, 1���, 2��ʾ, 3׷��, 4ɾ��, 5����, 6��С����, 7�������, 8����):";
        cin >> choice;
        switch (choice) {
            case 0:{
                system("cls");  // ����
                cout << "�ټ���" << endl;
                system("pause");  // ��ͣ
                exit(0);  // �˳�����
            }
            case 1:{
                BST.clear();
                cout << "����ɹ�" << endl;
                break;
            }
            case 2:{
                BST.printBinarySearchTree();
                break;
            }
            case 3:{
                int value;
                cout << "����׷�ӵ�Ԫ�أ�";
                cin >> value;
                BST.insert(value);
                cout << "׷�ӳɹ�" << endl;
                break;
            }
            case 4:{
                int value;
                cout << "����ɾ����Ԫ�أ�";
                cin >> value;
                BST.erase(value);
                cout << "ɾ���ɹ�" << endl;
                break;
            }
            case 5: {
                cout << "����ҪѰ�ҵĽڵ�Ԫ�أ�";
                int value;
                cin >> value;
                Node<int>* tmp = BST.search(value);
                if(tmp != nullptr) {
                    cout << "Ŀ��ڵ�ĸ��ڵ�Ԫ��Ϊ��";
                    if(tmp->parent != nullptr) cout << tmp->parent->data << endl;
                    else cout << "��" << endl;
                    cout << "Ŀ��ڵ�����ӽڵ�Ԫ��Ϊ��";
                    if(tmp->parent != nullptr) cout << tmp->leftChild->data << endl;
                    else cout << "��" << endl;
                    cout << "Ŀ��ڵ���Һ��ӽڵ�Ԫ��Ϊ��";
                    if(tmp->parent != nullptr) cout << tmp->rightChild->data << endl;
                    else cout << "��" << endl;
                }
                else cout << "�����ڽڵ�" << endl;
                break;
            }
            case 6: {
                Node<int>* tmp = BST.getMinimum();
                cout << "��С����Ϊ��" << tmp->data << endl;
                break;
            }
            case 7: {
                Node<int>* tmp = BST.getMaximum();
                cout << "�������Ϊ��" << tmp->data << endl;
                break;
            }
            case 8: {
                cout << "ѡ�񴴽���ʽ��1. �������� 2. �ⲿ�ļ�����" << endl;
                int k;
                cin >> k;
                if(k == 1){
                    BST.createTree();
                }
                else if(k == 2){
                    cout << "�������ļ���ַ��";
                    string s;
                    cin >> s;
                    BST.createTree(s);
                }
                cout << "�����ɹ�" << endl;
                break;
            }
            default: cout << "ѡ�����" << endl;
        }
    }
#endif
    return 0;
}
