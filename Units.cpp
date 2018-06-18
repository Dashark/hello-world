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
    virtual double convert(std::string unit) = 0;
    virtual double _from(double num, std::string unit) = 0;
    virtual double _to(double num,std::string unit) =0;
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
      ~Mass(){}
      double convert(std::string toUnit);
    private:
      double _from();
      double _to(double num,std::string unit);
      static std::map<std::string,int> massMap;
};

/*
class Length: virtual public Unit{
  public:
    Length(double num, std::string unit) : Unit(num, unit){}
    ~Length(){}
  private:
    static std::map<std::string,int> lenMap;      
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

std::map<std::string,int> Mass::massMap(initial_mass());

int main() {
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
    }
}

double Mass::convert(std::string toUnit) {
    return this->_to(this->_from(), toUnit);
}