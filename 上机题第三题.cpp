#include<iostream>
#include<string>
#include<cctype> 
#include<algorithm>
using namespace std;
int main ()
{
	string line;
	getline(cin,line);
	string word[100];
	cout<<"请输入一句英语："; 
	int n=0;
	for(int i=0;i<line.length();i++)
	{
		if(i==0||line[i-1]==' ')
		{
			word[n].append(1,line[i]);
			i++;
			while(isalpha(line[i]))
			{
				word[n].append(1,line[i]);
				i++;
			}
			n++;
		}
	}
	cout<<"这句话的单词数量为"<<n<<endl;
	sort(word,word+n);
	for(int i=0;i<n;i++)
	{
		cout<<word[i]<<endl;
	 } 
	return 0;
}
