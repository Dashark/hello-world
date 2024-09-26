#include<stdio.h>
int prime(int n){//素数
    int i;
    if(n>2 && !(n&1) || n<2)
        return 0;
    for(i=3;i*i<=n;i+=2)
        if(!(n%i))
            return 0;
    return 1;
}
int main(){
	int a,n,s,b;//n为个数，s为和，b为个数
	a=100,n=0,s=0,b=0;
	for(a=100;a<=999;a++){
		int bai = a/100,shi = (a%100)/10,ge = a%10;
		int c1 = bai + shi + ge,c2 = bai * shi * ge,c3 = bai*bai + shi*shi + ge*ge;
		if(prime(c1)==1&&prime(c2)==1&&prime(c3)==1){
			n=n+1;
			s=s+a;
			b=a;
		}
	} 
	printf("%d %d %d",n,s,b);
	return 0;
}
