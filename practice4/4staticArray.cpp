#include <vector>
#include "iostream"
#define ROWS 100
#define COLS 5

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
void addStudentInArray(Student student, vector<vector<string>> array, int n){
    vector<string> studentData(4);
    vector<string> temp;
    studentData[0] = student.studentBook;
    studentData[1] = student.firstTask;
    studentData[2] = student.secondTask;
    studentData[3] = student.thirdTask;

    for (int i = 0; i < n - 1; ++i) {
        temp = array[i + 1];
        array[i + 1] = array[i];
        array[i] = temp;
    }
    array[0] = studentData;

}

void printArray(vector<vector<string>> vector, int n){
    int i;
    int j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 4; j++)
            cout << vector[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}



int main(){
    vector<vector<string>> array;
    int n;

    cout << "Введите количество студентов: " << endl;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Student student = addStudent();
        addStudentInArray(student, array, n);
    }

    printArray(array, n);


    return 0;
}
