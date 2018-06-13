//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
#include<iostream>
#include<map>
#include<string>
using namespace std;
typedef map<string,double> Mapsi;
class units{
public://单位成员  在单位组合中添加新单位的方法 
	void Mapsi_insert(Mapsi *mapsi,string ch,double n){
		mapsi->insert(Mapsi::value_type(ch,n));
	}
	virtual bool Find(string,string)=0;
private: 
};
class Basic_units:public units{

public:
	Basic_units():index(0){
		//长度单位预置
		//常规应该是length.insert(Mapsi::value_type("m",1))，但我把insert函数抽象进了父类 
		u[0]="length";
		Mapsi_insert(&total[u[0]],"m",1);
		Mapsi_insert(&total[u[0]],"km",1000);
		Mapsi_insert(&total[u[0]],"dm",0.1);
		Mapsi_insert(&total[u[0]],"cm",0.01);
		Mapsi_insert(&total[u[0]],"mm",0.001);
		Mapsi_insert(&total[u[0]],"um",0.000001);
		Mapsi_insert(&total[u[0]],"nm",0.000000001);
		
		
		
		u[1]="weight";
		u[2]="time";
		u[3]="ele";
		
		
		
		
		
		
	}
	virtual bool Find(string st1,string st2){
		return true;
	}
	double result(int x,string st1,string st2){
		return x*total[u[index]][st2]/total[u[index]][st1];
	}
private:
	map<string,Mapsi> total;
	int index;
	string u[4];
};
int main(){
	int n;
	string st1,st2;
	cout<<"Please put in a number：";
	cin>>n;
	cout<<"Please put in it's unit：";
	cin>>st1; 
	cout<<"Please put in it's next unit：" ;
	cin>>st2;
	Basic_units Bu;
	if(Bu.Find(st1,st2)){
		cout<<"result: "<<Bu.result(n,st1,st2)<<endl;
	}
		else{
			cout<<"My program is too low to identify your units."<<endl;
		}
	return 0;
}
