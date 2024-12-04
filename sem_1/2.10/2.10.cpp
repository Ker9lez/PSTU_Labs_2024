#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, a, max;
	cout << "Введите длину последовательности: \n";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите следующее число : \n";
		cin >> a;
		if (i == 1) { max = a; }
		else if (a > max) { max = a; }
	}
	cout << "Максимальный элемент равен - " << max << endl;
	return 0;
}
