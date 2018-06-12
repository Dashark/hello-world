#include<iostream>
#include<string>
#include<cstdio>

const int START = 1;
const int Month[13] = {-1,31,-1,31,30,31,30,31,31,30,31,30,31};
const std::string WEEK[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int JudgeYear(int n)
{
	if(n%4==0 && n%100!=0 || n%400==0) return true;
	else return false;
}

class Date
{
public:
	Date(int a,int b,int c):Year(a),Mon(b),Day(c) { Week = JudgeWeek();}
	~Date(){};
	int JudgeWeek();
	void Cout_Week();
private:
	int Year,Mon,Day;
	int Week;
};

int Date:: JudgeWeek()
{
	int Sum_1 = 0,Sum_2 = 0;
	//calculate Year days
	for(int i = START;i < Year;i++)
	{
		if(JudgeYear(i)==1) Sum_1 += 366;
		else Sum_1 += 365;
	}
	//calculate Month days
	for(int i = 1;i < Mon;i++)
	{
		if(i == 2)
		{
			if(JudgeYear(Year)) Sum_2 += 29;
			else Sum_2 += 28;
		}
		else Sum_2 += Month[i];
	}
	Sum_2 += Day;
	return (Sum_2+Sum_1)%7 + 1;
}

void Date:: Cout_Week()
{
	std::cout << Week << '\n';
}

int main()
{
	int a,b,c;
	scanf("%d-%d-%d",&a,&b,&c);
	Date date(a,b,c);
	date.Cout_Week();
	return 0;
}
