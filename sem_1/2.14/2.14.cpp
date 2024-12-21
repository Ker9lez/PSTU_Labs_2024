#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	int sum = 0;
	cout << "Введите число: \n";
	cin >> n;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	cout << "Сумма цифр числа равна - " << sum << endl;
	return 0;
}
