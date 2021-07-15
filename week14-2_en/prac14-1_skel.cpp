#include <iostream>
using std::cout;

void sqrt(int *x, int *y); // 引数を適当に指定

int main()
{
	int x{10};
	cout << "&x   : " << &x << "\n"; // xを参照（アドレスを示すこと）

	int *xPtr;							// ポインタの宣言（*は関節参照演算子）
	xPtr = &x;							// xのアドレスを代入
	cout << "*xPtr: " << *xPtr << "\n"; // xを間接的に出力
	cout << " xPtr: " << xPtr << "\n";	// xのアドレスを出力

	int y{5};
	int *yPtr = &y;						// ポインタを宣言し，yのアドレスを代入
	cout << "*yPtr: " << *yPtr << "\n"; // yを間接的に出力
	cout << " yPtr: " << yPtr << "\n";	// yのアドレスを出力

	sqrt(xPtr, yPtr);					// sqrt関数の呼び出し
	cout << "*yPtr: " << *yPtr << "\n"; // yを間接的に出力

	cout << "x = " << x << ", y = " << y << "\n";
}

void sqrt(int *x, int *y)
{				  // 引数を適当に指定
	*y = *x * *x; // 平方計算
}
// 返り値がない，つまり，コピーを作成する必要がない
// 大規模なデータで関数呼び出ししても，データのコピーをしないため，メモリの圧迫が少ない