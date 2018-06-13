#include<iostream>
#include<cstring>
using namespace std;
int main(){
	long int x,y,z;
	int n,flag;
	string p,q,r;
	cin>>n;
	while (n>0){
		cin>>p>>q>>r;
		flag=1;
		for (int i=2;i<=16;i++){
			if (strtol(p.c_str(),nullptr,i)) x=strtol(p.c_str(),nullptr,i);
			else continue;
			if (strtol(q.c_str(),nullptr,i)) y=strtol(q.c_str(),nullptr,i);
			else continue;
			if (strtol(r.c_str(),nullptr,i)) z=strtol(r.c_str(),nullptr,i);
			else continue;
			if (x*y==z) {
				flag=0;
				cout<<i<<endl;
				break;
			}
		}
		if (flag) cout<<0<<endl;
		n--;
	}
	return 0;
}
