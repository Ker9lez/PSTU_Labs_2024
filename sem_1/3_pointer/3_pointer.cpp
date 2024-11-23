#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float a, b;
	cout << "Введите 2 числа, по одному в каждой строке: \n";
	cin >> a >> b;
	float* a_ptr = &a;
	float* b_ptr = &b;
	float c = *b_ptr + *a_ptr;
	cout << "a + b = " << c << endl;
	return 0;
}