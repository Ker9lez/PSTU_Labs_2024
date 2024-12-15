#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, tmp;
	bool flag_pos = false, flag_neg = false;
	cout << "Введите длину последовательности: \n";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		if (!flag_pos && !flag_neg && tmp != 0)
		{
			if (tmp > 0) {flag_pos = true;}
			else {flag_neg = true;}
		}
	}
	if (flag_pos) {cout << "Сначала ввели положительное число";}
	else if (flag_neg) {cout << "Сначала ввели отрицательное число";}
	else {cout << "Все элементы были нулевыми";}
	cout << endl;
	return 0;
}
