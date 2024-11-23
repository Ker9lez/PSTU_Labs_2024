#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n, tmp, sum = 0;
	cout << "Введите число: \n";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		tmp = 1;
		for (int j = i; j <= 2 * i; j++)
		{
			tmp *= j;
		}
		sum += tmp;
	}
	cout << "Данная сумма равна - " << sum << endl;
	return 0;
}