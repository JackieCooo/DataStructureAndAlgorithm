/**
 ******************************************************************************
 * @file    huffmanTree.cpp
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-17
 * @brief   哈夫曼树源文件
 ******************************************************************************
 */

#include "huffmanTree.h"

using namespace std;

HuffmanTree::HuffmanTree() {
    root = nullptr;
    code = nullptr;
}

HuffmanTree::~HuffmanTree() {
    _delete_huffman_tree(root);
}

void HuffmanTree::_delete_huffman_tree(Node* tar) {
    if (tar == nullptr) return;
    _delete_huffman_tree(tar->leftChild);
    _delete_huffman_tree(tar->rightChild);
    delete tar;
}

void HuffmanTree::createHuffmanTree(const string &filepath) {
    ifstream ifs;
    ifs.open(filepath, ios::in);
    if (ifs.is_open()){
        vector<int> v(256, 0);  // 保存每个字符的出现次数
        char ch;
        while (!ifs.eof()){
            ifs >> ch;
            ++v[ch];
        }
        --v[ch];
        _create_huffman_tree(v);  // 创建哈夫曼树
        ifs.close();
    }
    else{
        cout << "文件打开失败" << endl;
    }
}

void HuffmanTree::_create_huffman_tree(vector<int> &dat) {
    list<Node*> w;  // 保存字符出现的权值
    for (int i = 0; i < 256; i++) {
        if (dat[i] == 0) continue;  // 没有出现该字符，跳过
        auto* tmp = new Node(char(i), dat[i], nullptr, nullptr);
        w.push_back(tmp);
    }
    int w_size = int(w.size());
    for (int i = 0; i < w_size-1; i++){
        // 找出2个最小权值的节点
        auto m1 = (min_element(w.begin(), w.end(), _cmp));
        auto* n1 = *m1;
        w.erase(m1);
        auto m2 = min_element(w.begin(), w.end(), _cmp);
        auto* n2 = *m2;
        w.erase(m2);
        auto* tmp = new Node('\0', n1->weight+n2->weight, n1, n2);  // 合并节点
        w.push_back(tmp);  // 加入列表
    }
    root = w.front();
}

bool HuffmanTree::_cmp(const Node* a, const Node* b) {
    return a->weight < b->weight;
}

void HuffmanTree::createHuffmanCode() {
    if (root == nullptr) return;
    code = new vector<pair<char, string>>;  // 创建哈夫曼码表
    string tmpCode;
    _create_huffman_code(root, tmpCode);
    cout << endl;
}

void HuffmanTree::_create_huffman_code(Node *tar, string& tmpStr) {
    if (tar->leftChild == nullptr && tar->rightChild == nullptr){  // 此节点为叶节点
        (*code).emplace_back(tar->data, tmpStr);  // 增加哈夫曼码
        return;
    }
    // dfs
    tmpStr += '0';
    _create_huffman_code(tar->leftChild, tmpStr);
    tmpStr.pop_back();
    tmpStr += '1';
    _create_huffman_code(tar->rightChild, tmpStr);
    tmpStr.pop_back();
}

void HuffmanTree::exportAsFile(const string& filepath) {
    ofstream ofs;
    ofs.open(EXPORT_FILEPATH, ios::out);
    ifstream ifs;
    ifs.open(filepath, ios::in);
    if (ofs.is_open() && ifs.is_open()){
        char ch;
        while (!ifs.eof()){
            ifs >> ch;
            auto it = find_if((*code).begin(), (*code).end(), Finder(ch));  // 找到对应的哈夫曼码
            ofs << (*it).second << " ";
        }
        ifs.close();
        ofs.close();
    }
    else{
        cout << "导出失败" << endl;
    }
}

bool Finder::operator()(const pair<char, string> &tar) const {
    return tar.first == tarStr;
}

void HuffmanTree::transferWithHuffman(const string &filepath) {
    createHuffmanTree(filepath);
    createHuffmanCode();
    exportAsFile(filepath);
}