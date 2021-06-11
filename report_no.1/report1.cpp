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
  Record() : score{}, aite{} {};
  int shiro()
  {
    int shiro{0};
    /* 白星または不戦勝の数を計算*/
    for (auto e : score)
    {
      if (e == "Shiroboshi" || e == "Fusenshou")
        shiro++;
    }
    return shiro;
  }
  int kuro()
  {
    int kuro{0};
    /*黒星または不戦敗の数を計算*/
    for (auto e : score)
    {
      if (e == "Kuroboshi" || e == "Fusenpai")
        kuro++;
    }
    return kuro;
  }
  int yasumi()
  {
    int yasumi{0};
    /*やすみの数を計算*/
    for (auto e : score)
    {
      if (e == "Yasumi")
        yasumi++;
    }
    return yasumi;
  }

  std::string get_r()
  { /*rankに対するゲッター*/
    return rank;
  }
  std::string get_n()
  { /*nameに対するゲッター*/
    return name;
  }
  std::vector<std::string> get_s()
  { /*scoreに対するゲッター*/
    return score;
  }
  std::vector<std::string> get_a()
  { /*aiteに対するゲッター*/
    return aite;
  }
  void set_r(std::string r)
  { /*rankに対するセッター*/
    rank = r;
  }
  void set_n(std::string n)
  { /*nameに対するセッター*/
    name = n;
  }
  void set_s(std::vector<std::string> s)
  { /*scoreに対するセッター*/
    score = s;
  }
  void set_a(std::vector<std::string> a)
  { /*aiteに対するセッター*/
    aite = a;
  }

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

public:
  void add(Record r)
  {
    /*vにrを追加*/
    v.push_back(r);
  }
  void print()
  {
    for (auto e : v)
    {
      e.print();
    }
  }
  void sort()
  {
    size_t n = v.size();
    for (size_t i = 0; i < v.size() - 1; i++)
    {
      size_t max{i};
      for (size_t j = i + 1; j < v.size(); j++)
      /*勝敗(白星，不戦勝，黒星，不戦敗)によってvをソートする（選択ソート）*/
      {
        if (v[max].shiro() > v[j].shiro())
          max = j;
        else if (v[max].shiro() == v[j].shiro() && v[max].kuro() < v[j].kuro())
          max = j;
        std::swap(v[j], v[max]);
      }
    }
  }
  void result(std::ofstream &fout)
  {
    for (auto e : v)
    {
      if (e.yasumi() > 0)
        fout << std::setw(22) << e.get_r() << std::setw(20) << e.get_n() << std::setw(5) << e.shiro() << "Shou" << std::setw(5) << e.kuro() << "Hai" << std::setw(5) << e.yasumi() << "Kyu" << std::endl;
      else
        fout << std::setw(22) << e.get_r() << std::setw(20) << e.get_n() << std::setw(5) << e.shiro() << "Shou" << std::setw(5) << e.kuro() << "Hai" << std::endl;
    }
  }
};

std::vector<std::string> split(std::string s, char sep = ' ', char sep2 = '\t')
{
  std::vector<std::string> v;
  auto iter{s.begin()};
  while (iter != s.end())
  {
    /*空白（sep=' '）またはタブ（sep2='\t'）で区切られているsの要素をvに格納．string(iter_first,iter)でiter_firstとiterで指定された文字の一部抽出ができる*/
    auto last = iter;
    while (last != s.end() && *last != sep && *last != sep2)
      ++last;
    v.push_back(std::string(iter, last));
    if (last != s.end())
      ++last;
    iter = last;
  }
  return v;
}

void import(std::ifstream &fin, Table &table)
{ //力士ファイルの取り込み
  Record record;
  std::string rank, name, score, aite, blank;
  int n{0};
  while (fin)
  {
    if (n % 5 == 0)
    {
      /*finからrankを取り出しrecordに格納*/
      getline(fin, rank);
      record.set_r(rank);
    }
    else if (n % 5 == 1)
    {
      /*finからnameを取り出しrecordに格納*/
      getline(fin, name);
      record.set_n(name);
    }
    else if (n % 5 == 2)
    {
      /*finからscoreを取り出しrecordに格納. その際split関数を用いる*/
      getline(fin, score);
      record.set_s(split(score));
    }
    else if (n % 5 == 3)
    {
      /*finからaiteを取り出しrecordに格納．その際split関数を用いる*/
      /*recordをtableに追加*/
      getline(fin, aite);
      record.set_a(split(aite));
      table.add(record);
    }
    else
    {
      getline(fin, blank);
    }
    n++;
  }
}

int main()
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