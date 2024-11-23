#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, c, max;
    cout << "Введите 3 числа, по одному в каждой строке: \n";
    cin >> a >> b >> c;
    if (a >= b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    cout << max << endl;
    return 0;
}
