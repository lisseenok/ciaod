#include <iostream>
/**
 * вариант 28
* пирамидальная сортировка
*/

using namespace std;

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

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

void heapify(int arr[], int n, int i)
{
    /**
     * Функция для построения max-heap
     */
    int largest = i;
// Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}


// Управляющая программа
int main()
{
    srand(time(0));

    int size = 0;
    cout << "Введите размер массива: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i != size; ++i)
        arr[i] = randomInt(-100, 100);

    cout << "Исходный массив: " << endl;

    printArray(arr, size);

    heapSort(arr, size);

    cout << "Отсортированный массив: " << endl;
    printArray(arr, size);
}

