/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-06-12
  * @brief   主程序
  ******************************************************************************
  * @attention
  * C++标准：C++20
  * IDE：Clion 2021.1
  * .exe文件在cmake-build-debug文件内
  * 调用函数时保证数组已经升序排序
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/DataStructureAndAlgorithm/Index
  * 码云：https://gitee.com/JackieCoo/DataStructureAndAlgorithm/Index
  ******************************************************************************
  */

#include <iostream>
#include "Index.h"

using namespace std;

int num[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
    // 自己根据需要选择不同的编译方案
#if 0  // 这里为用户代码
//    int* res = sequentialIndex(num, num+11, 6);
    int* res = binaryIndex(num, num+11, 0);
//    int* res = blockIndex(num, num+11, 1);
//    auto* res = hashIndex(num, num+11, 6);
    if(res != nullptr) {
        cout << *res << endl;
    }
    else {
        cout << "无此数据" << endl;
    }
#else  // 这里为测试代码
    int choice;
    while (true) {
        cout << "请选择(0退出, 1顺序索引, 2二分索引, 3块索引, 4哈希索引):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // 清屏
                cout << "再见！" << endl;
                system("pause");  // 暂停
                exit(0);  // 退出程序
            }
            case 1: {
                cout << "输入查找的数: ";
                cin >> choice;
                auto* res = sequentialIndex(num, num+11, choice);
                if (res != nullptr){
                    cout << *res << endl;
                }
                else{
                    cout << "无此数据" << endl;
                }
                break;
            }
            case 2: {
                cout << "输入查找的数: ";
                cin >> choice;
                auto* res = binaryIndex(num, num+11, choice);
                if (res != nullptr){
                    cout << *res << endl;
                }
                else{
                    cout << "无此数据" << endl;
                }
                break;
            }
            case 3: {
                cout << "输入查找的数: ";
                cin >> choice;
                auto* res = blockIndex(num, num+11, choice);
                if (res != nullptr){
                    cout << *res << endl;
                }
                else{
                    cout << "无此数据" << endl;
                }
                break;
            }
            case 4: {
                cout << "输入查找的数: ";
                cin >> choice;
                auto* res = hashIndex(num, num+11, choice);
                if (res != nullptr){
                    cout << *res << endl;
                }
                else{
                    cout << "无此数据" << endl;
                }
                break;
            }
            default: cout << "选择错误！" << endl;
        }
    }
#endif
    return 0;
}
