//作业：面向对象设计以下框架的代码细节，程序能编译运行得到正确结果 
//作业：面向对象设计以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
using namespace std;
class Prime {
public:
    Prime() :number(0) {
    }
    Prime(int n) :number(n) {
    }
    ~Prime() {
    }
    bool isPrime() {
        //2到number-1的因子
        int s = 0;
        for (int i = 1; i <= number; i++)
            if (number % i == 0)
                s++;
        if (s == 2)
            return true;
        return false;
    }
private:
    const int number;
};
class PrimeSet {
private:
    Prime** N;
    int size, index;
public:
    PrimeSet(int size) {//size=3
        //集合的构造什么？ 
        N = new Prime * [size];
        this->size = size;
        index = 0;
    }
    ~PrimeSet() {
        for (int i = 0; i < index; ++i)  //销毁对象 
            delete N[i];
        delete[] N;
    }
    bool add(int n) {
        if (index == size)  return false;
        Prime* p = new Prime(n);
        N[index] = p;
        index += 1;
        return true;
    }
    bool isAllPrime() {
        for (int i = 0; i < index; i++)
            if (!N[i]->isPrime())
                return false;
        return true;
    }
};
class SuperPrime {
public:
    SuperPrime() :number(0), pset(3) {  //为什么必须有？ 
    }
    SuperPrime(int n) :number(n), pset(3) {
        split();  //它就是构造对象 
        sum();
        multi();
        squareSum();
    }
    ~SuperPrime() {
    }
    bool isSuperPrime() {
        if (pset.isAllPrime())
            return true;
        return false;
    }
private:
    int N[10];
    int size = 0;
    const int number;
    PrimeSet pset;
    void split() {   //工厂方法设计模式 
      // number split into N
        int temp = number;
        while (temp > 0) {
            N[size++] = temp % 10;
            temp /= 10;
            //            pset.add(n);  //作业：单个数字为对象？还是和/积/平方和为对象？ 
        }
    }
    int sum() {
        int s = 0;
        for (int i = 0; i < size; i++)
            s += N[i];
        pset.add(s);
        return 0;
    }
    int multi() {
        int s = 1;
        for (int i = 0; i < size; i++)
            s *= N[i];
        pset.add(s);
        return 0;
    }
    int squareSum() {
        int s = 0;
        for (int i = 0; i < size; i++)
            s += N[i] * N[i];
        pset.add(s);
        return 0;
    }
};
class SuperPrimeSet {
private:
;
    int begin;
    int size;
public:
    SuperPrimeSet(int from, int to) {
        begin = from;
        size = to - from;
    }
    int count() {
        int num = 0;
        for (int i = 0; i < size; i++)
        {
            SuperPrime set(i+begin);
            if (set.isSuperPrime())
                num += 1;
        }
        return num;
    }
    int sum() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            SuperPrime set(i + begin);
            if (set.isSuperPrime())
                sum += i + begin;
        }
        return sum;
    }
};
int main() {
    SuperPrimeSet ss(100, 1000);
    cout << "How Many: " << ss.count() << endl;
    cout << "Sum is " << ss.sum() << endl;
    return 0;
}
