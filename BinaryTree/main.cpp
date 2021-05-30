/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-23
  * @brief   主程序
  ******************************************************************************
  * @attention
  * C++标准：C++20
  * IDE：Clion 2021.1
  * .exe文件在cmake-build-debug文件内
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/BinaryTree
  * 码云：https://gitee.com/JackieCoo/BinaryTree
  ******************************************************************************
  */

#include <iostream>
#include "BinaryTree.h"

using namespace std;

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
    // 自己根据需要选择不同的编译方案
#if 0  // 这里为用户代码
    int preorder[] = {1, 2, 4, 0, 0, 0, 3, 5, 0, 7, 0, 0, 6, 8, 0, 0, 9, 0, 0};

    BinaryTree BTree;
    BTree.creatBTreeWithPreorderTraversal(preorder);
    cout << "创建成功" << endl;
    cout << "前序遍历为：" << endl;
    BTree.printBTreeWithPreorderTraversal();
    cout << endl << "中序遍历为：" << endl;
    BTree.printBTreeWithInorderTraversal();
    cout << endl << "后序遍历为：" << endl;
    BTree.printBTreeWithPostorderTraversal();
    cout << endl << "层序遍历为：" << endl;
    BTree.printBTreeWithLevelTraversal();

#else  // 这里为测试代码
    BinaryTree BTree;
    int choice;
    while (true) {
        cout << "请选择(0退出, 1清除, 2创造二叉树, 3前序遍历二叉树, 4中序遍历二叉树, 5后序遍历二叉树, 6层序遍历二叉树):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // 清屏
                cout << "再见！" << endl;
                system("pause");  // 暂停
                exit(0);  // 退出程序
            }
            case 1: {
                BTree.clear();
                break;
            }
            case 2: {
                cout << "按前序遍历输入二叉树节点（节点为空用0表示）：" << endl;
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
            default: cout << "选择错误！" << endl;
        }
    }
#endif
    return 0;
}
