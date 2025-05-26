#include <iostream>
#include <vector>

using namespace std;

// Функция бинарного поиска (возвращает индекс элемента или -1, если не найден)
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Чтобы избежать переполнения

        if (arr[mid] == target) {
            return mid;  // Элемент найден
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // Ищем в правой половине
        }
        else {
            right = mid - 1;  // Ищем в левой половине
        }
    }

    return -1;  // Элемент не найден
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> sortedNumbers = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int target;

    cout << "Отсортированный массив: ";
    for (int num : sortedNumbers) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Введите число для поиска: ";
    cin >> target;

    int result = binarySearch(sortedNumbers, target);

    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << endl;
    }
    else {
        cout << "Элемент не найден в массиве." << endl;
    }

    return 0;
}