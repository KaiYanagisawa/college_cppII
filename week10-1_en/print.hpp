#include <iostream>
template <typename T>
void print(const T &c)
{
    for (auto &e : c)
        std::cout << e << " ";
    std::cout << "\n";
}
template <typename Itr>
void print(Itr b, Itr e)
{
    for (; b != e; ++b)
        std::cout << *b << " ";
    std::cout << "\n";
}