#include <iostream>
#include <vector>

int main()
{
    using std::cout, std::boolalpha, std::vector;

    vector<int> x, y;

    cout << "Input elements of a vector x, /n where input 9999 to terminate.";

    //ここでｘに値を格納していく
    //くりかえり処理、ただし9999が入力されるとそのループから抜ける
    //ループから抜けるためにbreakを使う
    cout << "Input elements of a vector x, /n where input 9999 to terminate.";
    //ここでｙに値を格納していく
    cout << "\n------\n";
    cout << boolalpha;
    cout << "x == y" << (x == y) << "\n";
    cout << "x == y" << (x != y) << "\n";
    cout << "x == y" << (x <= y) << "\n";
    cout << "x == y" << (x >= y) << "\n";
    cout << "x == y" << (x > y) << "\n";
    return 0;
}