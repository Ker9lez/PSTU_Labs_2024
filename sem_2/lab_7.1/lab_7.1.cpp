#include <iostream>
#include <vector>

using namespace std;
int countSpecial(const vector<int>& arr)
{
    int count = 0;
    for (int num : arr)
    {
        if (num < 0) count++;
    }
    return count;
}

int countSpecial(const char* str)
{
    int count = 0;
    bool inWord = false;
    char firstChar = '\0';
    char prevChar = '\0';

    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (!inWord)
            {
                firstChar = str[i];
                inWord = true;
            }
            prevChar = str[i];
        }
        else
        {
            if (inWord)
            {
                if (firstChar == prevChar ||
                    (firstChar + 32 == prevChar) ||
                    (firstChar - 32 == prevChar))
                {
                    count++;
                }
                inWord = false;
            }
        }
    }
    if (inWord && (firstChar == prevChar ||
        (firstChar + 32 == prevChar) ||
        (firstChar - 32 == prevChar)))
    {
        count++;
    }

    return count;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int> numbers;
    int n, num;
    cout << "Введите количество элементов массива: ";
    cin >> n;
    cout << "Введите элементы массива через пробел: ";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        numbers.push_back(num);
    }
    cout << "Количество отрицательных элементов: " << countSpecial(numbers) << endl;
    cin.ignore();
    char text[100];
    cout << "Введите строку на латинице (до 100 символов): ";
    cin.getline(text, 100);
    cout << "Количество слов с одинаковыми первой и последней буквами: "
        << countSpecial(text) << endl;
    return 0;
}