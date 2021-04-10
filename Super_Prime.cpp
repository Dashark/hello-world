#include<stdio.h>
#include<math.h>

int zhishu(int r){
	float b = sqrt(r);
	for(int i = 2; i <= b; i++){
		if(r % i ==0){
			return 0;
		}
		else if(r % i != 0&& b - i < 1){
		    return 1;
		}
	}
	
}
int main()
{	
    int count = 0, sum = 0, zuida = 0;
	int a = 100;
	for(; a <= 999; a++){  
		int bai = a / 100;
		int shi = (a % 100) / 10;
		int ge = a % 10;
		
		if(zhishu(a)&&zhishu(bai + shi + ge)&&zhishu(bai * shi * ge)&&zhishu(bai * bai + shi * shi + ge * ge)){
		count++;
		sum+=a;
		zuida = a;
		} 
	}
	
	printf("%d %d %d", count, sum, zuida);
	
	
	return 0;
}
