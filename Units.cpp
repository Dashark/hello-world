#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Unit{
public:
	Unit(string a,double b):name(a),rate(b){}
	const string get_n(){return name;}
	const double get_r(){return rate;}
private:
	string name;
	double rate;	
};
vector< vector<Unit> > Units;
void info(){
	cout<<"Welcome , this is an unit-convertor . \n";
	cout<<"To use this program , you need the commands below :\n";
	cout<<" $query X : convert X into other units";
	cout<<" $cls  : clear the screen\n";
	cout<<" $show : show the available units\n";
	cout<<" $help : show this tip\n";
	cout<<" $add X Y Z : add X = Z * Y to the unit-system \n";
	cout<<" $create X  : Create a new type of units , the basic is X";
	cout<<"\n";
	cout<<"An complete example :\n\n";
	cout<<"$query 15kg\n";
	cout<<" : 15kg = 15000g = 0.015t\n";
	cout<<"add Superkg kg 15\n";
	cout<<"$query 15kg\n";
	cout<<" : 15kg = 15000g = 0.015t = 1Superkg\n";
	cout<<"$create RMB\n";
	cout<<"$add dollar RMB 6\n";
	cout<<"$query 5dollar\n";
	cout<<" : 5dollar = 30RMB\n\n";

}
void init(){
	vector<Unit> weights;
	weights.push_back(Unit("g",1));
	weights.push_back(Unit("kg",1000));
	weights.push_back(Unit("t",1000000));
	vector<Unit> lengths;
	lengths.push_back(Unit("cm",1));
	lengths.push_back(Unit("dm",10));
	lengths.push_back(Unit("m",100));
	lengths.push_back(Unit("km",1000));
	Units.push_back(weights);
	Units.push_back(lengths);
}

int main(){
	string command;
	init();
	info();
	while(1){
		fflush(stdin);
		cout<<"$";
		cin>>command;
		if(command == "query"){
			int value,flag=1;
			int i,j;
			cin>>value>>command;
			for(i=0;i<Units.size();i++){
				for(j=0;j<Units[i].size();j++){
					if(Units[i][j].get_n() == command){
						flag=0;
						cout<<" : "<<value<<command;
						for(int m=0;m<Units[i].size();m++){
							if(m==j) continue;
							cout<<" = "<<value*Units[i][j].get_r()/Units[i][m].get_r()<<Units[i][m].get_n();
						}
						cout<<'\n';
					}
					if(flag==0) break;
				}
				if(flag==0) break;
			}
		}
		else if(command == "add"){
			string tp1,tp2;
			double tp3;
			int i,j,flag=1;
			cin>>tp1>>tp2>>tp3;
			for(i=0;i<Units.size();i++){
				for(j=0;j<Units[i].size();j++){
					if(Units[i][j].get_n() == tp2){
						flag = 0;
						Units[i].push_back(Unit(tp1,tp3*Units[i][j].get_r()));
					}
					if(flag==0) break;
				}
				if(flag==0) break;
			}
		}
		else if(command == "cls")
			system("cls");
		else if(command == "create"){
			string ts;
			cin>>ts;
			vector<Unit> newtype;
			newtype.push_back(Unit(ts,1));
			Units.push_back(newtype);
		}
		else if(command == "help")
			info();
		else if(command == "show"){
			int i,j;
			for(i=0;i<Units.size();i++){
				cout<<" : ";
				for(j=0;j<Units[i].size();j++)
					cout<<Units[i][j].get_n()<<'\t';
				cout<<endl;
			}
		}
	}
	return 0;
}
