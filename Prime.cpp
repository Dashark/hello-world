#include <iostream>
using namespace std;

class Prime{
public:
	Prime(int a){num =a;}
	int getvalue(){return num;}
	int pf(int);
	int ji(int);
	int he(int);
	int is_prime(int);
private:
	int num;
};

int Prime::is_prime(int a){
	if(a<=1) return 0;
	if(a==2) return 1;
	for(int i=2;i<a;i++){
		if(a%i==0) return 0;
	}
	return 1;
}
int Prime::he(int a){
	int total=0;
	while(a!=0){
		total+=a%10;
		a/=10;
	}
	return total;
}
int Prime::ji(int a){
	int total=1;
	while(a!=0){
		total*=a%10;
		a/=10;
	}
	return total;
}
int Prime::pf(int a){
	int total=0;
	while(a!=0){
		total+= (a%10)*(a%10);
		a/=10;
	}
	return total;
}


int main(){
	int ct=0,num=0,biggest=0;
	for(int i=100;i<10000;i++){
		Prime pm(i);
		if(pm.is_prime(pm.getvalue() )  && pm.is_prime(pm.he(pm.getvalue()))&&  pm.is_prime(pm.ji(pm.getvalue())) &&pm.is_prime(pm.pf(pm.getvalue()))){
			biggest=i;
			ct+=i;
			num++;
		}
	}
	printf("%d %d %d",num,ct,biggest);
	return 0;
}
