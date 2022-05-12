#include <iostream>

/**
 * вариант 28
* сортировка простого выбора
*/

using std::cout;
using std::cin;
using std::endl;

int randomInt(int A, int B) {
    /**
     * функция для генерации рандомного числа от А до B
     */
    return A + rand() % ((B + 1) - A);
}

void printArray(int arr[], int n)
{
    /**
     * Вспомогательная функция для вывода на экран массива размера
     */
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    srand(time(0));

    int size = 0;
    cout << "Введите размер массива: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i != size; ++i)
        arr[i] = randomInt(-100, 100);

    cout << "Исходный массив: " << endl;
    printArray(arr, size);

    for (int i = 0; i < size; ++i) {
        int min = i;

        for (int j = i + 1; j < size; ++j)
            if (arr[j] < arr[min])
                min = j;

        int tmp  = arr[min];
        arr[min] = arr[i];
        arr[i]   = tmp;
    }

    cout << "Отсортированный массив: " << endl;
    printArray(arr, size);

    return 0;
}

