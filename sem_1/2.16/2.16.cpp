﻿#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	int sum = 0;
	cout << "Введите число: \n";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0) { sum += i; }
		else { sum -= i; }
	}
	cout << sum << endl;
	return 0;
}
