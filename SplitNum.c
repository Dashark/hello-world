#include <stdio.h>
void PrintNum(int num){//¶¨ÒåPrintNumº¯Êı 
	if(num>9){
		PrintNum(num/10);
	}
	printf("%d ",num%10);
}
int main(){
	int num=0;
	scanf("%d",&num);
	PrintNum(num);
return 0;

