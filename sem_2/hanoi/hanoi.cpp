#include <iostream>
using namespace std;
const int MAX_DISKS = 8;
const int POLE_COUNT = 3;
int poles[POLE_COUNT][MAX_DISKS];
int heights[POLE_COUNT] = { 0 };
void drawDisk(int size, int max_size) 
{
    int spaces = max_size - size;
    for (int i = 0; i < spaces / 2; ++i) cout << ' ';
    for (int i = 0; i < size; ++i) cout << 'O';
    for (int i = 0; i < spaces / 2; ++i) cout << ' ';
}
void drawTower(int disk_count, int step) 
{
    cout << "\nШаг " << step << ":\n";
    for (int level = disk_count - 1; level >= 0; --level) 
    {
        for (int pole = 0; pole < POLE_COUNT; ++pole) 
        {
            if (level < heights[pole]) {
                drawDisk(poles[pole][level], disk_count * 2 - 1);
            }
            else 
            {
                drawDisk(0, disk_count * 2 - 1);
            }
            cout << "| ";
        }
        cout << '\n';
    }
    for (int i = 0; i < POLE_COUNT; ++i) 
    {
        for (int j = 0; j < disk_count; ++j) cout << '=';
        cout << "| ";
    }
    cout << "\n";
}
void moveDisk(int from, int to, int disk_count, int& step) 
{
    if (heights[from] == 0) return;
    poles[to][heights[to]] = poles[from][heights[from] - 1];
    heights[to]++;
    heights[from]--;
    drawTower(disk_count, ++step);
    cout << "Нажмите Enter...";
    cin.ignore();
}
void solve(int n, int from, int to, int aux, int disk_count, int& step) 
{
    if (n <= 0) return;
    solve(n - 1, from, aux, to, disk_count, step);
    moveDisk(from, to, disk_count, step);
    solve(n - 1, aux, to, from, disk_count, step);
}
int readInt(int min, int max) 
{
    int value;
    while (true) 
    {
        cout << "Введите количество дисков (" << min << "-" << max << "): ";
        if (cin >> value && value >= min && value <= max) 
        {
            return value;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Некорректный ввод. Попробуйте снова.\n";
    }
}
int main() 
{
    setlocale(LC_ALL, "Russian");
    int disk_count = readInt(1, MAX_DISKS);
    for (int i = 0; i < disk_count; ++i) 
    {
        poles[0][i] = disk_count - i;
    }
    heights[0] = disk_count;
    int step = 0;
    drawTower(disk_count, step);
    cout << "Начальное состояние. Нажмите Enter чтобы начать...";
    cin.ignore();
    solve(disk_count, 0, 2, 1, disk_count, step);
    cout << "\nРешение завершено за " << step << " шагов!\n";
    return 0;
}