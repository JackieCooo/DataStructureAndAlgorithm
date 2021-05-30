#pragma once

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *leftChild, *rightChild;

public:
    Node() = default;
};
