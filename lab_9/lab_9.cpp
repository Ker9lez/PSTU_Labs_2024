#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

// Функция для проверки, есть ли в строке одинаковые слова
bool hasSameWords(const string& line) {
    vector<string> words;
    string word;
    istringstream iss(line);

    // Разбиваем строку на слова
    while (iss >> word) {
        words.push_back(word);
    }

    // Проверяем есть ли одинаковые слова
    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = i + 1; j < words.size(); ++j) {
            if (words[i] == words[j]) {
                return true;
            }
        }
    }
    return false;
}

// Функция для подсчета гласных букв в строке
int countVowels(const string& line) {
    int count = 0;
    const string vowels = "aeiouyAEIOUY"; // Учитываем и заглавные буквы

    for (char c : line) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Создаем файл F1 и записываем в него информацию
    ofstream f1("F1.txt");
    if (!f1.is_open()) {
        cerr << "Не удалось создать файл F1.txt" << endl;
        return 1;
    }

    // Записываем несколько строк в файл F1
    f1 << "Hello world world\n";
    f1 << "This is a test\n";
    f1 << "C++ programming is fun fun\n";
    f1 << "No duplicates here\n";
    f1 << "Apple apple are not the same\n";
    f1 << "Repeat repeat is a word\n";
    f1 << "All words are unique in this line\n";
    f1 << "Same Same words here\n";
    f1 << "The quick brown fox\n";
    f1 << "Last line of the file\n";
    f1.close();

    // Открываем файлы F1 для чтения и F2 для записи
    ifstream inFile("F1.txt");
    ofstream outFile("F2.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Не удалось открыть файлы" << endl;
        return 1;
    }

    string line;
    vector<string> f2Lines; // Сохраним строки F2 для проверки последней строки

    // Копируем строки с одинаковыми словами из F1 в F2
    while (getline(inFile, line)) {
        if (hasSameWords(line)) {
            outFile << line << endl;
            f2Lines.push_back(line);
        }
    }

    inFile.close();
    outFile.close();

    // Проверяем, есть ли строки в F2
    if (f2Lines.empty()) {
        cout << "В файле F2 нет строк (в F1 не было строк с одинаковыми словами)" << endl;
        return 0;
    }

    // Получаем последнюю строку F2
    string lastLine = f2Lines.back();
    int vowelCount = countVowels(lastLine);

    cout << "Последняя строка в F2: \"" << lastLine << "\"" << endl;
    cout << "Количество гласных букв в последней строке F2: " << vowelCount << endl;

    return 0;
}