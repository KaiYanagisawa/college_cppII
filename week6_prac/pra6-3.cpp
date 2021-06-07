#include <iostream>
#include <map>
using std::cout, std::string;
int main()
{
    std::map<string, int> price;
    price["orange"] = 150;
    price["banana"] = 300;
    price["pineapple"] = 850;
    cout << price["nabana"] << " " << price.size() << "\n";
}