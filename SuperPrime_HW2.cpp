#include <iostream>
#include <vector>
class Nature {
private: 
  const int num;  //数 
public:
  Nature(int n):num(n) {
  }
  ~Nature();
  Nature add(Nature sp);    //求和 
  bool compare(Nature sp) {  //比大小 
     if(num > sp.num)
       return true;
    return false;
  }
  bool isSuperPrime(int c)
          {bool light=1;
		   int ge,shi,bai,he,ji,ping,a,b=0;
		   ge=c%10;shi=((c-ge)%100)/10;bai=(c-ge-shi*10)/100;
		   he=ge+shi+bai;ji=ge*shi*bai;ping=ge*ge+shi*shi+bai*bai; 
		   if(ge!=0&&shi!=0&&bai!=0) 
		   {for(int a=2;a<he;a++){if(he%a==0){b++;}}if(b!=0) {light=0;}
		   if(light==1){for(int a=2;a<ji;a++){if(ji%a==0){b++;}}
		   if(b!=0) {light=0;}}
		   if(light==1){for(int a=2;a<ping;a++){if(ping%a==0){b++;}}
		   if(b!=0) {light=0;}}}
		   else light=0;
		   return light;}
};

class SuperPrime {
private:
  std::vector<Nature> range;  //超级素数的容器 
public:
  SuperPrime(int a, int b) {
  	for(int i = a; i < b; i++) {
  	  Nature nat(i);
  	  if(nat.isSuperPrime(i)) //过滤器 
  	    range.push_back(nat);
    }
  }
  int max(int c) {
  	for(int n=100;n<=999;n++,c++) {
	  Nature nat(n);int max2;
	  if(nat.isSuperPrime(n))
	  c=n;
	} 
  	return c;
  }
 
  int howmany(int c) {
  	c=0;
  	for(int n=100;n<=999;n++,c++) {
	  Nature nat(n);int max2;
	  if(nat.isSuperPrime(n))
	  c++;
	  return c;
  }
  int sum(int c) {
  	c=0;
  	for(int n=100;n<=999;n++,c++) {
	  Nature nat(n);int max2;
	  if(nat.isSuperPrime(n))
	  c+=n;
    return c;
  }
private:
  void split(int x) {
    int a, sum, mult, sqrsum;
    while(x != 0) {
      a = x % 10;
	  sum += a;
	  mult *= a;
	  sqrsum += a*a;
	  x = x / 10;
	}
  }
};

int main() 
{
  SuperPrime sp(100, 999);
  std::cout << "最大的超级素数：" << sp.max(100) << std::endl;
  std::cout << "超级素数个数：" << sp.howmany(100) << std::endl;
  std::cout << "超级素数的和：" << sp.sum(100) << std::endl;
  return 0;
}
