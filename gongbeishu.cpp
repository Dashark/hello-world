#include<stdio.h>

int main()
{
	int m,n,temp;
	int i ;
	printf("input m & n");
	scanf("%d%d",&m,&n);
	if(m<n)
	{
		temp = m;
		m = n;
		n = temp;	
	}
	for(i=m;i>0;i++)
		if(i % m == 0 & i % n == 0){
		
		printf("最小公倍数是：%d",i);
		break;
	}
	return 0;
}

	 
 
