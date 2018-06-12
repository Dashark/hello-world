// 描述
//
// 求一个矩阵的转置矩阵。
//
// 输入
//
// 输入整数m和n分别代表一个矩阵的行和列。再输入m*n个整数作为矩阵的元素。
//
// 输出
//
// 若m和n能构成矩阵，则输出原矩阵及其转置矩阵；否则输出NO。


#include<iostream>
#include<cstdio>

using namespace std;
int num[100][100];
int m,n;

class Juzhen
{
public:
	Juzhen(int (*a)[100]):p(a){}
	void Prev();
	void End();
private:
	int (*p)[100];
};

void Juzhen::Prev()
{
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++) cout << num[i][j]<<" ";
		cout << endl;
	}
}

void Juzhen::End()
{
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++) cout << num[j][i] << " ";
		cout << endl;
	}
}

int main()
{
	cin >> m >> n;
	if(m > 0&&n > 0)
	{
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++) cin >> num[i][j];
		Juzhen juzhen(num);
		juzhen.Prev();
		juzhen.End();
	}
	else cout << "NO";
	return 0;
}
