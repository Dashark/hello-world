#include<stdio.h>
#include<math.h>
int qb(int i);
int o,a[10000],b[10000],k,n=0,sum,summ,p=0,m=0,s;
int i,h,f;
int main(){
	for(i = 100;i <= 10000;i++){ 
		o = i;
		while(qb(o)==1){
		do{
			a[n] = o % 10;
			o = o / 10;
			n++;
		}while(o>0);
		for(k=0;k<n;k++){
			sum += a[k];
		}
		while(qb(sum)==1){
			for(h=0;h<n;h++){
				p =p + pow(a[h],2);
			}
			while(qb(p)==1){
				printf("%d\n",i);
				b[m] = i;
				m++;
				break;
				}
				break;
			}
			break;	
		}
		n = 0;
		h = 0;
		sum = 0;
		p = 0;
	}
	for(s=0;s<m;s++){
		summ += b[s];
	}
	f = summ / m;
	printf("average:");
	printf("%d",f);
	return 0;
	 
}
int qb(int i){
	int n,g=0;
	if(i==1||i==2)
	return 1;
	else{
		for(n=2;n<i;n++){
			if(i%n==0)
			g++;
		}
	}
	if(g==0)
		return 1;
	else
		return 0;
}
