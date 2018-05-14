#include"utility.h"
#include"matrix.h"
int main()
{
	int n;//矩阵的结束
	cout << "请输入矩阵的阶：";
	do    //限制输入结束在1~19
	{
		cin >> n;
		if (n < 1 || n >= 20)
		{
			cout << "n的值应该在1~19之间，请重新输入n:";
		}
	} while (n < 1 || n >= 20);
	Matrix<int>squre(n, n);//n*n阶方阵
	int value = 1, side = n, i, j;//设定当前要填入矩阵的值为1，当前正方形边长为n。

	//生成n*n阶的螺旋矩阵
	for (i = 1; i <= (n + 1) / 2; i++)
	{
		//生成第i个正方形，则其四个顶点的下标为（i,i）（i+side-1,i+side-1）（i+side-1,i）（i,i+side-1）
		if (side == 1)
		{
			squre(1, 1) = value++;
		}
		else
		{
			for (j = i; j < i + side - 1; j++)
			{
				//填入正方形的左边的边
				squre(j, i) = value;
				value++;
			}
			for (j = i; j < i + side - 1; j++)
			{
				//填入正方形的下边的边
				squre(i + side - 1, j) = value++;
			}
			for (j = i + side - 1; j > i; j--)
			{
				//填入正方形的右边的边
				squre(j, i + side - 1) = value++;
			}
			for (j = i + side - 1; j > i; j--)
			{
				//填入正方形的上边的边
				squre(i, j) = value++;
			}
		}
		side = side - 2;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << setw(4) << squre(i, j);
		}
		cout << endl;
	}
	cin.get();
	return 0;
}











