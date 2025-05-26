#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Начинаем с большого шага, затем уменьшаем его
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Делаем сортировку вставками для этого шага
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Сдвигаем элементы, пока не найдем правильное место для arr[i]
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Фиксированный тестовый массив
    vector<int> arr = { 12, 34, 54, 2, 3, 8, 5, 1, 19, 23 };

    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Вызов сортировки Шелла
    shellSort(arr);

    cout << "Отсортированный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}