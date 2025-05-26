#include <iostream>
#include <vector>

using namespace std;

// Функция для разделения массива (схема Хоара)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[(low + high) / 2];  // Опорный элемент (середина массива)
    int i = low - 1;                    // Индекс левого указателя
    int j = high + 1;                   // Индекс правого указателя

    while (true) {
        // Находим элемент слева, который больше опорного
        do {
            i++;
        } while (arr[i] < pivot);

        // Находим элемент справа, который меньше опорного
        do {
            j--;
        } while (arr[j] > pivot);

        // Если указатели пересеклись
        if (i >= j) {
            return j;
        }

        // Меняем местами неотсортированные элементы
        swap(arr[i], arr[j]);
    }
}

// Основная функция быстрой сортировки
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Получаем индекс разделения
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы до и после разделения
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Фиксированный тестовый массив
    vector<int> arr = { 10, 7, 8, 9, 1, 5, 3, 2, 4, 6 };

    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Вызов сортировки Хоара
    quickSort(arr, 0, arr.size() - 1);

    cout << "Отсортированный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}