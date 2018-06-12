#include<iostream>
using namespace std;
int main(){
	string stra,strb;
	int a[200]={0};
	int b[200]={0};
	int c[201]={0};
	int len1,len2,len,p,t;
	while (getline(cin,stra)){
		getline(cin,strb);
		len1=stra.length();
		for (int i=len1-1;i>=0;i--) a[len1-i-1]=stra[i]-'0';
		len2=strb.length();
		for (int i=len2-1;i>=0;i--) b[len2-i-1]=strb[i]-'0';
		if (len1>len2) len=len1;
		else len=len2;
		p=0;t=0;
		while (p<len){
			c[p]=(t+a[p]+b[p])%10;
			t=(t+a[p]+b[p])/10;
			p++;
		}
		if (t>0) c[p++]=t;
		for (int i=p-1;i>=0;i--)
		if (i==0) cout<<c[i]<<endl;
		else cout<<c[i];
	}
	return 0;
}
