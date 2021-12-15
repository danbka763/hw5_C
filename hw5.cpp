// Код написан на Visual Studio C++

#include <iostream>
#include <cstdlib> 
#include <math.h>


using namespace std;


int Random()
{
    srand(time(NULL) + rand());

    return rand() % 20 - 10;
}


// Среднее арифметическое значение
float Average(int* mass, unsigned n)
{
    float sum = 0;

    for (unsigned i = 0; i < n; i++)
        sum += mass[i];

    return sum/n;
}


// кол-во элементов, больших заданному
unsigned Count(int* mass, unsigned n, float min)
{
    unsigned count = 0;

    for (unsigned i = 0; i < n; i++)
        if (mass[i] > min) count++;

    return count;
}


// Сумма положительных элементов
unsigned Sum_unsigned_elems(int* mass, unsigned n)
{
    int sum = 0;

    for (unsigned i = 0; i < n; i++)
        if (mass[i] > 0) sum += mass[i];

    return sum;
}


int main()
{
    system("chcp 1251");
    system("cls");

    cout << "Работу выполнил Жигалин Данил Вадимович гр. 421-1, вариант 8\n" << endl;

    unsigned n, m;

    cout << "Введите n = ";
    cin >> n;
    cout << "Введите m = ";
    cin >> m;

    int* X = new int[n];
    int* Y = new int[m];
    
    // Заполняем массивы рандомными значениями и выводим их на экран
    cout << "\nX: [";
    for (unsigned i = 0; i < n; i++)
    {
        if (i) cout << ", ";
        X[i] = Random();
        cout << X[i];
    }
    cout << "]" << endl;

    cout << "Y: [";
    for (unsigned i = 0; i < m; i++)
    {
        if (i) cout << ", ";
        Y[i] = Random();
        cout << Y[i];
    }
    cout << "]" << endl;


    // A6(X) - среднее арифметическое значение элементов массива X;
    float A6 = Average(X, n);
    // М3(X) - количество элементов массива X, значения которых больше А6;
    unsigned M3 = Count(X, n, A6);
    
    // А8(Y) - корень квадратный из суммы положительных элементов массива Y;
    float A8 = sqrt( Sum_unsigned_elems(Y, m) );

    cout << "\nСреднее арифметическое значение массива X: " << A6 
         << "\nКол-во элементов массива Х, больших А6: " << M3 
         << "\nКв. корень от суммы положительных эл-ов массива Y: " << A8 << endl;

    
    cout << "\nОтвет: ";
    if (M3 < 7)
    {
        float A = A8 + 34.2 * 100 * cos(A8);
        float B = 18.3 * A8;
        cout << A / B << " (При M3(x) < 7)" << endl;
    }
    else 
    {
        cout << sqrt(A8 + 1.79 * M3) << " (При M3(x) >= 7)" << endl;
    }

    delete[] X, Y;
}