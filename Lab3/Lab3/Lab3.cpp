#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define SIZE 9
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    int a[SIZE][SIZE] = {
        {0, 7, 10, 0, 0, 0, 0, 0, 0},     // 1
        {7, 0, 0, 0, 0, 9, 27, 0, 0},     // 2
        {10, 0, 0, 0, 31, 8, 0, 0, 0},    // 3
        {0, 0, 0, 0, 32, 0, 0, 17, 21},   // 4
        {0, 0, 31, 32, 0, 0, 0, 0, 0},    // 5
        {0, 9, 8, 0, 0, 0, 0, 11, 0},     // 6
        {0, 27, 0, 0, 0, 0, 0, 0, 15},    // 7
        {0, 0, 0, 17, 0, 11, 0, 0, 15},   // 8
        {0, 0, 0, 21, 0, 0, 15, 15, 0}    // 9
    }
    ; // матрица связей
    int d[SIZE]; // минимальное расстояние
    int v[SIZE]; // посещенные вершины
    int temp, minindex, min;
    int begin_temp;
    cout << "Введите начальный индекс "; cin >> begin_temp;
    int begin_index = begin_temp - 1;
    system("chcp 1251");
    system("cls");
    // Вывод матрицы связей
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
    //Инициализация вершин и расстояний
    for (int i = 0; i < SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
    // Шаг алгоритма
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++)
        { // Если вершину ещё не обошли и вес меньше min
            if ((v[i] == 1) && (d[i] < min))
            { // Переприсваиваем значения
                min = d[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != 10000)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = min + a[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);
    // Вывод кратчайших расстояний до вершин
    printf("\nКратчайшие расстояния до вершин: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%5d ", d[i]);

    // Восстановление пути
    int ver[SIZE]; // массив посещенных вершин
    int end = 8; // индекс конечной вершины = 9 - 1
    ver[0] = end + 1; // начальный элемент - конечная вершина
    int k = 1; // индекс предыдущей вершины
    int weight = d[end]; // вес конечной вершины

    while (end != begin_index) // пока не дошли до начальной вершины
    {
        for (int i = 0; i < SIZE; i++) // просматриваем все вершины
            if (a[i][end] != 0)   // если связь есть
            {
                int temp = weight - a[i][end]; // определяем вес пути из предыдущей вершины
                if (temp == d[i]) // если вес совпал с рассчитанным
                {                 // значит из этой вершины и был переход
                    weight = temp; // сохраняем новый вес
                    end = i;       // сохраняем предыдущую вершину
                    ver[k] = i + 1; // и записываем ее в массив
                    k++;
                }
            }
    }
    // Вывод пути (начальная вершина оказалась в конце массива из k элементов)
    printf("\nВывод кратчайшего пути\n");
    for (int i = k - 1; i >= 0; i--)
        printf("%3d ", ver[i]);
    getchar(); getchar();
    return 0;
}