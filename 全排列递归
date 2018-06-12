#include<iostream>
#include<string.h>
using namespace std;

int out(int *ans,int n){
	for (int i=0;i<n;i++)
	if (i==n-1) cout<<ans[i]<<endl;
	else cout<<ans[i];
	return 0;
}

bool check(int *ans,int n,int x){
	for (int i=0;i<n;i++)
	if (ans[i]==x) return false;
	return true;
}


int done(int *ans,int n,int &p){
	if (p==n) {
		out(ans,n);
	}
	else {
		for (int i=1;i<=n;i++)
		if (check(ans,p,i)){
			ans[p]=i;
			done(ans,n,++p);
			p--;
		}
	}
}


int main(){
	int n,p;
	int ans[10];
	while (cin>>n){
		p=0;
		memset(ans,0,sizeof(ans)); 
		done(ans,n,p);
	}
	return 0;
}
