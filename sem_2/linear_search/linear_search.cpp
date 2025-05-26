#include <iostream>
#include <vector>

using namespace std;

// Функция линейного поиска
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;  // Возвращаем индекс найденного элемента
        }
    }
    return -1;  // Элемент не найден
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> numbers = { 4, 2, 7, 1, 9, 5, 3, 8, 6 };
    int target;

    cout << "Массив: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Введите число для поиска: ";
    cin >> target;

    int result = linearSearch(numbers, target);

    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << endl;
    }
    else {
        cout << "Элемент не найден в массиве" << endl;
    }

    return 0;
}