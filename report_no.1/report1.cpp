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
  Record() = default; //自動生成を依頼

  //成績をカウント
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

  //データメンバの値を取り出すメンバ関数
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

  //データメンバの値を設定するメンバ関数
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

  //力士の名前、番付、成績、対戦相手を出力
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
{
  //Recordをvectorに格納するクラス

  friend Record; //privateデータメンバへのアクセス許可
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
      e.print();
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
        if (v[max].shiro() > v[j].shiro()) //前後のvの要素を比較し、前の要素より後の要素の勝ち数が多ければswapで前後を交換
          max = j;
        else if (v[max].shiro() == v[j].shiro() && v[max].kuro() < v[j].kuro()) //前後の勝ち数が同じ場合、負け数が少なければswapで前後を交換
          max = j;
        std::swap(v[j], v[max]);
      }
    }
  }

  void result(std::ofstream &fout)
  {
    //出力ファイルに各力士のデータを出力するメンバ関数
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
  //文字列から" "と"\n"の区切りでvに格納
  std::vector<std::string> v;
  auto iter{s.begin()};   //sの最初を表すイテレータ
  while (iter != s.end()) //テキストが残っている間繰り返す
  {
    /*空白（sep=' '）またはタブ（sep2='\t'）で区切られているsの要素をvに格納．string(iter_first,iter)でiter_firstとiterで指定された文字の一部抽出ができる*/
    auto last = iter;
    while (last != s.end() && *last != sep && *last != sep2) //seqかつseq2までイテレータを進める
      ++last;
    v.push_back(std::string(iter, last)); //分割文字をvへ格納
    if (last != s.end())
      ++last;
    iter = last; //次のループのためにlastの示すイテレータを設定
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
    if (n % 5 == 0) //各力士データの一行目を取得
    {
      /*finからrankを取り出しrecordに格納*/
      getline(fin, rank);
      record.set_r(rank);
    }
    else if (n % 5 == 1) //各力士データの二行目を取得
    {
      /*finからnameを取り出しrecordに格納*/
      getline(fin, name);
      record.set_n(name);
    }
    else if (n % 5 == 2) //各力士データの三行目を取得
    {
      /*finからscoreを取り出しrecordに格納. その際split関数を用いる*/
      getline(fin, score);
      record.set_s(split(score));
    }
    else if (n % 5 == 3) //各力士データの四行目を取得
    {
      /*finからaiteを取り出しrecordに格納．その際split関数を用いる*/
      /*recordをtableに追加*/
      getline(fin, aite);
      record.set_a(split(aite));
      table.add(record); //Table型に上記で取得したRecord型のデータを格納
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