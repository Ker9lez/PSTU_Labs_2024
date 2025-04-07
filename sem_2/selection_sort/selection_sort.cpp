#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void fillArray(int arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = rand() % 100;
    }
}
void printArray(const int arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selectionSort(int arr[], int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    const int size = 10;
    int arr[size];
    fillArray(arr, size);
    cout << "Исходный массив: ";
    printArray(arr, size);
    selectionSort(arr, size);
    cout << "Отсортированный массив: ";
    printArray(arr, size);
    return 0;
}