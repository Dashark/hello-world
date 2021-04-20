#include<iostream> 
#include <vector>
#include<numeric>
#include <algorithm>
using namespace std;
bool is_prime(int m) {
	int i;
	if(m<=2) 
	return false;
	else 
	for(i=2; i<=m-1; i++)
		if(m%i==0) return false;
	return true;               }
	bool is_superprime(int number) {
		int num1=number/100;int num2=(number-num1*100)/10;int num3=number-num1*100-num2*10;
		int number1=num1+num2+num3;int number2=num1*num2*num3;int number3=num1*num1+num2*num2+num3*num3; 
		if(is_prime(number1)&&is_prime(number2)&&is_prime(number3)) 
			return true; 
			else
			return false; 
		}
class superprime{
	private:int num;std::vector<int>range;
	public:
		int num_amount() {
		return range.size();
		}
		superprime(int a,int b) {
		for(int i = a; i < b; i++) {
  	    if(is_superprime(i))
  	    range.push_back(i);
        } 
		}
		int num_sum(){
			int sum = accumulate(range.begin(),range.end(),0);
			return sum; 
		} 
		int num_big(){
        int big =*max_element(range.begin(),range.end()); 
		} 
		};
int main() 
{
  superprime sp(100, 999);
  std::cout << "超级素数个数：" << sp.num_amount() << std::endl;
  std::cout << "最大的超级素数：" << sp.num_big() << std::endl;
  std::cout << "超级素数的和:" << sp.num_sum() << std::endl;
  return 0;
} 
