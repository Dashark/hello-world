//作业：大整数，比如9081321110693270343633073697474256143563558458718976746753830538032062222085722974121768604305613921745580037409259811952655310075487163797179490457039169594160088430571674960498834085812920457916453747019461644031395307920624947349951053530086146486307198155590763466429392673709525428510973272600608981219760099374675982933766845473509473676470788342281338779191792495900393751209539300628363443012 6538005862664913074813656220643842443844131905754565672075358391135537108795991638155474452610874309742867231360502542308382199053675592825240788613991898567277116881793749340807728335795394301261629479870548736450984003401594705923178314906195914825136973281314862289454100745237769034410057080703111299605127114594552921209928891515242515620324828055912854227507525717981351447473570262981491527798
//重新设计下面的代码，使其可以处理大整数的素数与超级素数
//同时仔细理解面向对象的编程方式
#include <iostream>
#include<cmath>
class BigPrime {
public:
	BigPrime(long long int n) : num(n) {}
	virtual bool isPrime() const {
		if (num == 1) return false;
		if (num == 2 || num == 3) return true;
		if (num % 6 != 1 && num % 6 != 5) return false;
		int tmp = sqrt(num);
		for (int i = 5; i <= tmp; i += 6)
			if (num % i == 0 || num % (i + 2) == 0)return false;
		return true;
	}
private:
	const int num;
};
class BigSuperPrime : public BigPrime {
public:
	BigSuperPrime(int n) : BigPrime(n), num(n) {
		split();
	}
	bool isAllPrime()const {
		BigPrime a(sum());
		BigPrime b(multi());
		BigPrime c(SquareSum());
		if (a.isPrime() && b.isPrime() && c.isPrime())
			return true;
		return false;

	}
	virtual bool isPrime() const {
		if (BigPrime::isPrime()&&isAllPrime())
			return true;
		return true;
	}
	
private:
	const int num;
	int size=0;
	int N[1000];
	void split() {
		int temp = num;
		while (temp > 0) {
			N[size++] = temp % 10;
			temp /= 10;
		}
	}
	int sum()const {
		int s = 0;
		for (int i = 0; i < size; i++)
			s += N[i];
		return s;
	}
	int multi()const
	{
		int s = 1;
		for (int i = 0; i < size; i++)
			s *= N[i];
		return s;
	}
	int SquareSum() const{
		int s = 0;
		for (int i = 0; i < size; i++)
			s += N[i] * N[i];
		return s;
	}
};
template<class T>
class Set {
public:
	Set(int sz) :size(sz) {
		index = 0;
		pset = new T * [size];
	}
	~Set() {
		delete[] pset;  //鍥炴敹
	}
	bool add(T* bp) {
		pset[index++] = bp;
		return true;
	}
	bool remove(T* bp) {};
	int count() const {
		int ret = 0;
		for (int i = 0; i < index; i++) {
			if (pset[i]->isPrime())
				ret += 1;
		}
		return ret;
	}
	int sum() const {
		return 0;
	}
private:
	T** pset;
	int size, index;
};
int main() {
	Set<BigPrime> set(1000);
	BigSuperPrime bp(12345678987654321);
	set.add(&bp);
	if (bp.isPrime())
		std::cout << "the number is a SuperPrime";
	else
		std::cout << "the number is not a SuperPrime";
	return 0;
}
