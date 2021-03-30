#include<stdio.h>
#include<math.h>

int main(){
	
	int i,n,num=0,max=0;
	int jia=0;
	for(i=101;i<1000;i=i+2){
		
		int count=0;
		char a[5];
		n=i;
		a[0]=n%10;
		a[1]=n/10%10;	
		a[2]=n/100;
		
		
		int sum,mul,u;
		sum=a[0]+a[1]+a[2];
		mul=a[0]*a[2]*a[1];
		u=a[0]*a[0]+a[1]*a[1]+a[2]*a[2];
		
		for(int y=2;y<=sqrt(i);y++){
			if(i%y==0) count++;
		}
		for(int y=2;y<=sqrt(sum);y++){
			if(sum%y==0) count++;
		}
		
		if(mul!=0 && mul!=1){
			for(int y=2;y<mul;y++){
				if(mul%y==0) count++;
			}
		}else{
			count++;
		}
		
		for(int y=2;y<=sqrt(u);y++){
			if(u%y==0) count++;
		}
		
		if(count==0) {
			num++;
			jia+=i;
			max=i;
		}
		
	}
	
	printf("%d\n",num);
	printf("%d\n",jia);
	printf("%d\n",max);
	
	return 0;
}
