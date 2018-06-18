//组员：任子尧 程鑫华 孙银凯
//完整代码：https://github.com/uuuser123/UnitConverter

#include<bits/stdc++.h>
#include<QApplication>
#include<QMainWindow>
#include<QLayout>
#include<QLabel>
#include<QPushButton>
#include<QWidget>
#include<QTextCodec>
#include<QLineEdit>
#include<QMessageBox>

using namespace std;

class unit{
	public:
		unit(){}
		~unit(){}
		double convert(string newUnit);//change the unit and return coefficient(if the unit type is different return -1)
		int set(string newUnit);//change the unit and return 0 if suceed(only use if the unit type is diffierent)
		string showUnit();//return the unit name
		string showUnitTypeName();//return the unit type name
	private:
		int unitId;
		int unitType;
};

double unit::convert(string newUnit)
{
	for(int i=0;i<maxUnitType;i++)
	{
		for(int j=0;j<maxUnitNum;j++)
		{
			if(newUnit==unitName[i][j])
			{
				if(i!=unitType)
				{
					return -1;
				}
				double ret=coefficient[unitType][unitId]/coefficient[unitType][j];
				unitId=j;
				unitType=i;
				return ret;
			}
		}
	}
	return -1;
}

int unit::set(string newUnit)
{
	for(int i=1;i<maxUnitType;i++)
	{
		for(int j=0;j<maxUnitNum;j++)
		{
			if(newUnit==unitName[i][j])
			{
				unitId=j;
				unitType=i;
				return 0;
			}
		}
	}
	unitType=0;
	return 1;
}

string unit::showUnit()
{
	return unitName[unitType][unitId];
}

string unit::showUnitTypeName()
{
	return unitTypeName[unitType];
}

class mainWin:public QMainWindow{
	Q_OBJECT
	private:
		QPushButton *button1;
		QPushButton *button2;
		QPushButton *button3;
		QLineEdit *edit1,*edit2,*edit3,*edit4,*edit5,*edit6;
	private slots:  
		void convert(){
			string unitNumStr=(edit1->text()+edit2->text()).toStdString();
			unitNum a=unitNum(unitNumStr);
			int ret=a.convertUnit(edit4->text().toStdString());
			if(ret==0)
				edit3->setText(QString::fromStdString(to_string(a.showVal())));
			else
				edit3->setText("Err");
		}
		int calculate(){
			string expression=(edit5->text()).toStdString()+"$";
			int lastPos=0;
			unitNum ans=unitNum("");
			bool first=true;
			for(int i=0;i<(int)expression.length();i++)
			{
				if(expression[i]=='+' || expression[i]=='-' || expression[i]=='$')
				{
					if(first){
						ans=unitNum(expression.substr(0,i));
						lastPos=i;
						first=false;
						continue;
					}
					unitNum tmp=unitNum(expression.substr(lastPos+1,i-lastPos-1));
					if(tmp.showUnitTypeName()!=ans.showUnitTypeName()){
						edit6->setText("Err");
						return 0;
					}
					if(expression[lastPos]=='+'){
						ans=ans+tmp;
					}
					else if(expression[lastPos]=='-'){
						ans=ans-tmp;
					}
					lastPos=i;
				}
			}
			edit6->setText(QString::fromStdString(to_string(ans.showVal())+ans.showUnit()));
			return 0;
		}
	public:
		mainWin(){
			this->resize(QSize(600,300));
			this->setWindowTitle("Unit Converter");
			QGridLayout *layout=new QGridLayout;
			for(int i=0;i<8;i++)
				layout->setColumnStretch(i,1);
			for(int i=0;i<5;i++)
				layout->setRowStretch(i,1);
			QWidget *mywidget=new QWidget;
			mywidget->setLayout(layout);
			this->setCentralWidget(mywidget);
			//add button1&button2
			button1=new QPushButton("-->");
			button2=new QPushButton("=");
			layout->addWidget(button1,1,3,1,1);
			layout->addWidget(button2,3,4,1,1);
			//add label1
			QLabel *label1= new QLabel("单位转换器");
			layout->addWidget(label1,0,2,1,4,Qt::AlignCenter);
			//add lineedit
			edit1=new QLineEdit;
			layout->addWidget(edit1,1,1,1,1);
			//add lineedit
			edit2=new QLineEdit("Unit");
			layout->addWidget(edit2,1,2,1,1);
			//add lineedit
			edit3=new QLineEdit();
			layout->addWidget(edit3,1,4,1,1);
			//add lineedit
			edit4=new QLineEdit("NewUnit");	
			layout->addWidget(edit4,1,5,1,2);
			edit5=new QLineEdit("e.g. 1km+3m");
			layout->addWidget(edit5,3,1,1,3);
			edit6=new QLineEdit("Ans & Unit");
			layout->addWidget(edit6,3,5,1,2);
			edit6->setFocusPolicy(Qt::NoFocus);
			edit3->setFocusPolicy(Qt::NoFocus);
			connect(button1, SIGNAL(clicked()), this, SLOT(convert())); 
			connect(button2, SIGNAL(clicked()), this, SLOT(calculate())); 
		} 
};

int main(int argc,char *argv[]){
	QTextCodec *codec=QTextCodec::codecForName("utf-8");
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForTr(codec);
	QApplication app(argc,argv);
	mainWin *win=new mainWin;
	win->show();
	app.exec();
	return 0;
}

