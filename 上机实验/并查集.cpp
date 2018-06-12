// Description:
// 第一行有两个n, m。表示集合的个数与操作的个数。
// 接下来有m行，每行有以下两种操作的其中一种。
// U x y 将集合x与集合y合并
// Q x y 询问集合x与集合y是否被合并在了一起，如果已被合并在一起输出Y，否则输出N。
//
// Sample Input:
// 4 9
// Q 1 2
// U 1 2
// Q 1 2
// Q 3 4
// U 3 4
// Q 3 4
// Q 2 4
// U 1 3
// Q 2 4
//
// Sample Output:
// N
// Y
// N
// Y
// N
// Y
//
// Hint:
// 对于80%的数据1 <= n, m <= 1000
// 对于100%的数据1 <= n, m <= 1000000

#include <iostream>

using namespace std;

int father[1000100];

int find(int x)
{
	if(father[x] != x)
	{
		return father[x]=find(father[x]);
	}
	return x;
}

int main()
{
	int n,m; scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) father[i] = i;
	while(m--)
	{
		char cmp;
		int target_1, target_2;
		scanf("%c%d%d",&cmp,&target_1,&target_2);
		printf("%c %d %d",cmp,target_1,target_2);
		if(cmp == 'U')
		{
			target_1 = find(target_1);
			target_2 = find(target_2);
			father[target_1] = target_2;
		}
		else
		{
			target_1 = find(target_1);
			target_2 = find(target_2);
			if(target_1 == target_2) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}

// int father[50002],a,b,m,n,p;
// int find(int x)
// {
// 	if(father[x]!=x)
// 	x=find(father[x]);
// /*
// x代表例题中的人，father[x]中所存的数代表这一集合中所有人都与一个人有亲戚关系
// 相当于例题中第一个集合所有的元素都与第一个元素有亲戚关系
// 搜索时只要找元素所指向的father[x]=x的元素(即父元素)
// 然后比较两个元素的父元素是否相同就可以判断其关系
// */
// 	return x;
// }
// int main()
// {
//   int i;
//   scanf("%d%d%d",&n,&m,&p);
//   for(i=1;i<=n;i++)
//     father[i]=i;
//   for(i=1;i<=m;i++)
//     {
//       scanf("%d%d",&a,&b);
//       a=find(a);
//       b=find(b);
//       father[a]=b;
//     }
//   for(i=1;i<=p;i++)
//     {
//       scanf("%d%d",&a,&b);
//       a=find(a);
//       b=find(b);
//       if(a==b)
//         printf("Yes\n");
//       else
//         printf("No\n");
//     }
//   return 0;
// }
