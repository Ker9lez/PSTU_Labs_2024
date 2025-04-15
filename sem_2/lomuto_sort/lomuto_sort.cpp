#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ARRAY_SIZE = 10;

void initializeRandomArray(int array[], int size)
{
    if (size < 2)
    {
        cerr << "Ошибка: размер массива должен быть не менее 2 элементов" << endl;
        exit(EXIT_FAILURE);
    }

    srand(time(nullptr));
    cout << "Исходный массив:" << endl;

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
        cout << array[i] << " ";
    }
    cout << endl;
}

int partition(int array[], int startIndex, int endIndex)
{
    int pivotValue = array[endIndex];
    int partitionIndex = startIndex;

    for (int currentIndex = startIndex; currentIndex < endIndex; currentIndex++)
    {
        if (array[currentIndex] <= pivotValue) {
            swap(array[currentIndex], array[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(array[partitionIndex], array[endIndex]);
    return partitionIndex;
}

void quickSort(int array[], int startIndex, int endIndex)
{
    if (startIndex >= endIndex) return;

    int pivotIndex = partition(array, startIndex, endIndex);
    quickSort(array, startIndex, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, endIndex);
}

void printArray(const int array[], int size)
{
    cout << "Отсортированный массив:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int numbers[ARRAY_SIZE];

    initializeRandomArray(numbers, ARRAY_SIZE);
    quickSort(numbers, 0, ARRAY_SIZE - 1);
    printArray(numbers, ARRAY_SIZE);

    return EXIT_SUCCESS;
}