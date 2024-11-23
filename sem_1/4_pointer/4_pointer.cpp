#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, tmp, * ptr = &tmp, max, min;
	cout << "Введите длину последовательности:" << endl;
	cin >> n;
	cout << "Введите первое число:" << endl;
	cin >> *ptr;
	max = *ptr;
	min = *ptr;
	for (int i = 2; i <= n; i++)
	{
		cout << "Введите следующее число:" << endl;
		cin >> *ptr;
		if (*ptr > max) { max = *ptr; }
		else if (*ptr < min) { min = *ptr; }
	}
	cout << "Максимальный элемент равен: " << max << endl;
	cout << "Минимальный элемент равен: " << min << endl;
	return 0;
}