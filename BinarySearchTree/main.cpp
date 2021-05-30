/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-05-01
  * @brief   主程序
  ******************************************************************************
  * @attention
  * C++标准：C++20
  * IDE：Clion 2021.1
  * .exe文件在cmake-build-debug文件内
  * ExternImportExample.txt文件为外部文件创建二叉搜索树的模板
  * 通过外部文件创建二叉搜索树时，若使用相对路径，注意.exe文件的路径
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/BinarySearchTree
  * 码云：https://gitee.com/JackieCoo/BinarySearchTree
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include "binSearchTree.h"

using namespace std;

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
// 自己根据需要选择不同的编译方案
#if 0  // 这里为用户代码
    binSearchTree<int> BST;
    string filepath = "../ExternImportExample.txt";
    BST.createTree(filepath);
    BST.printBinarySearchTree();

    BST.erase(6);
    cout << "删除节点后为：" << endl;
    BST.printBinarySearchTree();

    Node<int>* tmp = BST.getMinimum();
    cout << "最小索引为：" << tmp->data << endl;

    tmp = BST.getMaximum();
    cout << "最大索引为：" << tmp->data << endl;

#else  // 这里为测试代码
    binSearchTree<int> BST;
    int choice;
    while(true) {
        cout << "请选择(0退出, 1清除, 2显示, 3追加, 4删除, 5查找, 6最小索引, 7最大索引, 8创建):";
        cin >> choice;
        switch (choice) {
            case 0:{
                system("cls");  // 清屏
                cout << "再见！" << endl;
                system("pause");  // 暂停
                exit(0);  // 退出程序
            }
            case 1:{
                BST.clear();
                cout << "清除成功" << endl;
                break;
            }
            case 2:{
                BST.printBinarySearchTree();
                break;
            }
            case 3:{
                int value;
                cout << "输入追加的元素：";
                cin >> value;
                BST.insert(value);
                cout << "追加成功" << endl;
                break;
            }
            case 4:{
                int value;
                cout << "输入删除的元素：";
                cin >> value;
                BST.erase(value);
                cout << "删除成功" << endl;
                break;
            }
            case 5: {
                cout << "输入要寻找的节点元素：";
                int value;
                cin >> value;
                Node<int>* tmp = BST.search(value);
                if(tmp != nullptr) {
                    cout << "目标节点的父节点元素为：";
                    if(tmp->parent != nullptr) cout << tmp->parent->data << endl;
                    else cout << "空" << endl;
                    cout << "目标节点的左孩子节点元素为：";
                    if(tmp->parent != nullptr) cout << tmp->leftChild->data << endl;
                    else cout << "空" << endl;
                    cout << "目标节点的右孩子节点元素为：";
                    if(tmp->parent != nullptr) cout << tmp->rightChild->data << endl;
                    else cout << "空" << endl;
                }
                else cout << "不存在节点" << endl;
                break;
            }
            case 6: {
                Node<int>* tmp = BST.getMinimum();
                cout << "最小索引为：" << tmp->data << endl;
                break;
            }
            case 7: {
                Node<int>* tmp = BST.getMaximum();
                cout << "最大索引为：" << tmp->data << endl;
                break;
            }
            case 8: {
                cout << "选择创建方式：1. 键盘输入 2. 外部文件导入" << endl;
                int k;
                cin >> k;
                if(k == 1){
                    BST.createTree();
                }
                else if(k == 2){
                    cout << "请输入文件地址：";
                    string s;
                    cin >> s;
                    BST.createTree(s);
                }
                cout << "创建成功" << endl;
                break;
            }
            default: cout << "选择错误！" << endl;
        }
    }
#endif
    return 0;
}
