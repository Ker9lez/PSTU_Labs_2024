#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n, fact = 1;
	cout << "Введите число: \n";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}
	cout << "Произведение " << n << " первых чисел равно: " << fact << endl;
	return 0;