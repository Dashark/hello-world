#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

const int NMAX=10000;
int is_prime[NMAX];

//graham-start
struct point{
	int x,y;
};

int n;
vector<point> points;
stack<int> s;

point operator -(point A,point B)
{
	point C;
	C.x=A.x-B.x;
	C.y=A.y-B.y;
	return C;
}

int operator *(point A,point B)
{
	return A.x*B.y-A.y*B.x;
}

int dist(point A,point B)
{
	return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}

int cmp(point A,point B)
{
	int tmp=(A-points[0])*(B-points[0]);
	if(tmp!=0)
		return tmp>0;
	int dist1=dist(points[0],A);
	int dist2=dist(points[0],B);
	return dist1>dist2;
}

int graham()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		point TMP;
		scanf("%d %d",&TMP.x,&TMP.y);
		points.push_back(TMP);
	}
	for(int i=1;i<n;i++)
		if(points[i].y<points[0].y || (points[i].y == points[0].y && points[i].x<points[0].x))
			swap(points[i],points[0]);
	sort(points.begin()+1,points.end(),cmp);
	s.push(0);s.push(1);s.push(2);
	for(int i=3;i<n;i++)
	{
		s.push(i);
		while(s.size()>3)
		{
			int a=s.top();s.pop();point A=points[a];
			int b=s.top();s.pop();point B=points[b];
			int c=s.top();s.pop();point C=points[c];
			int tmp=(A-B)*(B-C);
			if(tmp>=0)
			{
				s.push(c);s.push(a);
			}
			else if(tmp<0)
			{
				s.push(c);s.push(b);s.push(a);
				break;
			}
		}
		printf("%d\n",i);
	}
	printf("Calculate Success\n");
	return 0;
}
//graham-end

void init_prime()
{
	is_prime[1]=0;
	for(int i=2;i<NMAX;i++)
	{
		is_prime[i]=!is_prime[i];
		if(is_prime[i])
			for(int j=i+i;j<NMAX;j+=i)
				is_prime[j]=1;
	}
	return;
}

class Prime {
	public:
		Prime(int num):mNum(num){}
		~Prime(){}

		bool isPrime()
		{
			return is_prime[mNum];
		}
	private:
		const int mNum;
};

class SuperPrime : public Prime {
	public:
		SuperPrime(int _num):Prime(_num),num(_num){}
		~SuperPrime(){}

		//bool isPrime(){}

		Prime sumBit()
		{
			int sum=0,tmp_mNum=num;
			while(tmp_mNum!=0)
			{
				sum+=tmp_mNum%10;
				tmp_mNum/=10;
			}
			return Prime(sum);
		}
		
		Prime multiBit()
		{
			int product=1,tmp_mNum=num;
			while(tmp_mNum!=0)
			{
				product*=tmp_mNum%10;
				tmp_mNum/=10;
			}
			return Prime(product);
		}
		
		Prime squareSumBit()
		{
			int sum=0,tmp_mNum=num;
			while(tmp_mNum!=0)
			{
				sum+=(tmp_mNum%10)*(tmp_mNum%10);
				tmp_mNum/=10;
			}
			return Prime(sum);
		}
	private:
		const int num;
};

int main()
{
	init_prime();
	SuperPrime sp(113);
	if(sp.isPrime()) {
		printf("sp is a prime\n");
	}
	if(sp.sumBit().isPrime()) {
		printf("sp'sumbit is a prime\n");
	}
	if(sp.multiBit().isPrime()) {
		printf("sp'multibit is a prime\n");
	}
	if(sp.squareSumBit().isPrime()) {
		printf("sp'squareSumBit is a prime\n");
	}
}
