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

int main() {

	string from, to;

	double temp;

	cin >> temp >> from >> to;

	pressure_unit a(from, temp);

	weight_unit b(from, temp);

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
