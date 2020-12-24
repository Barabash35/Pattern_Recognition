#include <iostream>
#include <stdio.h>
void fill(int A[81][9], int i, int j);              //функция заполнения начальной разметкой
void show(int A[81][9]);                            //функция вывода
bool check(int A[81][9]);                           //функция проверки на допустимость (проверка если все метки в объекте вычеркнуты)
void clear(int A[81][9], int B[81], int A2[81]);    //функция вычеркивания
void update(int A[81][9], int B[81]);               //функция обновления матрицы-указателя однозначно заполненых ячеек
void solution(int A[81][9], int d);       //функция выбора метки при поиске разметки
void copy(int A[81][9], int A3[81][9]);             //функция копирования разметки
void roleback(int A[81][9], int A3[81][9]);         //функция отката в случае неудачи при поиске разметки

void fill(int A[81][9], int i, int j)           //функция заполнения начальной разметкой
{
    for (int k = 0; k <= 8; k++) {
        if (A[i][k] != j) {
            A[i][k] = 0;
        }
    }
}

void show(int A[81][9])                         //функция вывода
{
    for (int i = 0; i <= 80; i++) {
        for (int j = 0; j <= 8; j++) {
            if (A[i][j] != 0) {
                cout << A[i][j];
            }
            else {
                cout << "-";
            }
        }
        cout << "   ";
        if ((i + 1) % 3 == 0) {
            cout << "|   ";
        }
        if ((i + 1) % 9 == 0) {
            cout << endl;
        }
        if ((i + 1) % 27 == 0) {
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
}

bool check(int A[81][9])                        //функция проверки на недопустимость имеющейся разметки
{
    int f = 0;
    for (int i = 0; i <= 80; i++) {
        for (int j = 0; j <= 8; j++) {
            if (A[i][j] == 0) {
                f++;
            }  
        }
        if (f == 9) {
            return false;
        }
        else {
            f = 0;
        }
    }
    return true;
}

void update(int A[81][9], int B[81])            //функция обновления матрицы-указателя однозначно заполненых ячеек
{
    int f = 0;
    for (int n = 0; n <= 80; n++) {
        for (int m = 0; m <= 8; m++) {
            if (A[n][m] == 0) {
                f++;
            }
        }
        B[n] = 0;
        if (f == 8 && B[n] == 0) {
            B[n] = 1;
        }
        f = 0;
    }
}
