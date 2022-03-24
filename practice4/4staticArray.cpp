#include <vector>
#include "iostream"
#define ROWS 100
#define COLS 5

using namespace std;

// вариант 28
struct Student{
    string studentBook;
    string numberOfTask;
    string firstTask;
    string secondTask;
    string thirdTask;
};

// 1) Заполнение данных по заданному заданию заданного студента с клавиатуры.
void addStudent(){
    Student student;
    int buffer;

    cout << "Введите номер зачетной книжки студента: " << endl;
    cin >> buffer;
    student.studentBook = buffer;

    cout << "Введите номер задания: " << endl;
    cin >> buffer;
    student.numberOfTask = buffer;

    cout << "Введите балл за это задание: " << endl;
    cin >> buffer;
    student.studentBook = buffer;

    if (student.numberOfTask == "1") student.firstTask = buffer;
    else if (student.numberOfTask == "2") student.secondTask = buffer;
    else student.thirdTask = buffer;
}

// 2) Вставить запись по студенту в начало таблицы.
void addStudentInArray(Student student, string array[ROWS][5]){
    string studentData[5];
    studentData[0] = student.studentBook;
    studentData[1] = student.numberOfTask;
    studentData[2] = student.firstTask;
    studentData[3] = student.secondTask;
    studentData[4] = student.thirdTask;

    array[0] = studentData;
}
