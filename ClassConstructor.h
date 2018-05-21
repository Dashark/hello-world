//stock00.h
//version 00
#ifndef STOCKOO_H_
#define STOCKOO_H_
#include<string>
class Stock
{private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot(){
		total_val = shares * share_val;
	}
public:
	Stock(const std::string & co,long n,double pr);
	void buy(long num,double price);
	void sell(long num,double price);
	void update(double price);
	void show();
};
#endif
