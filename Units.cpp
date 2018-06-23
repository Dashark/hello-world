//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的

// Cooperate with FingerBlack (https://github.com/FingerBlack/)
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

map<string, double> length;
map<string, double> weight;
map<string, double> pressure;
map<string, double> force;


class dosomething{
public:
    void doing(map<string, double> a, double _num, string _originUnit, string _toUnit){
        // cout << "请输入值和原单位以及新单位" << endl;
        // double yy;
        // string ss, ss1;
        
        // cin >> yy >> ss >> ss1;
        
        printf("%.8lf\n", _num * a[ _originUnit ] / a[ _toUnit ]);
    }

};

static void print_usage( char* argv[] ) {
    printf( "\nusage: %s unittype number originUnit exceptUnit \n", argv[ 0 ] );
    printf( "\nnumber               : Number that you want to convert" );
    printf( "\noriginUnit           : Unit to be converted" );
    printf( "\nexceptUnit           : Unit want to convert to" );
    printf( "\n   unittype:" );
    printf( "\n-weight              : We accept: t, kg, g, mg, mug, μg, q, lb, oz, ct, gr, dr," );
    printf( "\n                       dan, jin, jin(tw), liang, qian" );
    printf( "\n-length              : We accept: km, m, dm, cm, mm, μm, mum, nm, nmi, mi, fur," ); 
    printf( "\n                       fm, yd, ft, in, gongli, li, zhang, chi, cun, fen, lii, hao" );
    printf( "\n-force            : We accept: N, dyn, lbf" ); 
    printf( "\n-pressure            : We accept: pa, mpa, psi" ); 
    printf( "\nexample: %s -weight 10 kg g", argv[ 0 ]);
}

int main(int argc, char* argv[]) //（参数个数，指向字符串的指针，指向环境变量的指针）
{
    // weight
    weight[ "t" ] = 1000000;
    weight[ "kg" ] = 1000;
    weight[ "g" ] = 1;
    weight[ "mg" ] = 0.001;
    weight[ "mug" ] = 0.000001;
    weight[ "μg" ] = 0.000001;
    weight[ "q" ] = 100000;
    weight[ "lb" ] = 453.59237;
    weight[ "oz" ] = weight[ "lb" ] / 16;
    weight[ "ct" ] = 0.2;
    weight[ "gr" ] = 0.06479891;
    weight[ "dr" ] = weight[ "oz" ] / 16;
    weight[ "dan" ] = 50000;
    weight[ "jin" ] = 500;
    weight[ "qian" ] = 5;
    weight[ "liang" ] = 50;
    weight[ "jin(tw)" ] = 600;
    
    // force
    force[ "N" ] = 1; // 1 N = 1 kg*m/s^2
    force[ "dyn" ] = 1/100000; // 1 dyn = 1 g·cm/s2
    force[ "lbf" ] = ((weight[ "lb" ]/1000) * 9.80665); // 1 lbf = 0.45359237 kg × 9.80665 m/s2 = 4.4482216152605

    //length
    length[ "km" ] = 1000;
    length[ "m" ] = 1;
    length[ "dm" ] = 0.1;
    length[ "cm" ] = 0.01;
    length[ "mm" ] = 0.001;
    length[ "mum" ] = 0.000001;
    length[ "μm" ] = 0.000001;
    length[ "nm" ] = 0.000000001;
    length[ "nmi" ] = 1852;
    length[ "mi" ] = 1609.344;
    length[ "fur" ] = 201.168;
    length[ "fm" ] = 1.8288;
    length[ "yd" ] = 0.9144;
    length[ "ft" ] = 0.3048;
    length[ "in" ] = 0.0254;
    length[ "gongli" ] = 1000;
    length[ "li" ] = 500;
    length[ "zhang" ] = 10/3;
    length[ "chi" ] = 1/3;
    length[ "cun" ] = 1/30;
    length[ "fen" ] = 1/300;
    length[ "lii" ] = 1/3000;
    length[ "hao" ] = 1/30000;
    
    //pressure = force / (length*length)
    pressure[ "pa" ] = 1; // = 1 N / 1 m^2
    pressure[ "mpa" ] = pressure[ "pa" ] * 1000000;
    // pressure[ "psi" ] = 6894.757;
    pressure[ "psi" ] = force[ "lbf" ] / (length[ "in" ] * length[ "in" ]);
    
    if( argc < 4 ){
        print_usage( argv );
        exit( 0 );
    }
    
    /* get arguments */
    double number;
    string ounit, tunit;
    
    sscanf(argv[ 2 ], "%lf", &number);
    ounit = argv[ 3 ];
    tunit = argv[ 4 ];
    char strTtypeunit[ 150 ];
    strcpy( strTtypeunit, argv[ 1 ] );
	map<string, double> ::iterator it0 = weight.find(ounit);
	map<string, double> ::iterator it00 = weight.find(tunit);
	map<string, double> ::iterator it1 = length.find(ounit);
	map<string, double> ::iterator it11 = length.find(tunit);
	map<string, double> ::iterator it2 = pressure.find(ounit);
	map<string, double> ::iterator it22= pressure.find(tunit);
	map<string, double> ::iterator it3 = force.find(ounit);
	map<string, double> ::iterator it33 = force.find(tunit);
	if (it0 != weight.end() || it1 != length.end() || it2 != pressure.end() || it3 != force.end()||it00 != weight.end() ||
		it11 != length.end() || it22 != pressure.end() ||it33 != force.end()){

		dosomething d;

		if (strcmp(strTtypeunit, "-weight") == 0){
			d.doing(weight, number, ounit, tunit);
		}
		else if (strcmp(strTtypeunit, "-length") == 0){
			d.doing(length, number, ounit, tunit);
		}
		else if (strcmp(strTtypeunit, "-pressure") == 0){
			d.doing(pressure, number, ounit, tunit);
		}
		else if (strcmp(strTtypeunit, "-force") == 0){
			d.doing(force, number, ounit, tunit);
		}
		else{
			printf("Error: unrecognized unittype: %s\n\n", strTtypeunit);
			print_usage(argv);
			exit(0);
		}
	}
	else{
		printf("It's a wrong data.\n");
	}
    return 0;
}
//注意 ： argv[0]    是  ./filename

