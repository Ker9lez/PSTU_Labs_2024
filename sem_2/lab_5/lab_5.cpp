#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

void fillMatrix(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            matrix[i][j] = rand() % 10;
        }
    }
}
void printMatrix(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int findMaxRepeating(int** matrix, int rows, int cols) 
{
    const int MAX_VALUE = 100;
    int count[MAX_VALUE + 1] = { 0 };
    int maxRepeating = INT_MIN;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            count[matrix[i][j]]++;
        }
    }
    for (int i = 0; i <= MAX_VALUE; ++i) 
    {
        if (count[i] > 1 && i > maxRepeating) 
        {
            maxRepeating = i;
        }
    }
    return maxRepeating;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    const int rows = 5;
    const int cols = 5;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        matrix[i] = new int[cols];
    }
    fillMatrix(matrix, rows, cols);
    cout << "Исходная матрица:" << endl;
    printMatrix(matrix, rows, cols);
    int result = findMaxRepeating(matrix, rows, cols);
    if (result != INT_MIN) 
    {
        cout << "Максимальный повторяющийся элемент: " << result << endl;
    }
    else 
    {
        cout << "Повторяющихся элементов нет" << endl;
    }
    for (int i = 0; i < rows; ++i) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}