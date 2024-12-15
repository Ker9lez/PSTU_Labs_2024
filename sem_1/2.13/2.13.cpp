#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float a, b, c, D, x1, x2;
	cout << "Введите коэффициенты уравнения: \n";
	cin >> a >> b >> c;
	D = pow(b, 2) - 4 * a * c;
	if (D >= 0)
	{
		x1 = (-1 * b + sqrt(D)) / (2 * a);
		x2 = (-1 * b - sqrt(D)) / (2 * a);
		cout << "Корни уравнения равны - " << x1 << ", " << x2 << endl;
	}
	else
	{
		cout << "Корней нет" << endl;
	}
	return 0;
}
