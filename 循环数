#include<iostream>
using namespace std;

bool check(int *a,int *b,int n){
	int p,t;
	for (int i=0;i<n;i++){
		p=i;
		t=0;
		while (t<n){
			if (a[t]==b[p]){
				t++;
				if (p==n-1) p=0;
				else p++;
			}
			else break;
		}
		if (t==n) return true;
	}
	return false;
}

int main(){
	int a[256]={0};
	int b[256]={0};
	int len,t,flag;
	string str;
	while(cin>>str){
		len=str.length();
		for (int i=0;i<len;i++) a[i]=str[i]-'0';
		flag=1;
		for (int i=1;i<=len;i++){
			t=0;
			for (int j=len-1;j>=0;j--){
				b[j]=(a[j]*i+t)%10;
				t=(a[j]*i+t)/10;
			}
			if (t!=0){
				flag=0;
				break;
			}
			//system("pause");
			if (!check(a,b,len)){
				flag=0;
				break;
			}
		}
		if (flag) cout<<str<<" is cyclic"<<endl;
		else cout<<str<<" is not cyclic"<<endl;
	}
	return 0;
}
