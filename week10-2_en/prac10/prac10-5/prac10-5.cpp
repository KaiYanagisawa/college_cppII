#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>

class Book
{
    std::string title, author;
    int year;

public:
    Book() = default;
    Book(std::string t, std::string a, int y) : title(t), author(a), year(y) {}
    void print() const
    {
        std::cout << author << "(" << year << ") : " << title << "\n";
    }
    int get_y() { return year; }
};

bool judge(Book &s)
{
    return s.get_y() < 1950;
}

int main()
{
    std::vector<Book> bookshelf;
    std::string t, a, y;
    std::ifstream bfile("./books.csv");
    if (!bfile)
    {
        return 1;
    }
    while (std::getline(bfile, t, ',') && std::getline(bfile, a, ',') && std::getline(bfile, y))
        bookshelf.push_back(Book(t, a, std::stoi(y))); //本棚に本を格納
    for (const auto &book : bookshelf)                 //本棚から出力
        book.print();

    std::cout << "removing=======";
    auto it{bookshelf.begin()};
    it = std::remove_if(bookshelf.begin(), bookshelf.end(), judge);
    bookshelf.erase(it, bookshelf.end());
    std::cout << "=======removed\n";
    for (const auto &book : bookshelf)
        book.print();

    std::cout << "shuffling=======";
    std::random_device seed;
    std::mt19937 engine{seed()};
    std::shuffle(bookshelf.begin(), bookshelf.end(), engine);
    std::cout << "=======shuffled\n";
    for (const auto &book : bookshelf)
        book.print();

    return 0;
}