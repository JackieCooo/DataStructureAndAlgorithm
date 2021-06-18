/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-06-17
  * @brief   主程序
  ******************************************************************************
  * @attention
  * C++标准：C++20
  * IDE：Clion 2021.1
  * .exe文件在cmake-build-debug文件内
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/DataStructureAndAlgorithm/huffmanTree
  * 码云：https://gitee.com/JackieCoo/DataStructureAndAlgorithm/huffmanTree
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include "huffmanTree.h"

using namespace std;

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
    // 自己根据需要选择不同的编译方案
#if 1  // 这里为用户代码
    string s = "../ExternImportExample.txt";
    HuffmanTree ht;
    ht.transferWithHuffman(s);

#else  // 这里为测试代码

#endif
    return 0;
}
