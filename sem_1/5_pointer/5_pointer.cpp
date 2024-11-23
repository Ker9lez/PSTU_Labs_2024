#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	unsigned int n, fact = 1;
	unsigned int* f = &fact;
	cout << "Введите число: \n";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		*f *= i;
	}
	cout << "Факториал " << n << " равен: " << fact << endl;
	return 0;
}