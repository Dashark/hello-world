#include<iostream> 
#include <vector>
#include<numeric>
#include <algorithm>
using namespace std;
class Nature {
private:
  int num;
public:
  Nature():num(0){
    //std::cout << "Default Create Nature as " << num << std::endl;
  }
  Nature(int n):num(n) {
    //std::cout << "Create Nature as " << num << std::endl;
  }
  Nature(const Nature &nat):num(nat.num){
    //std::cout << "Copy Create Nature as " << num << std::endl;
  }
  ~Nature() {
    //std::cout << "Destroy Nature as " << num << std::endl;
  }

		friend class superprime;
	};
class superprime{
	private:int num1,num2,num3;std::vector<int>natures;
	public:
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
		Nature num_amount() {
		return num1=natures.size();
		}
		superprime(int a,int b) {
		for(int i = a; i < b; i++) {
  	    if(is_superprime(i))
  	    natures.push_back(i);
        } 
		}
		Nature num_sum(){
			int sum = accumulate(natures.begin(),natures.end(),0);
			num2=sum; 
		} 
		Nature num_big(){
        int big =*max_element(natures.begin(),natures.end()); 
            num3=big;
		} 
		int show(){
        std::cout << "超级素数个数：" << num1 << std::endl;
        std::cout << "最大的超级素数：" << num2 << std::endl;
        std::cout << "超级素数的和:" << num3 << std::endl;
		} 
		};
int main() 
{
  superprime sp(100, 999);
  Nature n1=sp.num_amount(); 
  Nature n2=sp.num_sum();
  Nature n3=sp.num_big(); 
  sp.show();
  return 0;
}

