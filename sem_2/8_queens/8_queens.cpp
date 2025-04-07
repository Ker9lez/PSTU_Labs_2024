#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N = 8;

bool isSafe(vector<vector<int>>& board, int row, int col) 
{
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}
bool solveNQueens(vector<vector<int>>& board, int col) 
{
    if (col >= N)
        return true;
    if (col == 0) 
    {
        int randomRow = rand() % N;
        if (isSafe(board, randomRow, col)) 
        {
            board[randomRow][col] = 1;
            if (solveNQueens(board, col + 1))
                return true;
            board[randomRow][col] = 0;
        }
        return false;
    }
    for (int i = 0; i < N; i++) 
    {
        if (isSafe(board, i, col)) 
        {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
void printBoard(const vector<vector<int>>& board) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}
int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (solveNQueens(board, 0)) 
    {
        cout << "Решение найдено:\n";
        printBoard(board);
    }
    else 
    {
        cout << "Решение не найдено\n";
        board = vector<vector<int>>(N, vector<int>(N, 0));
        if (solveNQueens(board, 0)) {
            cout << "Решение найдено со второй попытки:\n";
            printBoard(board);
        }
        else 
        {
            cout << "Решение не найдено после двух попыток\n";
        }
    }
    return 0;
}