
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Student
{
private:
	string name;  //姓名
	char sex;     //性别（男：M、女：F）
	string grade; //年级
	float gpa;    //绩点
public:
	Student(string n = "Unknown", char s = '?' , string gra = "Unknown", float g = 0) :
		name(n), sex(s), grade(gra), gpa(g) {}
	void show_myself();  //打印信息
	void study_time(float study_time);  //增加GPA
};

void Student::show_myself()  //打印信息
{
	cout << "Name:" << name << endl;
	cout << "Sex:" << sex << endl;
	cout << "Grade:" << grade << endl;
	cout << "GPA:" << gpa << endl;
}

void Student::study_time(float study_time)  //增加GPA
{
	gpa += log(study_time);
	if (gpa > 4.0) gpa = 4.0;
}

int main()
{
	Student Mike = { "Mike Barnes",'M',"Freshman",4 };
	Student Jim = { "Jim Nickerson",'M',"Dophomore",3 };
	Student Jack = { "Jack Indabox",'M',"Junior",2.5 };
	Student Jane = { "Jane Miller",'F',"Senior",3.6 };
	Student Mary = { "Mary Scott",'F',"Senior",2.7 };
	Student stu[5] = { Mike , Jim ,Jack ,Jane ,Mary };
	for (int i = 0; i < 5; i++)
	{
		stu[i].show_myself();
		cout << endl;
	}
	cout << "After studying......" << endl << endl;
	int s_time[5] = { 60,100,40,300,1000 };
	for (int i = 0; i < 5; i++)
	{
		stu[i].study_time(s_time[i]);
		stu[i].show_myself();
		cout << endl;
	}
	return 0;
}



