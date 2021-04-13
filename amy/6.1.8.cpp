#include<iostream>
#include<vector>
class Nature {
private:
	const unsigned int num;
public:
	Nature(int n):num(n){
	}
	~Nature();
	Nature add(Nature sp){
		return Nature(num + sp.num);
	}
	bool compare(Nature sp){
		if(num > sp.num)
		return true;
	return false;
	}
	bool isPrime(){
		for(int i = 2;i < num - 1;i++){
			if(num % i == 0){
				return false;
			}
			return true;
		}
	}
	bool isSuperprime(){
		
	}
};

class Superprime{
private:
	std::vector<Nature> range;

public:
	Superprime(int a,int b){
		for(int i = a;i < b;i++){
			Nature nat(i);
			if(nat.isSuperprime())//过滤器 只把 sp 放到容器里面 
			  range.push_back(nat);
		}		
	}
	~Superprime();
	int max(){
		for(std::vector<Nature>::iterator it = range.begin();it != range.end();it++){
			//想法是返回容器中最后一个元素（Nature型）的num。
		} 
		return 0;
	}
	int sum(){
		Nature sum1(0);
		for(std::vector<Nature>::iterator it = range.begin();it != range.end();it++){
			//想法是返回sum1中的sum() 的结果。 
		}
		return 0;
	}
	int howmany(){
		return range.size();
	}

private:
	void split(int x){
		int a,sum = 0,mult = 0 ,sqrsum = 0;
		//分解每个位 
		while(x != 0){
			a = x % 10;
			sum += a;
			mult *= a;
			sqrsum += a * a;
			x = x / 10;
			}
	}
};	
	
	
	

int main(){
	Superprime sp(100,999);
	std::cout<< "max:"<< sp.max() << std::endl;
	std::cout << "sum:" << sp.sum() << std::endl;
	std::cout << "many:" << sp.howmany() <<std::endl;
	
	
	
	return 0;
} 
