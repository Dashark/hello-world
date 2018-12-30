#include <stdio.h>
int main(){
	int n=0,i,y=0,j,k,a[10],b,c,x,t,d;
	for(i=10;i<100;i++){
		j=0;
		do{
		a[j]=i%10;
		i/=10;
		j++;
		}while(i>0);
		for(k=0;k<=j;k++){
			b+=a[k];
			c*=a[k];
			d+=a[k]*a[k];
		}
	for(n=2;n<b;n++){
	if(b%n==0){
	for(n=2;n<=c;n++){
		if(c%n==0){for(n=2;n<=d;n++){
				if(d%n==0){
				a[n]=i;
				n++;}
		}
	}
	}
			
		}
	}
	
	}
	for(x=0;x<n;x++){
		y+=a[x];
	}
	for(x=0;x<=n;x++){
			for(j=x+1;j<=n;j++){
				if(a[x]<a[j]){
					t=a[x];
					a[x]=a[y];
					a[y]=t;
				}
			}
	}
	printf("%d %d %d",&n+1,&y,&a[0]);
	return 0;
}
