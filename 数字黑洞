#include<iostream>
#include<cmath>
using namespace std;

int num(int *a) {
	int ans;
	ans=0;
	for (int i=0; i<4; i++) {
		ans=ans+a[i]*pow(10,3-i);
	}
	return ans;
}


int func(int n) {
	int a[4]= {0};
	int b[4]= {0};
	int p=0,t;
	while (n>0) {
		a[p++]=n%10;
		n/=10;
	}
	p--;
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			if (a[j]<a[j+1]) {
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
	for (int i=0; i<=3; i++) b[i]=a[3-i];
	return num(a)-num(b);
}


int main() {
	int n,ans;
	while (cin>>n) {
		ans=0;
		while (n!=6174) {
			n=func(n);
			ans++;
		}
		cout<<ans<<endl;
	}

	return 0;
}
