#include"Prime.h"
#include<math.h>

Prime::Prime(int low , int high){
	for(int i = low ; i <= high ; i++){
		if(judgePrime(i)){
			p.push_back(i);//push进容器中 
		}
	}
}

void Prime::showPrime(){
	for(int i = 0 ; i < p.size() ; i++){
		cout << p[i] << " ";//循环输出 
	}
	cout << endl;
}

int Prime::getSize(){
	return p.size();//获取个数 
}

//int *Prime::getPrime(){
//	int *arr = new int[p.size()];//动态分配数组以存储素数 
//	for(int i = 0 ; i < p.size() ; i++){
//		arr[i] = p[i];
//	}
//	return arr;
//}

superPrime::superPrime(int low , int high){
	findPrime(low, high); 
}

//void superPrime::findsuperPrime(int low , int high){
//	Prime get;//创建一个实例 
//	get.findPrime(low , high); 
//	int *super = get.getPrime();//获得存有素数的数组 
//	for(int i = 0 ; i < get.getSize() ; i++){
//		if(judgeSuperPrime(super[i])){//判断是否为超级素数 
//			sp.push_back(super[i]); //push进vector 
//		}
//	}
//	delete super;
//}

void superPrime::findPrime(int low , int high){
	vector<int> prime;
	for(int i = low ; i <= high ; i++){
		if(Prime::judgePrime(i)){
			prime.push_back(i);//push进容器中 
		}
	}
//	for(int i = 0 ; i < prime.size() ; i++){
//		cout << prime[i] << " ";
//	}
//	cout << prime.size() << endl;
	for(int i = 0 ; i < prime.size() ; i++){
		if(superPrime::judgePrime(prime[i])){
			sp.push_back(prime[i]); 
		}
	}
} 

void superPrime::showPrime(){
	for(int i = 0 ; i < sp.size() ; i++){
		cout << sp[i] << " ";
	}
	cout << endl;
}  

bool Prime::judgePrime(int a){
	if(a == 2){//2单独判断 
		return true;
	}
	for(int i = 2 ; i <= sqrt(a) + 1 ; i++){
		if(a % i == 0){
			return false;
		}
	}
	return true;
}

bool superPrime::judgePrime(int a){
	int eve[20] = {0} , i = 0 , sum = 0 , largesum = 0;//sum为各位数的和，largesum是各位数平方和，i是脚标 
	while(a){//循环提取各位数 
		eve[i] = a % 10;
		sum += eve[i];
		largesum += eve[i] * eve[i];
		i++;
		a /= 10;
	}
	if(Prime::judgePrime(sum) && Prime::judgePrime(largesum) && Prime::judgePrime(a)){
		return true;
	}
	return false;
}
