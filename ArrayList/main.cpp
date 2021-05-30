/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0.1
  * @date    2021-04-08
  * @brief   主程序
  ******************************************************************************
  * @attention
  * C++标准：C++20
  * IDE：Clion 2020.2
  * .exe文件在cmake-build-debug文件内
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/arrList
  * 码云：https://gitee.com/JackieCoo/arrList
  ******************************************************************************
  */

#include <iostream>
#include "arrList.h"

using namespace std;

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
// 自己根据需要选择不同的编译方案
#if 0  // 这里为用户代码
    arrList<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout << vec;
#else  // 这里为测试代码
    arrList<int> vec(1000);
    int choice;
    int p;
    int value;
    while(true) {
        cout << "请选择(0退出, 1清除, 2显示, 3表长, 4插入, 5追加, 6删除, 7查找, 8修改, 9定位):";
        cin >> choice;
        switch (choice) {
            case 0:{
                system("cls");  // 清屏
                cout << "再见！" << endl;
                system("pause");  // 暂停
                exit(0);  // 退出程序
            }
            case 1:{
                vec.clear();
                break;
            }
            case 2:{
                cout << vec;
                break;
            }
            case 3:{
                cout << "表长:" << vec.size() << endl;
                break;
            }
            case 4:{
                cout << "位置:";
                cin >> p;
                cout << "元素:";
                cin >> value;
                vec.insert(p, value);
                break;
            }
            case 5: {
                printf("元素:");
                cin >> value;
                vec.push_back(value);
                break;
            }
            case 6: {
                cout << "位置:";
                cin >> p;
                vec.erase(p);
                break;
            }
            case 7: {
                cout << "位置:";
                cin >> p;
                cout << "元素为：" << vec[p] << endl;
                break;
            }
            case 8: {
                cout << "位置:";
                cin >> p;
                cout << "元素:";
                cin >> vec[p];
                break;
            }
            case 9: {
                cout << "元素:";
                cin >> value;
                cout << "元素位置为:" << vec.getPos(value) << endl;
                break;
            }
            default: cout << "选择错误！" << endl;
        }
    }
#endif
    return 0;
}
