#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, d, max = 0;
	cout << "Введите длину последовательности: \n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите число - ";
		cin >> d;
		if (d > max)
		{
			max = d;
		}
	}
	cout << max << endl;
	return 0;
}