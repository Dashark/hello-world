//输入若干数字求平均值，输入0代表输入结束 
#include <stdio.h>
int main(){
	int number, sum = 0, count = 0;
	
	scanf("%d",&number);
	while(number != 0){
		sum += number;
		count ++;
		scanf("%d",&number);
	}
	printf("%f\n",1.0*sum/count);
	return 0;
} 
