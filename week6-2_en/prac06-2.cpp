//prac06-2.cpp

/*
空欄１ 必要なヘッダをインクルードしなさい．
*/
#include <iostream>
#include <map>
#include <string>

int main()
{

	//ある日のお弁当屋さんにおける開店時の各弁当の在庫を表す連想配列
	std::map<std::string, int> stocklist{
		{"シウマイ弁当", 50},
		{"チャーハン弁当", 25},
		{"お赤飯弁当", 5},
		{"幕の内弁当", 15},
		{"松花堂弁当", 10},
		{"初夏の彩弁当", 20}};
	std::string s;
	while (std::cin >> s)
	{
		/*
		空欄２ 正しく注文された弁当を在庫から減らしていくプログラムを作成せよ．
		ただし，在庫切れになった弁当はstocklistから削除せよ．
		*/
		if (s == "シウマイ弁当")
		{
			if (auto i{stocklist.find("シウマイ弁当")}; i != stocklist.end())
			{
				auto &[a, b]{*i};
				b -= 1;
				if (b == 0)
					stocklist.erase(i);
			}
		}
		if (s == "チャーハン弁当")
		{
			if (auto i{stocklist.find("チャーハン弁当")}; i != stocklist.end())
			{
				auto &[a, b]{*i};
				b -= 1;
				if (b == 0)
					stocklist.erase(i);
			}
		}
		if (s == "お赤飯弁当")
		{
			if (auto i{stocklist.find("お赤飯弁当")}; i != stocklist.end())
			{
				auto &[a, b]{*i};
				b -= 1;
				if (b == 0)
					stocklist.erase(i);
			}
		}
		if (s == "幕の内弁当")
		{
			if (auto i{stocklist.find("幕の内弁当")}; i != stocklist.end())
			{
				auto &[a, b]{*i};
				b -= 1;
				if (b == 0)
					stocklist.erase(i);
			}
		}
		if (s == "松花堂弁当")
		{
			if (auto i{stocklist.find("松花堂弁当")}; i != stocklist.end())
			{
				auto &[a, b]{*i};
				b -= 1;
				if (b == 0)
					stocklist.erase(i);
			}
		}
		if (s == "初夏の彩弁当")
		{
			if (auto i{stocklist.find("初夏の彩弁当")}; i != stocklist.end())
			{
				auto &[a, b]{*i};
				b -= 1;
				if (b == 0)
					stocklist.erase(i);
			}
		}
	}

	std::cout << "--売れ残った弁当--\n";
	/*
	空欄３ 余った在庫を出力せよ．
	*/
	if (auto i{stocklist.find("シウマイ弁当")}; i != stocklist.end())
	{
		auto &[a, b]{*i};
		std::cout << "シウマイ弁当" << b << "個余りました.\n";
	}
	if (auto i{stocklist.find("チャーハン弁当")}; i != stocklist.end())
	{
		auto &[a, b]{*i};
		std::cout << "チャーハン弁当" << b << "個余りました.\n";
	}
	if (auto i{stocklist.find("お赤飯弁当")}; i != stocklist.end())
	{
		auto &[a, b]{*i};
		std::cout << "お赤飯弁当" << b << "個余りました.\n";
	}
	if (auto i{stocklist.find("幕の内弁当")}; i != stocklist.end())
	{
		auto &[a, b]{*i};
		std::cout << "幕の内弁当" << b << "個余りました.\n";
	}
	if (auto i{stocklist.find("松花堂弁当")}; i != stocklist.end())
	{
		auto &[a, b]{*i};
		std::cout << "松花堂弁当" << b << "個余りました.\n";
	}
	if (auto i{stocklist.find("初夏の彩弁当")}; i != stocklist.end())
	{
		auto &[a, b]{*i};
		std::cout << "初夏の彩弁当" << b << "個余りました.\n";
	}
}