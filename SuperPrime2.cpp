//作业：完成以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
#include<cmath> 
using namespace std;
class SuperPrime {
private:
    const int number;//int number;number=x;
    int N[100], size;
    bool isPrime(int x) {
        if (x == 2 || x == 3)
            return 1;
        if (x % 6 != 1 && x % 6 != 5)
            return 0;
        int tmp = (int)sqrt(x);
        int i;
        for (i = 5; i <= tmp; i += 6)
            if (x % i == 0 || x % (i + 2) == 0)
                return 0;
        return 1;
    }
    void split(int number, int N[]) {
        size = 0;
        int x = number;
        while (x >= 10) {
            N[size++] = x % 10;
            x /= 10;
        }
        N[size++] = x;
    }
    int sum() {
        int s = 0;
        for (int i = 0; i < size; i++)
            s += N[i];
        return s;
    }
    int multi() {
        int s = 1;
        for (int i = 0; i < size; i++)
            s *= N[i];
        return s;
    }
    int squareSum() {
        int s = 0;
        for (int i = 0; i < size; i++)
            s += N[i] * N[i];
        return s;
    }
public:
    SuperPrime() :number(0) {
    } //?
    ~SuperPrime() {
    }
    void Setnumber(int x) {
        int* p = (int*)&number;
        *p = x;
    }
    bool isSuperPrime() {
        split(number, N);
        int a = sum();
        int b = multi();
        int c = squareSum();
        if (isPrime(number) && isPrime(a) && isPrime(b) && isPrime(c))
            return true;
        return false;
    }
    int num() {
        return number;
    }
};
class Set {
private:
    SuperPrime set[1000];
    int size;
    int begin;
public:
    Set(int from, int to) {
        begin = from;
        size = to - from;
    }
    ~Set() {
    }
    int count() {
        int count = 0;
        for (int i = 0; i < size; i++) {
            set[i].Setnumber(begin + i);
            if (set[i].isSuperPrime())
                count += 1;
        }
        return count;
    }
    int sum() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            set[i].Setnumber(begin + i);
            if (set[i].isSuperPrime())
                sum += set[i].num();
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
