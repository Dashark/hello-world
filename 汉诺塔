#include<iostream>
#include<cstring> 
using namespace std;

class longint{
	public:
		/*longint(const longint &x){
			num=x.num;
			p=x.p;
		}*/
		longint operator=(const long &x);
		longint operator*(const int &x);
		longint operator-(const int &x);
		void out(){
			for (int i=p;i>=0;i--)
			if (i==0) cout<<num[i]<<endl;
			else cout<<num[i];
		}
		void clear(){
			memset(num,0,sizeof(num));
			p=0;
		}
	private:
		int num[40];
		int p;
};


longint longint::operator*(const int &x){
	longint ans;
	ans.clear();
	int t=0;
	for (int i=0;i<=this->p;i++){
		ans.num[i]=this->num[i]*x+t;
		t=ans.num[i]/10;
		ans.num[i]%=10;
	}
	if (t!=0) {
		ans.num[this->p+1]=t;
		ans.p=this->p+1;
	}
	else ans.p=this->p;
	return ans;
}

longint longint::operator=(const long &x){
	longint ans;
	ans.clear();
	ans.p=0;
	int t=x;
	while (t>0){
		ans.num[ans.p]=t%10;
		ans.p=ans.p+1;
		t/=10;
	}
	ans.p--;
	return ans;
}


longint longint::operator-(const int &x){
	longint ans;
	ans.clear();
	ans=*this;
	ans.num[0]-=1;
	for (int i=0;i<=this->p;i++){
		if (ans.num[i]<0){
			ans.num[i+1]-=1;
			ans.num[i]+=10;
		}
	}
	if (ans.num[this->p]==0) ans.p=this->p-1;
	else ans.p=this->p;
	return ans;
}

int main(){
	int n;
	longint ans;
	while(cin>>n){
		ans.clear();
		ans=ans=2;
		for(int i=2;i<=n;i++)
		ans=ans*2;
		ans=ans-1;
		ans.out();
	}
	return 0;
}
