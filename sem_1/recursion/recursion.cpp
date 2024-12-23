#include <iostream>
#include <cmath>
using namespace std;
int Fibonacci(int n) 
{
	if (n <= 2) { return 1; }
	else { return Fibonacci(n - 1) + Fibonacci(n - 2); }
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, ans;
	cout << "Введите номер числа в ряде Фибоначчи(1, 1, 2, ...): \n";
	cin >> n;
	ans = Fibonacci(n);
	cout << "Данный член ряда Фибоначчи равен - " << ans << endl;
	return 0;
}
