/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-06-08
  * @brief   主程序
  ******************************************************************************
  * @attention
  * C++标准：C++20
  * IDE：Clion 2021.1
  * .exe文件在cmake-build-debug文件内
  * 建议不要对负数进行排序，有的排序方式不支持
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/DataStructureAndAlgorithm/Sort
  * 码云：https://gitee.com/JackieCoo/DataStructureAndAlgorithm/Sort
  ******************************************************************************
  */

#include <iostream>
#include <random>
#include <ctime>
#include "Sort.h"
#include "Compare.h"

using namespace std;

int num[11] = {5, 38, 43, 19, 55, 21, 41, 10, 32, 14, 1};

/**
  * @brief  此函数重新随机填充num数组
  * @param None
  * @retval None
  */
void resetNum() {
    default_random_engine engine(time(nullptr));
    uniform_int_distribution<unsigned> u(0, 100);
    for (auto &i : num) {
        i = u(engine);
    }
}

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
    // 自己根据需要选择不同的编译方案
#if 0  // 这里为用户代码
    Sort<int, Greater<int>> s;
//    s.bubbleSort(num, num+11);
//    s.shellSort(num, num+11);
//    s.heapSort(num, num+11);
//    s.quickSort(num, num+11);
//    s.bucketSort(num, num+11);
//    s.mergeSort(num, num+11);
    for (auto &i : num) {
        cout << i << " ";
    }
#else  // 这里为测试代码
    Sort<int, Greater<int>> sort;
    int choice;
    while (true) {
        cout << "请选择(0退出, 1冒泡排序, 2希尔排序, 3堆排序, 4快速排序, 5桶排序, 6归并排序):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // 清屏
                cout << "再见！" << endl;
                system("pause");  // 暂停
                exit(0);  // 退出程序
            }
            case 1: {
                cout << "冒泡排序前为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.bubbleSort(num, num+11);
                cout << "冒泡排序后为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            case 2: {
                cout << "希尔排序前为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.shellSort(num, num+11);
                cout << "希尔排序后为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            case 3: {
                cout << "堆排序前为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.heapSort(num, num+11);
                cout << "堆排序后为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            case 4: {
                cout << "快速排序前为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.quickSort(num, num+11);
                cout << "快速排序后为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            case 5: {
                cout << "桶排序前为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.bucketSort(num, num+11);
                cout << "桶排序后为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            case 6: {
                cout << "归并排序前为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                sort.mergeSort(num, num+11);
                cout << "归并排序后为: ";
                for (auto &i : num) {
                    cout << i << " ";
                }
                cout << endl;
                resetNum();
                break;
            }
            default: cout << "选择错误！" << endl;
        }
    }
#endif
    return 0;
}
