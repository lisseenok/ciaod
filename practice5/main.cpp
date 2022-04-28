/**
 * Даны два однонаправленных списка L1 и L2 и целое число а.
1)	Разработать функцию, которая вставляет список L2 после узла со значением а в список L1.
2)	Разработать функцию создания нового списка из значений, которые входят и в список L1 и L2.
3)	Удалить из список L1.

 */


#include "Node.h"
#include "list.h"
#include <vector>


bool isInVector(vector<int> vec, int a){
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == a) return true;
    }
    return false;
}

list functionAdd(list l1, list l2, int a){
    Node* nextA = l1.find(a)->next;
    l1.find(a)->next = l2.first;

    l2.last->next = nextA;
    //l1.last->next = nextA;
    return l1;

}

list functionNewList(list l1, list l2){
    list newList;
    vector<int> l2Values;
    Node* p2 = l2.first;
    Node* p1 = l1.first;

    while (p2){
        l2Values.push_back(p2->val);
        p2 = p2->next;
    }

    while (p1){
        if (isInVector(l2Values, p1->val)) newList.push_back(p1->val);
        p1 = p1->next;
    }
    return newList;
}
int main()
{

    list l1;
    list l2;
    list l3;
    int a = 2;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    cout << "Первый связанный список: " << endl;
    l1.print();

    l2.push_back(1);
    l2.push_back(6);
    l2.push_back(7);
    l2.push_back(4);
    l2.push_back(9);
    cout << "Второй связанный список: " << endl;
    l2.print();

    l3 = functionNewList(l1, l2);
    cout << "Связанный список из их общих элементов: " << endl;
    l3.print();

    cout << "Измененный первый список: " << endl;
    l1 = functionAdd(l1, l2, a);
    l1.print();


    return 0;
}

