#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите натуральное число: \n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}