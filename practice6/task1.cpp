#include <iostream>

using namespace std;
/**
 * вариант 20, задача 1
 * Дано целое число. Определить количество делителей числа.
 */

int main(){
    int n;
    int m;
    int k = 0;
    cout << "Введите целое число" << endl;
    cin >> n;

    m = n / 2; // наибольший возможный делитель
    for (int i = 2; i < m; ++i) {
        if (n % i == 0){
            ++k;
            //cout << i << endl;
        }

    }
    cout << "Количество делителей числа " << n << ": " << k + 2 << endl;
    return 0;
}




