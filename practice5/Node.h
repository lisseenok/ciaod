#ifndef CIAOD_NODE_H
#define CIAOD_NODE_H
#include <iostream>

using namespace std;

// реализация узла
struct Node {
    // значение
    int val;

    // ссылка на следующий элемент
    Node* next;

    // конструктор
    Node(int _val) : val(_val), next(nullptr){}
};


#endif //CIAOD_NODE_H
