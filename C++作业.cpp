#include<stdio.h>
void maopao(int a[],int n);
int main()
{
	int a[20];
	int o=0;
	   for(int i=100;i<=999;i++)
	   {
	   	int c=i%10,b=(i-i%10)%10,a=i%100;
	   	for(int x=2;x<i;x++)
	   	{
	   		if(i%x==0)
	   		{
	   			break;
			   }		
			   else
			   {
			   	for(int y=2;y<a*b*c;y++)
			   	{
			   		if((a*b*c)%y==0)
			   		{
			   			break;
					   }
					   else
					   {
					   	for(int z=2;z<(a+b+c);z++)
					   	{
					   		if((a+b+c)%z==0)
					   		{
					   			break;
							   }
							   else
							   {
							   	for(int m=2;m<(a*a+b*b+c*c);m++)
							   	{
							   		if((a*a+b*b+c*c)%m==0)
							   		{
							   			break;
										} 
										else
										{
											a[o]=i;///Having problem.Debug it
											o++;
										}
								   }
							   }
						   }
					   }
				   }
			   	
			   }
			   
			   
			   
		   }
	   	
		} 
		printf("The number: %d\n",sizeof(a));
		int sum=0;
	for(int q=0;q<sizeof(a);q++)
	{
		sum += a[q];
	}
	printf("The sum: %d\n",sum);
	maopao(a,sizeof(a));
	int t=sizeof(a)-1;
	printf("The biggest number: %d\n",a[t]);
	
	return 0;
}



void maopao(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	 {
		for(j=0;j<n-i-1;j++)
		 {
		 	if( a[j]>a[j+1] )
		    	{
		    		int temp;
		    		temp=a[j];
		    		a[j]=a[j+1];
		    		a[j+1]=temp;
			    }  
		 }
	 }
	
	
}
