//第五题： 
#include<iostream>
using namespace std;
class Matrix 
{public:
	Matrix();//默认构造函数 
	friend Matrix operator+(Matrix &a,Matrix &b);//重载函数作为友元函数 
	friend ostream& operator<<(ostream&,Matrix&);
	friend istream& operator>>(istream&,Matrix&);
private:
	int mat[2][3];
};
Matrix::Matrix()
{
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			mat[i][j]=0;
		}
	}
}
Matrix operator+(Matrix &a,Matrix &b)
{
	Matrix c;
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			c.mat[i][j]=a.mat[i][j]+b.mat[i][j];
		}
	}
	return c;
}
ostream& operator<<(ostream& out,Matrix&m)
{
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++) out<<m.mat[i][j]<<" ";
		out<<endl;
	}
	return out;
}
istream& operator>>(istream& in,Matrix&m)
{
	cout<<"Input the value of matrix:"<<endl;
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++) in>>m.mat[i][j];
	}
	return in;
}

int main()
{
	Matrix a,b,c;
	cin>>a;
	cin>>b;
	cout<<endl<<"Matrix a:"<<endl<<a<<endl;
	cout<<endl<<"Matrix b:"<<endl<<b<<endl; 
	c=a+b;
	cout<<endl<<"Matrix c=Matrix a + Matrix b:"<<endl<<c<<endl;
	return 0;
}
