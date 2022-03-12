#include <iostream>
#include <math.h>
#include <stdio.h>
#define ROWS 5
#define COLS 5


using namespace std;

// РЕАЛИЗАЦИЯ НА СТАТИЧЕСКОМ МАССИВЕ (вариант 28)

void input(int a[][COLS], int n, int m)
{
    int i, j;
    printf("Введите %d натуральных чисел/числа:\n", n * m);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)		//заполнение элементов i-ой строки
        {
            scanf("%d", &a[i][j]);
        }
    }

}

void randomInput(int a[][COLS], int n, int m)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)		//заполнение элементов i-ой строки
        {
            a[i][j] = rand();
        }
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

void transposition(int array[][COLS], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int temp = array[i][j];
            array[i][j] = array[n - j - 1][n - i - 1];
            array[n - j - 1][n - i - 1] = temp;
        }
    }
}



int main() {
    int n;
    int f;

    cout << "Введите количество строк в квадратной матрице матрице: " << endl;
    cin >> n;
    int array[ROWS][COLS];

    cout << "Введите 1, если хотите внести числа в матрицу самостоятельно, и 2 - если заполнить ее рандомными числами:" << endl;
    cin >> f;
    if (f == 1) input(array, n, n);
    else if (f == 2) randomInput(array, n, n);

    cout << "Исходная матрица: " << endl;
    output(array, n, n);

    transposition(array, n);

    cout << "Транспонированная матрица: " << endl;
    output(array, n, n);

    return 0;
}
