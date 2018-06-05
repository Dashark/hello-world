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
	case 3:tToothers(); break;
	case 4:qToothers(); break;
	case 5:ctToothers(); break;
	case 6:pointToothers(); break;
	case 7:lbToothers(); break;
	case 8:ozToothers(); break;
	case 9:grToothers(); break;
	case 10:stToothers(); break;
	case 11:drToothers(); break;
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
	case 0:std::cout << this->value << "mg=" << this->value / kgTomg << this->new_unit << std::endl; break;
	case 1:std::cout << this->value << "mg=" << this->value / kgTomg*kgTog << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "mg=" << this->value / kgTomg*kgTot << this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "mg=" << this->value / kgTomg*kgToq << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "mg=" << this->value / kgTomg*kgToct << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "mg=" << this->value / kgTomg*kgTopoint << this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "mg=" << this->value / kgTomg*kgTolb << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "mg=" << this->value / kgTomg*kgTooz << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "mg=" << this->value / kgTomg*kgTogr << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "mg=" << this->value / kgTomg*kgTost << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "mg=" << this->value / kgTomg*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}

void Value_Unit::tToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 0:std::cout << this->value << "t=" << this->value / kgTot << this->new_unit << std::endl; break;
	case 1:std::cout << this->value << "t=" << this->value / kgTot*kgTog << this->new_unit << std::endl; break;
	case 2:std::cout << this->value << "t=" << this->value / kgTot*kgTomg << this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "t=" << this->value / kgTot*kgToq << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "t=" << this->value / kgTot*kgToct << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "t=" << this->value / kgTot*kgTopoint << this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "t=" << this->value / kgTot*kgTolb << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "t=" << this->value / kgTot*kgTooz << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "t=" << this->value / kgTot*kgTogr << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "t=" << this->value / kgTot*kgTost << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "t=" << this->value / kgTot*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}

void Value_Unit::qToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 0:std::cout << this->value << "q=" << this->value / kgToq << this->new_unit << std::endl; break;
	case 1:std::cout << this->value << "q=" << this->value / kgToq*kgTog << this->new_unit << std::endl; break;
	case 2:std::cout << this->value << "q=" << this->value / kgToq*kgTomg << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "q=" << this->value / kgToq*kgTot << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "q=" << this->value / kgToq*kgToct << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "q=" << this->value / kgToq*kgTopoint << this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "q=" << this->value / kgToq*kgTolb << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "q=" << this->value / kgToq*kgTooz << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "q=" << this->value / kgToq*kgTogr << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "q=" << this->value / kgToq*kgTost << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "q=" << this->value / kgToq*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}

void Value_Unit::ctToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 0:std::cout << this->value << "ct=" << this->value / kgToct << this->new_unit << std::endl; break;
	case 1:std::cout << this->value << "ct=" << this->value / kgToct*kgTog << this->new_unit << std::endl; break;
	case 2:std::cout << this->value << "ct=" << this->value / kgToct*kgTomg << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "ct=" << this->value / kgToct*kgTot << this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "ct=" << this->value / kgToct*kgToq << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "ct=" << this->value / kgToct*kgTopoint << this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "ct=" << this->value / kgToct*kgTolb << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "ct=" << this->value / kgToct*kgTooz << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "ct=" << this->value / kgToct*kgTogr << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "ct=" << this->value / kgToct*kgTost << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "ct=" << this->value / kgToct*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}

void Value_Unit::pointToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 0:std::cout << this->value << "point=" << this->value / kgTopoint << this->new_unit << std::endl; break;
	case 1:std::cout << this->value << "point=" << this->value / kgTopoint*kgTog << this->new_unit << std::endl; break;
	case 2:std::cout << this->value << "point=" << this->value / kgTopoint*kgTomg << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "point=" << this->value / kgTopoint*kgTot << this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "point=" << this->value / kgTopoint*kgToq << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "point=" << this->value / kgTopoint*kgToct << this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "point=" << this->value / kgTopoint*kgTolb << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "point=" << this->value / kgTopoint*kgTooz << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "point=" << this->value / kgTopoint*kgTogr << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "point=" << this->value / kgTopoint*kgTost << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "point=" << this->value / kgTopoint*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}

void Value_Unit::lbToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 0:std::cout << this->value << "lb=" << this->value / kgTolb << this->new_unit << std::endl; break;
	case 1:std::cout << this->value << "lb=" << this->value / kgTolb*kgTog << this->new_unit << std::endl; break;
	case 2:std::cout << this->value << "lb=" << this->value / kgTolb*kgTomg << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "lb=" << this->value / kgTolb*kgTot << this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "lb=" << this->value / kgTolb*kgToq << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "lb=" << this->value / kgTolb*kgToct << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "lb=" << this->value / kgTolb*kgTopoint << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "lb=" << this->value / kgTolb*kgTooz << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "lb=" << this->value / kgTolb*kgTogr << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "lb=" << this->value / kgTolb*kgTost << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "lb=" << this->value / kgTolb*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}

void Value_Unit::ozToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 0:std::cout << this->value << "oz=" << this->value / kgTooz << this->new_unit << std::endl; break;
	case 1:std::cout << this->value << "oz=" << this->value / kgTooz*kgTog << this->new_unit << std::endl; break;
	case 2:std::cout << this->value << "oz=" << this->value / kgTooz*kgTomg << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "oz=" << this->value / kgTooz*kgTot << this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "oz=" << this->value / kgTooz*kgToq << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "oz=" << this->value / kgTooz*kgToct << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "oz=" << this->value / kgTooz*kgTopoint << this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "oz=" << this->value / kgTooz*kgTolb << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "oz=" << this->value / kgTooz*kgTogr << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "oz=" << this->value / kgTooz*kgTost << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "oz=" << this->value / kgTooz*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}

void Value_Unit::grToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 0:std::cout << this->value << "gr=" << this->value / kgTogr << this->new_unit << std::endl; break;
	case 1:std::cout << this->value << "gr=" << this->value / kgTogr*kgTog << this->new_unit << std::endl; break;
	case 2:std::cout << this->value << "gr=" << this->value / kgTogr*kgTomg << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "gr=" << this->value / kgTogr*kgTot << this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "gr=" << this->value / kgTogr*kgToq << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "gr=" << this->value / kgTogr*kgToct << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "gr=" << this->value / kgTogr*kgTopoint << this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "gr=" << this->value / kgTogr*kgTolb << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "gr=" << this->value / kgTogr*kgTooz << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "gr=" << this->value / kgTogr*kgTost << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "gr=" << this->value / kgTogr*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}

void Value_Unit::stToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 0:std::cout << this->value << "st=" << this->value / kgTost << this->new_unit << std::endl; break;
	case 1:std::cout << this->value << "st=" << this->value / kgTost*kgTog << this->new_unit << std::endl; break;
	case 2:std::cout << this->value << "st=" << this->value / kgTost*kgTomg << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "st=" << this->value / kgTost*kgTot << this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "st=" << this->value / kgTost*kgToq << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "st=" << this->value / kgTost*kgToct << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "st=" << this->value / kgTost*kgTopoint << this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "st=" << this->value / kgTost*kgTolb << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "st=" << this->value / kgTost*kgTooz << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "st=" << this->value / kgTost*kgTogr << this->new_unit << std::endl; break;
	case 11:std::cout << this->value << "st=" << this->value / kgTost*kgTodr << this->new_unit << std::endl; break;
	default:
		break;
	}
}

void Value_Unit::drToothers()
{
	int i;
	for (i = 0; i < 12; i++)
		if (weightunit[i] == this->new_unit)
			break;
	switch (i)
	{
	case 0:std::cout << this->value << "dr=" << this->value / kgTodr << this->new_unit << std::endl; break;
	case 1:std::cout << this->value << "dr=" << this->value / kgTodr*kgTog << this->new_unit << std::endl; break;
	case 2:std::cout << this->value << "dr=" << this->value / kgTodr*kgTomg << this->new_unit << std::endl; break;
	case 3:std::cout << this->value << "dr=" << this->value / kgTodr*kgTot << this->new_unit << std::endl; break;
	case 4:std::cout << this->value << "dr=" << this->value / kgTodr*kgToq << this->new_unit << std::endl; break;
	case 5:std::cout << this->value << "dr=" << this->value / kgTodr*kgToct << this->new_unit << std::endl; break;
	case 6:std::cout << this->value << "dr=" << this->value / kgTodr*kgTopoint << this->new_unit << std::endl; break;
	case 7:std::cout << this->value << "dr=" << this->value / kgTodr*kgTolb << this->new_unit << std::endl; break;
	case 8:std::cout << this->value << "dr=" << this->value / kgTodr*kgTooz << this->new_unit << std::endl; break;
	case 9:std::cout << this->value << "dr=" << this->value / kgTodr*kgTogr << this->new_unit << std::endl; break;
	case 10:std::cout << this->value << "dr=" << this->value / kgTodr*kgTost << this->new_unit << std::endl; break;
	default:
		break;
	}
}












