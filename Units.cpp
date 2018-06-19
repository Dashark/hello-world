#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>

using namespace std;

map<string, int> unit_list;
class weight_unit
{
	public:
		weight_unit(string name,double digit) :unit_name(name), temp(digit) {
			unit_list["千克"]= 23; 
			unit_list["公吨"]= 24; 
			unit_list["克"]=   25;
			unit_list["毫克"]= 26; 
			unit_list["微克"]= 27; 
			unit_list["格令"]= 28; 
			unit_list["打兰"]= 29; 
			unit_list["盎司"]= 30; 
			unit_list["磅"]=   31; 
 			unit_list["英石"]= 32; 
			unit_list["英担"]= 33; 
			unit_list["短吨"]= 34;
			unit_list["长吨"]= 35; 
			unit_list["斤"]=   36;
			unit_list["两"]=   37;
			unit_list["担"]=   38;
		}
		~length_unit() {}

	void getallunit();//获取全部单位的值

	void printans(string name);//打印所需单位
	private:

	double kilogram;//千克 
	double gongdun;//公吨 
	double gram;//克 
	double mg;//毫克 
	double mcg;//微克 
	double grain;//格令 
	double dram;//打兰 
	double ounce;//盎司 
	double pound;//磅 
	double yingshi;//英石 
	double yingdan;//英担 
	double dd;//短吨 
	double cd;//长吨 
	double jin;//斤 
	double liang;//两 	
	double dan;//担 	
	double temp;
	string unit_name;//输入单位名称
};
void weight_unit::getallunit() {
	switch (unit_list[unit_name])
	{
	case 23: {
		gram = 1000.0*temp;
		break;
	}
	case 24: {
		gram = 1000000.0*temp;
		break;
	}
	case 25: {
		gram = temp ;
		break;
	}
	case 26: {
		gram = 0.001*temp;
		break;
	}
	case 27: {
		gram = temp / 1000000.0;
		break;
	}
	case 28: {
		gram = 0.065*temp ;
		break;
	}
	case 29: {
		gram = 1.772*temp;
		break;
	}
	case 30: {
		gram = 28.35*temp;
		break;
	}
	case 31: {
		gram = 0.4536*temp;
		break;
	}
	case 32: {
		gram = 6350.0*temp;
		break;
	}
	case 33: {
		gram = 50800.0*temp ;
		break;
	}
	case 34: {
		gram = 907000.0*temp ;
		break;
	}
	case 35: {
		gram = 1016000.0*temp ;
		break;
	}
	case 36: {
		gram = temp * 500.0;
		break;
	}
	case 37: {
		gram = temp * 50.0;
		break;
	}
	case 38:{
		gram = temp*50000.0;
		break;
	}
	}
	 kilogram=gram/1000.0; 
	 gongdun=gram/1000000.0; 
	 mg=gram*1000.0; 
	 mcg=gram*1000000.0; 
 	grain=gram/0.065; 
	 dram=gram/1.772; 
	 ounce=gram/28.35;
	pound=gram/453.6;
	 yingshi=gram/6350.0;
	 yingdan=gram/50800.0;
	 dd=gram/907000.0;
	 cd=gram/1016000.0;
	 jin=gram/500.0; 
	liang=gram/50.0;	
	 dan=gram/50000.0; 
}
void weight_unit::printans(string name)
{
	switch (unit_list[name]) {
	case 23: {
		cout << kilogram << "千克" << endl;
		break;
	}
	case 24: {
		cout << gongdun << "公吨" << endl;
		break;
	}
	case 25: {
		cout << gram << "克" << endl;
		break;
	}
	case 26: {
		cout << mg << "毫克" << endl;
		break;
	}
	case 27: {
		cout << mcg << "微克" << endl;
		break;
	}
	case 28: {
		cout << grain << "格令" << endl;
		break;
	}
	case 29: {
		cout << dram << "打兰" << endl;
		break;
	}
	case 30: {
		cout << ounce << "盎司" << endl;
     	break;
	}
	case 31: {
		cout << pound<< "磅" << endl;
		break;
	}
	case 32: {
		cout << yingshi << "英石" << endl;
		break;
	}
	case 33: {
		cout << yingdan << "英担" << endl;
		break;
	}
	case 34: {
		cout << dd << "短吨" << endl;
		break;
	}
	case 35: {
		cout << cd << "长吨" << endl;
		break;
	}
	case 36: {
		cout << jin << "斤" << endl;
		break;
	}
	case 37: {
		cout << liang << "两" << endl;
		break;
	}
	case 38：{
		cout << dan <<"担" <<endl;
		break; 

	}
	}
}
class pressure_unit {
public:
	pressure_unit(string name, double digit) :unit_name(name), temp(digit) {
		unit_list["巴"] = 39;
		unit_list["兆帕"] = 40;
		unit_list["千帕"] = 41;
		unit_list["帕"] = 42;
		unit_list["标准大气压"] = 43;
	}
	~pressure_unit() {}
	void getallunit();//获取全部单位值
	void printans(string name);//打印所需单位
private:
	double bar;//巴 
	double MPa;//兆帕 
	double KPa;//千帕 
	double Pa;//帕 
	double ATM;//标准大气压 
	double temp;
	string unit_name;//输入的单位名称

};
void pressure_unit::getallunit() {
	switch (unit_list[unit_name])
	{
	case 39:
	{
		bar = temp;	
		Pa = bar*100000.0;
		Kpa = Pa/1000.0;
		Mpa = Pa/1000000.0;
		ATM = Pa/103330.0;
		break;
	}
	case 40:
	{
		 MPa = temp;
		Pa = 1000000.0*MPa;
		Kpa = Pa/1000.0;
		ATM = Pa/103330.0;
		bar = Pa/100000.0;
		break;
	}
	case 41:
	{
		KPa = temp;
		Pa = KPa*1000.0;
		ATM = Pa/103330.0;
		bar = Pa/100000.0;
		MPa = Pa/1000000.0;
		break;
	}
	case 42:
	{
		Pa = temp;
		MPa = Pa /1000000.0;
		Kpa = Pa/1000.0;
		ATM = Pa/103330.0;
		bar = Pa/100000.0;
		break;
	}
	case 43:
	{
		ATM= temp;
		Pa = ATM*101325.0;
		Kpa = Pa/1000.0;
		MPa = Pa /1000000.0;
		bar = Pa/100000.0;
		break;
	}
	}
}
void pressure_unit::printans(string name) {
	switch (unit_list[name])
	{
	case 39:
	{
		cout << bar << "bar\n" << endl;
		break;
	}
	case 40:
	{
		cout << MPa << "MPa\n" << endl;
		break;
	}
	case 41:
	{
		cout << KPa << "KPa\n" << endl;
		break;
	}
	case 42:
	{
		cout << Pa << "Pa\n" << endl;
		break;
	}
	case 43:
	{
		cout << ATM << "ATM\n" << endl;
		break;
	}
	}
}
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
	double li;//里	double zhang;//丈
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
class power_unit {
public:
	power_unit(string name, double digit) :unit_name(name), temp(digit) {
		unit_list["瓦"] = 44;
		unit_list["千瓦"] = 45;
		unit_list["英制马力"] = 46;
		unit_list["米制马力"] = 47;
	}
	~power_unit() {}
	void getallunit();//获取全部单位值
	void printans(string name);//打印所需单位
private:
	double W;//瓦
	double kW;//千瓦
	double hp;//英制马力
	double ps;//米制马力
	double temp;
	string unit_name;//输入的单位名称
};
void power_unit::getallunit() {
	switch (unit_list[unit_name])
	{
	case 44:
	{
		W = temp;
		break;
	}
	case 45:
	{
		W = temp * 1000.0;
		break;
	}
	case 46:
	{
		W = temp * 745.699872;
		break;
	}
	case 47:
	{
		W = temp * 735.49875;
		break;
	}
	kW = W / 1000.0;
	hp = W / 745.699872;
	ps = W / 735.49875;
	}
}
void power_unit::printans(string name) {
	switch (unit_list[name])
	{
	case 44:
	{
		cout << W << "W\n" << endl;
		break;
	}
	case 45:
	{
		cout << kW << "kW\n" << endl;
		break;
	}
	case 46:
	{
		cout << hp << "hp\n" << endl;
		break;
	}
	case 47:
	{
		cout << ps << "ps\n" << endl;
		break;
	}
	}
}
int main() {
	string from, to;
	double temp;
	cout << "请依次输入数值、原单位、新单位（请以中文全称输入单位名称）" << endl;
	cin >> temp >> from >> to;
	pressure_unit a(from, temp);
	weight_unit b(from, temp);
	temperature_unit c(from, temp);
	power_unit d(from, temp);
	length_unit e(from, temp);
	b.getallunit();
	b.printans(to);
	a.getallunit();
	a.printans(to);
	c.getallunit();
	c.printans(to);
	d.getallunit();
	d.printans(to);
	e.getallunit();
	e.printans(to);
	return 0;
}
//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
