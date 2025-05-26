#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Функция для создания таблицы плохих символов
unordered_map<char, int> buildBadCharTable(const string& pattern) {
    unordered_map<char, int> badChar;
    int m = pattern.length();

    for (int i = 0; i < m - 1; ++i) {
        badChar[pattern[i]] = m - 1 - i;
    }
    return badChar;
}

// Функция для создания таблицы хороших суффиксов
vector<int> buildGoodSuffixTable(const string& pattern) {
    int m = pattern.length();
    vector<int> goodSuffix(m, m);
    vector<int> borderPos(m + 1, 0);

    // Этап 1: Находим границы
    int i = m, j = m + 1;
    borderPos[i] = j;

    while (i > 0) {
        while (j <= m && pattern[i - 1] != pattern[j - 1]) {
            if (goodSuffix[j - 1] == m) {
                goodSuffix[j - 1] = j - i;
            }
            j = borderPos[j];
        }
        i--; j--;
        borderPos[i] = j;
    }

    // Этап 2: Заполняем оставшиеся значения
    j = borderPos[0];
    for (i = 0; i <= m; ++i) {
        if (goodSuffix[i] == m) {
            goodSuffix[i] = j;
        }
        if (i == j) {
            j = borderPos[j];
        }
    }

    return goodSuffix;
}

// Основная функция поиска Бойера-Мура
vector<int> boyerMooreSearch(const string& text, const string& pattern) {
    vector<int> occurrences;
    int n = text.length();
    int m = pattern.length();

    if (m == 0 || n < m) return occurrences;

    unordered_map<char, int> badChar = buildBadCharTable(pattern);
    vector<int> goodSuffix = buildGoodSuffixTable(pattern);

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            // Найдено совпадение
            occurrences.push_back(shift);
            shift += goodSuffix[0];
        }
        else {
            // Используем максимальный сдвиг из двух таблиц
            int badCharShift = badChar.count(text[shift + j]) ?
                max(1, badChar[text[shift + j]] - (m - 1 - j)) : m;
            shift += max(goodSuffix[j + 1], badCharShift);
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

    vector<int> result = boyerMooreSearch(text, pattern);

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