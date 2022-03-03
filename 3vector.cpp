#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// РЕАЛИЗАЦИЯ НА ВЕКТОРЕ

// Функция для ввода в вектор значений
vector<long> inputArray(vector<long> vec, int n)
{	cout<<"Введите "<< n <<" натуральных чисел:" << endl;
    long buffer = 0;
    for (int i = 0; i < n; ){
        cin >> buffer;
        if (buffer > 0) {
            vec.push_back(buffer);
            i++;
        }
    }
    return vec;

}

// Функция для вывода вектора
void outputArray(vector<long> vec, string phrase)
{
    cout << phrase << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        //cout << vec[i] << endl;
        cout << "vector[" << i << "]=" << vec[i] << endl;
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

// Функция для определения количества простых чисел в векторе
int amountOfPrime(vector<long> vec, int n)
{
    int amount = 0;
    for (int i = 0; i < n; ++i) {
        if (isPrime(vec[i]))
        {
            amount++;
        }
    }
    return amount;
}

// Функция для удаления минимального (первого) элемента вектора
vector<long> deleteMinimal(vector<long> vec)
{
    vec.erase(vec.begin());
    return vec;
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
    // Получаем размер вектора
    int n = 0;
    cout << "Введите длину вектора: " << endl;
    cin >> n;

    // Создаем вектор
    vector<long> array;

    // Заполняем с клавиатуры и выводим
    array = inputArray(array, n);

    outputArray(array, "Исходный вектор: ");

    // Сортируем
    sort(array.begin(), array.end());

    // Считаем количество простых чисел в исходном векторе
    int newLength = amountOfPrime(array, n);
    if (newLength == 0)
    {
        cout << "Простых чисел в векторе нет :(" << endl;
    } else
    {
        // Создаем новый вектор по количеству простых чисел исходного
        vector <long> newArray(newLength);

        // Заполняем новый вектор простыми числами исходного
        for (int i = 0; i < newLength; ++i) {
            if (isPrime(array[i]))
            {
                newArray[i] = array[i];
            }
        }

        // Выводим новый вектор простых чисел
        outputArray(newArray, "Новый вектор (из простых чисел исходного):");

        if (newLength > 1)
        {
            // Удаляем первый (минимальный элемент) и выводим вектор
            newArray = deleteMinimal(newArray);
            outputArray(newArray, "Удалим минимальное число нового вектора, получим вектор: ");
        } else
        {
            cout << "В векторе всего один элемент, поэтому удаление первого элемента дало пустой вектор :с" << endl;
        }

    }

    // Считаем, у скольких элементов вектора, количество делителей больше трех
    int amount = 0;
    for (int i = 0; i < n; ++i) {
        if (numberOfDivisors(array[i]) > 3) amount += 1;
    }
    cout << "Количество делителей больше трех у " << amount << " элемента(ов) исходного массива." << endl;

}


