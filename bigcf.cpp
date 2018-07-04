#include<stdio.h>
#include<string.h>
#define M 100
int main()
{
	int n=0,m='0',temp,carry;
	int num1[M],num2[M],num3[M];
	char str1[M],str2[M];
	int i,j,k,length1,length2,length_max;
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		memset(num3,0,sizeof(num3));
		memset(str1,0,sizeof(str1));
		memset(str2,0,sizeof(str2));
		scanf("%s",str1);
		scanf("%s",str2);
		length1=strlen(str1);
		length2=strlen(str2);
		length_max=length1+length2;
		j=0;
		for(i=length1-1;i>=0;i--) num1[j++]=str1[i]-m;
		j=0;
		for(i=length2-1;i>=0;i--) num2[j++]=str2[i]-m;
		for(i=0;i<length2;i++){
			for(j=0;i<length1;j++){
				temp=num1[j]*num2[i];
				num3[i+j]=temp;
			}
			for(k=0;k<=j+i-1;k++){
				if(num3[k]>9){
					carry=num3[k]/10;
					num3[k]=num3[k]%10;
					num3[k+1]+=carry;
				}
			}
			j=0;
		}
			if(num3[length_max]) printf("%d",num3[length_max]);
			for(i=length_max-1;i>=0;i--) printf("%d",num3[i]);
			printf("\n");
	return 0;
}
