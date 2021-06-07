#include <iostream>
#include <string>

using std::string;

template <typename T>
void print_smaller(T a, T b)
{
    if (a < b)
        std::cout << a << "\n";
    else
        std::cout << b << "\n";
}

int main()
{
    print_smaller(5, 3);
    print_smaller(2.5, 4.8);
    print_smaller("abc", "xyz");
    print_smaller<string>("abc", "xyz");
}