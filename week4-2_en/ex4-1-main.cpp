#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<std::vector<int>> Mat(5, std::vector<int>(5, 0));
    //左下半分に整数値を格納
    int num;
    for (int i = 0; i < 5; i++)
    {
        cout << "Input " << i + 1 << "th row ---> ";
        for (int m = 0; m < i + 1; m++)
        {
            cin >> num;
            Mat[i][m] = num;
            num = 0;
        }
        cout << "\n";
    }
    //Mat[1][2];
    //  0 1 2 3 4
    //0 0 0 0 0 0
    //1 0 0 0 0 0
    //2 0 0 0 0 0
    //3 0 0 0 0 0
    //4 0 0 0 0 0

    for (int i = 0; i < 5; i++)
    {
        for (int m = 0; m < i + 1; m++)
        {
            cout << Mat[i][m] << " ";
        }
        cout << "\n";
    }
    return 0;
}