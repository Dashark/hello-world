/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.
例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
//2018/11/14 更新
#include <stdio.h>
#include <stdbool.h>
int main(){
	int n,i=0,j,k,s,t,N;
	int qw=200;
	int sum,pdt,sqarsum;int sum2=0;
	bool x,y,c,d;
	int a[10000],b[10000];
	for(n=100;n<=9999;n++){
		x=true;y=true;c=true;d=true;
		N=n;t=1;
		for(j=1;j<=n;j++){
			if(j!=1&&j!=n&&n%j==0){
				x=false;
			}
		}
		while(N>9){
		N/=10;
		t*=10;
		}
		j=0;
		while(t>0){
		a[j]=n/t;
		n%=t;
		t/=10;
		j++;
		} 
		sum=a[0];
		pdt=a[0];
		sqarsum=a[0]*a[0];
		for(k=1;k<j;k++){
			sum=sum+a[k];
			pdt=pdt*a[k];
			sqarsum=sqarsum+a[k]*a[k];
		}
		for(s=1;s<=sum;s++){
			if(s!=1&&s!=sum&&sum%s==0){
				y=false;
			}
		}
		for(s=1;s<=pdt;s++){
			if(s!=1&&s!=pdt&&pdt%s==0){
				c=false;
			}
		}
		for(s=1;s<=sqarsum;s++){
			if(s!=1&&s!=sqarsum&&sqarsum%s==0){
				d=false;
			}
		}
		if(x==true&&y==true&&c==true&&d==true){
			sum2=sum2+n;
			b[i]=n;
			i++;
		}
	}
	printf("%d %d %d",i,sum2,b[i-1]);
} 
