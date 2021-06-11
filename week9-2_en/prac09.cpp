#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

class Student
{
private:
	std::string name;
	bool gender; //true-> male, false->female
	int score;

public:
	Student(std::string name, bool gender, int score) : name(name), gender(gender), score(score) {}
	bool getGender() { return gender; }
	int getScore() { return score; }
	std::string getName() { return name; }
};
bool Gender1(Student s)
{
	return s.getGender();
}
bool Gender2(Student s)
{
	return !s.getGender();
}
bool operator<(Student &s1, Student &s2)
{
	return s1.getScore() < s2.getScore();
}
bool find_func_B(Student &s)
{
	return (s.getScore() >= 70 && s.getScore() < 80);
}
bool find_func_D(Student &s)
{
	return (s.getScore() < 60);
}
bool find_func_n(Student &s)
{
	return (s.getScore() < 60);
}
int main()
{
	std::vector<Student> students;
	students.push_back(Student("haruto", true, 66));
	students.push_back(Student("mio", false, 90));
	students.push_back(Student("souta", true, 84));
	students.push_back(Student("minato", true, 77));
	students.push_back(Student("mei", false, 96));
	students.push_back(Student("haruki", true, 59));
	students.push_back(Student("itsuki", true, 88));
	students.push_back(Student("yui", false, 90));
	students.push_back(Student("akari", false, 95));
	students.push_back(Student("yuito", true, 73));

	// 人数を出力する
	std::cout << "学生 : " << students.size() << "人\n";

	// 男子学生と女子学生の人数をそれぞれ出力する
	std::cout << "男子学生 : " << count_if(students.begin(), students.end(), Gender1) << "人\n";
	std::cout << "女子学生 : " << count_if(students.begin(), students.end(), Gender2) << "人\n";

	// 最高点及び、その学生の名前を出力する
	auto it{std::max_element(students.begin(), students.end())};
	std::cout << "最高点 : " << it->getScore() << " (氏名 " << it->getName() << ")\n";

	// 成績がB評価（得点が70以上80未満）の人数を出力する
	auto it2{std::find_if(students.begin(), students.end(), find_func_B)};
	int num{0};
	while (it2 != students.end())
	{
		++num;
		++it2;
		it2 = std::find_if(it2, students.end(), find_func_B);
	}
	std::cout << "成績がB評価 (得点が70点以上80点未満) の人数 : " << num << "\n";

	// 成績がD評価（得点が60未満）の人数を出力する
	auto it3{std::find_if(students.begin(), students.end(), find_func_D)};
	int num2{0};
	while (it3 != students.end())
	{
		++num2;
		++it3;
		it3 = std::find_if(it3, students.end(), find_func_D);
	}
	std::cout << "成績がD評価 (60未満) の人数 : " << num2 << "\n";

	// 名前に mi が含まれている学生の情報を出力する：mio, minato
	std::vector<char> cv{'m', 'i'};
	for (int i = 0; i < students.size(); i++)
	{
		std::string str{};
		str = students[i].getName();
		auto it4{std::search(str.begin(), str.end(),
							 cv.begin(), cv.end())};
		if (it4 != str.end() && students[i].getGender() == true)
		{
			std::cout << str << ", Male, " << students[i].getScore() << "\n";
		}
		if (it4 != str.end() && students[i].getGender() == false)
		{
			std::cout << str << ", Female, " << students[i].getScore() << "\n";
		}
	}

	return 0;
}
