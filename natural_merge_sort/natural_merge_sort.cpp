#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Функция для разделения на серии и записи во временные файлы
void distributeRuns(const string& inputFile, vector<string>& tempFiles) {
    ifstream inFile(inputFile, ios::binary);
    int prev, current;
    int fileIndex = 0;

    // Создаем первые два временных файла
    tempFiles = { "temp1.dat", "temp2.dat" };
    ofstream outFiles[2];
    outFiles[0].open(tempFiles[0], ios::binary);
    outFiles[1].open(tempFiles[1], ios::binary);

    if (!inFile.read(reinterpret_cast<char*>(&prev), sizeof(int))) {
        // Файл пустой
        outFiles[0].close();
        outFiles[1].close();
        return;
    }
    outFiles[fileIndex].write(reinterpret_cast<char*>(&prev), sizeof(int));

    while (inFile.read(reinterpret_cast<char*>(&current), sizeof(int))) {
        if (current < prev) {
            // Конец серии, переключаемся на другой файл
            fileIndex = 1 - fileIndex;
        }
        outFiles[fileIndex].write(reinterpret_cast<char*>(&current), sizeof(int));
        prev = current;
    }

    outFiles[0].close();
    outFiles[1].close();
    inFile.close();
}

// Функция для слияния серий из двух файлов в один
void mergeFiles(const string& inFile1, const string& inFile2, const string& outFile) {
    ifstream in1(inFile1, ios::binary);
    ifstream in2(inFile2, ios::binary);
    ofstream out(outFile, ios::binary);

    int val1, val2;
    bool hasVal1 = static_cast<bool>(in1.read(reinterpret_cast<char*>(&val1), sizeof(int)));
    bool hasVal2 = static_cast<bool>(in2.read(reinterpret_cast<char*>(&val2), sizeof(int)));

    while (hasVal1 && hasVal2) {
        if (val1 <= val2) {
            out.write(reinterpret_cast<char*>(&val1), sizeof(int));
            hasVal1 = static_cast<bool>(in1.read(reinterpret_cast<char*>(&val1), sizeof(int)));
        }
        else {
            out.write(reinterpret_cast<char*>(&val2), sizeof(int));
            hasVal2 = static_cast<bool>(in2.read(reinterpret_cast<char*>(&val2), sizeof(int)));
        }
    }

    // Дописываем оставшиеся элементы
    while (hasVal1) {
        out.write(reinterpret_cast<char*>(&val1), sizeof(int));
        hasVal1 = static_cast<bool>(in1.read(reinterpret_cast<char*>(&val1), sizeof(int)));
    }
    while (hasVal2) {
        out.write(reinterpret_cast<char*>(&val2), sizeof(int));
        hasVal2 = static_cast<bool>(in2.read(reinterpret_cast<char*>(&val2), sizeof(int)));
    }

    in1.close();
    in2.close();
    out.close();
}

// Основная функция естественной сортировки
void naturalMergeSort(const string& inputFile, const string& outputFile) {
    vector<string> tempFiles;
    int phase = 0;

    while (true) {
        // Распределение серий по файлам
        if (phase == 0) {
            distributeRuns(inputFile, tempFiles);
        }
        else {
            vector<string> newTempFiles = { "temp3.dat", "temp4.dat" };
            mergeFiles(tempFiles[0], tempFiles[1], newTempFiles[phase % 2]);
            tempFiles = newTempFiles;
        }

        // Проверка, осталась ли только одна серия
        ifstream test(tempFiles[1], ios::binary);
        int dummy;
        if (!test.read(reinterpret_cast<char*>(&dummy), sizeof(int))) {
            // Все данные в одном файле - сортировка завершена
            rename(tempFiles[0].c_str(), outputFile.c_str());
            break;
        }
        test.close();

        phase++;
    }

    // Удаляем временные файлы
    remove("temp1.dat");
    remove("temp2.dat");
    remove("temp3.dat");
    remove("temp4.dat");
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Создаем тестовый файл с данными
    ofstream out("input.dat", ios::binary);
    vector<int> testData = { 12, 3, 45, 23, 6, 78, 34, 21, 9, 1, 65, 32, 17, 28, 54 };
    out.write(reinterpret_cast<const char*>(testData.data()), testData.size() * sizeof(int));
    out.close();

    // Выполняем сортировку
    naturalMergeSort("input.dat", "output.dat");

    // Читаем и выводим результат
    ifstream in("output.dat", ios::binary);
    vector<int> result(testData.size());
    in.read(reinterpret_cast<char*>(result.data()), testData.size() * sizeof(int));

    cout << "Отсортированный массив: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Удаляем тестовые файлы
    remove("input.dat");
    remove("output.dat");

    return 0;
}