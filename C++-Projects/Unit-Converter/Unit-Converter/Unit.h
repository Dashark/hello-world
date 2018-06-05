#ifndef UNIT_H_
#define UNIT_H_
#include<string>
class Value_Unit
{
public:

	/*公制：kg（千克），g（克），mg（毫克），t（吨），q（公担），ct（克拉），point（分）
	英制：lb（磅），oz（盎司），gr（格令），st（英石），dr（打兰）
	*/
	double value;//数值
	std::string old_unit;//原单位
	std::string new_unit;//新单位
	Value_Unit(double newvalue,std::string newold_unit,std::string newnew_unit);
	void Weight();//质量单位转换
	void kgToothers();//从kg转换到其他单位
	void gToothers();//从g转换到其他单位
	void mgToothers();//从mg转换到其他单位
	void tToothers();//从t转换到其他单位
	void qToothers();//从q转换到其他单位
	void ctToothers();//从ct转换到其他单位
	void pointToothers();//从point转换到其他单位
	void lbToothers();//从lb转换到其他单位
	void ozToothers();//从oz转换到其他单位
	void grToothers();//从gr转换到其他单位
	void stToothers();//从st转换到其他单位
	void drToothers();//从dr转换到其他单位
	~Value_Unit();
};
#endif UNIT_H_