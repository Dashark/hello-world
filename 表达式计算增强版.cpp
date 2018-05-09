#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;
int isp(char refer){
	switch(refer){
	case '#':return 0;
	case '(':return 1;
	case '*':return 5;
	case '/':return 5;
	case '+':return 3;
	case '-':return 3;
	case ')':return 6;
	}
	return -1;
}
int icp(char refer){
	switch(refer){
	case '#':return 0;
	case '(':return 6;
	case '*':return 4;
	case '/':return 4;
	case '+':return 2;
	case '-':return 2;
	case ')':return 1;
	}
	return -1;
}
int is_num(char a){
	if(a=='.') return 1;
	if(a>='0' && a<='9') return 1;
	return 0;
}
class Calculator{
public:
	int Inputer(const char*);
	int Calculate();
	double Get_result();
private:
	string _expression;
	stack<double> _nums;
	stack<char> _operators;
	double result;
};
int Calculator::Inputer(const char* a){
	if(a==0) return 0;
	_expression = a;
	_expression += '#';
	return 1;
}
int Calculator::Calculate(){
	int i;
	string temp;
	_operators.push('#');
	int mode=0;// if mode is 0 ,it means the stack needs a num , otherwise, it needs a operator.
	for(i=0;i<_expression.size();i++){
		if(_expression[i]=='('){
			_operators.push('(');
			continue;
		}
		if(_expression[i]==')'){
			while(_operators.top()!='('){
				char tp = _operators.top();
				_operators.pop();
				double num1 = _nums.top();_nums.pop();
				double num2 = _nums.top();_nums.pop();  // num2 op num1
				double tp_result;
				switch(tp){
				case '+':
					tp_result = num2+num1;break;
				case '-':
					tp_result = num2-num1;break;
				case '*':
					tp_result = num2*num1;break;
				case '/':
					tp_result = num2/num1;break;
				}
				_nums.push(tp_result);
			}
			_operators.pop();
			continue;
		}
		if(mode==0){
			temp="";
			temp+=_expression[i];
			i++;
			while(is_num(_expression[i])){
				temp += _expression[i];
				i++;
			}
			_nums.push(atof(temp.c_str()));
			mode=1;
			i--;
		} //read num
		else{
				while( _expression[i]=='#' ||(icp(_expression[i]) <= isp(_operators.top()) && _operators.top()!='(') ){
					char tp = _operators.top();
					_operators.pop();
					if(_operators.empty()) break;
					double num1 = _nums.top();_nums.pop();
					double num2 = _nums.top();_nums.pop();  // num2 op num1			
					double tp_result;		
					switch(tp){
					case '+':
						tp_result = num2+num1;break;
					case '-':
						tp_result = num2-num1;break;
					case '*':
						tp_result = num2*num1;break;
					case '/':
						tp_result = num2/num1;break;
					}
					_nums.push(tp_result);
				}
				_operators.push(_expression[i]);
			mode=0;
		}


	}
	this->result = _nums.top();
	return 1;
}
double Calculator::Get_result(){
	return result;
}


class Super_calculator{
public:
	int Inputer(char*);
	int compute();
	double Get_result();
private:
	string _expression;
	double result;
};
double Super_calculator::Get_result(){
	return result;
}

int Super_calculator::Inputer(char *a){
	_expression = a;
	return 1;
}
int Super_calculator::compute(){
	int temp_it = _expression.find("sin");
	while(temp_it >= 0 && temp_it < _expression.size()){

		int start = temp_it;
		temp_it+=4;
		string temp_str="";
		while(_expression[temp_it]!=')'){
			temp_str+=_expression[temp_it];
			temp_it++;
		}
		Calculator my_eval;
		my_eval.Inputer(temp_str.c_str());
		my_eval.Calculate();
		stringstream temp_sstream;
		temp_sstream<<sin(my_eval.Get_result());
		temp_str = temp_sstream.str();
		_expression.replace(start,temp_it-start+1,temp_str);
		temp_it = _expression.find("sin");
	}

	temp_it = _expression.find("cos");
	while(temp_it >= 0 && temp_it < _expression.size()){

		int start = temp_it;
		temp_it+=4;
		string temp_str="";
		while(_expression[temp_it]!=')'){
			temp_str+=_expression[temp_it];
			temp_it++;
		}
		Calculator my_eval;
		my_eval.Inputer(temp_str.c_str());
		my_eval.Calculate();
		stringstream temp_sstream;
		temp_sstream<<cos(my_eval.Get_result());
		temp_str = temp_sstream.str();
		_expression.replace(start,temp_it-start+1,temp_str);
		temp_it = _expression.find("cos");
	}

	temp_it = _expression.find("ln");
	while(temp_it >= 0 && temp_it < _expression.size()){
		int start = temp_it;
		temp_it+=3;
		string temp_str="";
		while(_expression[temp_it]!=')'){
			temp_str+=_expression[temp_it];
			temp_it++;
		}
		Calculator my_eval;
		my_eval.Inputer(temp_str.c_str());
		my_eval.Calculate();
		stringstream temp_sstream;
		temp_sstream<<log(my_eval.Get_result());
		temp_str = temp_sstream.str();
		_expression.replace(start,temp_it-start+1,temp_str);
		temp_it = _expression.find("ln");
	}

	temp_it = _expression.find("pow");
	while(temp_it >= 0 && temp_it < _expression.size()){
		int start = temp_it;
		temp_it+=4;
		string temp_str="";
		while(_expression[temp_it]!=','){
			temp_str+=_expression[temp_it];
			temp_it++;
		}
		double a = atof(temp_str.c_str());
		temp_it++;

		temp_str="";
		while(_expression[temp_it]!=')'){
			temp_str+=_expression[temp_it];
			temp_it++;
		}
		double b = atof(temp_str.c_str());	
		a = pow(a,b);
		stringstream stream;
		stream<<a;
		temp_str = stream.str();
		_expression.replace(start,temp_it-start+1,temp_str);
		temp_it = _expression.find("pow");
	}

	temp_it = _expression.find("abs");
	while(temp_it >= 0 && temp_it < _expression.size()){

		int start = temp_it;
		temp_it+=4;
		string temp_str="";
		while(_expression[temp_it]!=')'){
			temp_str+=_expression[temp_it];
			temp_it++;
		}
		Calculator my_eval;
		my_eval.Inputer(temp_str.c_str());
		my_eval.Calculate();
		stringstream temp_sstream;
		temp_sstream<<abs(my_eval.Get_result());
		temp_str = temp_sstream.str();
		_expression.replace(start,temp_it-start+1,temp_str);
		temp_it = _expression.find("abs");
	}

	Calculator last_eval;
	last_eval.Inputer(_expression.c_str());
	last_eval.Calculate();
	result = last_eval.Get_result();

	return 1;
}