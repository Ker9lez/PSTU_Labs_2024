#include <iostream>
#include <vector>

using namespace std;

// Функция разбиения Ломуто (выбирает последний элемент как опорный)
int lomutoPartition(vector<float>& arr, int low, int high) {
    float pivot = arr[high]; // Опорный элемент (pivot)
    int i = low - 1;         // Индекс меньшего элемента

    for (int j = low; j < high; ++j) {
        // Если текущий элемент <= pivot
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]); // Меняем местами
        }
    }
    swap(arr[i + 1], arr[high]); // Ставим pivot на правильное место
    return i + 1;                // Возвращаем индекс pivot
}

// Основная функция быстрой сортировки (схема Ломуто)
void quickSortLomuto(vector<float>& arr, int low, int high) {
    if (low < high) {
        // Получаем индекс pivot после разбиения
        int pivotIndex = lomutoPartition(arr, low, high);

        // Рекурсивно сортируем левую и правую части
        quickSortLomuto(arr, low, pivotIndex - 1);
        quickSortLomuto(arr, pivotIndex + 1, high);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Тестовый массив
    vector<float> arr = { 5.2, 1.8, 3.6, 2.4, 4.0, 9.1, 7.7, 0.5, 8.3, 6.9 };

    cout << "Исходный массив: ";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Вызов сортировки
    quickSortLomuto(arr, 0, arr.size() - 1);

    cout << "Отсортированный массив: ";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}