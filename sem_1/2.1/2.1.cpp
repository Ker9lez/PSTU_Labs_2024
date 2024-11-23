#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, sum = 0;
	cout << "Введите число: \n";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	cout << "Сумма " << n << " первых чисел равна: " << sum << endl;
	return 0;
}