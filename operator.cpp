#include<iostream>
using namespace std;
class Matrix 
{public:
	Matrix();//默认构造函数 
	friend Matrix operator+(Matrix &a,Matrix &b);//重载函数作为友元函数 
	void input();
	void display();
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
void Matrix::input()
{
	cout<<"Please input the value of matrix:"<<endl;
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++) cin>>mat[i][j];
	}
}
void Matrix::display()
{
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++) cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	
}
int main()
{
	Matrix a,b,c;
	a.input();
	b.input();
	cout<<endl<<"matrix a:"<<endl;
	a.display();
	cout<<endl<<"matrix b:"<<endl;
	b.display();
	c=a+b;
	cout<<endl<<"matrix c:"<<endl;
	c.display() ;
	return 0;
}
