#include<iostream>
#include<string>
#include<sstream>


class Sentence
{
public:
	Sentence(std::string line): sentence(line){}
	~Sentence(){}
	int CountWords();
private:
	const std::string sentence;
};

int Sentence::CountWords()
{
	int num = 0;
	std::string str;
	std::stringstream ss(sentence);
	while(ss >> str) num++;
	return num;
}


int main()
{
	std::string line;
	getline(std::cin,line);
	Sentence Line(line);
	std::cout << Line.CountWords() << '\n';
	return 0;
}
