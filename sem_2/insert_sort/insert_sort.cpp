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
void insertionSort(int arr[], int size) 
{
    for (int i = 1; i < size; ++i) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, size);
    cout << "Отсортированный массив: ";
    printArray(arr, size);
    return 0;
}