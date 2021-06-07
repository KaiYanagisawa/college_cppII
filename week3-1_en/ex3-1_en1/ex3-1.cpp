#include "prsmall.hpp"

int main()
{
    print_smaller(5, 3);
    print_smaller(2.5, 4.8);
    print_smaller<std::string>("abc", "xyz");
}