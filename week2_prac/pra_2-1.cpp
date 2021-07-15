#include <iostream>
#include <vector>
class Loud
{
public:
    Loud() { std::cout << "Hello!!\n"; }
};

int main()
{
    std::vector<Loud> x(10);
}