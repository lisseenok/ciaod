#ifndef CIAOD_LIST_H
#define CIAOD_LIST_H

#include "Node.h"

// реализация односвязного списка
struct list {
    // указатель на первый узел
    Node* first;

    // указатель на последний узел
    Node* last;

    // конструктор
    list() : first(nullptr), last(nullptr) {}

    // метод проверки наличия узлов в списке
    bool is_empty() const {
        return first == nullptr;
    }

    // метод добавления элемента в конец списка
    void push_back(int _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    // функция печати всего списка
    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    // метод поиска узла в списке по заданному значению
    Node* find(int _val) {
        Node* p = first;
        while (p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    // метод удаления первого узла
    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    // метод удаления последнего узла
    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    // метод удаления узла по заданному значению
    void remove(int _val) {
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    // метод обращения к узлу по индексу
    Node* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};
#endif //CIAOD_LIST_H
