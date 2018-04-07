#include <stdio.h>
using namespace std;
int is_prime(int a){
	if(a<=1) return 0;
	if(a==2) return 1;
	for(int i=2;i<a;i++){
		if(a%i==0) return 0;
	}
	return 1;
}
int he(int a){
	int total=0;
	while(a!=0){
		total+=a%10;
		a/=10;
	}
	return total;
}
int ji(int a){
	int total=1;
	while(a!=0){
		total*=a%10;
		a/=10;
	}
	return total;
}
int pf(int a){
	int total=0;
	while(a!=0){
		total+= (a%10)*(a%10);
		a/=10;
	}
	return total;
}
int main(){
	int ss[1000];int top=0;
	for(int i=100;i<10000;i++){
		if(is_prime(i) && is_prime(he(i)) && is_prime(ji(i)) && is_prime(pf(i)) ){
			ss[top]=i;
			top++;
		}
	}
	int ct=0;
	for(int j=0;j<top;j++) ct+=ss[j];
	printf("%d %d %d",top,ct,ss[top-1]);
	return 0;
}
