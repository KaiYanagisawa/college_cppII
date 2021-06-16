#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    return 0;
}