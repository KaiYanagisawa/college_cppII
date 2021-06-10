#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

class Student {
private:
	std::string name;
	bool gender; //true-> male, false->female
	int score;

public:
	Student(std::string name, bool gender, int score) :
		name(name), gender(gender), score(score) {}
	bool getGender() { return gender; }
	int getScore() { return score; }
	std::string getName() { return name; }
};


int main() {
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
	

	// 男子学生と女子学生の人数をそれぞれ出力する
	

	// 最高点及び、その学生の名前を出力する


	// 成績がB評価（得点が70以上80未満）の人数を出力する


	// 成績がD評価（得点が60未満）の人数を出力する
	

	// 名前に mi が含まれている学生の情報を出力する：mio, minato


	return 0;
}