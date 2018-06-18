//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
#include<iostream>
#include<string>
#include<map>
#include<cstdio>

class Unit{
  public:
    Unit(double num, std::string unit) : data(num), unit(unit){}
    virtual ~Unit(){}
    virtual double convert(std::string unit) = 0;
    virtual double _from() = 0;
    virtual double _to(double num,std::string unit) = 0;
    double getData() {
        return data;
    }
    std::string getUnit() {
        return unit;
    }
  private:
    double data;
    std::string unit;
};

class Mass: virtual public Unit{
    public:
      Mass(double num, std::string unit) : Unit(num, unit){}
      virtual ~Mass(){}
      double convert(std::string toUnit);
      double _from();
      double _to(double num,std::string unit);
    private:
      static std::map<std::string,int> massMap;      
};

class Length : virtual public Unit{
    public:
      Length(double num, std::string unit) : Unit(num, unit) {}
      ~Length() {}
      double convert(std::string toUnit);
    private:
      double _from();
      double _to(double num, std::string unit);
      static std::map<std::string, int> lenMap;
};

class Time :virtual public Unit{
    public:
      Time(double num, std::string unit) :Unit(num, unit) {}
      ~Time() {}
      double convert(std::string toUnit);
    private:
      double _from();
      double _to(double num,std::string unit);
      static std::map<std::string, int> TimeMap;
};

class Velocity{
    public:
      Velocity(double _data, std::string unit):data(_data), len(1,unit.substr(0, unit.find('/'))),t(1,unit.substr(unit.find('/')+1, unit.length() - 1)){}
      ~Velocity(){}
      double convert(std::string toUnit);
    private:
      double data;
      Length len;
      Time t;
};

/*

class Stress : virtual public Unit{
    public:
      Stress(double num, std::string unit) : Unit(num, unit){}
      ~Stress(){}
    private:
      static std::map<std::string, int> stressMap;
};

class Force : virtual public Unit{
    public:
      Force(double num, std::string unit) : Unit(num, unit){}
      ~Force(){}
    private:
      static std::map<std::string, int> forceMap;
};
*/

std::map<std::string, int>initial_length()
{
	std::map<std::string, int> tmp;
	tmp.insert(std::make_pair("m", 1));
	tmp.insert(std::make_pair("km", 2));
	tmp.insert(std::make_pair("mile", 3));
	tmp.insert(std::make_pair("foot", 4));
	tmp.insert(std::make_pair("inch", 5));
	tmp.insert(std::make_pair("mm", 6));
	tmp.insert(std::make_pair("cm", 7));
	tmp.insert(std::make_pair("chi", 8));//尺
	tmp.insert(std::make_pair("cun", 9));//寸
	tmp.insert(std::make_pair("zhang", 10));//丈
	return tmp;
}

std::map<std::string,int> initial_mass() {
    std::map<std::string,int> temp;
    temp.insert(std::make_pair("kg",1));
    temp.insert(std::make_pair("g",2));
    temp.insert(std::make_pair("mg",3));
    temp.insert(std::make_pair("gr",4));
    temp.insert(std::make_pair("lb",5));
    temp.insert(std::make_pair("ct",6));
    temp.insert(std::make_pair("t",7));
    temp.insert(std::make_pair("oz",8));
    temp.insert(std::make_pair("q",9));
    temp.insert(std::make_pair("point",10));
    return temp;
}

std::map<std::string, int>initial_time()
{
	std::map<std::string, int>tmp;
	tmp.insert(std::make_pair("s", 1));
	tmp.insert(std::make_pair("min", 2));
	tmp.insert(std::make_pair("h", 3));
	tmp.insert(std::make_pair("day", 4));
	tmp.insert(std::make_pair("ms", 5));
	return tmp;
}

std::map<std::string,int> Mass::massMap(initial_mass());
std::map<std::string, int> Length::lenMap(initial_length());
std::map<std::string, int>Time::TimeMap(initial_time());

int main() {
    int typeNum;
    double data;
    char yOrn;
    std::string unit, toUnit;
    while(true) {
        std::cout << "*************************" << std::endl;
        std::cout << "请选择要转换的单位：" << std::endl;
        std::cout << "1、长度" << std::endl << "2、质量" << std::endl << "3、时间" << std::endl << 
        "4、速度" << std::endl << "输入序号：";
        std::cin >> typeNum;
        std::cout << "输入待转换内容（大小及单位）：" << std::endl;
        std::cin >> data >> unit;
        std::cout << "要转换为（单位）：" << std::endl;
        std::cin >> toUnit;
        switch(typeNum) {
            case 1:
            {
                Length len(data, unit);
                std::printf("结果是：%lf",len.convert(toUnit));
                std::cout << toUnit << std::endl;
                break;
            }
            case 2:
            {
                Mass weight(data, unit);
                std::printf("结果是：%lf",weight.convert(toUnit));
                std::cout << toUnit << std::endl;
                break;
            }
            case 3:
            {
                Time t(data, unit);
                std::printf("结果是：%lf",t.convert(toUnit));
                std::cout << toUnit << std::endl;
                break;
            }
            case 4:
            {
                Velocity v(data, unit);
                std::printf("结果是：%lf",v.convert(toUnit));
                std::cout << toUnit << std::endl;
                break;
            }
        }
        std::cout << "是否继续(y/n):" << std::endl;
        std::cin >> yOrn;
        if(yOrn == 'n') {
            break;
        }
    }
    return 0;
}

double Mass::_from() {
   switch(massMap.at(Unit::getUnit())) {
      case 1:return Unit::getData();
      case 2:return Unit::getData()/1000;
      case 3:return Unit::getData()/1000000;
      case 4:return Unit::getData()*0.45359237/7000;
      case 5:return Unit::getData()*0.45359237;
      case 6:return Unit::getData()*0.0002;
      case 7:return Unit::getData()*1000;
      case 8:return Unit::getData()*0.02835;
      case 9:return Unit::getData()*100;
      case 10:return Unit::getData()*2.0/1000000;
      default:return 0;
   }
}

double Mass::_to(double num, std::string unit) {
    switch(massMap.at(unit)) {
      case 1:return num;
      case 2:return num*1000;
      case 3:return num*1000000;
      case 4:return num*7000/0.45359237;
      case 5:return num/0.45359237;
      case 6:return num/0.0002;
      case 7:return num/1000;
      case 8:return num/0.02835;
      case 9:return num/100;
      case 10:return num/2.0*1000000;
      default:return 0;
    }
}

double Mass::convert(std::string toUnit) {
    return this->_to(this->_from(), toUnit);
}

double Length::_from()
{
	switch (lenMap.at(Unit::getUnit()))
	{
	case 1:return Unit::getData();
	case 2:return 1000 * Unit::getData();
	case 3:return 1609.3448*Unit::getData();
	case 4:return 0.3048*Unit::getData();
	case 5:return 0.0254*Unit::getData();
	case 6:return 0.001*Unit::getData();
	case 7:return 0.01*Unit::getData();
	case 8:return Unit::getData() / 3;
	case 9:return Unit::getData() /30;
	case 10:return Unit::getData() * 10 / 3;
	default:return 0;
  }
}

double Length::_to(double num, std::string unit)
{
	switch (lenMap.at(unit))
	{
	case 1: return num;
	case 2:return num / 1000;
	case 3:return num / 1609.3448;
	case 4:return num / 0.3048;
	case 5:return num / 0.0254;
	case 6:return num / 0.001;
	case 7:return num / 0.01;
	case 8:return Unit::getData() *3;
	case 9:return Unit::getData() *30;
	case 10:return Unit::getData() *0.3;
	default:return 0;
  }
}

double Length::convert(std::string toUnit)
{
	return _to(this->_from(), toUnit);
}

double Time::_from()
{
	switch (TimeMap.at(Unit::getUnit()))
	{
	case 1:return Unit::getData();
	case 2:return Unit::getData() * 60;
	case 3:return Unit::getData() * 3600;
	case 4:return Unit::getData() * 24 * 3600;
	case 5:return  Unit::getData()/ 1000;
  default:return 0;
	}
}

double Time::_to(double num, std::string unit)
{
	switch (TimeMap.at(unit))
	{
	case 1:return num;
	case 2:return num/ 60;
	case 3:return num/ 3600;
	case 4:return num/ (24 * 3600);
	case 5:return num * 1000;
	default:return 0;
  }
}

double Time::convert(std::string toUnit)
{
	return _to(this->_from(), toUnit);
}

double Velocity::convert(std::string toUnit) {
  return data * len.convert(toUnit.substr(0,toUnit.find('/'))) / t.convert(toUnit.substr(toUnit.find('/')+1, toUnit.length() - 1));
}