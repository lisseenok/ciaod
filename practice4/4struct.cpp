#include <vector>
#include <iomanip>
#include "iostream"
#define ROWS 100
#define COLS 4

using namespace std;

// вариант 28
struct Student{
    string studentBook;
    string firstTask;
    string secondTask;
    string thirdTask;
};

// 1) Заполнение данных по заданному заданию заданного студента с клавиатуры.
Student addStudent(){
    Student student;
    string buffer;

    cout << "Введите номер зачетной книжки студента: " << endl;
    cin >> buffer;
    student.studentBook = buffer;

    cout << "Введите балл за задачу 1: " << endl;
    cin >> buffer;
    student.firstTask = buffer;

    cout << "Введите балл за задачу 2: " << endl;
    cin >> buffer;
    student.secondTask = buffer;

    cout << "Введите балл за задачу 3: " << endl;
    cin >> buffer;
    student.thirdTask = buffer;


    return student;
}

// 2) Вставить запись по студенту в начало таблицы.
vector<vector<string>> addStudentInArray(Student student, vector<vector<string>> array, int n){
    vector<string> studentData(4);
    auto iter1 = array.cbegin();
    vector<string> temp;
    studentData[0] = student.studentBook;
    studentData[1] = student.firstTask;
    studentData[2] = student.secondTask;
    studentData[3] = student.thirdTask;

    array.insert(iter1, studentData);
    return array;

}

// 3) Удалить записи по заданному студенту.
vector<vector<string>> deleteStudent(string studentBook, vector<vector<string>> array, int n){
    for (int i = 0; i < n; ++i) {
        if (array[i][0] == studentBook) array.erase(array.begin() + i);
    }
    return array;
}

void printArray(vector<vector<string>> vector, int n){
    cout <<  "Номер студента "  << "      Задача 1"  << "       Задача 2" <<  "       Задача 3" << endl;
    int i;
    int j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 4; j++)
            cout << setw(14) << vector[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void output(int **a, int n, int m)
{
    int i, j;
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < m; j++)		//вывод i-ой строки
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");			//переход на другую строку
    }


}

void output(int a[][COLS], int n, int m)
{
    int i, j;
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < m; j++)		//вывод i-ой строки
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");			//переход на другую строку
    }


}



int main(){
    vector<vector<string>> array;
    int n;
    string buff;

    cout << "Введите количество студентов: " << endl;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Student student = addStudent();
        array = addStudentInArray(student, array, n);
    }


    printArray(array, n);

    cout << "Введите номер зачетной книжки студента, которого необходимо удалить: " << endl;
    cin >> buff;
    array = deleteStudent(buff, array, n);


    printArray(array, (n - 1));


    return 0;
}
