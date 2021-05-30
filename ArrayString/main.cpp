/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-04-16
  * @brief   ������
  ******************************************************************************
  * @attention
  * C++��׼��C++20
  * IDE��Clion 2021.1
  * .exe�ļ���cmake-build-debug�ļ���
  *
  * �������ϴ���Github�����ƣ���ע�պ����
  * Github��https://github.com/JackieCooo/arrString
  * ���ƣ�https://gitee.com/JackieCoo/arrString
  ******************************************************************************
  */

#include <iostream>
#include "arrString.h"

using namespace std;

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
    // �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
    arrString s1("Hello, World");
    arrString s2(10, 'a');
    arrString s3(s1);
    arrString s4(s1, 8);
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    cout << "s1�ĳ���Ϊ: " << s1.size() << endl;
    s1.clear();
    cout << "s1 clear��ĳ���Ϊ: " << s1.size() << endl;
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
    cout << "s2��16λ��ʼ��ǰ�ң��ַ�o��: " << s2.find('o', 16) << endl;
    cout << "s2��16λ��ʼ����ң��ַ�o��: " << s2.rfind('o', 16) << endl;
    cout << "s2�ĵ�11��Ԫ��Ϊ��" << s2[10] << endl;
    cout << "s1 = " << s1.c_str() << endl;
    s4 = s1.substr(2, 6);
    cout << "ȡ��s1��2-8��Ԫ�ز�����s4��" << s4 << endl;
    cout << "��s4��׷��4��c��" << s4.append("cccc") << endl;
    cout << "s4����λΪ��" << s4.front() << endl;
    cout << "s4��ĩλΪ��" << s4.back() << endl;

#else  // ����Ϊ���Դ���
    arrString s;
    int choice;
    int p;
    int n;
    char value;
    while (true) {
        cout << "��ѡ��(0�˳�, 1���, 2��ʾ, 3����, 4׷���ַ�, 5׷���ַ���, 6����, 7��ȡ�ַ���, 8����):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // ����
                cout << "�ټ���" << endl;
                system("pause");  // ��ͣ
                exit(0);  // �˳�����
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
                cout << "����:" << s.size() << endl;
                break;
            }
            case 4: {
                printf("�ַ�:");
                cin >> value;
                s.push_back(value);
                break;
            }
            case 5: {
                const char* val = "abcd";
                cout << "�ַ���Ϊ: abcd";
                s.append(val);
                cout << "׷�Ӻ�Ϊ:" << s << endl;
                break;
            }
            case 6: {
                cout << "Ԫ��:";
                cin >> value;
                cout << "λ��:";
                cin >> p;
                int res = s.find(value, p);
                if(res != -1) cout << "Ԫ�ص�λ��Ϊ��" << res << endl;
                break;
            }
            case 7: {
                cout << "λ��:";
                cin >> p;
                cout << "����:";
                cin >> n;
                arrString t = s.substr(p, n);
                cout << "��ȡ���ַ���Ϊ:" << t << endl;
                break;
            }
            case 8: {
                const char* val = "abcd";
                cout << "�ַ���Ϊ:abcd";
                s = val;
                cout << "���ƺ�Ϊ:" << s << endl;
                break;
            }
            default: cout << "ѡ�����" << endl;
        }
    }
#endif
    return 0;
}
