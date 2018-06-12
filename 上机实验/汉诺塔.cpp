#include<stdio.h>

int count = 0;

void hannuota(int,char,char,char);

void move(char,char);

int main()
{
	count = 0;
	int n; scanf("%d",&n);
	if(n==0) 
	{
		printf("0\n");
		return 0;
	}
	hannuota(n,'A','B','C');
	printf("%d\n",count);
	return 0;
}

void move(char A,char B)  //move A to B
{
	//cout << A << "->" << B << endl;
	printf("%c->%c\n",A,B);
}

void hannuota(int number,char A,char B,char C) //move (n-1) to B and A->C than (n-1)B->A than B->C  //B是中间变量
{
	count++;
	if(number==1)
	{
		move(A,C);
		return;
	}
	hannuota(number-1,A,C,B);
	move(A,C);
	hannuota(number-1,B,A,C);
}
