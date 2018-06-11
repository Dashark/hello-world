///:Unit_Transformer.cpp
//the codes' purpose is to accomplish the function of Unit Convertor

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<iomanip>
#include<cctype>

using namespace std;

// the class defination
class Unit_ALL;
class INPUTER;
class TRANSFORMER;
class LENTH;
class QUALITY;
class TIME;
class PRESSURE;
class SPEED;
//:~end defination

//class Unit_ALL
class Unit_ALL    //All units and some useful string
{
public:
	enum
	{
		Lenth = 1, Quality,Time,Pressure,Speed
	};
	const string head = "Transformer:>>";
	const string undefined = "undefined";
	const string Error = "The input format is wrong, please re-enter it.\
\nThe format is:\n1.help\n2.srcUnit + desUnit\n3.digit \
+ srcUnit + desUnit\nplease input help to know more";
	const string Version = "The procedure is  to accomplish the function of Unit Convertor\n\
The input format is:\n1.help\n2.srcUnit + desUnit\n3.digit\
+ srcUnit + desUnit\nAnd the Precision reserved 6 decimal places";
	//Lenth 
	const string Unit_Lenth[11] =
	{
		"m","km","cm","dm","um","nm","in","ft","Cun","Chi","Zhang"
	};
	const double DUnit_Lenth[11]=
	{
		1,0.001,100,10,10e6,10e9,39.37007874016,3.280839895013,30,0.002,3
	};
	//Quality
	const string Unit_Quality[8] = 
	{
		"kg","g","mg","ug","t","lb","gr","Jin"
	};
	const double DUnit_Quality[8] = 
	{
		1,1000,10e6,10e9,0.001,2.204622621849,15432.35835294,2
	};
	//TIME
	const string Unit_Time[9] = 
	{
		"d","week","h","yr","min","s","ms","us","ns"
	};
	const double DUnit_Time[9] = 
	{
		1,1/7,24,1/365,60,8.64e4,8.64e7,8.64e10,8.64e13
	};
	//Pressure
	const string Unit_Pressure[7] = 
	{
		"Pa","Mpa","kpa","hpa","psf","atm","mmHug"
	};
	const double DUnit_Pressure[7] = 
	{
		1,1e-6,1e-3,0.01,0.02088543512121,9.8692e-6,0.101972
	};
	//SPEED
	const string Unit_Speed[6] = 
	{
		"m/s","km/s","in/s","c","km/h","mach"
	};
	const double DUnit_Speed[6] =
	{
		1,0.01,39.370079,3.3356e-9,0.001,0.0029386
	};
};
//:~end

//INPUTER defination
class INPUTER: public Unit_ALL/* public HELPER ,public TRANSFORMER*/          //输入模块，参数为传入的字符串命令
{										   					  //派生与帮助模块和转换模块
public:
	INPUTER(const string&);
	constexpr static const double standard_digit = 1;         //数值标准量
	void getError();
	int judge_Unit(const string&);
private:
	double digit;     //转换数值
	string srcUnit;   //源单位
	string desUnit;   //目标单位
	int flag;         //标志命令是否符合标准
};
//:~end INPUTER defination

class TRANSFORMER
{
	
};

int main()
{
	cout << "the codes' purpose is to accomplish the function of Unit Convertor" << endl;
	cout << "the author is LinWeijun"<<endl<<endl;
	cout << "Transformer:>>";
	while(true)
	{
		string cmd; getline(cin,cmd);
		INPUTER inputer(cmd);
	}
	return 0;
}//:~


//class INPUTER
INPUTER::INPUTER(const string& cmd):digit(1),srcUnit(undefined),desUnit(undefined),flag(false)
{
	vector<string> str;         //存储每一个命令
	string temp;
	int lenth = 0;
	stringstream ss_cmd(cmd);
	while(ss_cmd >> temp) 
	{
		str.push_back(temp);
		lenth++;
	}
	if(lenth==1 && str[0]=="help")
	{
		flag = true;
		cout << Version << endl;
	}
	else if(lenth == 2)
	{
		if(judge_Unit(str[0])==judge_Unit(str[1])&&judge_Unit(str[0]))
		{
			cout << "two unit transform" << endl;
			srcUnit = str[0];
			desUnit = str[1];
			flag = true;
		}
		else flag = false;
	}
	else if(lenth == 3)
	{
		bool mid = true;
		for(int i = 0;i < str[0].size();i++)
		{
			if(isalpha(str[0][i]))
			{
				mid = false;
				break;
			}
		}
		if(mid&&judge_Unit(str[2])==judge_Unit(str[1])&&judge_Unit(str[1]))
		{
			stringstream change(str[0]); change >> digit;
			cout << endl << "digit is " << digit << endl;
			cout <<fixed<<setprecision(6)<< "three unit transform" << endl;
			srcUnit = str[1];
			desUnit = str[2];
			flag = true;
			
		}
		else flag = false;
	}
	else flag = false;
	if(flag == false) cout << Error << endl;
	cout << endl << head;
	
}

void INPUTER::getError()
{
	cout << Error << endl;
}


int INPUTER::judge_Unit(const string& target)
{
	for(int i = 0;i < 11;i++)
	{
		if(Unit_Lenth[i] == target) return Lenth;
	}
	for(int i = 0;i < 8;i++)
	{
		if(Unit_Quality[i] == target) return Quality;
	}
	for(int i = 0;i < 9;i++)
	{
		if(Unit_Time[i] == target) return Time;
	}
	for(int i = 0;i < 7;i++)
	{
		if(Unit_Pressure[i] == target) return Pressure;
	}
	for(int i = 0;i < 6;i++)
	{
		if(Unit_Speed[i] == target) return Speed;
	}
	return false;
}

//: ~class INPUTER end

