#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите натуральное нечетное число больше 3: \n";
	cin >> n;
	int spaces = n / 2, stars = 1;
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = 0; j < spaces; j++)
		{
			cout << " ";
		}
		spaces--;
		for (int j = 0; j < stars; j++)
		{
			cout << "*";
		}
		stars += 2;
		cout << endl;
	}
	return 0;
}