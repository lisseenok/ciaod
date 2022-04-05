#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>

/**
 * Дан текст, содержащий слова, которые разделены пробелами.
 * Сформировать массив слов. Найти пары слов (анаграммы)- при прочтении каждого из которых в
 * обратном порядке образуется другое слово этой пары, например, ТОК,КОТ; ПОЛК, КЛОП; БАР, РАБ.
 * Сформировать двумерный массив этих пар.
 */
using namespace std;

string reverse(string a){
    string res;
    for (int i = a.length() - 1; i >= 0; --i) {
        res += a[i];
    }
    return res;
}
int main()
{
    string text = "kot polk tok mama bar rab sosiska";
    vector<string> vec;
    vector<vector<string>> result;
    string buffer;

    for (int i = 0; i < text.size(); ++i) {
        if (text[i] != ' ') {
            buffer += text[i];
        }else{
            vec.push_back(buffer);
            buffer = "";
        }
    }
    vec.push_back(buffer);

    cout << "Исходный список слов:" << endl;
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }


    vector<string> buff;
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            if (vec[i] != vec[j]){
                if (reverse(vec[i]) == vec[j]){
                    buff.push_back(vec[i]);
                    buff.push_back(vec[j]);
                    result.push_back(buff);
                    buff.clear();
                }
            }
        }
    }

    cout << "Пары анаграммы: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



