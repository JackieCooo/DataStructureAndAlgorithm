/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-16
  * @brief   主程序
  ******************************************************************************
  * @attention
  * C++标准：C++20
  * IDE：Clion 2019.3
  * .exe文件在cmake-build-debug文件内
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/lnkQueue
  * 码云：https://gitee.com/JackieCoo/lnkQueue
  ******************************************************************************
  */

#include <iostream>
#include "lnkQueue.h"

using namespace std;

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
    // 自己根据需要选择不同的编译方案
#if 0  // 这里为用户代码
    lnkQueue<int> q;

#else  // 这里为测试代码
    lnkQueue<int>* ptr;
    ptr = nullptr;
    int choice;
    int value;
    while (true) {
        cout << "请选择(0退出, 1显示, 2队长, 3入队, 4出队, 5查看队首, 6查看队尾, 7创建, 8销毁):";

        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // 清屏
                cout << "再见！" << endl;
                system("pause");  // 暂停
                exit(0);  // 退出程序
            }
            case 1: {
                cout << *ptr;
                break;
            }
            case 2: {
                cout << "队长:" << ptr->size() << endl;
                break;
            }
            case 3: {
                printf("元素:");
                cin >> value;
                ptr->push(value);
                break;
            }
            case 4: {
                ptr->pop();
                break;
            }
            case 5: {
                cout << "队首元素为：" << ptr->front() << endl;
                break;
            }
            case 6: {
                cout << "队尾元素为：" << ptr->back() << endl;
                break;
            }
            case 7: {
                if (ptr != nullptr) {
                    delete ptr;
                    ptr = nullptr;
                }
                ptr = new lnkQueue<int>;
                cout << "创建成功" << endl;
                break;
            }
            case 8: {
                delete ptr;
                ptr = nullptr;
                cout << "删除成功" << endl;
                break;
            }
            default: cout << "选择错误！" << endl;
        }
    }
#endif
    return 0;
}
