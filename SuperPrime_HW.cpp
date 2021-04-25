#include <iostream>

class SuperPrime {
	private:
		int left,right;
	public:
		SuperPrime(int a,int b)	{
			left=a;
			right=b;
		}
		int isPrime(int x) {
			int state = 1;
			if (x <= 0) {
				state = 0;
			}
			if (x > 2) {
				for (int i = 2; i < x && state == 1; i++) {
					if (x % i == 0) {
						state = 0;
						break;
					}
				}
			}
			return state;
		} //返回1则是素数
		int isSuperPrime(int x) {
			int a,sum=0,mult=1,sqrsum=0;
			int X=x;
			while(x!=0) {
				a=x%10;
				sum=sum+a;
				mult=mult*a;
				sqrsum=sqrsum+a*a;
				x=x/10;
			}
			if(isPrime(X)==1&&isPrime(sum)==1&&isPrime(mult)==1&&isPrime(sqrsum)==1)
				return 1;
		}//返回1则是超级素数
		int max() {
			int max;
			for(int x=left; x<right; x++) {
				if(isSuperPrime(x)==1) {
					max=x;
				}
			}
			return max;
		}
		int howmany() {
			int count=0;
			for(int x=left; x<right; x++) {
				if(isSuperPrime(x)==1)
					count++;
			}
			return count;
		}
		int sum() {
			int sum=0;
			for(int x=left; x<right; x++) {
				if(isSuperPrime(x)==1)
					sum+=x;
			}
			return sum;
		}
};
int main() {
	SuperPrime sp(100,999);
	std::cout<<"最大的超级素数："<<sp.max()<<std::endl;
	std::cout<<"超级素数个数："<<sp.howmany()<<std::endl;
	std::cout<<"超级素数的和："<<sp.sum()<<std::endl;
}
