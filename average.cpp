//��������������ƽ��ֵ������0����������� 
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
