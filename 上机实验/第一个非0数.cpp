//求一个正整数的阶乘（如2016!)的最后一个非零数字是几？
#include<iostream>
#include<cstdio>

using namespace std;

const int MAX = 10001;
int Num[MAX];
int Num_2[MAX];
int Num_5[MAX];
int Mod[10];
int count = 0;

int main()
{
	for(int i = 1;i <= MAX;i++) Num[i] = i;
	for(int i = 1;i <= MAX;i++)    //去除所有的5
	{
		while(Num[i]%5==0)
		{
			Num[i]/=5;
			count++;
		}
		Num_5[i] = count;
	}
	count = 0;
	for(int i = 1;i <= MAX;i++) //除去所有的2
	{
		while(Num[i]%2==0)
		{
			Num[i]/=2;
			count++;
		}
		Num_2[i] = count;
	}
	for(int i = 1;i <= MAX;i++) Num[i]%=10; //取个位，此时已经没有0
	int Mod_2[4] = {6,2,4,8};
	int Mod_3[4] = {1,3,9,7};
	int Mod_7[4] = {1,7,9,3};
	int Mod_9[4] = {1,9,1,9};  //每个数字4次一循环
	int n; scanf("%d",&n);
	while(n--)
	{
		Mod[2] = Mod[3] = Mod[7] = Mod[9] = 0;
		int num;
		scanf("%d",&num);
		if(num == 1) {printf("1\n"); continue;}
		for(int i = 1;i <= num;i++) Mod[Num[i]]++;
		Mod[3]%=4;
		Mod[7]%=4;
		Mod[9]%=4;
		Mod[2] = (Num_2[num] - Num_5[num]) % 4;
		//printf("2= %d 5 = %d\n",Num_2[num],Num_5[num]);
		//cout << Mod[2] << Mod[3] << Mod[7] << Mod[9] << endl;
		printf("%d\n",Mod_2[Mod[2]] * Mod_3[Mod[3]] * Mod_7[Mod[7]] * Mod_9[Mod[9]]%10);
	}
	return 0;
}
