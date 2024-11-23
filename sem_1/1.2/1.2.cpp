#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    float a, b;
    cout << "Введите 2 числа, по одному в каждой строке: \n";
    cin >> a >> b;
    if (b == 0)
    {
        cout << "На ноль делить нельзя!" << endl;
    }
    else
    {
        cout << a / b << endl;
    }
    return 0;
}
