#include <iostream>
#include <vector>

using namespace std;

// Функция для слияния двух отсортированных подмассивов
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создаем временные подмассивы
    vector<int> L(n1), R(n2);

    // Копируем данные во временные подмассивы
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Слияние временных подмассивов обратно в arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы L[], если они есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы R[], если они есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Рекурсивная функция сортировки слиянием
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Находим среднюю точку
        int mid = left + (right - left) / 2;

        // Сортируем первую и вторую половины
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Сливаем отсортированные половины
        merge(arr, left, mid, right);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Фиксированный тестовый массив
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    cout << "Исходный массив: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    // Вызов сортировки
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Отсортированный массив: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}