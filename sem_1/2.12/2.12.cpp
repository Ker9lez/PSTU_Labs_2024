#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, tmp, max, min;
	cout << "Введите длину последовательности: \n";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите следующее число: \n";
		cin >> tmp;
		if (i == 1)
		{
			min = tmp;
			max = tmp;
		}
		else
		{
			if (tmp > max)
			{
				max = tmp;
			}
			else if (tmp < min)
			{
				min = tmp;
			}
		}
	}
	cout << "Сумма максимального и минимального чисел равна - " << max + min << endl;
	return 0;
}
