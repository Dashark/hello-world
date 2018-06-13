#include<iostream>
#include<cstring>
using namespace std;
const int N=11;

int n;


struct MAT {
	int x[N][N];
};

MAT operator *(MAT a,MAT b) {
	MAT c;
	int i,j,k;
	memset(c.x,0,sizeof(c.x));
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			for (k=0; k<n; k++)
				c.x[i][j]+=a.x[i][k]*b.x[k][j];
			c.x[i][j]%=9973;
		}
	}
	return c;
}

MAT operator ^ (MAT a,int k) {
	MAT c;
	for (int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			c.x[i][j]=(i==j);
	}

	for (; k; k>>=1) {
		if (k&1) {
			c=c*a;
		}
		a=a*a;
	}
	return c;
}

int main() {
	MAT x;
	int t,ans,k;
	cin>>t;
	while (t>0) {
		cin>>n>>k;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				cin>>x.x[i][j];
		/*
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++)
				cout<<x.x[i][j]<<" ";
				cout<<endl;
		}
		*/


		x=x^k;
		
		ans=0;
		for (int i=0; i<n; i++) {
			ans+=x.x[i][i];
			ans%=9973;
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
