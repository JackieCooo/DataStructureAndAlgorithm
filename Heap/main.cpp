/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-06-16
  * @brief   主程序
  ******************************************************************************
  * @attention
  * C++标准：C++20
  * IDE：Clion 2021.1
  * .exe文件在cmake-build-debug文件内
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/DataStructureAndAlgorithm/Heap
  * 码云：https://gitee.com/JackieCoo/DataStructureAndAlgorithm/Heap
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include "Heap.h"

using namespace std;

int num[11] = {5, 38, 43, 19, 55, 21, 41, 10, 32, 14, 1};

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
    // 自己根据需要选择不同的编译方案
#if 0  // 这里为用户代码

#else  // 这里为测试代码
    string s = "../ExternImportExample.txt";
    Heap<int, Greater<int>> h(s);
    int choice;
    while (true) {
        cout << "请选择(0退出, 1打印堆, 2插入, 3查看堆顶, 4弹出顶堆元素):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // 清屏
                cout << "再见！" << endl;
                system("pause");  // 暂停
                exit(0);  // 退出程序
            }
            case 1: {
                cout << h;
                break;
            }
            case 2: {
                cout << "输入插入的数: ";
                cin >> choice;
                h.insert(choice);
                break;
            }
            case 3: {
                cout << h.top();
                break;
            }
            case 4: {
                h.pop();
                break;
            }
            default: cout << "选择错误！" << endl;
        }
    }
#endif
    return 0;
}
