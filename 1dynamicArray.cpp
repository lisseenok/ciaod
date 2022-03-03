#include <iostream>
#include <math.h>

using namespace std;

// РЕАЛИЗАЦИЯ НА ДИНАМИЧЕСКОМ МАССИВЕ

// Функция для ввода в массив значений
void inputArray(long L[], int n)
{	cout<<"Введите "<< n <<" натуральных чисел:" << endl;
    for (int i = 0; i < n; ){
        cin >> L[i];
        if (L[i] > 0) i++;
    }
}

// Функция для вывода массива
void outputArray(long L[], int n, string phrase)
{
    cout << phrase << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "array[" << i << "]=" << L[i] <<endl;
    }
}

// Функция, определяющая простоту числа
bool isPrime(long n)
{
    for(long long i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

// Функция для определения количества простых чисел в массиве
int amountOfPrime(long array[], int n)
{
    int amount = 0;
    for (int i = 0; i < n; ++i) {
        if (isPrime(array[i]))
        {
            amount++;
        }
    }
    return amount;
}

// Функция для ?удаления? минимального (первого) элемента массива
void deleteMinimal(long array[], int n)
{
    for (int i = 0; i < n; ++i) {
        array[i] = array[i + 1];
    }
    outputArray(array, (n - 1), "Удалим минимальное число нового массива, получим массив");
}

// Функция для подсчета делителей числа
int numberOfDivisors(int n)
{
    int number = 0;
    for (int q = 1; q <= sqrt(n); q++)
    {
        if (n % q == 0) number += 2;
    }
    return number;
}

int main()
{
    // Получаем размер массива
    int n = 0;
    cout << "Введите длину массива" << endl;
    cin >> n;

    // Создаем массив
    long *array = new long[100];

    // Заполняем с клавиатуры и выводим
    inputArray(array, n);
    outputArray(array, n, "Исходный массив: ");

    // Сортируем
    sort(array, array + n);

    // Считаем количество простых чисел в исходном массиве
    int newLength = amountOfPrime(array, n);
    if (newLength == 0)
    {
        cout << "Простых чисел в массиве нет :(" << endl;
    } else
    {
        // Создаем новый массив по количеству простых чисел исходного
        long *newArray = new long[newLength];

        // Заполняем новый массив простыми числами исходного
        for (int i = 0; i < newLength; ++i) {
            if (isPrime(array[i]))
            {
                newArray[i] = array[i];
            }
        }

        // Выводим новый массив простых чисел
        outputArray(newArray, newLength, "Новый массив (из простых чисел исходного):");

        if (newLength > 1)
        {
            // Удаляем первый (минимальный элемент) и выводим массив
            deleteMinimal(newArray, newLength);
        } else
        {
            cout << "В массиве всего один элемент, поэтому удаление первого элемента дало пустой массив :с" << endl;
        }

    }

    // Считаем, у скольких элементов массива, количество делителей больше трех
    int amount = 0;
    for (int i = 0; i < n; ++i) {
        if (numberOfDivisors(array[i]) > 3) amount += 1;
    }
    cout << "Количество делителей больше трех у " << amount << " элемента(ов) исходного массива." << endl;

    delete[] array;
}


