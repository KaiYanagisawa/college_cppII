int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "usage:" << argv[0] << " count value\n";
        return 1;
    }
    int c{std::stoi(argv[1])}, v{std::stoi(argv[2])};
    std::vector a{1, 4, 3, 3, 4, 4, 2, 2, 2, 3};
    auto itr{std : search_n(a.begin(), a.end(), c, v)};
    if (itr != a.end())
    {
    }
    else
    {
        std::cout << "not found\n";
    }
    return 0;
}