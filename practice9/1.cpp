#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "ctime"
/**
 * Фибоначчи поиск
*/
using namespace std;

struct City{
    int key;
    string name;
    City(int key, string name){
        this->name = name;
        this->key = key;
    }
};

int first_search(int find_key, vector<City> cities) {

    /**
    * линейный поиск методом "грубой силы"
    */
    int index = 0;
    for (int i = 0; i < cities.size(); ++i) {
        if (cities[i].key == find_key){
            index = i;
            break;
        }
    }

    return index;
}

int second_search(int find_key, vector<City> cities){

    /**
    * поиск с барьером
    */
    int size = cities.size();

    if (size != 0) {
        int last = cities[size - 1].key;//Сохраним прежний элемент массива
        cities[size - 1].key = find_key;//Гарантируем, что value есть в массиве
        //Есть гарантия того, что элемент есть в массиве, значит индекс можно не проверять
        size_t i = 0;
        for (i = 0; cities[i].key != find_key; ++i) {//Одно условие в цикле
        }
        cities[size - 1].key = last;//Восстанавливаем последний элемент
        if (i != (size - 1) || find_key == last) {//Не уткнулись в барьер или последний элемент был искомым
            return i;
        }
    }
    return std::numeric_limits<size_t>::max();
}

int third_search(int find_key, vector<City> cities){
    /**
    Интерполяционный поиск
     */
    int mid, left = 0, right = cities.size() - 1;
    while (cities[left].key <= find_key && cities[right].key >= find_key)
    {
        mid = left + ((find_key - cities[left].key) * (right-left)) / (cities[right].key - cities[left].key);
        if (cities[mid].key < find_key) left = mid + 1;
        else if (cities[mid].key > find_key) right = mid - 1;
        else return mid;
    }
    if (cities[left].key == find_key) return left;
    else return -1;
}

int main(){
    int find_key, key;
    string name;
    vector<City> cities;

    cout << "Введите ключ: " << endl;
    cin >> find_key;

    ifstream file("cities.txt");


    if (file.is_open()) while (file >> key >> name) cities.emplace_back(key, name);;
    file.close();


    cout << "-----------------------------" << endl;
    cout << "Исходная таблица: " << endl;

    cout << "Key       Name" << endl;
    for (int i = 0; i < 9; ++i) {
        cout << left << setw(10) << cities[i].key << cities[i].name << endl;
    }

    cout << "-----------------------------" << endl;


    cout << "Алгоритм: линейный поиск методом \"грубой силы\"" << endl;
    unsigned int start_time = clock();
    cout << "Найденная позиция: " << first_search(find_key, cities) << endl;
    unsigned int end_time = clock();
    cout << "Время нахождения: " << end_time - start_time << endl;

    cout << "-----------------------------" << endl;

    cout << "Алгоритм поиск с барьером: " << endl;
    start_time = clock();
    cout << "Найденная позиция: " << second_search(find_key, cities) << endl;
    end_time = clock();
    cout << "Время нахождения: " <<  end_time - start_time << endl;

    cout << "-----------------------------" << endl;

    cout << "Алгоритм: Интерполяционный поиск" << endl;
    start_time = clock();
    cout << "Найденная позиция: " << third_search(find_key, cities) << endl;
    end_time = clock();
    cout << "Время нахождения: " <<  end_time - start_time << endl;
    return 0;
}
