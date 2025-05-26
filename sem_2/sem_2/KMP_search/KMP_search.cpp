#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Функция для построения префикс-функции (таблицы сдвигов)
vector<int> computePrefixFunction(const string& pattern) {
    int m = pattern.length();
    vector<int> prefix(m, 0);
    int k = 0;

    for (int q = 1; q < m; ++q) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        prefix[q] = k;
    }
    return prefix;
}

// Функция поиска KMP
vector<int> KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> prefix = computePrefixFunction(pattern);
    vector<int> occurrences;
    int q = 0;  // Количество совпавших символов

    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];  // Сдвигаем шаблон
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            occurrences.push_back(i - m + 1);  // Найдено вхождение
            q = prefix[q - 1];  // Продолжаем поиск
        }
    }
    return occurrences;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string text, pattern;

    cout << "Введите текст: ";
    getline(cin, text);

    cout << "Введите подстроку для поиска: ";
    getline(cin, pattern);

    vector<int> result = KMPSearch(text, pattern);

    if (result.empty()) {
        cout << "Подстрока не найдена." << endl;
    }
    else {
        cout << "Подстрока найдена в позициях: ";
        for (int pos : result) {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}