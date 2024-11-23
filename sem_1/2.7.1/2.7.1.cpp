#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n, k;
	cout << "Введите натуральное число, из которого можно извлечь целый корень: \n";
	cin >> n;
	k = sqrt(n);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}