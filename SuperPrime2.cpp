//作业：面向对象设计以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
#include<cmath> 
using namespace std;  
class SuperPrime {
private:
    const int number;
    SuperPrime* N[100];
    int size;
    bool isPrime() {  // 2到number-1的因子
        if (number == 2 || number == 3)
            return 1;
        if (number % 6 != 1 && number % 6 != 5)
            return 0;
        int tmp = (int)sqrt(number);
        int i;
        for (i = 5; i <= tmp; i += 6)
            if (number % i == 0 || number % (i + 2) == 0)
                return false;
        return true;
    }
    void split() {   //工厂方法设计模式       // number split into N
        size = 0;
        int temp = number;
        while (temp > 0) {
            int n = temp % 10;
            temp /= 10;
            N[size] = new SuperPrime(n);   //构造对象 
            size += 1;
        }
    }
    int sum() {
        int s = 0;
        for (int i = 0; i < size; i++)
            s += N[i]->number;
        return s;
    }
    int multi() {
        int s = 1;
        for (int i = 0; i < size; i++)
            s *= N[i]->number;
        return s;
    }
    int squareSum() {
        int s = 0;
        for (int i = 0; i < size; i++)
            s += (N[i]->number) * (N[i]->number);
        return s;
    }
public:
    SuperPrime() :number(0) {  //为什么必须有？ ::默认构造函数(无参)
        size = 0;
    }
/*构造函数在产生对象时使用，通常在programer没有定义构造函数时编译器会自动生成，
如果定义了一个有参的构造函数(如N[size] = new SuperPrime(n))后， 
还需要一个无参的构造函数(如此处的set[1000])时，就需要自己定义*/
    SuperPrime(int n) :number(n) {  //它就是构造对象 
        size = 0;
    }
    ~SuperPrime() {
        for (int i = 0; i < size; i++)  //销毁对象 
            delete N[i];
    }
    bool isSuperPrime() {
        split();
        SuperPrime a(sum());   //将普通整数转变为对象 
        SuperPrime b(multi());
        SuperPrime c(squareSum());
        if (isPrime() && a.isPrime() && b.isPrime() && c.isPrime())
            return true;
        return false;
    }
    void Setnum(int n) {
        int* p = (int*)&number;
        *p = n;
    }
};
class Set {
private:
    SuperPrime set[1000];
    int size;
    int begin, end;
public:
    Set(int from, int to) { //构造函数传入参数
        begin = from;
        end = to;
        size = to-from;
    }
    ~Set() {}
    int count() {
        int count = 0;
        for (int i = 0; i < size; i++) {
            set[i].Setnum(i + begin);
            if (set[i].isSuperPrime())
                count += 1;
        }
        return count;
    }
    int sum() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            set[i].Setnum(i+begin);
            if (set[i].isSuperPrime())
                sum += i + begin;
        }
        return sum;
    }

};
int main() {
    Set ss(100, 1000);
    cout << "How Many: " << ss.count() << endl;
    cout << "Sum is " << ss.sum() << endl;
    return 0;
}

