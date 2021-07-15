#include <iostream>
void print(int a[][4], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << (j == 0 ? "" : ", ") << a[i][j];
        }
        std::cout << "\n";
    }
}
void printT(int a[][4], int n)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << (j == 0 ? "" : ", ") << a[i][j];
        }
        std::cout << "\n";
    }
}
int main()
{
    int x[2][4]{{1, 2, 3, 4}, {5, 6, 7, 8}};
    print(x, 2);
    std::cout << "---\n";
    printT(x, 2);
}