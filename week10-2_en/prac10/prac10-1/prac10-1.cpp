#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
    bool operator<(Book s) const
    {
        return author < s.author;
    }
};
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
    std::cout << "sorting===========";
    std::sort(bookshelf.begin(), bookshelf.end()); //本棚をソート
    std::cout << "===========sorted\n";
    for (const auto &book : bookshelf) //ソート済本棚から出力
        book.print();
    return 0;
}