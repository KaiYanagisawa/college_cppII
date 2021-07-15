#include <iostream>
#include "mycec-u.hpp"
int main()
{
    MyVec<int> myvec;
    for (size_t i = 0; i < 5; i++)
        myvec.push_back(i);
    myvec.erase(3);
    for (size_t i = 0; i < myvec.size(); i++)
        std::cout << myvec[i] << " ";
    std::cout << "\n";
}