#include<iostream>
#include<math.h>

class Nature{
	private:
		int num;
		int a,b,c;
		int add,x,sqrtsum;
	
	public:
		Nature(int num);
		int sum(int a,int b,int c);
		int mul(int a,int b,int c);
		int sqrts(int a,int b,int c);
	
};

	Nature::Nature(int num){
		a=num%10;
		b=num/10%10;
		c=num/100;
	} 
	
	Nature::sum(int a,int b,int c){
		add=a+b+c;
	}
	
	Nature::mul(int a,int b,int c){
		x=a*b*c;
	}
	
	Nature::sqrts(int a,int b,int c){
		sqrtsum=a*a+b*b+c*c;
	}
	

class SuperPrime{
	private:
		int i;
		
	public:
		Nature sp(int i);
		SuperPrime(int i,int sum,int mul ,int sqrts);
		int max(int i);
		int he(int i);
}; 
	
	SuperPrime::SuperPrime(int i,int sum,int mul ,int sqrts){
		int count=0;
		for(int h=2;h<sqrt(i);h++){
			if(i%h==0){
				count++;
			}
		}
		
		for(int h=2;h<sqrt(sum);h++){
			if(sum%h==0){
				count++;
			}
		}
		
		for(int h=2;h<sqrt(mul);h++){
			if(mul%h==0){
				count++;
			}
		}
		
		for(int h=2;h<sqrt(sqrts);h++){
			if(sqrts%h==0){
				count++;
			}
		}
		
		if(count==0) {
			return i;
		}
		else{
			return 0;
		}
	}
	
	SuperPrime::he(int pd){
		int sum=0;
		sum+=pd;
	}
	
	SuperPrime::max(int pd){
		if
	}
	
	
	
	
int main(){
	
	Nature sp(i);
	sp.sum;
	return 0;
}
	
	
	
	
	
