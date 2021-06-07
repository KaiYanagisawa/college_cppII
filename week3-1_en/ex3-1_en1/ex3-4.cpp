#include <iostream>

template <typename T>
T sum(T a, T b, T c = T{})
{
    return a + b + c;
}

int main()
{
    using std::cout;
    cout << sum(1, 2) << " " << sum(1, 2, 3) << "\n";
    using namespace std::string_literals;
    cout << sum("a"s, "b"s) << " " << sum("a"s, "bc"s, "def"s) << "\n";
}