#include <vector>
#include "iostream"

using namespace std;

// РЕАЛИЗАЦИЯ НА ВЕКТОРЕ (вариант 22 потомушто 28 сложный простите)

int main()
{
    int i, j, n, m;
//создаем массив
    cout << "введи число уравнений: ";
    cin >> n;
    cout << "введи число неизвестных: ";
    cin >> m;
    m+=1;

    vector<vector<int>> matrix(n, vector<int>(m));

//инициализируем

    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)
        {
            cout << "Элемент " << "[" << i + 1 << " , " << j + 1 << "]: " ;

            cin >> matrix[i][j];
        }

    //выводим вектор
    cout << "matrix: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;

//Метод Гаусса
//Прямой ход, приведение к верхнетреугольному виду
    float  tmp, xx[m];
    int k;

    for (i = 0; i < n; i++)
    {
        tmp = matrix[i][i];
        for (j = n; j >= i; j--)
            matrix[i][j] /= tmp;
        for (j = i + 1; j < n; j++)
        {
            tmp = matrix[j][i];
            for (k = n; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
    }
    /*обратный ход*/
    xx[n - 1] = matrix[n - 1][n];
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j];
    }

//Выводим решения
    for (i = 0; i < n; i++)
        cout << xx[i] << " ";
    cout << endl;
    return 0;
}