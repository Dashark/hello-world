#include<iostream>
using namespace std;

int check(int x,int y) {
	if (x%y==0) return y;
	else check(y,x%y);
}

bool done(int x,int y) {
	if (check(x,y)!=1) return false;
	return true;
}


int main() {
	int n,ans;
	int a[600];
	while (cin>>n && n!=0) {
		ans=0;
		for (int i=0; i<n; i++) cin>>a[i];
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (a[i]<a[j] && done(a[i],a[j])) ans+=1;
		cout<<ans<<endl;
	}
	return 0;
}
