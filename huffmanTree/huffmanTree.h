/**
 ******************************************************************************
 * @file    huffmanTree.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-17
 * @brief   哈夫曼树头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include "Node.h"

#define EXPORT_FILEPATH "../ExportResult.txt"  // 输出文件路径

using namespace std;

class HuffmanTree{

private:
    Node* root;  // 哈夫曼树
    vector<pair<char, string>>* code;  // 哈夫曼码

public:
    HuffmanTree();
    ~HuffmanTree();
    void createHuffmanTree(const string& filepath);
    void createHuffmanCode();
    void exportAsFile(const string& filepath);
    void transferWithHuffman(const string& filepath);

private:
    void _delete_huffman_tree(Node* tar);
    void _create_huffman_tree(vector<int>& dat);
    static bool _cmp(const Node* a, const Node* b);
    void _create_huffman_code(Node* tar, string& tmpStr);

};

class Finder{
private:
    char tarStr;

public:
    explicit Finder(char tarStr) : tarStr(tarStr) {};
    bool operator() (const pair<char, string>& tar) const;
};
