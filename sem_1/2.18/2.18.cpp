#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	int r = 0;
	cout << "Введите число: \n";
	cin >> n;
	while (n > 0)
	{
		r = r * 10 + n % 10;
		n /= 10;
	}
	cout << r << endl;
	return 0;
}
