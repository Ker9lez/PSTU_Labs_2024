﻿#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите натуральное число больше 1: \n";
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		cout << "* ";
	}
	cout << endl;
	for (int i = 0; i < n - 2; i++)
	{
		cout << "* ";
		for (int j = 0; j < n - 2; j++)
		{
			cout << "  ";
		}
		cout << "* " << endl;;
	}
	for (int j = 0; j < n; j++)
	{
		cout << "* ";
	}
	cout << endl;
	return 0;
}