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
			if(nat.isSuperprime())//������ ֻ�� sp �ŵ��������� 
			  range.push_back(nat);
		}		
	}
	~Superprime();
	int max(){
		for(std::vector<Nature>::iterator it = range.begin();it != range.end();it++){
			//�뷨�Ƿ������������һ��Ԫ�أ�Nature�ͣ���num��
		} 
		return 0;
	}
	int sum(){
		Nature sum1(0);
		for(std::vector<Nature>::iterator it = range.begin();it != range.end();it++){
			//�뷨�Ƿ���sum1�е�sum() �Ľ���� 
		}
		return 0;
	}
	int howmany(){
		return range.size();
	}

private:
	void split(int x){
		int a,sum = 0,mult = 0 ,sqrsum = 0;
		//�ֽ�ÿ��λ 
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
