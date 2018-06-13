#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;
map<string, int> unit_list;
class length_unit {
public:
	length_unit(string name, double digit) :unit_name(name), temp(digit) {
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
	void getallunit();//获取全部单位的值
	void printans(string name);//打印所需单位
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
void length_unit::getallunit() {
	switch (unit_list[unit_name])
	{
	case 1: {
		metre = 1000.0*temp;
		break;
	}
	case 2: {
		metre = temp;
		break;
	}
	case 3: {
		metre = temp / 10.0;
		break;
	}
	case 4: {
		metre = temp / 100.0;
		break;
	}
	case 5: {
		metre = temp / 1000.0;
		break;
	}
	case 6: {
		metre = temp / 1000000.0;
		break;
	}
	case 7: {
		metre = 500.0*temp;
		break;
	}
	case 8: {
		metre = temp / 0.3;
		break;
	}
	case 9: {
		metre = temp / 3.0;
		break;
	}
	case 10: {
		metre = temp / 30.0;
		break;
	}
	case 11: {
		metre = temp / 300.0;
		break;
	}
	case 12: {
		metre = temp / 3000.0;
		break;
	}
	case 13: {
		metre = temp * 1852.0;
		break;
	}
	case 14: {
		metre = temp * 1609.344;
		break;
	}
	case 15: {
		metre = temp * 0.9144;
		break;
	}
	case 16: {
		metre = temp * 0.3048;
		break;
	}
	case 17: {
		metre = temp * 0.0254;
		break;
	}
	}
	kilometre = metre / 1000.0;
	decimetre = metre * 10.0;
	centimetre = metre * 100.0;
	millimetre = metre * 1000.0;
	micrometre = metre * 1000000.0;
	li = metre / 500.0;
	zhang = 0.3*metre;
	chi = 3.0*metre;
	cun = 30.0*metre;
	fen = 300.0*metre;
	lii = 3000.0*metre;
	nautical_mile = metre / 1852.0;
	mile = metre / 1609.344;
	yard = metre / 0.9144;
	foot = metre / 0.3048;
	inch = metre / 0.0254;
}
void length_unit::printans(string name)
{
	switch (unit_list[name]) {
	case 1: {
		cout << kilometre << "公里" << endl;
		break;
	}
	case 2: {
		cout << metre << "米" << endl;
		break;
	}
	case 3: {
		cout << decimetre << "分米" << endl;
		break;
	}
	case 4: {
		cout << centimetre << "厘米" << endl;
		break;
	}
	case 5: {
		cout << millimetre << "毫米" << endl;
		break;
	}
	case 6: {
		cout << micrometre << "微米" << endl;
		break;
	}
	case 7: {
		cout << li << "里" << endl;
		break;
	}
	case 8: {
		cout << zhang << "丈" << endl;
		break;
	}
	case 9: {
		cout << chi << "尺" << endl;
		break;
	}
	case 10: {
		cout << cun << "寸" << endl;
		break;
	}
	case 11: {
		cout << fen << "分" << endl;
		break;
	}
	case 12: {
		cout << lii << "厘" << endl;
		break;
	}
	case 13: {
		cout << nautical_mile << "海里" << endl;
		break;
	}
	case 14: {
		cout << mile << "英里" << endl;
		break;
	}
	case 15: {
		cout << yard << "码" << endl;
		break;
	}
	case 16: {
		cout << foot << "英尺" << endl;
		break;
	}
	case 17: {
		cout << inch << "英寸" << endl;
		break;
	}
	}
}
class temperature_unit {
public:
	temperature_unit(string name, double digit) :unit_name(name), temp(digit) {
		unit_list["摄氏度"] = 18;
		unit_list["华氏度"] = 19;
		unit_list["开氏度"] = 20;
		unit_list["兰氏度"] = 21;
		unit_list["列氏度"] = 22;
	}
	~temperature_unit() {}
	void getallunit();//获取全部单位值
	void printans(string name);//打印所需单位
private:
	double C;//摄氏度
	double F;//华氏度
	double K;//开氏度
	double Ra;//兰氏度
	double Re;//列氏度
	double temp;
	string unit_name;//输入的单位名称
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
	switch (unit_list[name])
	{
	case 18:
	{
		cout << C << "℃\n" << endl;
		break;
	}
	case 19:
	{
		cout << F << "℉\n" << endl;
		break;
	}
	case 20:
	{
		cout << K << "K\n" << endl;
		break;
	}
	case 21:
	{
		cout << Ra << "°Ra\n" << endl;
		break;
	}
	case 22:
	{
		cout << Re << "°Re\n" << endl;
		break;
	}
	}

}
int main() {
	string from, to;
	double temp;
	cin >> temp >> from >> to;
	temperature_unit a(from, temp);
	length_unit b(from, temp);
	b.getallunit();
	b.printans(to);
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