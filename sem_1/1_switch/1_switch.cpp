#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    float a, b, ans;
    int code;
    cout << "Введите 2 числа, по одному в каждой строке: \n";
    cin >> a >> b;
    cout << "Введите код операции (1 - '+', 2 - '-', 3 - '*', 4 - '/'): \n";
    cin >> code;
    switch (code)
    {
        case 1: ans = a + b; cout << ans << endl; break;
        case 2: ans = a - b; cout << ans << endl; break;
        case 3: ans = a * b; cout << ans << endl; break;
        case 4:
        {
            if (b == 0)
            {
                cout << "Деление на 0 невозможно" << endl;
                break;
            }
            else
            {
                ans = a / b;
                cout << ans << endl;
                break;
            }
        }
    default: cout << "Неверный код операции \n";
    }
    return 0;
}