#include <iostream>
#include <vector>

using namespace std;

// Функция интерполяционного поиска
int interpolationSearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Формула интерполяции для определения позиции
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target) {
            return pos;  // Элемент найден
        }
        if (arr[pos] < target) {
            low = pos + 1;  // Ищем в правой части
        }
        else {
            high = pos - 1;  // Ищем в левой части
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

    int result = interpolationSearch(sortedNumbers, target);

    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << endl;
    }
    else {
        cout << "Элемент не найден в массиве" << endl;
    }

    return 0;
}