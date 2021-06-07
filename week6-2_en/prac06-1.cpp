//prac06-1.cpp

#include <iostream>
#include <list>
using std::list, std::cout, std::cin;

void erase(list<int> &l, int n)
{
	list<int> L1{}, L2{l};

	/*
	erase関数を完成させよ
	*/
	for (auto &p : l)
	{
		if (p != n)
		{
			L1.push_back(p);
		}
		else
		{
			for (auto &q : L2)
			{
				if (q != n)
				{
					L2.pop_front();
				}
				else
				{
					L2.pop_front();
					break;
				}
			}
			break;
		}
	}
	L1.splice(L1.end(), L2);
	l = L1;
}

int main()
{
	list<int> L{1, 3, 8, 4, 5, 3, 5, 9};

	cout << "元のリストは\nL= ";
	for (auto &e : L)
		cout << e << " ";
	cout << "\n";

	//メンバ関数のerase()を使って要素を削除
	for (auto it = L.begin(); it != L.end(); it++)
	{
		if (*it == 3)
		{
			it = L.erase(it);
			break;
		}
	}
	cout << "\n3 を見つけてリストから消すと\nL= ";
	for (auto &e : L)
		cout << e << " ";
	cout << "\n";

	//一般関数のerase()を使って要素を削除
	cout << "\n消す数字を選んでください: ";
	int x;
	cin >> x;
	erase(L, x);

	cout << "\n"
		 << x << " を見つけてリストから消すと\nL= ";
	for (auto &e : L)
		cout << e << " ";
	cout << "\n";
}