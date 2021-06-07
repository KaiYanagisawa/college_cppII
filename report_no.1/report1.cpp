#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

class Record
{ //番付，力士の名前，成績，対戦相手を格納するクラス
  std::string rank, name;
  std::vector<std::string> score, aite;

public:
  /* コンストラクタを定義*/
  Record(){

  };
  int shiro()
  {
    int shiro{0};
    /* 白星または不戦勝の数を計算*/
    return shiro;
  }
  //   int kuro()
  //   {
  //     int kuro{0};
  //     /*黒星または不戦敗の数を計算*/
  //     return kuro;
  //   }
  //   int yasumi()
  //   {
  //     int yasumi{0};
  //     /*やすみの数を計算*/
  //     return yasumi;
  //   }

  //   std::string get_r()
  //   { /*rankに対するゲッター*/
  //   }
  //   std::string get_n()
  //   { /*nameに対するゲッター*/
  //   }
  //   std::vector<std::string> get_s()
  //   { /*scoreに対するゲッター*/
  //   }
  //   std::vector<std::string> get_a()
  //   { /*aiteに対するゲッター*/
  //   }
  //   void set_r(std::string r)
  //   { /*rankに対するセッター*/
  //   }
  //   void set_n(std::string n)
  //   { /*nameに対するセッター*/
  //   }
  //   void set_s(std::vector<std::string> s)
  //   { /*scoreに対するセッター*/
  //   }
  //   void set_a(std::vector<std::string> a)
  //   { /*aiteに対するセッター*/
  //   }

  void print()
  {
    std::cout << "Banzuke:" << rank << std::endl;
    std::cout << "Shikona:" << name << std::endl;
    std::cout << "Seiseki:";
    for (auto e : score)
      std::cout << e << " ";
    std::cout << std::endl;
    std::cout << "Taisen_aite:";
    for (auto e : aite)
      std::cout << e << " ";
    std::cout << std::endl;
  }
};

class Table
{ //Recordをvectorに格納するクラス
  friend Record;
  std::vector<Record> v;

  // public:
  //   void add(Record r)
  //   {
  //     /*vにrを追加*/
  //   }
  //   void print()
  //   {
  //     for (auto e : v)
  //     {
  //       e.print();
  //     }
  //   }
  //   void sort()
  //   {
  //     size_t n = v.size();
  //     for (size_t i = 0; i < v.size() - 1; i++)
  //     {
  //       size_t max{i};
  //       for (size_t j = i + 1; j < v.size(); j++)
  //         /*勝敗(白星，不戦勝，黒星，不戦敗)によってvをソートする（選択ソート）*/
  //         std::swap(v[i], v[max]);
  //     }
  //   }
  //   void result(std::ofstream &fout)
  //   {
  //     for (auto e : v)
  //     {
  //       if (e.yasumi() > 0)
  //         fout << std::setw(22) << e.get_r() << std::setw(20) << e.get_n() << std::setw(5) << e.shiro() << "Shou" << std::setw(5) << e.kuro() << "Hai" << std::setw(5) << e.yasumi() << "Kyu" << std::endl;
  //       else
  //         fout << std::setw(22) << e.get_r() << std::setw(20) << e.get_n() << std::setw(5) << e.shiro() << "Shou" << std::setw(5) << e.kuro() << "Hai" << std::endl;
  //     }
  //   }
  // };

  // std::vector<std::string> split(std::string s, char sep = ' ', char sep2 = '\t')
  // {
  //   std::vector<std::string> v;
  //   auto iter{s.begin()};
  //   while (iter != s.end())
  //   {
  //     /*空白（sep=' '）またはタブ（sep2='\t'）で区切られているsの要素をvに格納．string(iter_first,iter)でiter_firstとiterで指定された文字の一部抽出ができる*/
  //   }
  //   return v;
  // }

  // void import(std::ifstream &fin, Table &table)
  // { //力士ファイルの取り込み
  //   Record record;
  //   int n{0};
  //   std::string rank, name, score, aite, blank;
  //   while (fin)
  //   {
  //     if (n % 5 == 0)
  //     {
  //       /*finからrankを取り出しrecordに格納*/
  //     }
  //     else if (n % 5 == 1)
  //     {
  //       /*finからnameを取り出しrecordに格納*/
  //     }
  //     else if (n % 5 == 2)
  //     {
  //       /*finからscoreを取り出しrecordに格納. その際split関数を用いる*/
  //     }
  //     else if (n % 5 == 3)
  //     {
  //       /*finからaiteを取り出しrecordに格納．その際split関数を用いる*/
  //       /*recordをtableに追加*/
  //     }
  //     else
  //     {
  //       getline(fin, blank);
  //     }
  //     n++;
  //   }
}

int
main()
{
  std::ifstream fin("higashi.txt");
  std::ofstream fout("result.txt");

  Table table;
  import(fin, table);
  table.print();
  table.sort();
  table.result(fout);
  return 0;
}