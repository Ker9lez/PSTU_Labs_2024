#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите натуральное число больше 2: \n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < n - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}