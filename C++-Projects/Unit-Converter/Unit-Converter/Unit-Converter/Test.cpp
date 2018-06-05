#include<iostream>
#include<string>
#include"Unit.h"
void change(int num, std::string unit);
int main()
{
	int num;
	std::string old_unit,new_unit;
	std::cin >> num >> old_unit>>new_unit;
	Value_Unit testone=Value_Unit(num, old_unit, new_unit);
	testone.Weight();
	return 0;
}

