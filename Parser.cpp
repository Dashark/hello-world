#include <iostream>
#include <string>
#include <vector>
using namespace std;
int is_num(char a){
	if( (a>='0' && a<='9') || (a=='+' || a=='-'))
		return 1;
	return 0;
}
struct node{
	int value;
	vector<node> sons;
};
class BTG{
public:
	BTG(string ips):index(0),input_str(ips){}
	node* parse_N();
private:
	string input_str;
	int index;
	vector<node> parse_G();
	void next();
	int read_value();
};
void BTG::next(){
	while(input_str[index]==' ')
		index++;
}
int BTG::read_value(){
	int result = 0;
	int np = 0;
	if(input_str[index]=='-')
		np = 1;
	if(input_str[index]=='-' || input_str[index]=='+')
		index++;
	while(is_num(input_str[index])){
		result = result*10 + (input_str[index]-'0');
		index ++;
	}
	if(np==1) result *= -1 ;
	next();
	return result;
}
node* BTG::parse_N(){
	next();
	node *tmp = NULL;
	if( is_num(input_str[index])==1 ){
		tmp = new node;
		int value = read_value();
		tmp -> value = value;
		if(input_str[index]=='('){
			index++;next();
			tmp -> sons = parse_G();
			index++;next();
		}
	}
	return tmp;
}
vector<node> BTG::parse_G(){
	next();
	vector<node> rts;
	if( is_num(input_str[index]) == 1 ){
		node* temp = parse_N();
		rts.push_back(*temp);
		if(input_str[index]==','){
			index++;next();
			vector<node> new_cm = parse_G();
			rts.insert(rts.end(),new_cm.begin(),new_cm.end());
		}
	}
	return rts;
}
void Visit(node *tgt){
	cout<<tgt->value<<' ';
	for(int i=0;i<tgt->sons.size();i++){
		cout<<tgt->value<<':';
		Visit(&tgt->sons[i]);
	}
}
int main(){
	while(1){
	char temp[10086];
	cin.getline(temp,10086);
	string a(temp);
	BTG tst(a);
	node * reslt  = tst.parse_N();
	Visit(reslt);
	cout<<endl;
	}
	return 0;
}