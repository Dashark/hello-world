#include<iostream>
using namespace std;
int a[100][100];
int dx[4]= {0,1,1,-1};
int dy[4]= {1,-1,0,1};

int swap(int &x,int &y){
	int t;
	t=x;
	x=y;
	y=t;
	return 0;
}


int func(int n) {
	int i,j,t,k;
	i=0;
	j=0;
	t=1;
	a[i][j]=t++;
	k=0;
	while (t<=n*n) {
		switch (k){
			case 0:
				if (i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<n) {i+=dx[k]; j+=dy[k]; a[i][j]=t++; k++;}
				else k++;
			break;
			case 1:
				while (i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<n){i+=dx[k]; j+=dy[k]; a[i][j]=t++;}
				if ((i==0 && j==n-1) || (i==n-1 && j==0)){swap(dx[0],dx[2]); swap(dy[0],dy[2]);}
				k++;
			break;
			case 2:
				if (i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<n) {i+=dx[k]; j+=dy[k]; a[i][j]=t++; k++;}
				else k++;
			break;
			case 3:
				while (i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<n){i+=dx[k]; j+=dy[k]; a[i][j]=t++;}
				if ((i==0 && j==n-1) || (i==n-1 && j==0)){swap(dx[0],dx[2]); swap(dy[0],dy[2]);}
				k=0;
			break;	
		}
		
	}
	return 0;
}


int out(int n){
	for (int i=0;i<n;i++)
		for (int j=n-1;j>=0;j--)
		if (j==0) cout<<a[i][j]<<endl;
		else cout<<a[i][j]<<" ";
		return 0;
}


int main() {
	int n;
	while (cin>>n) {
		func(n);
		out(n);
		swap(dx[0],dx[2]);
		swap(dy[0],dy[2]);
	}

	return 0;
}
