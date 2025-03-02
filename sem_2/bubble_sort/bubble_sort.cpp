#include <iostream>
#include <cstdlib> 
#include <ctime>  
using namespace std;

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
    bubbleSort(arr, size);
    cout << "Отсортированный массив: ";
    printArray(arr, size);
    return 0;
}