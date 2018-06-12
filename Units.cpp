#include <iostream>
using namespace std;

int main(){
	char s1[100];
	char s2[100];
	char s3[100];
	int i,j,k,t,t1;
	float n,m;
	cin>>n>>s1>>s2;
	if (s1[0]=='n') t=1;else
	if (s1[0]=='u') t=3;else
	if (s1[0]=='m'&&s1[1]=='m') t=6;else
	if (s1[0]=='c') t=7;else
	if (s1[0]=='m') t=9;else
	if (s1[0]=='k') t=12;
	
	if (s2[0]=='n') t1=1;else
	if (s2[0]=='u') t1=3;else
	if (s2[0]=='m'&&s2[1]=='m') t1=6;else
	if (s2[0]=='c') t1=7;else
	if (s2[0]=='m') t1=9;else
	if (s2[0]=='k') t1=12;
	
	if (t1>t) k=t1-t;else k=t-t1;
	m=1;
	for (i=1;i<=k;i++){
		m=m*10;
	}
	if (t1>t) n=n*m;else n=n/m;
    cout<<n;
}
