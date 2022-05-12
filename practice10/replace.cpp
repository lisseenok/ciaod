#include <iostream>
#include <string>

/**
2) Дан текст, содержащий адреса сайтов. Заменить в тексте в доменных имена России ru на рус.
*/
using namespace std;

int main()
{
    string text;
    string str1 = ".ru";
    string str2 = ".рус";
    long sPos;

    cout<<"Введите текст: " << endl;
    getline(cin,text);
    cin.ignore();

    while((sPos = text.find(str1,0)) != string::npos)
        text.replace(sPos,str1.length(),str2);
    cout<<"Обработанный тест:" << endl << text <<endl;

    return 0;
}

// test: mos.ru google.com gosuslugi.ru vk.com vk.ru

