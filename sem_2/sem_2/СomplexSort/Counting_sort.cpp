#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Находим минимальное и максимальное значения в массиве
    int minVal = arr[0];
    int maxVal = arr[0];
    for (int num : arr) {
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }

    // Создаем массив для подсчета частот
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);

    // Подсчитываем количество каждого элемента
    for (int num : arr) {
        count[num - minVal]++;
    }

    // Перезаписываем исходный массив в отсортированном порядке
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i] > 0) {
            arr[index++] = i + minVal;
            count[i]--;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Фиксированный тестовый массив (целые числа)
    vector<int> arr = { 4, 2, 2, 8, 3, 3, 1, 5, 9, 6 };

    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Сортируем массив
    countingSort(arr);

    cout << "Отсортированный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}