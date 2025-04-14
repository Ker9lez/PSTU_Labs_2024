#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
int main() 
{
    srand(time(0));
    int size;
    cout << "Введите размер массива строк: ";
    cin >> size;
    cin.ignore();
    string* arr = new string[size];
    cout << "\nИсходный массив строк:\n";
    for (int i = 0; i < size; i++) 
    {
        int strLength = 3 + rand() % 5;
        for (int j = 0; j < strLength; j++) 
        {
            arr[i] += 'a' + rand() % 26;
        }
        cout << i << ": " << arr[i] << endl;
    }
    int indexToDelete;
    cout << "\nВведите номер строки для удаления (0-" << size - 1 << "): ";
    cin >> indexToDelete;
    if (indexToDelete < 0 || indexToDelete >= size) 
    {
        cout << "Ошибка: неверный номер строки!\n";
        delete[] arr;
        return 1;
    }
    string* newArr = new string[size - 1];
    for (int i = 0, j = 0; i < size; i++) 
    {
        if (i != indexToDelete) 
        {
            newArr[j] = arr[i];
            j++;
        }
    }
    cout << "\nМассив после удаления строки " << indexToDelete << ":\n";
    for (int i = 0; i < size - 1; i++) {
        cout << i << ": " << newArr[i] << endl;
    }
    delete[] arr;
    delete[] newArr;

    return 0;
}