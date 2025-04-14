#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    char s[256];
    char processed[256];

    cout << "Введите строку (оканчивается точкой): ";
    cin.getline(s, 256);

    int j = 0;
    for (int i = 0; s[i] != '\0' && s[i] != '.'; i++) 
    {
        if (s[i] != ' ')
        {
            processed[j] = tolower(s[i]);
            j++;
        }
    }
    processed[j] = '\0';

    bool isPalindrome = true;
    int len = j;
    for (int i = 0; i < len / 2; i++)
    {
        if (processed[i] != processed[len - 1 - i])
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) 
    {
        cout << "Строка является палиндромом." << endl;
    }
    else 
    {
        cout << "Строка НЕ является палиндромом." << endl;
    }

    return 0;
}