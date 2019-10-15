#include<stdio.h>

int main()
{
	int x,m,n,temp,i=1;
	printf("Input:\n");
	scanf("%d%d",&m,&n);
	if(m<n)
	{	
		temp=m;
		m=n;
		n=temp;
	}
	for(i=1;i<=n;i=i+1){
		
		if(m % i == 0 && n % i == 0)
		 
		  x=i;
	}
	if(x==1){
		printf("»¥ÖÊ"); 
	}
	else{
		printf("²»»¥ÖÊ"); 
	} 

	return 0;
} 
