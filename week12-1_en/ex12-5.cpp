#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "usage: " << argv[0] << " regex\n";
        return 1;
    }
    string rs{argv[1]};
    std::regex r{rs};
    string data{"acaaac aac akbac cccancnkp"};
    cout << "data: " << data << "\n";
    std::smatch m;
    std::regex_search(data, m, r);
    if (!m.empty())
    {
        cout << "m.prefix():" << m.prefix() << "\n"
             << "m.suffix():" << m.suffix()
             << "\n";
        for (size_t i = 0; i < m.size(); i++)
        {
            cout << "m[" << i << "]:" << m[i] << ", "
                 << "m.position" << i << "):" << m.position(i) << "\n";
        }
    }
}