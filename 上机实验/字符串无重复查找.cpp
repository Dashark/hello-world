#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string) ;
	int Find(char c,int i,int j,string s)
	{
		for(int a = i;a < j;a++)
		{
			if(c==s[a]) return a;
		}
		return -1;
	}
};

int Solution::lengthOfLongestSubstring(string s)
{
	int MAX  = 0,i = 0,j = 0,len = 0;
	for(j = 0;j < s.size();j++)
	{
		int mid = Find(s[j],i,j,s);
		if(mid == -1) len++;
		else
		{
			i = mid+1;
			len = j-i+1;
		}
		if(MAX < len) MAX = len;
	}
	return MAX;
}

int main()
{
	Solution a;
	string str_1,str_2;
	cin>>str_1;
	cout<<a.lengthOfLongestSubstring(str_1);
	return 0;
}
