#include <iostream>
#include <iterator>
int main()
{
    std::istream_iterator<int> in{std::cin};
    std::istream_iterator<int> eos;
    std::ostream_iterator<int> out{std::cout, ", "};
    for (; in != eos; ++in)
        *out = *in * 2;
}