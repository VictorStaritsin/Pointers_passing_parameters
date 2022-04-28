/*
Задание 2. Написать функцию, которая получает 
указатель на динамический массив и его размер. Функция
должна удалить из массива все простые числа и вернуть
указатель на новый динамический массив.
*/

#include<iostream>
#include <cmath>
using namespace std;

bool prostae_chislo(int n) {
    bool result(true);

    if ((n == 2) || (n == 3))
        result = true;
    else {
        for (int i = 2; i <= floor(sqrt(n)); ++i)
            if (n % i == 0)
            {
                result = false;
                break;
            }
    }
    return (result && (n != 1));
}

int* proverca(int* A, int size) {

    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (!prostae_chislo(A[i]))
            ++count;
    }

    int* B = new int[count];

    int j = 0;
    for (int i = 0; i < size; ++i)
        if (!prostae_chislo(A[i]))
            B[j++] = A[i];

    for (int j = 0; j < count; j++)
        cout << B[j] << " ";
    return B;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    int* A = new int[size];
    cout << "Заполните массив через пробел: ";
    for (int i = 0; i < size; i++)
        cin >> A[i];
    int* res = proverca(A, size);

    delete[]A;
    delete[]res;
    return 0;
}
