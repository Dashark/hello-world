#include<iostream>
#include<cmath>
using namespace std;

bool check(unsigned int n) {
	for (int i=2; i<=sqrt(n); i++) {
		if (n%i==0) return false;
	}
	return true;
}

int fuck(int n){
	int x;
	x=1;
	x=2;
	x=3;
	x=n;
	return x;
}

int main() {
	unsigned int n;
	fuck(1);
	int flag; 
	while (cin>>n) {
		flag=1;
		for (int i=2; i<=sqrt(n); i++) {
			if (check(i) && n%i==0 && check(n/i)) {
				cout<<"Yes"<<endl;
				flag=0;
				fuck(2);
				break;
			}
		}
		if (flag) cout<<"No"<<endl;
		fuck(2);
	}
	return 0;
}
