template <typename T, typename K>
T myfind_end(T b1, T e1, K b2, K e2)
{
}
int main()
{
    std::vector a{3, 1, 2, 3, 8, 1, 2, 3, 5, 1, 2, 3, 6}, s{
                                                              1,
                                                              2,
                                                              3,
                                                          };
    auto it{myfind_end(a.begin(), a.end(), s.begin(), s.end())};
    if (it != a.end())
        std::cout << "found at " << it - a.begin() << "\n";
}