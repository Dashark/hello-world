#include<iostream>     //超级素数 
using namespace std;

int self(int a){
	int i,b=0;
	
	if(a==2)
	b=1;

	for(i=2;i<a;i++){
		if(a%i==0)
		{
			b=0;
			break;
		}else b=1;
		
	}

	return b;
	
}//判断一个数本身是不是素数 ，是为1，不是为0 

int sum(int a){
	int hun,ten,one,sum,i,b=0;
	hun=a/100;
	ten=(a-100*hun)/10;
	one=a-100*hun-10*ten;
	sum=hun+ten+one;
	
	if(a==2)
	b=1;
	
	for(i=2;i<sum;i++){
		if(sum%i==0)
		{
			b=0;
			break;
		}else{b=1;} 
		
	}

	return b;
	}//判断所有数字和是否为素数，是为1，不是为0 
	
	
	
int mul(int a){
	int hun,ten,one,mul,i,b=0;
	hun=a/100;
	ten=(a-100*hun)/10;
	one=a-100*hun-10*ten;
	mul=hun*ten*one;
	
	if(a==2)
	b=1;
	
		for(i=2;i<mul;i++){
		if(mul%i==0 || hun == 0 || ten == 0 || one == 0)
		{
			b=0;
			break;
		}else{b=1;} 
		
	}

	return b;//易错！！！！！ 
	
}//判断所有数字之积 是否为素数 


int square_add(int a){
	int hun,ten,one,mul_add,i,b=0;
	hun=a/100;
	ten=(a-100*hun)/10;
	one=a-100*hun-10*ten;
	mul_add=hun*hun+ten*ten+one*one;
	
	if(a==2)
	b=1;
	
		for(i=2;i<mul_add;i++){
		if(mul_add%i==0)
		{
			b=0;
			break;
		}else{b=1;}
		
	} 

	return b;
	
	
	
}//所有数字平方和是否为素数 









int main()
{
	int num,count=0,summ=0,i;
	int a[900];
	
	for(num=100;num<1000;num++)
	{
		if(self(num) * sum(num) * mul(num) * square_add(num))//判断是否为超级素数 
		{
			count++;//数超级素数个数 
			a[count-1]=num;//把所有超级素数装入数组 
		}
		
	} 
	
	for(i=0;i<count;i++)
	{
		summ+=a[i];
	}//求超级素数的和
	
	cout<<"超级素数的个数:"<< count << endl ;
	cout<<"所有超级素数之和："<< summ <<endl ;
	cout << "最大的超级素数:" << a[count-1] << endl ;
	
	

	
	
	
	
	
	
	return 0;
 } 
