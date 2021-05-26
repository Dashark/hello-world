#include<iostream>
#include<string>
#include<cmath>
#include<list>
#include<iomanip>
using namespace std;
class Student
{
	public:
		Student(){
			
		}
		~Student(){
			
		}
		void set()
		{
			string xing,ming;
			int xingbie,nianji;
			float gpa1;
			cout<<"依次输入该学生的姓、名、性别、年级、gpa"<<endl;
		
			cin>>xing>>ming>>xingbie>>nianji>>gpa1;
			this->lastname=xing;
			this->firstname=ming;
			this->lastname=xing;
			this->sex=xingbie;
			this->grade=nianji;
			this->gpa=gpa1;
		}
		void show_myself()
		{
			cout<<"学生姓名:";
			cout<<firstname<<" "<<lastname;
			cout<<" 性别："; 
			if(sex==0)
			cout<<"woman";
			else if(sex==1)
			cout<<"man";
			cout<<" 年级：";
			switch(grade)
			{
				case 1:
					cout<<"大一";
					break;
				case 2:
					cout<<"大二";
					break;
				case 3:
				    cout<<"大三";
				    break;
				case 4:
					cout<<"大四";
					break;
			}
			cout<<" gpa:";
			if(gpa>=4.0)
			cout<<"4.0"<<endl;
			else
			cout<<setprecision(1)<<fixed<<gpa<<endl;
		}
		void study_time(float x){
			this->gpa=gpa+log(x/60);
		}
	private:
		
		string firstname;
		string lastname;
		int sex;
		int grade;
		float gpa;
};
int main(void)
{
    list<Student> Student_list;
	Student std[100];
	int i;
    list<Student>::iterator it;
    cout<<"注：英文名前面是名，后面是姓；性别用0或1表示（0代表女性，1代表男性）；"<<endl; 
	cout<<"    年级用1（大一）、2（大二）、3（大三）4（大四）表示"<<endl;
	cout<<"学习时间超过60分钟则gpa增长，学习分钟不足60分钟则gpa减少"<<endl; 
    for(i=0;i<5;i++)
	{
		cout<<"输入第"<<i+1<<"个学生的基本信息"<<endl;
		std[i].set(); 
	}	
    for(i=0;i<5;i++)
    {
    	std[i].show_myself();
	}
	for(i=0;i<5;i++)
	{
		int study_time;
		cout<<"输入第"<<i+1<<"个学生的学习时间"<<endl;
		cin>>study_time; 
		std[i].study_time(study_time);
		Student_list.push_back(std[i]);
	}
    for(it=Student_list.begin();it!=Student_list.end();it++)
	{
		(*it).show_myself();
	}
	return 0;
}
