/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-07
  * @brief   主程序
  ******************************************************************************
  * @attention
  * C++标准：C++20
  * IDE：Clion 2020.2
  * .exe文件在cmake-build-debug文件内
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/lnkList
  * 码云：https://gitee.com/JackieCoo/lnkList
  ******************************************************************************
  */

#include <iostream>
#include "lnkList.h"

using namespace std;

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
    // 自己根据需要选择不同的编译方案
#if 0  // 这里为用户代码
    lnkList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
#else  // 这里为测试代码
    lnkList<int> *ptr;
    ptr = nullptr;
    int choice;
    int p;
    int value;
    while (true) {
        cout << "请选择(0退出, 1清除, 2显示, 3表长, 4插入, 5追加, 6删除, 7查找, 8修改, 9定位, 10创建, 11销毁):";

        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // 清屏
                cout << "再见！" << endl;
                system("pause");  // 暂停
                exit(0);  // 退出程序
            }
            case 1: {
                ptr->clear();
                break;
            }
            case 2: {
                cout << *ptr;
                break;
            }
            case 3: {
                cout << "表长:" << ptr->size() << endl;
                break;
            }
            case 4: {
                cout << "位置:";
                cin >> p;
                cout << "元素:";
                cin >> value;
                ptr->insert(p, value);
                break;
            }
            case 5: {
                printf("元素:");
                cin >> value;
                ptr->push_back(value);
                break;
            }
            case 6: {
                cout << "位置:";
                cin >> p;
                ptr->erase(p);
                break;
            }
            case 7: {
                cout << "位置:";
                cin >> p;
                cout << "元素为：" << (*ptr)[p] << endl;
                break;
            }
            case 8: {
                cout << "位置:";
                cin >> p;
                cout << "元素:";
                cin >> (*ptr)[p];
    //            (*ptr)[p] = value;
                break;
            }
            case 9: {
                cout << "元素:";
                cin >> value;
                cout << "元素位置为:" << ptr->getPos(value) << endl;
                break;
            }
            case 10: {
                if (ptr != nullptr){
                    delete ptr;
                    ptr = nullptr;
                }
                ptr = new lnkList<int>;
                cout << "创建成功" << endl;
                break;
            }
            case 11:{
                delete ptr;
                ptr = nullptr;
                cout << "删除成功" << endl;
                break;
            }
            default: cout << "选择错误！" << endl;
        }
    }
#endif
    exit(0);
}
