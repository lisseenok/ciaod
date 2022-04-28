#include <iostream>
#include <vector>
#include "Node.h"
#include "list.h"

using namespace std;
/**
 * Дан линейный однонаправленный список. Сформировать новый список, записав него четные числа,
 * но в обратном порядке, по отношению к их расположению в исходном.
 */

int randomInt(int A, int B){
    /**
     * функция для генерации рандомного числа от А до B
     */
    return A + rand() % ((B + 1) - A);
}

int main(){
    list l;
    list l2;

    vector<int> vec;

    for (int i = 0; i < 30; ++i) {
        l.push_back(randomInt(-50, 50));
    }
    cout << "Исходный список: " << endl;
    l.print();

    Node* first = l.first;

    while (first){
        if (first->val % 2 == 0){
            vec.push_back(first->val);
        }
        first = first->next;
    }

    for (int i = vec.size() - 1; i >= 0; --i) {
        l2.push_back(vec[i]);
    }

    cout << "Новый список: " << endl;
    l2.print();

}
