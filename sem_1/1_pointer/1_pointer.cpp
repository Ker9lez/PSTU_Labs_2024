#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	cout << "Введите 2 числа, по одному в каждой строке: \n";
	cin >> a >> b;
	int c = a;
	int* a_ptr = &a;
	int* b_ptr = &b;
	int* c_ptr = &c;
	a = *b_ptr;
	b = *c_ptr;
	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}