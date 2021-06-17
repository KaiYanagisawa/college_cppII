#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool is_b_big(int x, int y) { return x >= y; }

int main(int argc, char *argv[])
{
    std::string filename{argc > 1 ? argv[1] : ""};
    std::fstream infile(filename.c_str());
    if (!infile)
    {
        return 1;
    }
    //整数列の入力
    int N;
    infile >> N;
    std::vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i)
        infile >> a[i];
    for (int i = 0; i < N; ++i)
        infile >> b[i];
    //以下で条件を満たすかどうかの判定と結果の出力を行う

    for (int i = 0; i < N; ++i)
    {
        if (!is_b_big(b[i], a[i]))
        {
            for (int j = 0; j < N; j++)
            {
                if (is_b_big(b[j], a[j]) && is_b_big(b[i], a[j]) && is_b_big(b[j], a[i]))
                    std::swap(a[j], a[i]);
            }
        }
    }

    bool judge{true};
    for (int i = 0; i < N; ++i)
    {
        if (!is_b_big(b[i], a[i]))
        {
            judge = false;
            break;
        }
    }
    if (judge)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}