#include<iostream>
using namespace std;

int done(int m,int n){
	if(m==0 || n==1) return 1;
	if (n>m) return done(m,m);
	else return done(m,n-1)+done(m-n,n);
}

int main(){
	int m,n;
	while(cin>>m>>n){
	
		cout<<done(m,n)<<endl;
		
	}
	return 0;
}
