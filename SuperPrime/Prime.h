#include<iostream>
#include<vector>

using namespace std;

class Prime{
	public:
		Prime(int low , int high);//构造函数 
        static bool judgePrime(int);//判断一个数是否为素数 
		void showPrime();//打印出所选范围内的所有素数，空格分隔 
		int getSize();//获取素数个数 
//		int *getPrime();//将vector中的素数放入一个数组并返回首地址，以供superPrime使用 
	protected:
		vector<int> p;//容器，存放素数 
};

class superPrime : public Prime {
	public:
		superPrime(int low , int high);//构造函数 
		void showPrime();
	private:
        bool judgePrime(int);//判断是否为超级素数 
		void findPrime(int , int);//找素数，放入vector 
};


