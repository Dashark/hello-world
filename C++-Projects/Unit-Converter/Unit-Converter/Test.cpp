#include<iostream>
#include<string>
#include"Unit.h"
void change(int num, std::string unit);
int main()
{
	int num;
	std::cout << "该程序可实现下列单位的互相转换：" << std::endl << "公制：kg（千克），g（克），mg（毫克），t（吨），q（公担），point（分）" << std::endl << "英制：lb（磅），oz（盎司），gr（格令），st（英石），dr（打兰），ct（克拉）" << std::endl;
	std::string old_unit,new_unit;
	std::cout << "请输入数值: ";
	std::cin >> num;
	std::cout << "请输入旧单位: ";
	std::cin >> old_unit;
	std::cout << "请输入新单位: ";
	std::cin >> new_unit;
	Value_Unit testone=Value_Unit(num, old_unit, new_unit);
	testone.Weight();
	return 0;
}

