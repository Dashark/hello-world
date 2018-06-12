#include<iostream>
#include<string>

using namespace std;

const int index = 9;
inline int ctoi(char c){return c-48;}

int Nine_Ten(string);

class Trans
{
public:
	Trans(int a):num(a){};
	void To_two();
private:
	int num;
};

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string number;
		cin >> number;
		//cout << Nine_Ten(number) <<endl;
		Trans Number(Nine_Ten(number));
		Number.To_two();
	}
	return 0;
}

int Nine_Ten(string n)
{
	int sum = 0;
	for(int i = 0;i < n.size()-1;i++)
	{
		sum = (sum+ctoi(n[i]))*index;
	}
	return sum+=ctoi(n[n.size()-1]);
}

void Trans::To_two()
{
	int n = num,i = 0;
	int number[100];
	while(true)
	{
		number[i] = n%2;
		n /= 2;
		if(n == 0) break;
		i++;
	}
	for(int j = i;j >= 0;j--) cout << number[j];
	cout <<endl;
}
