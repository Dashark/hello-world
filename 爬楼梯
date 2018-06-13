#include<iostream>
using namespace std;

int t; 

void func(int n){
	if (n==1) t++;
	else if (n==2){
		t++;
		func(n-1);
	}
	else if (n>2){
		func(n-1);
		func(n-2);
	}
}

int main(){
	int n;
	while (cin>>n){
		t=0;
		func(n);
		cout<<t<<endl;	
	} 
	return 0;
}
