#include <iostream>
#include<cmath>
using namespace std;
class Answer
{
private:
    int num;
    int sum;
    int maxn;
    bool isPrime(int num)
    {
        bool flag = true;
        if (num == 0 || num == 1)
        {
            flag = false;
        }
        for (int i = 2; i < ((num / 2) + 1); i++)
        {
            if (num % i == 0)
            {
                flag = false;
                break;
            }
        }
        return flag;
    }

public:
    Answer()
    {
        num = 0;
        maxn = 0;
        sum = 0;
        for (int i = 101; i <= 999; i += 2)
        {
            int s1, s2, s3;
            s1 = i / 100;
            s2 = (i / 10) % 10;
            s3 = i % 10;
            if ((isPrime(i)) && (isPrime(s1 + s2 + s3)) && (isPrime(s1 * s2 * s3))&&(isPrime(pow(s1,2)+pow(s2,2)+pow(s3,2))))
            {
                //  cout << i << endl;
                num++;
                maxn = i;
                sum += i;
            }
        }
    }
    ~Answer(){}
    int Num()
    {
        return num;
    }
    int Sum()
    {
        return sum;
    }
    int max()
    {
        return maxn;
    }
};
int main(void)
{
    Answer Answer;
    cout << Answer.Num() << endl;
    cout << Answer.Sum() << endl;
    cout << Answer.max() << endl;
    return 0;
}