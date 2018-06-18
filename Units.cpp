//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
#include<iostream>
#include<string>
#include<map>

class Unit{
    public:
      Unit(double num, std::string unit) : data(num), unit(unit){}
      ~Unit(){}
      virtual double convert(Unit &obj);
      virtual double _from(double num, std::string unit, std::map<std::string,int>& unitMap);
    private:
      double data;
      std::string unit;
};


class Length: virtual public Unit{
    public:
      Length(double num, std::string unit) : Unit(num, unit){}
      ~Length(){}
    private:
      std::map<std::string,int> lenMap;
};

/*
class Mass: virtual public Unit{
    public:
      Mass(double num, std::string unit) : Unit(num, unit){}
      ~Mass(){}
    private:
      static std::vector<std::vector<double(*)(double)> > Formula;
};

class Stress : virtual public Unit{
    public:
      Stress(double num, std::string unit) : Unit(num, unit){}
      ~Stress(){}
    private:
      static std::vector<std::vector<double(*)(double)> > Formula;      
};

class Force : virtual public Unit{
    public:
      Force(double num, std::string unit) : Unit(num, unit){}
      ~Force(){}
    private:
      static std::vector<std::vector<double(*)(double)> > Formula;      
};
*/

double Unit::_from(double num, std::string unit, std::map<std::string,int>& unitMap) {
  switch(unitMap.at(unit)){
    case 1:return num*1000;
    case 2:return 1;
  }
}