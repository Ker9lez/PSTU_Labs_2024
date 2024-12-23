#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float x = 2, xPrev = 0;
	double eps = 0.000001, lambda = -0.05;
	while (abs(x - xPrev) > eps)
	{
		xPrev = x;
		x = lambda * (pow(xPrev, 3) - xPrev - 1) + xPrev;
	}
	cout << "Корень по методу итераций: " << x << endl;
	return 0;
}
