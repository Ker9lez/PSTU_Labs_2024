#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159265358979323846;
// Функция вычисления угла треугольника
double triangleAngle(double a, double b, double c) 
{
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) 
    {
        cout << "Ошибка: несуществующий треугольник!" << endl;
        return -1.0;
    }
    return acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / PI;
}
void angles(double a, double b, double c) 
{
    cout << "Углы треугольника:\n";
    cout << "A = " << triangleAngle(a, b, c) << "°\n";
    cout << "B = " << triangleAngle(b, a, c) << "°\n";
    cout << "C = " << triangleAngle(c, a, b) << "°\n";
}
void angles(double s1, double s2, double s3, double s4, double s5, double s6, double s7, double s8, double s9) 
{
    cout << "Углы 9-угольника (правильного):\n";
    double angle = 180.0 * 7 / 9;
    for (int i = 1; i <= 9; i++) 
    {
        cout << "Угол " << i << " = " << angle << "°\n";
    }
}
void angles(double s1, double s2, double s3, double s4, double s5, double s6, double s7, double s8, double s9, double s10, double s11) 
{
    cout << "Углы 11-угольника (правильного):\n";
    double angle = 180.0 * 9 / 11;
    for (int i = 1; i <= 11; i++) 
    {
        cout << "Угол " << i << " = " << angle << "°\n";
    }
}
int main() 
{
    setlocale(LC_ALL, "Russian");
    // Треугольник
    double a, b, c;
    cout << "Введите 3 стороны треугольника: ";
    cin >> a >> b >> c;
    angles(a, b, c);
    // 9-угольник
    double s9[9];
    cout << "\nВведите 9 сторон 9-угольника: ";
    for (int i = 0; i < 9; i++) cin >> s9[i];
    angles(s9[0], s9[1], s9[2], s9[3], s9[4], s9[5], s9[6], s9[7], s9[8]);
    // 11-угольник
    double s11[11];
    cout << "\nВведите 11 сторон 11-угольника: ";
    for (int i = 0; i < 11; i++) cin >> s11[i];
    angles(s11[0], s11[1], s11[2], s11[3], s11[4], s11[5], s11[6], s11[7], s11[8], s11[9], s11[10]);
    return 0;
}