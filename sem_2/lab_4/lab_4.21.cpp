#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printLeft(const int ring[], int size, int K)
{
    int index = K % size;
    for (int i = 0; i < size; ++i) 
    {
        cout << ring[(index - i + size) % size] << " ";
    }
    cout << endl;
}

void printRight(const int ring[], int size, int K)
{
    int index = K % size;
    for (int i = 0; i < size; ++i) 
    {
        cout << ring[(index + i) % size] << " ";
    }
    cout << endl;
}

int main() 
{
    setlocale (LC_ALL, "Russian");
    srand(time(0));
    const int size = 5;
    int ring[size];
    for (int i = 0; i < size; ++i) 
    {
        ring[i] = rand() % 100;
    }
    cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) 
    {
        cout << ring[i] << " ";
    }
    cout << endl;
    int K;
    cout << "Введите число K (от 0 до " << size - 1 << "): ";
    cin >> K;
    if (K < 0 || K >= size) 
    {
        cout << "Ошибка: K должно быть в диапазоне от 0 до " << size - 1 << endl;
        return 1;
    }

    cout << "Печать массива влево: ";
    printLeft(ring, size, K);

    const int newSize = size + 4;
    int newRing[newSize];

    for (int i = 0; i < size; ++i) 
    {
        newRing[i] = ring[i];
    }

    newRing[size] = ring[0];

    newRing[size + 1] = ring[size - 1];
    newRing[size + 2] = ring[size - 2];
    newRing[size + 3] = ring[size - 3];

    cout << "Печать массива вправо: ";
    printRight(newRing, newSize, K);

    return 0;
}