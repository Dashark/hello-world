#include<iostream>
#include<string>
#include"Unit.h"
int main()
{
	double num;
	std::string old_unit, new_unit;
	//----------------测试质量单位转换
	std::cout << "1.测试质量单位转换，可转换单位如下：" << std::endl << "公制：kg（千克），g（克），mg（毫克），t（吨），q（公担），point（分）." << std::endl << "英制：lb（磅），oz（盎司），gr（格令），st（英石），dr（打兰），ct（克拉）." << std::endl;
	std::cout << "请输入数值: ";
	std::cin >> num;
	std::cout << "请输入旧单位: ";
	std::cin >> old_unit;
	std::cout << "请输入新单位: ";
	std::cin >> new_unit;
	Weight_Converter resultone = Weight_Converter(num, old_unit, new_unit);
	resultone.Converter();
	std::cout << num << resultone;
	//-----------------测试温度单位转换
	std::cout <<std::endl<< "2.测试温度单位转换，可转换单位如下：" << std::endl << "C（摄氏度），F（华氏度），K（开尔文），R（兰氏度），Re（列式度）." << std::endl;
	std::cout << "请输入数值: ";
	std::cin >> num;
	std::cout << "请输入旧单位: ";
	std::cin >> old_unit;
	std::cout << "请输入新单位: ";
	std::cin >> new_unit;
	Temper_Converter resulttwo = Temper_Converter(num, old_unit, new_unit);
	resulttwo.Converter();
	std::cout << num << resulttwo;
	return 0;
}

