#include<iostream>
using namespace std;
const int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int n,m1,m2,d1,d2,time;
	long ans;
	cin>>n;
	while (n>0){
		cin>>m1>>d1>>ans>>m2>>d2;
		time=0;
		for (int i=m1;i<m2;i++)
		time+=m[i-1];
		time=time-d1+d2;
		while(time>0){
			ans*=2;
			time--; 
		}
		cout<<ans<<endl;
		n--;
	}
	return 0;
}
