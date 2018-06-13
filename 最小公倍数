#include<iostream>
using namespace std;

int ans(int a,int b){
	if (a%b==0) return b;
	else {
		return ans(b,a%b);
	}
}


int main(){
	int n,a,b;
	while(cin>>n){
		for (int i=0;i<n;i++){
			cin>>a>>b;
			cout<<ans(a,b)<<endl;
		}
	}
	
	
	return 0;
}
