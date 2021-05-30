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
  * IDE：Clion 2021.1
  * .exe文件在cmake-build-debug文件内
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/arrString
  * 码云：https://gitee.com/JackieCoo/arrString
  ******************************************************************************
  */

#include <iostream>
#include "arrString.h"

using namespace std;

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
    // 自己根据需要选择不同的编译方案
#if 0  // 这里为用户代码
    arrString s1("Hello, World");
    arrString s2(10, 'a');
    arrString s3(s1);
    arrString s4(s1, 8);
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    cout << "s1的长度为: " << s1.size() << endl;
    s1.clear();
    cout << "s1 clear后的长度为: " << s1.size() << endl;
    s1 = "Hello";
    cout << "s1 = " << s1 << endl;
    s1.resize(10, 'a');
    cout << "s1 = " << s1 << endl;
    s1.resize(3);
    cout << "s1 = " << s1 << endl;
    s1 += "World";
    cout << "s1 + World = " << s1 << endl;
    s2 += s3;
    cout << "s2 + s3 = " << s2 << endl;
    cout << "s2第16位开始向前找，字符o在: " << s2.find('o', 16) << endl;
    cout << "s2第16位开始向后找，字符o在: " << s2.rfind('o', 16) << endl;
    cout << "s2的第11号元素为：" << s2[10] << endl;
    cout << "s1 = " << s1.c_str() << endl;
    s4 = s1.substr(2, 6);
    cout << "取出s1第2-8号元素并赋给s4：" << s4 << endl;
    cout << "往s4后追加4个c：" << s4.append("cccc") << endl;
    cout << "s4的首位为：" << s4.front() << endl;
    cout << "s4的末位为：" << s4.back() << endl;

#else  // 这里为测试代码
    arrString s;
    int choice;
    int p;
    int n;
    char value;
    while (true) {
        cout << "请选择(0退出, 1清除, 2显示, 3串长, 4追加字符, 5追加字符串, 6查找, 7提取字符串, 8复制):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // 清屏
                cout << "再见！" << endl;
                system("pause");  // 暂停
                exit(0);  // 退出程序
            }
            case 1: {
                s.clear();
                break;
            }
            case 2: {
                cout << s;
                break;
            }
            case 3: {
                cout << "串长:" << s.size() << endl;
                break;
            }
            case 4: {
                printf("字符:");
                cin >> value;
                s.push_back(value);
                break;
            }
            case 5: {
                const char* val = "abcd";
                cout << "字符串为: abcd";
                s.append(val);
                cout << "追加后为:" << s << endl;
                break;
            }
            case 6: {
                cout << "元素:";
                cin >> value;
                cout << "位置:";
                cin >> p;
                int res = s.find(value, p);
                if(res != -1) cout << "元素的位置为：" << res << endl;
                break;
            }
            case 7: {
                cout << "位置:";
                cin >> p;
                cout << "个数:";
                cin >> n;
                arrString t = s.substr(p, n);
                cout << "提取的字符串为:" << t << endl;
                break;
            }
            case 8: {
                const char* val = "abcd";
                cout << "字符串为:abcd";
                s = val;
                cout << "复制后为:" << s << endl;
                break;
            }
            default: cout << "选择错误！" << endl;
        }
    }
#endif
    return 0;
}
