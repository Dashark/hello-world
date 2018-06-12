#ifndef UNIT_H_
#define UNIT_H_
#include<string>
#include <iomanip>
#include<iostream>
class Value_Unit
{
public:
	double value;//数值
	std::string old_unit;//原单位
	std::string new_unit;//新单位
	Value_Unit(){ value = 0; old_unit = "#"; new_unit = "#"; };//默认构造函数
	Value_Unit(double newvalue,std::string newold_unit,std::string newnew_unit);
	virtual Value_Unit Converter(){ return  Value_Unit(); };
	~Value_Unit();
	friend std::ostream & operator << (std::ostream &os, const Value_Unit&test);//对<<运算符重载，使显示对象的内容
};

class Weight_Converter:public Value_Unit//Weight_Converter公有继承自Value_Unit,表示质量单位转换
{
public:
	/*公制：kg（千克），g（克），mg（毫克），t（吨），q（公担），ct（克拉），point（分）
	英制：lb（磅），oz（盎司），gr（格令），st（英石），dr（打兰）
	*/
	Weight_Converter(double newvalue, std::string newold_unit, std::string newnew_unit);
	~Weight_Converter();
	virtual Value_Unit Converter();//质量单位转换，覆盖抽象基类Converter()方法
	Weight_Converter kgToothers();//从kg转换到其他单位
	Weight_Converter gToothers();//从g转换到其他单位
	Weight_Converter mgToothers();//从mg转换到其他单位
	Weight_Converter tToothers();//从t转换到其他单位
	Weight_Converter qToothers();//从q转换到其他单位
	Weight_Converter ctToothers();//从ct转换到其他单位
	Weight_Converter pointToothers();//从point转换到其他单位
	Weight_Converter lbToothers();//从lb转换到其他单位
	Weight_Converter ozToothers();//从oz转换到其他单位
	Weight_Converter grToothers();//从gr转换到其他单位
	Weight_Converter stToothers();//从st转换到其他单位
	Weight_Converter drToothers();//从dr转换到其他单位
	
};

class Temper_Converter :public Value_Unit//Temper_Converter公有继承自Value_Unit,表示温度单位转换
{
public:
	//C（摄氏度），F（华氏度），K（开尔文），R（兰氏度），Re（列式度）
	Temper_Converter(double newvalue, std::string newold_unit, std::string newnew_unit);
	~Temper_Converter();
	virtual Value_Unit Converter();//温度单位转换，覆盖抽象基类Converter()方法
	Temper_Converter CToothers();//从C转换到其他单位
	Temper_Converter FToothers();//从F转换到其他单位
	Temper_Converter KToothers();//从K转换到其他单位
	Temper_Converter RToothers();//从R转换到其他单位
	Temper_Converter ReToothers();//从Re转换到其他单位
};

#endif UNIT_H_