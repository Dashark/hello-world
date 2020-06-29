//作业：大整数，比如9081321110693270343633073697474256143563558458718976746753830538032062222085722974121768604305613921745580037409259811952655310075487163797179490457039169594160088430571674960498834085812920457916453747019461644031395307920624947349951053530086146486307198155590763466429392673709525428510973272600608981219760099374675982933766845473509473676470788342281338779191792495900393751209539300628363443012 6538005862664913074813656220643842443844131905754565672075358391135537108795991638155474452610874309742867231360502542308382199053675592825240788613991898567277116881793749340807728335795394301261629479870548736450984003401594705923178314906195914825136973281314862289454100745237769034410057080703111299605127114594552921209928891515242515620324828055912854227507525717981351447473570262981491527798 
//重新设计下面的代码，使其可以处理大整数的素数与超级素数
//同时仔细理解面向对象的编程方式 
#include <iostream>
#include<string>
#include <cstdio>
#include <vector>
 
using namespace std;
struct BigInteger
{
    vector<int> s;
    static const int BASE=10000;
    static const int WIDTH=4;
    void standardize()
    {
        for(int i=s.size()-1;i>=0;--i)
        {
            if(s[i]==0)
                s.pop_back();
            else
                break;
        }
        if(s.empty())
            s.push_back(0);
    }
 
    BigInteger& operator = (long long num)
    {
        s.clear();
        do
        {
            s.push_back(num%BASE);
            num/=BASE;
        }while(num>0);
        return *this;
    }
    BigInteger& operator = (const string& num)
    {
        s.clear();
        int len=(num.size()-1)/WIDTH+1;
        int x=0;
        for(int i=0;i<len;++i)
        {
            int end=num.size()-i*WIDTH;
            int start=max(0,end-WIDTH);
            sscanf(num.substr(start,end-start).c_str(),"%d",&x);
            s.push_back(x);
        }
        standardize();
        return *this;
    }
    BigInteger operator + (const BigInteger& rhs) const
    {
        int size=max(s.size(),rhs.s.size());
        int carry=0;
        BigInteger ans;
        for(int i=0;i<size;++i)
        {
            int sum=carry;
            if(i<s.size()) sum+=s[i];
            if(i<rhs.s.size()) sum+=rhs.s[i];
            carry=sum/BASE;
            ans.s.push_back(sum%BASE);
        }
        if(carry>0)
        {
            ans.s.push_back(carry);
        }
        return ans;
    }
    BigInteger operator * (const BigInteger& rhs) const
    {
        BigInteger ans;
        for(int i=0;i<rhs.s.size();++i)
        {
            BigInteger lans;
            for(int k=0;k<i;++k) lans.s.push_back(0);
            int carry=0;
            for(int j=0;j<s.size();++j)
            {
                int result=rhs.s[i]*s[j]+carry;
                carry=result/BASE;
                lans.s.push_back(result%BASE);
            }
            while(carry>0)
            {
                lans.s.push_back(carry%BASE);
                carry/=BASE;
            }
            ans=ans+lans;
        }
        return ans;
    }
    BigInteger operator - (const BigInteger& rhs) const
    {
        BigInteger ans;
        int carry=0;
        for(int i=0;i<s.size();++i)
        {
            int diff=s[i]-carry;
            if(i<rhs.s.size()) diff-=rhs.s[i];
            carry=0;
            while(diff<0)
            {
                ++carry;
                diff+=BASE;
            }
            ans.s.push_back(diff);
        }
        ans.standardize();
        return ans;
    }
    BigInteger operator / (int rhs) const
    {
        BigInteger ans;
        vector<int> t;
        long long rmder=0;
        for(int i=s.size()-1;i>=0;--i)
        {
            long long temp=rmder*BASE+s[i];
            long long div=temp/rhs;
            rmder=temp%rhs;
            t.push_back(div);
        }
        for(int i=t.size()-1;i>=0;--i)
            ans.s.push_back(t[i]);
        ans.standardize();
        return ans;
    }
 
    friend ostream& operator << (ostream& out,const BigInteger& rhs)
    {
        out<<rhs.s.back();
        for(int i=rhs.s.size()-2;i>=0;--i)
        {
            char buf[5];
            sprintf(buf,"%04d",rhs.s[i]);
            cout<<string(buf);
        }
        return out;
    }
    bool operator < (const BigInteger& rhs) const
    {
        if(s.size()!=rhs.s.size()) return s.size()<rhs.s.size();
        for(int i=s.size()-1;i>=0;--i)
        {
            if(s[i]!=rhs.s[i])
                return s[i]<rhs.s[i];
        }
        return false;
    }
};
//The function below need more tests.
//This function is generally the most difficult. Meanwhile, that means it is rarely used.
BigInteger operator / (const BigInteger& a,const BigInteger& b)
{
    BigInteger rmder,x,xbk,rslt;
    rmder=a;
    x=xbk=b;
    int baseNum=0;
    while(1)
    {
        x=x*10;
        if(x<rmder)
        {
            ++baseNum;
            xbk=x;
            continue;
        }
 
        int div=0;
        while(xbk<=rmder)
        {
            ++div;
            rmder=rmder-xbk;
        }
        if(div==0)
            break;
 
        BigInteger t;
        for(int i=0;i<baseNum;++i)
        {
            t.number.push_back(0);
        }
        t.number.push_back(div);
        rslt=rslt+t;
 
        baseNum=0;
        x=xbk=b;
    }
    rslt.rmZero();
    return rslt;
}

class BigPrime {
public:
  BigPrime(string n) : largeNumber(n){
  }
  virtual bool IsPrime()
{
    BigInteger bigInteger = BigInteger.Parse(largeNumber);
    if (bigInteger.IsEven)
    {
        return false;
    }
    for (BigInteger bi = 3; BigInteger.Pow(bi, 2) <= bigInteger; bi += 2)
    {
        if (bigInteger % bi == 0)
        {
            return false;
        }
    }
    return true;
}
private:
  const string largeNumber;
}; 
class BigSuperPrime : public BigPrime {
public:
  BigSuperPrime(int n) : BigPrime(n), num(n){
  }
  virtual bool isPrime() const {
    return true;
  }
private:
  const int num;
};
template <class T>
class Set {
public:
  Set(int sz);
  ~Set();
  bool add(T *bp);
  bool remove(T *bp);
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
  T **pset;
  int size, index;
};
int main() {
  Set<BigPrime> set(1000);
  BigSuperPrime bp(2), bp1(3);
  set.add(&bp);
  set.add(&bp1);
  std::cout << set.count() << std::endl;
  return 0;
} 

template <class T>
Set<T>::Set(int sz):size(sz) {
  index = 0;
  pset = new T*[size];  //分配存储空间 
}

template <class T>
Set<T>::~Set() {
  delete[] pset;  //回收 
}

template <class T>
bool Set<T>::add(T *bp) {
  pset[index++] = bp;
  return true;
}
