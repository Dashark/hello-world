#include <stdio.h>

int main()
{	
	int n,i,j,l,x=1;
	while (x==1)
	{
	n = 5;
	int a[n];
	printf("Enter 5 number:\n");
	for (i = 0; i < 5; i++)
	  scanf("%d", &a[i]);
	
	for (l = 0;l < 5; l++) 
	  {
	  for (i=0;a[i+1]>a[i];i++)
	  {
	  	  j = a[i];
	      a[i] = a[i+1];
	      a[i+1] = j;
	  }
	}

	for (i = 0; i < 5; i++)
	  printf("%d", a[i]);
	  
	printf("\nY or N:\n");
	scanf("%d", &x);
 	}
}
