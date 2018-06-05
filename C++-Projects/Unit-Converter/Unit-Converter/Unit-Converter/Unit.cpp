#include"Unit.h"
#include<string>
#include<iostream>

/*公制：kg（千克），g（克），mg（毫克），t（吨），q（公担），ct（克拉），point（分）
英制：lb（磅），oz（盎司），gr（格令），st（英石），dr（打兰）
*/
const std::string weightunit[12] { "kg", "g", "mg", "t", "q", "ct", "point", "lb", "oz", "gr", "st", "dr" };
//kg转换成其他单位的换算率
const double kgTog = 1000, kgTomg = 1000000, kgTot = 0.001, kgToq = 0.01, kgToct = 5000, kgTopoint = 500000, kgTolb = 2.2046226, kgTooz = 35.2739619, kgTogr = 15432.3583529, kgTost = 0.157473, kgTodr = 564.3833912;

Value_Unit::Value_Unit(double newvalue, std::string newold_unit, std::string newnew_unit)
{
	value = newvalue;
	old_unit = newold_unit;
	new_unit = newnew_unit;
}

Value_Unit::~Value_Unit()
{

}

void Value_Unit::Weight()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->old_unit)
			break;
	switch (i)
	{
	case 0:kgToothers(); break;
	case 1:gToothers(); break;
	case 2:mgToothers(); break;
	default:
		break;
	}
}

void Value_Unit::kgToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 1:std::cout << this->value << "kg=" << this->value*kgTog << this->new_unit << std::endl; break;
	case 2:std::cout << this->value << "kg=" << this->value*kgTomg << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "kg=" << this->value*kgTot<< this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "kg=" << this->value*kgToq << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "kg=" << this->value*kgToct << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "kg=" << this->value*kgTopoint<< this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "kg=" << this->value*kgTolb << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "kg=" << this->value*kgTooz << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "kg=" << this->value*kgTogr << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "kg=" << this->value*kgTost << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "kg=" << this->value*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}

void Value_Unit::gToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 0:std::cout << this->value << "g=" << this->value / kgTog << this->new_unit << std::endl; break;
	case 2:std::cout << this->value << "g=" << this->value / kgTog*kgTomg << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "g=" << this->value / kgTog*kgTot << this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "g=" << this->value / kgTog*kgToq << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "g=" << this->value / kgTog*kgToct << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "g=" << this->value / kgTog*kgTopoint << this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "g=" << this->value / kgTog*kgTolb << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "g=" << this->value / kgTog*kgTooz << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "g=" << this->value / kgTog*kgTogr << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "g=" << this->value / kgTog*kgTost << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "g=" << this->value / kgTog*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}

void Value_Unit::mgToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 0:std::cout << this->value << "mg=" << this->value / kgTog << this->new_unit << std::endl; break;
	case 1:std::cout << this->value << "mg" << this->value / kgTog*kgTomg << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "mg" << this->value / kgTog*kgTot << this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "mg" << this->value / kgTog*kgToq << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "mg" << this->value / kgTog*kgToct << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "mg" << this->value / kgTog*kgTopoint << this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "mg" << this->value / kgTog*kgTolb << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "mg" << this->value / kgTog*kgTooz << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "mg" << this->value / kgTog*kgTogr << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "mg=" << this->value / kgTog*kgTost << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "mg=" << this->value / kgTog*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}