/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
#include<iostream>
using namespace std;
bool isprime(int num) {
	for (int i = 2; i*i <= num; i++){
		if (num%i == 0){
			return false;
		}
	}
	return true;
}
int sum_bit(int num) {
<<<<<<< HEAD
	int sum = 0;
	while (num){
		sum += num % 10;
		num /= 10;
	}
	if (isprime(num)){
		return true;
	}
	return 0;
}

int multi_bit(int num) {
	int sum = 0;
	while (num){
		sum *= num % 10;
		num /= 10;
	}
	if (isprime(num)){
		return true;
	}
	return 0;
}

int square_sum_bit(int num) {
	int sum = 0;
	while (num){
		sum += num % 10 * num % 10;
		num /= 10;
	}
	if (isprime(num)){
		return true;
	}
	return 0;
}



int main() {
	if (isprime(113) && isprime(sum_bit(113)) && isprime(multi_bit(113)) && isprime(square_sum_bit(113))){
		cout << "This is prim num " << endl;
	}
	//to do sth
=======
 int sum=0;
  while(num){
    sum+=num%10;
  }
  if(isprime(sum)){
    return ture;
  }
  return 0;
}

int multi_bit(int num) {
  int sum=0;
  while(num){
    sum*=(num%10);
    num%=10;
  }
  if(isprime(sum)){
    return ture;
  }
  return 0;
}

int square_sum_bit(int num) {
  int sum=0;
  while(num){
    sum+=(num%10)*(num%10);
    num%=10;
  }
  if(isprime(sum)){
    return ture;
  }
  return 0;
}

bool isprime(int num) {
  for(int i=2;i*i<=num;i++){
    if(num%i==0){
       return false;
    }
  }
  return true;
}

int main() {
  if(isprime(113)&&isprime(sum_bit(113))&&isprime(multi_bit(113))&&isprime(square_sum_bit(113))){
      cout<<"This is a super prime"
  }
    return 0//to do sth
>>>>>>> origin/patch-2
}
