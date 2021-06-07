#include <iostream>
#include "./point.hpp"
#include "point.cpp"

// Pont 操作
int main()
{

  // (1) 以下を参考にコンストラクタを作成せよ
  Point a{"A", 1.0, 2.0}, b{"B", 3.4, 1.6};
  Point c{}, d{1.1, 2.2}, e{3.3}, m{"M"};

  std::cout << "\n(1)--- Constructer OK\n";

  //(2) 出力表示 コンストラクタの確認
  std::cout << "\n(2)--- Point output\n";
  std::cout << "a: " << a << "\n";
  std::cout << "b: " << b << "\n";
  std::cout << "c: " << c << "\n";
  std::cout << "d: " << d << "\n";
  std::cout << "e: " << e << "\n";
  std::cout << "m: " << m << "\n";

  //(3)入力
  std::cout << "\n(3)--- Point input\n";
  std::cout << "before: Point c:" << c << "\n";
  std::cout << "Input Point c: name, x,y: ";
  std::cin >> c; // 入力
  std::cout << "after: Point c:" << c << "\n";

  //(4)座標の代入設定
  std::cout << "\n(4)--- Point x,y setting\n";
  b <= c; //　bへcの座標の代入
  std::cout << b << "\n";

  //(5)座標の加算
  std::cout << "\n(5)--- Point addition\n";
  m <= (a + b); // Pointの座標の加算, 座標の代入 <=
  std::cout << a << " + " << b << " = " << m << "\n";
  /*
  //(6)座標の除算  
  std::cout<<"\n(6)--- Point scalar division\n"; 
  m <= (a+b)/2;  // 2点 a, bの中点mの計算(加算，除算），座標の代入 <= 
  std::cout<<"Middle point: "<<m<<"\n";

  //(7)座標のスカラー積  
  std::cout<<"\n(7)--- Point scalar multiplication\n"; 
  double k=3.4;
  d= a*k;
  std::cout<<"d=a*k "<< d<<"\n";

  //（８）座標のスカラー積2    できる人だけでいい  
  std::cout<<"\n(8)--- Scalar Point multiplication\n"; 
  e= k*a;  
  std::cout<<"e=k*a "<< e<<"\n";
*/
}
