#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#define N 5


    std::string Mike[]={"Mike Barnes","Male","1","4.0",};
    std::string Jim[]={"Jim Nickerson","Male","2","3.0",};
    std::string Jack[]={"Jack Indabox","Male","3","2.5",};
    std::string Jane[]={"Jane Miller","Female","4","3.6",};
    std::string Mary[]={"Mary Scott","Female","4","2.7",};
/*struct STUDENT
{
    std::string name;
    std::string sex;
    int grade;
    float gpa;
}stu1;
STUDENT students[N]
{
    NAME[0],SEX[0],1,4.0,
    NAME[1],SEX[0],2,3.0,
    NAME[2],SEX[0],3,2.5,
    NAME[3],SEX[1],4,3.6,
    NAME[4],SEX[1],4,2.7,
};*/

class Student
{
    private:
    std::string name;
    std::string sex;
    int grade;
    double gpa;
    
    public:
    Student(std::string str[])
    {
        name=str[0];
        sex=str[1];
        grade=std::stoi(str[2]);
        gpa=std::stod(str[3]);
    }
    ~Student()
    {

    }
    void show_myself()
    {
        std::cout<<name<<" "<<grade<<" "
        <<sex<<" "<<gpa<<std::endl;
    }
    float study_time(double study_time)
    {
        gpa+=log10(study_time);
        return gpa=gpa>4.0? 4.0: gpa;
    }
};

int main()
{
    Student student1(Mike);
    Student student2(Jim);
    Student student3(Jack);
    Student student4(Jane);
    Student student5(Mary);
    Student students[N]={student1,student2,student3,student4,student5};
    for(int i=0;i<N;i++)
    {
        students[i].show_myself();
    }
    double studytime[N]={60.0,100.0,40.0,300.0,1000.0};
    for(int i=0;i<N;i++)
    {
        students[i].study_time(studytime[i]);
    }
        for(int i=0;i<N;i++)
    {
        students[i].show_myself();
    }
    return 0;
}