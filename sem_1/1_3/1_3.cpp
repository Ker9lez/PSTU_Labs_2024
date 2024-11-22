#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    float a, b;
    cout << "Введите число: \n";
    cin >> a;
    if (a < 5)
    {
        b = a * 3;
    }
    else if (a > 5 and a < 7)
    {
        b = a / 10;
    }
    else
    {
        b = a + 3;
    }
    cout << b << endl;
    return 0;
}