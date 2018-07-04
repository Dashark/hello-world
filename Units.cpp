//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
#include<bits/stdc++.h> 
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
private:
	map<string,Mapsi> total;
	int index;
	string u[4];
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
		for(int i=0;i<4;i++){  //个数
			Mapsi::iterator it1=total[u[i]].find(st1),it2=total[u[i]].find(st2);
			bool flag1=(it1!=total[u[i]].end()&&it2!=total[u[i]].end());
			bool flag2=(it1!=total[u[i]].end()||it2!=total[u[i]].end());
			if(flag2){
				if(flag1){
					cout<<u[i]<<" units transform ";//什么单位的转换
				    index=i;  //遍历，看是否相匹配
				    return true;
				}
				else
				cout<<"can't transform to Basic_units"<<endl;//识别出单位但是无法转换
			} 
		}
		return false;
	}
	double result(double x,string st1,string st2){
		return x*total[u[index]][st2]/total[u[index]][st1];
	}
};

class Combine_units:public units{ //组合单位
private:
	map<string,Mapsi> total;
	int index;
	string u[4];
public:
	Combine_units():index(0){
		
		u[0]="speed_s";     //  length/time
		Mapsi_insert(&total[u[0]],"m/s",1);
		Mapsi_insert(&total[u[0]],"km/s",0.001);
		Mapsi_insert(&total[u[0]],"dm/s",10);
		Mapsi_insert(&total[u[0]],"cm/s",100);
		Mapsi_insert(&total[u[0]],"mm/s",1000);
		Mapsi_insert(&total[u[0]],"um/s",1000000);
		Mapsi_insert(&total[u[0]],"nm/s",1000000000);
		Mapsi_insert(&total[u[0]],"nmi/s",0.00053996);
		Mapsi_insert(&total[u[0]],"mi/s",0.00062137);
		Mapsi_insert(&total[u[0]],"in/s",39.37007874);
		Mapsi_insert(&total[u[0]],"ft/s",3.2808399);
		Mapsi_insert(&total[u[0]],"m/min",60);
		Mapsi_insert(&total[u[0]],"km/min",0.001*60);
		Mapsi_insert(&total[u[0]],"dm/min",10*60);
		Mapsi_insert(&total[u[0]],"cm/min",100*60);
		Mapsi_insert(&total[u[0]],"mm/min",1000*60);
		Mapsi_insert(&total[u[0]],"um/min",1000000*60);
	//	Mapsi_insert(&total[u[0]],"nm/min",1000000000*60);//溢出 
		Mapsi_insert(&total[u[0]],"nmi/min",0.00053996*60);
		Mapsi_insert(&total[u[0]],"mi/min",0.00062137*60);
		Mapsi_insert(&total[u[0]],"in/min",39.37007874*60);
		Mapsi_insert(&total[u[0]],"ft/min",3.2808399*60);
		Mapsi_insert(&total[u[0]],"km/h",0.001*3600);
		Mapsi_insert(&total[u[0]],"dm/h",10*3600);
		Mapsi_insert(&total[u[0]],"cm/h",100*3600);
		Mapsi_insert(&total[u[0]],"mm/h",1000*3600);
	//	Mapsi_insert(&total[u[0]],"um/h",1000000*3600);//溢出 
	//	Mapsi_insert(&total[u[0]],"nm/h",1000000000*3600);//溢出 
		Mapsi_insert(&total[u[0]],"nmi/h",0.00053996*3600);
		Mapsi_insert(&total[u[0]],"mi/h",0.00062137*3600);
		Mapsi_insert(&total[u[0]],"in/h",39.37007874*3600);
		Mapsi_insert(&total[u[0]],"ft/h",3.2808399*3600);
		
		u[1]="work"; 
		Mapsi_insert(&total[u[3]],"j",1);
		Mapsi_insert(&total[u[3]],"kw.h",3600000);
		//还有许多种组合 此处不在赘述 
}
	virtual bool Find(string st1,string st2){
		for(int i=0;i<2;i++){
			Mapsi::iterator it1=total[u[i]].find(st1),it2=total[u[i]].find(st2);
			bool flag1=(it1!=total[u[i]].end()&&it2!=total[u[i]].end());
			bool flag2=(it1!=total[u[i]].end()||it2!=total[u[i]].end());
			if(flag2){
				if(flag1){
					cout<<u[i]<<" units transform ";
				    index=i;
				    return true;
				}
				else
				cout<<"can't transform to Combine_units"<<endl;
			} 
		}
		return false;
	}
	double result(double x,string st1,string st2){
		return x*total[u[index]][st2]/total[u[index]][st1];
	}
}; 

class Power_units:public units{  //基本单位的幂
private:
	map<string,Mapsi> total;
	int index;
	string u[2];
public:
	Power_units():index(0){
u[0]="area";
		Mapsi_insert(&total[u[0]],"m^2",1);
		Mapsi_insert(&total[u[0]],"km^2",0.000001);
		Mapsi_insert(&total[u[0]],"dm^2",100);
		Mapsi_insert(&total[u[0]],"cm^2",10000);
		Mapsi_insert(&total[u[0]],"mm^2",1000000);
		Mapsi_insert(&total[u[0]],"um^2",1000000000000);
		Mapsi_insert(&total[u[0]],"nm^2",1000000000000000000);
		Mapsi_insert(&total[u[0]],"nmi^2",0.00002915568); 
		Mapsi_insert(&total[u[0]],"mi^2",0.00003861007);
		Mapsi_insert(&total[u[0]],"in^2",1559.0031);
		Mapsi_insert(&total[u[0]],"yd^2",1.195989);
		Mapsi_insert(&total[u[0]],"ft^2",10.7639104);
		Mapsi_insert(&total[u[0]],"fur^2",0.00002471054);
	
u[1]="volume";
		Mapsi_insert(&total[u[1]],"m^3",1);
		Mapsi_insert(&total[u[1]],"km^3",pow(0.001,3));
		Mapsi_insert(&total[u[1]],"dm^3",pow(10,3));
		Mapsi_insert(&total[u[1]],"cm^3",pow(100,3));
		Mapsi_insert(&total[u[1]],"mm^3",pow(1000,3));
		Mapsi_insert(&total[u[1]],"um^3",pow(1000000,3));
		Mapsi_insert(&total[u[1]],"nm^3",pow(1000000000,3));
		Mapsi_insert(&total[u[1]],"nmi^3",pow(0.00053996,3)); 
		Mapsi_insert(&total[u[1]],"mi^3",pow(0.00062137,3));
		Mapsi_insert(&total[u[1]],"in^3",pow(39.37007874,3)); 
		Mapsi_insert(&total[u[1]],"yd^3",pow(1.0936133,3));
		Mapsi_insert(&total[u[1]],"ft^3",pow(3.2808399,3));
		Mapsi_insert(&total[u[1]],"fu^3",pow(0.00497097,3));
	} 
	virtual bool Find(string st1,string st2){
		for(int i=0;i<2;i++){
			Mapsi::iterator it1=total[u[i]].find(st1),it2=total[u[i]].find(st2);
			bool flag1=(it1!=total[u[i]].end()&&it2!=total[u[i]].end());
			bool flag2=(it1!=total[u[i]].end()||it2!=total[u[i]].end());
			if(flag2){
				if(flag1){
					cout<<u[i]<<" units transform ";
				    index=i;
				    return true;
				}
				else
				cout<<"can't transform to Power_units"<<endl;
			} 
		}
		return false;
	}
	double result(double x,string st1,string st2){
		return x*total[u[index]][st2]/total[u[index]][st1];
	}
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
		Combine_units Cu;
		if(Cu.Find(st1,st2)){
			cout<<"result: "<<Cu.result(n,st1,st2)<<endl;
		}
		else{
			Power_units Pu;
			if(Pu.Find(st1,st2)){
				cout<<"result: "<<Pu.result(n,st1,st2)<<endl;
			}
			else 
			cout<<"My program is too low to identify your units."<<endl;
		}
	return 0;
}
} 
