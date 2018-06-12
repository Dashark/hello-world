#include<iostream>
#include<cmath> 
using namespace std;

bool check(int x){
	for (int i=2;i<=sqrt(x);i++)
	if (x%i==0) return false;
	return true;
}


int main(){
	int n;
	while (cin>>n){
		for (int i=2;i<=n/2;i++)
		if (check(i) && check(n-i)){
			cout<<i<<"+"<<n-i<<endl;
			break;
		}
	}
	return 0;
}
