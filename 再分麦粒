#include<iostream>
#include<cstring>
#define N 500
using namespace std;

class longint {
	public:
		void format() {
			num[0]=1;
			p=0;
		}
		void clear() {
			memset(num,0,sizeof(num));
			p=0;
		}
		void out() {
			for (int i=N-1; i>=0;i--)
				if (i==0) cout<<num[i]<<endl;
				else cout<<num[i];
		}
		longint operator+(const longint &x);
		longint operator*(const int &x);
	private:
		int num[N];
		int p;
};


longint longint::operator+(const longint &x) {
	longint ans;
	ans.clear();
	int t,len;
	if (this->p>x.p) len=this->p;
	else len=x.p;
	t=0;
	for (int i=0; i<=len; i++) {
		ans.num[i]=this->num[i]+x.num[i]+t;
		t=ans.num[i]/10;
		ans.num[i]%=10;
	}
	if (t!=0) {
		if (len<N-1){ ans.num[len+1]=t; ans.p=len+1; }
		else ans.p=N-1;
	}
	else ans.p=len;
	return ans;
}


longint longint::operator*(const int &x){
	longint ans;
	int t=0;
	for (int i=0;i<=this->p;i++){
		ans.num[i]=(this->num[i])*x+t;
		t=ans.num[i]/10;
		ans.num[i]%=10;
	}
	if (t!=0){
		if (this->p<N-1){ ans.num[(this->p)+1]=t; ans.p=(this->p)+1;}
		else ans.p=N-1;
	}
	else ans.p=this->p;
	return ans;
}


int main() {
	longint ans,temp;
	int n;
	while(cin>>n){
		ans.clear();
		ans.format();
		temp.clear();
		temp.format();
		while (n>1){
			temp=temp*2;
			ans=ans+temp;
			n--;
		}
		ans.out();
	}
	return 0;
}
