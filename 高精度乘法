#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string stra,strb;
	int a[100];
	int b[100];
	int c[200];
	int len1,len2,p,t;
	while (getline(cin,stra)){
		getline(cin,strb);
		memset(a,0,sizeof(a)); 
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		len1=stra.length();
		len2=strb.length();
		for (int i=len1-1;i>=0;i--) a[len1-i-1]=stra[i]-'0';
		for (int i=len2-1;i>=0;i--) b[len2-i-1]=strb[i]-'0';
		for (int i=0;i<len1;i++){
			for (int j=0;j<len2;j++){
				c[i+j]+=a[i]*b[j];
			}
			p=0;
			while (p<200)
			if (c[p]>=10) {
				c[p+1]=c[p+1]+c[p]/10;
				c[p]%=10;
				p++; 
			}else p++;
		}
		p=199;
		while (c[p--]==0);
		for (int i=p+1;i>=0;i--)
		if (i==0) cout<<c[i]<<endl;
		else cout<<c[i];
		
	}
	return 0;
}
