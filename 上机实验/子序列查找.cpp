#include<iostream>
#include<string>

using namespace std;

class Str
{
public:
	Str(string a,string b):host(a),customer(b){}
	bool Judge();
private:
	string host,customer;
};

bool Str::Judge()
{
	int Len_1 = host.size();
	int Len_2 = customer.size();
	int i = 0, j  = 0;
	while(true)
	{
		while(host[i]!=customer[j] && i < Len_1) i++;
		if(i==Len_1 || j==Len_2) break;
		if(host[i] == customer[j]) j++;
	}
	if(i==Len_1 && j!= Len_2) return false;
	else return true;
}

int main()
{
	string a,b;
	cin >> a >> b;
	Str str(a,b);
	if(str.Judge()) cout<<"YES\n";
	else cout << "NO\n";
	return 0;
}
