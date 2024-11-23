#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	cout << "Введите 2 числа, по одному в каждой строке: \n";
	cin >> a >> b;
	int* a_ptr = &a;
	int* b_ptr = &b;
	int c = *b_ptr + *a_ptr;
	cout << "a + b = " << c << endl;
	return 0;
}