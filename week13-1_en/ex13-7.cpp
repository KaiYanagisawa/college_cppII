#include <iostream>
void print(int *a[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == m - 1)
            {
                std::cout << a[i][j];
                break;
            }

            std::cout << a[i][j] << ", ";
        }
        std::cout << "\n";
    }
}

int main()
{
    int x[2][4]{{1, 2, 3, 4}, {5, 6, 7, 8}};
    int *p[2]{x[1], x[0]};
    print(p, 2, 4);
}