//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
#include<iostream>
#include<map>
#include<string>
#include<cmath> 
using namespace std;
typedef map<string,double> Mapsi;
class units{
public://单位成员insert  在单位组合中添加新单位的方法 
	void Mapsi_insert(Mapsi *mapsi,string ch,double n){
		mapsi->insert(Mapsi::value_type(ch,n));
	}
	virtual bool Find(string,string)=0;//由于find函数在两个类里都被需要，所以定义一个纯虚函数作为父类的方法； 
private: 
};
class Basic_units:public units{
public:
	Basic_units():index(0){
		//长度单位预置
		//常规应该是length.insert(Mapsi::value_type("m",1))，但我把insert函数抽象进了父类 
		u[0]="length";
		Mapsi_insert(&total[u[0]],"m",1);
		Mapsi_insert(&total[u[0]],"km",0.001);
		Mapsi_insert(&total[u[0]],"dm",10);
		Mapsi_insert(&total[u[0]],"cm",100);
		Mapsi_insert(&total[u[0]],"mm",1000);
		Mapsi_insert(&total[u[0]],"um",1000000);
		Mapsi_insert(&total[u[0]],"nm",1000000000);
		Mapsi_insert(&total[u[0]],"nmi",0.00053996);//海里 
		Mapsi_insert(&total[u[0]],"mi",0.00062137);//英里
		Mapsi_insert(&total[u[0]],"in",39.37007874);//英寸 
		Mapsi_insert(&total[u[0]],"yd",1.0936133);//码 
		Mapsi_insert(&total[u[0]],"ft",3.2808399);//英尺 
		Mapsi_insert(&total[u[0]],"fur",0.00497097);//弗隆 
		Mapsi_insert(&total[u[0]],"里",0.002);
		Mapsi_insert(&total[u[0]],"尺",3.00030003);
		Mapsi_insert(&total[u[0]],"分",300.030003);
		Mapsi_insert(&total[u[0]],"丈",0.30003);
		Mapsi_insert(&total[u[0]],"寸",30.0030003);
		Mapsi_insert(&total[u[0]],"厘",3000.30003);
		
		u[1]="weight";
		Mapsi_insert(&total[u[1]],"g",1);
		Mapsi_insert(&total[u[1]],"kg",0.001);
		Mapsi_insert(&total[u[1]],"t",0.000001);
		Mapsi_insert(&total[u[1]],"mg",1000);
		Mapsi_insert(&total[u[1]],"dwt",0.73487421);//英钱 
		Mapsi_insert(&total[u[1]],"oz",0.03527396);// 盎司
		Mapsi_insert(&total[u[1]],"lb",0.00220462);//磅 
		Mapsi_insert(&total[u[1]],"dr",0.56438339);//打兰 
		Mapsi_insert(&total[u[1]],"两",0.02);
		Mapsi_insert(&total[u[1]],"钱",0.2);
		Mapsi_insert(&total[u[1]],"市斤",0.002);
		
		u[2]="time";
		Mapsi_insert(&total[u[2]],"week",1);
		Mapsi_insert(&total[u[2]],"day",7);
		Mapsi_insert(&total[u[2]],"h",168);
		Mapsi_insert(&total[u[2]],"min",10080);
		Mapsi_insert(&total[u[2]],"s",604800);
		Mapsi_insert(&total[u[2]],"ms",604800000);
		Mapsi_insert(&total[u[2]],"us",604800000000);//μ用u代替 
		Mapsi_insert(&total[u[2]],"ns",604800000000000);
		Mapsi_insert(&total[u[2]],"month",0.23333333333333);
		Mapsi_insert(&total[u[2]],"year",0.019178082191781);
		
		u[3]="ele";
		Mapsi_insert(&total[u[3]],"A",1);
		Mapsi_insert(&total[u[3]],"kA",pow(10,-3));
		Mapsi_insert(&total[u[3]],"MA",pow(10,-6));
		Mapsi_insert(&total[u[3]],"GA",pow(10,-9));
		Mapsi_insert(&total[u[3]],"mA",pow(10,3));
		Mapsi_insert(&total[u[3]],"uA",pow(10,6));
		Mapsi_insert(&total[u[3]],"nA",pow(10,9));
		Mapsi_insert(&total[u[3]],"C/s",10);
		
	}
	virtual bool Find(string st1,string st2){
		for(int i=0;i<4;i++){
			Mapsi::iterator it1=total[u[i]].find(st1),it2=total[u[i]].find(st2);
			if(it1!=total[u[i]].end()&&it2!=total[u[i]].end()){
				index=i;
				return true; 
			} 
		}
		return false;
	}
	double result(double x,string st1,string st2){
		return x*total[u[index]][st2]/total[u[index]][st1];
	}
private:
	map<string,Mapsi> total;
	int index;
	string u[4];
};
int main(){
	double n;
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
