#include <iostream>
#include <vector>

using namespace std;

// Функция для сортировки пузырьком (используем вместо std::sort)
void bubbleSort(vector<float>& bucket) {
    int n = bucket.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (bucket[j] > bucket[j + 1]) {
                swap(bucket[j], bucket[j + 1]);
            }
        }
    }
}

// Функция для блочной сортировки (работает с числами от 0 до 1)
void bucketSort(vector<float>& arr) {
    if (arr.empty()) return;

    // 1. Создаем "ведра" (блоки)
    vector<vector<float>> buckets(arr.size());

    // 2. Распределяем элементы по ведрам
    for (float num : arr) {
        int bucketIndex = arr.size() * num;
        buckets[bucketIndex].push_back(num);
    }

    // 3. Сортируем каждое ведро пузырьковой сортировкой
    for (auto& bucket : buckets) {
        bubbleSort(bucket);
    }

    // 4. Собираем элементы обратно в исходный массив
    int index = 0;
    for (const auto& bucket : buckets) {
        for (float num : bucket) {
            arr[index++] = num;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); // Для вывода кириллицы

    // Создаем массив для сортировки (числа от 0 до 1)
    vector<float> arr = { 0.42, 0.32, 0.75, 0.12, 0.89, 0.63, 0.51, 0.23, 0.91, 0.15 };

    cout << "Исходный массив: ";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Вызываем блочную сортировку
    bucketSort(arr);

    cout << "Отсортированный массив: ";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}