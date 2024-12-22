#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float n, s, a;
	int i = 1;
	bool flag = false;
	cout << "Введите 2 числа: \n";
	cin >> n >> s;
	while (i <= n && !flag)
	{
		a = sin(n + i / n);
		if (a == s) { flag = true; }
		else { i++; }
	}
	if (flag)
	{
		cout << "Элемент найден" << endl;
	}
	else
	{
		cout << "Элемент не найден" << endl;
	}
	return 0;
}
