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
            scanf("%d",&a[i][j]);
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



int main() {
    int n;
    cout << "Введите количество строк в квадратной матрице матрице: " << endl;
    cin >> n;
    int array[ROWS][COLS];
    randomInput(array, n, n);
    output(array, n, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int temp = array[i][j];
            array[i][j] = array[n - j - 1][n - i - 1];
            array[n - j - 1][n - i - 1] = temp;
        }
    }
    cout << "----------------------------------------------" << endl;

    output(array, n, n);

    return 0;
}
