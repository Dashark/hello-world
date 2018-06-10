#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;
map<string, int> unit_list;
class length_unit{
public:
	length_unit(string name,double digit) :unit_name(name),temp(digit){
		unit_list["公里"] = 1;
		unit_list["米"] = 2;
		unit_list["分米"] = 3;
		unit_list["厘米"] = 4;
		unit_list["毫米"] = 5;
		unit_list["微米"] = 6;
		unit_list["里"] = 7;
		unit_list["丈"] = 8;
		unit_list["尺"] = 9;
		unit_list["寸"] = 10;
		unit_list["分"] = 11;
		unit_list["厘"] = 12;
		unit_list["海里"] = 13;
		unit_list["英里"] = 14;
		unit_list["码"] = 15;
		unit_list["英尺"] = 16;
		unit_list["英寸"] = 17;
	}
	~length_unit() {}
	void getallunit();
private:
	double kilometre;//公里
	double metre;//米
	double decimetre;//分米
	double centimetre;//厘米
	double millimetre;//毫米
	double micrometre;//微米
	double li;//里
	double zhang;//丈
	double chi;//尺
	double cun;//寸
	double fen;//分
	double lii;//厘
	double nautical_mile;//海里
	double mile;//英里
	double yard;//码
	double foot;//英尺
	double inch;//英寸
	double temp;
	string unit_name;//输入单位名称
};
class temperature_unit {
public:
	temperature_unit(string name,double digit):unit_name(name),temp(digit){
		unit_list["摄氏度"] = 18;
		unit_list["华氏度"] = 19;
		unit_list["开氏度"] = 20;
		unit_list["兰氏度"] = 21;
		unit_list["列氏度"] = 22;
	}
	~temperature_unit(){}
	void getallunit();
	void printans(string name);
private:
	double C;//摄氏度
	double F;//华氏度
	double K;//开氏度
	double Ra;//兰氏度
	double Re;//列氏度
	double temp;
	string unit_name;
};
void temperature_unit::getallunit() {
	switch (unit_list[unit_name])
	{
	case 18:
	{
		C = temp;
		F = C * 1.8 + 32.0;
		K = C + 273.15;
		Ra = C * 1.8 + 32 + 459.67;
		Re = C * 0.8;
		break;
	}
	case 19:
	{
		F = temp;
		C = (F - 32.0) / 1.8;
		K = C + 273.15;
		Ra = C * 1.8 + 32 + 459.67;
		Re = C * 0.8;
		break;
	}
	case 20:
	{
		K = temp;
		C = K - 273.15;
		F = C * 1.8 + 32.0;
		Ra = C * 1.8 + 32 + 459.67;
		Re = C * 0.8;
		break;
	}
	case 21:
	{
		Ra = temp;
		C = (Ra - 32 - 459.67) / 1.8;
		F = C * 1.8 + 32.0;
		K = C + 273.15;
		Re = C * 0.8;
		break;
	}
	case 22:
	{
		Re = temp;
		C = Re * 1.25;
		F = C * 1.8 + 32.0;
		K = C + 273.15;
		Ra = C * 1.8 + 32 + 459.67;
		break;
	}
	}
}
void temperature_unit::printans(string name) {
	switch (unit_list[unit_name])
	{
	case 18:
	{
		cout << C << "℃\n";
		break;
	}
	case 19:
	{
		cout << F << "℉\n";
		break;
	}
	case 20:
	{
		cout << K << "K\n";
		break; 
	}
	case 21:
	{
		cout << Ra << "°Ra\n";
		break;
	}
	case 22:
	{
		cout << Re << "°Re\n";
		break;
	}
	}

}
int main() {
	string from,to;
	double temp;
	cin >> temp >> from >> to;
	temperature_unit a(from,temp);
	a.getallunit();
	a.printans(to);
	return 0;
}
//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的