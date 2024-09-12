#include<stdio.h>
//sum <= 27 mul <= 729 mul2 <= 243
int main(){
	int p[1000] = {0};
	int pp[1000] = {0};
	int i = 2; 
	for(;i < 1000;i++){//筛数法 
		p[i] = i;
	}
	
	int j = 0;
	i = 2;
	for(; i < 1000;i++){//生成一个纯净的素数数组 
		if(p[i] == 0){
			continue;
		}
		pp[j] = p[i];
	
		//printf("A%d %d\n",pp[j],j);
	
		j++;
		int k = 2;
		for(;(i * k) < 1000;k++){
			p[i * k] = 0;
		}
	}
	int ppn = j;
	
	//printf("B%d\n",ppn);
	
	//for(i = 0; i < j;i++){
	//	printf("C%d %d\n",pp[i],i);
	//}


	int sp;
	int countsp = 0;
	int sumsp = 0;
	int max = 0;
	int judge = 0;
	int t;
	for(t = 25; t < ppn;t++){
		
		//printf("D%d\n",pp[t]);
		
		sp = pp[t];
		int g = sp % 10;
		int s = (sp - g) % 100 / 10;
		int b = (sp - 10 * s - g) / 100;
		int sum = g + s + b;
		int mul = g * s * b;
		int mul2 = g * g + s * s + b * b;
		
		//printf("E%d %d %d %d \n",sp,g,s,b);
		
		judge = 0;
		for(j = 0;j < ppn;j++){
			if(pp[j] == sum){
				judge++;
				
				//printf("Q1\n");
				
				break;
			}
		}
		
		//printf("go\n");
		
		for(j = 0;j < ppn;j++){
			if(pp[j] == mul){
				judge++;
				
				//printf("Q2\n");
				
				break;
			}
		}
		;
		for(j = 0;j < ppn;j++){
			if(pp[j] == mul2){
				judge++;
				
				//printf("Q3\n");
				
				break;
			}
		}
		
		if(judge == 3){
			countsp++;
			sumsp += sp;
			max = sp;
			
			//printf("Q%d\n",sp);
			
		}
		
	}
	printf("个数：%d 和：%d 最大：%d \n",countsp,sumsp,max);
	
	
	return 0;
} 
