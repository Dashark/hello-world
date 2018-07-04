#include<stdio.h>
#include<string.h>
#define M 100
int main()
{
	int n=0,m='0',temp;
	int num1[M],num2[M];
	char str1[M],str2[M];
	int i,j,length1,length2,length_max;
	scanf("%d",&n);
	while(n--)
	{
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		memset(str1,0,sizeof(str1));
		memset(str2,0,sizeof(str2));
		scanf("%s",str1);
		scanf("%s",str2);
		length1=strlen(str1);
		length2=strlen(str2);
		length_max=(length1>length2?length1:length2);
		j=0;
		for(i=length1-1;i>=0;i--) num1[j++]=str1[i]-m;
		j=0;
		for(i=length2-1;i>=0;i--) num2[j++]=str2[i]-m;
		for(i=0;i<length_max;i++){
			num2[i]+=num1[i];
			if(num2[i]>9){
				temp=num2[i]/10;
				num2[i]=num2[i]%10;
				num2[i+1]+=temp;
			}
		}
			if(num2[length_max]) printf("%d",num2[length_max]);
			for(i=length_max-1;i>=0;i--) printf("%d",num2[i]);
			printf("\n");
	}
	return 0;
}
