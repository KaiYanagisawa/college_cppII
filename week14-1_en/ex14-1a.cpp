#include <vector>
#include "./ex14.hpp"
using std::vector;
int sum(vector<T> *x)
{
    int s{0};
    for (auto e : *x)
        s += e.get();
    return s;
}
int main()
{
    vector<T> a(10);
    std::cout << "sum = " << sum(&a) << "\n";
}