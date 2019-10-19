#include <iostream>
#include <fstream> 
#include <stdio.h>
#include <string>
#include <windows.h>
using namespace std;

ifstream File("data.txt");

class CollegeStu
{
public:

	string name;
	int num;
	// 1 for girl  0 for boy
	bool sex;
	string birthday;
	int stature;
	float weight;
	int score;
	string address;

	void init();
	void print();
};

void CollegeStu::init()
{
	File >> name >> num >> sex >> birthday >> stature >> weight >> score >> address;
}

void CollegeStu::print()
{
	cout << name << '\t' << num << '\t';
	if (sex == 1)
		cout << "Female" << '\t' << birthday << '\t';
	else
		cout << "Male" << '\t' << birthday << '\t';
	cout << stature << '\t' << weight << '\t' << score << '\t' << address << endl;
}

int main()
{
	// to judge whether the file can be opened or not
	if (!File)
	{
		cout << "Error opening the file! / n";
		exit(1);
	}

	CollegeStu stu[50];

	// to get the number of the students
	int num;
	File >> num;

	// to init the dataset of the students
	for (int i = 0;i<num;i++)
		stu[i].init();

	// to check one's info
	cout << "Name\t" << "Num\t" << "Sex\t" << "Birthday\t" << "Stature\t" << "Weight\t" << "Score\t" << "Address\n";
	for (int i = 0; i < num; i++)
	{
		stu[i].print();
	}
	
	// to modify one's info
	stu[0].name = "dada";
	stu[0].print();

	File.close();
	system("pause");
	return 0;
}
