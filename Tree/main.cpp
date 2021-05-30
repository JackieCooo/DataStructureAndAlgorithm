/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-05-21
  * @brief   主程序
  ******************************************************************************
  * @attention
  * C++标准：C++20
  * IDE：Clion 2021.1
  * .exe文件在cmake-build-debug文件内
  * 使用外部文件导入树时注意.exe文件的路径
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/Tree
  * 码云：https://gitee.com/JackieCoo/Tree
  ******************************************************************************
  */

#include <iostream>
#include "Tree.h"

using namespace std;

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
    // 自己根据需要选择不同的编译方案
#if 0  // 这里为用户代码
    Tree<int, 3> tree;
    string s = "../ExternImportExample.txt";
    tree.createTree(s);
    tree.printTree();
#else  // 这里为测试代码
    Tree<int, 3> tree;
    int choice;
    while (true) {
        cout << "请选择(0退出, 1清除, 2建树, 3遍历树):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // 清屏
                cout << "再见！" << endl;
                system("pause");  // 暂停
                exit(0);  // 退出程序
            }
            case 1: {
                tree.clear();
                break;
            }
            case 2: {
                cout << "选择建树的方式: " << endl;
                cout << "1. 键盘输入" << endl;
                cout << "2. 外部文件输入" << endl;
                int val;
                cin >> val;
                if(val == 1) {
                    tree.createTree();
                    cout << "创建成功" << endl;
                }
                else if(val == 2){
                    cout << "请输入文件路径: ";
                    string filepath;
                    cin >> filepath;
                    tree.createTree(filepath);
                    cout << "创建成功" << endl;
                }
                break;
            }
            case 3: {
                tree.printTree();
                break;
            }
            default: cout << "选择错误！" << endl;
        }
    }
#endif
    return 0;
}
