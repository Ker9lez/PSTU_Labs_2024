#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, s, k;
	bool flag = false;
	cout << "Введите число и цифру: \n";
	cin >> n >> s;
	while (n > 0 && !flag)
	{
		k = n % 10;
		if (k == s)
		{
			flag = true;
			cout << "Цифра есть в числе" << endl;
		}
		else { n /= 10; }
	}
	if (!flag) { cout << "Цифры нет в числе" << endl; }
	return 0;
}
