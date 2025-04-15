#include <iostream>
#include <cstdarg>
using namespace std;

float calculateProduct(int numArgs, ...)
{
    float productValue = 1.0f;

    va_list argList;
    va_start(argList, numArgs);

    for (int i = 0; i < numArgs; ++i)
    {
        float currentNum = va_arg(argList, int);
        productValue *= currentNum;
    }

    va_end(argList);

    return productValue;
}

int main()
{
    cout << "Product 1: " << calculateProduct(3, 4, 6, 12) << endl;
    cout << "Product 2: " << calculateProduct(7, 8, 5, 6, 20, 10, 9, 2) << endl;
    cout << "Product 3: " << calculateProduct(11, 8, 5, 6, 20, 10, 9, 2, 3, 3, 7, 11, 23) << endl;

    return 0;
}