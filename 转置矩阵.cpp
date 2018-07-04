#include<iostream>
using namespace std;
void convert(int a[m][n],b[n][m])
{
	int i,j,m,n;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			b[n][m]=a[m][n];
		}
	}
}
int main()
{
	int i,j,n,m;
	cin>>m>>n;
	int a[10][10],b[10][10];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	if(m>=2) {
		for(i=0;i<m;i++){
			for(j=0;j<n;i++){
				cout<<a[i][j]<<' ';
			}
			cout<<endl;
		}
		convert(int a[m][n],b[n][m]);
		for(i=0;i<m;i++){
			for(j=0;j<n;i++){
				cout<<a[i][j]<<' ';
			}
			cout<<endl;
		}
	}else cout<<NO;
	return 0;
}
void convert(int a[m][n],b[n][m])
{
	int i;j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			b[n][m]=a[m][n];
		}
	}
}
