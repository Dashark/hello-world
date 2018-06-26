#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

double m1,m2;

int main(){
 int i,j,k,n,k1,k2,m;
 char s1[10];
 char s2[10];
 char ch;
 cout<<"欢迎来到鱼尾质朴的单位转换器"<<endl;
 cout<<"本转换器功能十分强大。"<<endl; 
 m=1;
 while (m==1){
 cout<<endl;
 cout<<"1:长度"<<endl;
 cout<<"2:质量"<<endl;
 cout<<"3:温度"<<endl;
 cout<<"4:压力"<<endl;
 cout<<"5:时间"<<endl;
 cout<<"6:速度"<<endl;
 cout<<"7:角度"<<endl;
 cout<<"8:退出"<<endl; 
 cout<<endl;
 cout<<"请选择功能(数字序号):";
 cin>>n;
 ch='Y';
 switch(n){
    case 1:
   while(ch=='Y'){
    cout<<endl<<"请输入长度数值是：";
    cin>>m1; 
    cout<<endl<<"1:千米(km)  2:米(m)  3:分米(dm)  4:厘米(cm)  5:毫米(mm)  6:微米(μm)  7:纳米(nm)"<<endl;
    cout<<"你输入的数值单位是:(序号)";
       cin>>k1;
    switch(k1){
       case 1:strcpy(s1,"千米");break;
       case 2:strcpy(s1,"米");break;
       case 3:strcpy(s1,"分米");break;
       case 4:strcpy(s1,"厘米");break;
       case 5:strcpy(s1,"毫米");break;
       case 6:strcpy(s1,"微米");break;
       case 7:strcpy(s1,"纳米");break;
      }       
    cout<<endl<<"1:千米(km)  2:米(m)  3:分米(dm)  4:厘米(cm)  5:毫米(mm)  6:微米(um)  7:纳米(nm)"<<endl;
    cout<<"你想转换到的单位是:(序号)"; 
    cin>>k2; 
    switch(k2){
       case 1:strcpy(s2,"千米");break;
       case 2:strcpy(s2,"米");break;
       case 3:strcpy(s2,"分米");break;
       case 4:strcpy(s2,"厘米");break;
       case 5:strcpy(s2,"毫米");break;
       case 6:strcpy(s2,"微米");break;
       case 7:strcpy(s2,"纳米");break;
      }
    switch(k1){
     case 1:
      strcpy(s1,"千米");
      switch(k2){
       case 1:m2=m1;break;
       case 2:m2=m1*1000;break;
       case 3:m2=m1*10000;break;
       case 4:m2=m1*100000;break;
       case 5:m2=m1*1000000;break;
       case 6:m2=m1*1000000000;break;
       case 7:m2=m1/1000000000000;break;
      }
      break;
     case 2:
      switch(k2){
       case 1:m2=m1/1000;break;
       case 2:m2=m1;break;
       case 3:m2=m1*10;break;
       case 4:m2=m1*100;break;
       case 5:m2=m1*1000;break;
       case 6:m2=m1*1000000;break;
       case 7:m2=m1/1000000000;break;
      }
      break;
     case 3:
      switch(k2){
       case 1:m2=m1/10000;break;
       case 2:m2=m1/10;break;
       case 3:m2=m1;break;
       case 4:m2=m1*10;break;
       case 5:m2=m1*100;break;
       case 6:m2=m1*100000;break;
       case 7:m2=m1/100000000;break;
      }
      break;
     case 4:
      switch(k2){
       case 1:m2=m1/100000;break;
       case 2:m2=m1/100;break;
       case 3:m2=m1/10;break;
       case 4:m2=m1*1;break;
       case 5:m2=m1*10;break;
       case 6:m2=m1*10000;break;
       case 7:m2=m1/10000000;break;
      }
      break;
     case 5:
      switch(k2){
       case 1:m2=m1/1000000;break;
       case 2:m2=m1/1000;break;
       case 3:m2=m1/100;break;
       case 4:m2=m1/10;break;
       case 5:m2=m1*1;break;
       case 6:m2=m1*1000;break;
       case 7:m2=m1/1000000;break;
      }
      break;
     case 6:
      switch(k2){
       case 1:m2=m1/1000000000;break;
       case 2:m2=m1/1000000;break;
       case 3:m2=m1/100000;break;
       case 4:m2=m1/10000;break;
       case 5:m2=m1/1000;break;
       case 6:m2=m1*1;break;
       case 7:m2=m1/1000;break;
      }
      break;
     case 7:
      switch(k2){
       case 1:m2=m1/1000000000000;break;
       case 2:m2=m1/1000000000;break;
       case 3:m2=m1/100000000;break;
       case 4:m2=m1/10000000;break;
       case 5:m2=m1/1000000;break;
       case 6:m2=m1/1000;break;
       case 7:m2=m1;break;
      }
      break;
    }
    cout<<endl<<endl<<"转化后结果是："<<endl<<"  "<<m1<<" "<<s1<<" = "<<m2<<" "<<s2<<endl;
  
   ch='1';
   while(ch!='Y' && ch!='N'){ 
    cout<<"还想继续转换长度吗？（Y/N）:";
    cin>>ch;
      } 
    }
    break;
    case 2:
   while(ch=='Y'){
    cout<<endl<<"请输入质量数值是：";
    cin>>m1; 
    cout<<endl<<"1:吨(t)  2:千克(kg)  3:克(g)  4:毫克(mg)  5:微克(μg)"<<endl;
    cout<<"你输入的数值单位是:(序号)";
       cin>>k1;
    switch(k1){
       case 1:strcpy(s1,"吨");break;
       case 2:strcpy(s1,"千克");break;
       case 3:strcpy(s1,"克");break;
       case 4:strcpy(s1,"毫克");break;
       case 5:strcpy(s1,"微克");break;
      }       
   cout<<endl<<"1:吨(t)  2:千克(kg)  3:克(g)  4:毫克(mg)  5:微克(μg)"<<endl;
    cout<<"你想转换到的单位是:(序号)"; 
    cin>>k2; 
    switch(k2){
       case 1:strcpy(s2,"吨");break;
       case 2:strcpy(s2,"千克");break;
       case 3:strcpy(s2,"克");break;
       case 4:strcpy(s2,"毫克");break;
       case 5:strcpy(s2,"微克");break;
      }
    switch(k1){
     case 1:
      switch(k2){
       case 1:m2=m1;break;
       case 2:m2=m1*1000;break;
       case 3:m2=m1*1000000;break;
       case 4:m2=m1*1000000000;break;
       case 5:m2=m1*1000000000000;break;
      }
      break;
     case 2:
      switch(k2){
       case 1:m2=m1/1000;break;
       case 2:m2=m1;break;
       case 3:m2=m1*1000;break;
       case 4:m2=m1*1000000;break;
       case 5:m2=m1*1000000000;break;
      }
      break;
     case 3:
      switch(k2){
       case 1:m2=m1/1000000;break;
       case 2:m2=m1/1000;break;
       case 3:m2=m1;break;
       case 4:m2=m1*1000;break;
       case 5:m2=m1*1000000;break;
      }
      break;
     case 4:
      switch(k2){
       case 1:m2=m1/1000000000;break;
       case 2:m2=m1/1000000;break;
       case 3:m2=m1/1000;break;
       case 4:m2=m1*1;break;
       case 5:m2=m1*1000;break;
      }
      break;
     case 5:
      switch(k2){
       case 1:m2=m1/1000000000000;break;
       case 2:m2=m1/1000000000;break;
       case 3:m2=m1/1000000;break;
       case 4:m2=m1/1000;break;
       case 5:m2=m1*1;break;
      }
      break;
    }
    cout<<endl<<endl<<"转化后结果是："<<endl<<"  "<<m1<<" "<<s1<<" = "<<m2<<" "<<s2<<endl;
  
   ch='1';
   while(ch!='Y' && ch!='N'){ 
    cout<<"还想继续转换质量吗？（Y/N）:";
    cin>>ch;
      } 
    }
    break;
    case 3:
   while(ch=='Y'){
    cout<<endl<<"请输入温度数值是：";
    cin>>m1; 
    cout<<endl<<"1:摄氏度(°C)  2:华氏度(°F)  3:开氏度(K)"<<endl;
    cout<<"你输入的数值单位是:(序号)";
       cin>>k1;
    switch(k1){
       case 1:strcpy(s1,"摄氏度");break;
       case 2:strcpy(s1,"华氏度");break;
       case 3:strcpy(s1,"开氏度");break;
      }       
   cout<<endl<<"1:摄氏度(°C)  2:华氏度(°F)  3:开氏度(K)"<<endl;
    cout<<"你想转换到的单位是:(序号)"; 
    cin>>k2; 
    switch(k2){
       case 1:strcpy(s2,"摄氏度");break;
       case 2:strcpy(s2,"华氏度");break;
       case 3:strcpy(s2,"开氏度");break;
      }
    switch(k1){
     case 1:
      switch(k2){
       case 1:m2=m1;break;
       case 2:m2=m1*1.8+32;break;
       case 3:m2=m1+273.15;break;
      }
      break;
     case 2:
      switch(k2){
       case 1:m2=(m1-32)/1.8;break;
       case 2:m2=m1;break;
       case 3:m2=(m1-32)/1.8+273.15;break;

      }
      break;
     case 3:
      switch(k2){
       case 1:m2=m1-273.15;break;
       case 2:m2=(m1-273.15)*1.8+32;break;
       case 3:m2=m1;break;
      }
      break;
    }
    cout<<endl<<endl<<"转化后结果是："<<endl<<"  "<<m1<<" "<<s1<<" = "<<m2<<" "<<s2<<endl;
  
   ch='1';
   while(ch!='Y' && ch!='N'){ 
    cout<<"还想继续转换温度吗？（Y/N）:";
    cin>>ch;
      } 
    }
    break;
    case 4:
   while(ch=='Y'){
    cout<<endl<<"请输入压力数值是：";
    cin>>m1; 
    cout<<endl<<"1:兆帕(MPa)  2:千帕(kPa)  3:百帕(hPa)  4:帕斯卡(Pa)  5:标准大气压(atm)"<<endl;
    cout<<"你输入的数值单位是:(序号)";
       cin>>k1;
    switch(k1){
       case 1:strcpy(s1,"兆帕");break;
       case 2:strcpy(s1,"千帕");break;
       case 3:strcpy(s1,"百帕");break;
       case 4:strcpy(s1,"帕斯卡");break;
       case 5:strcpy(s1,"个标准大气压");break;
      }       
   cout<<endl<<"1:兆帕(MPa)  2:千帕(kPa)  3:百帕(hPa)  4:帕斯卡(Pa)  5:标准大气压(atm)"<<endl;
    cout<<"你想转换到的单位是:(序号)"; 
    cin>>k2; 
    switch(k2){
       case 1:strcpy(s2,"兆帕");break;
       case 2:strcpy(s2,"千帕");break;
       case 3:strcpy(s2,"百帕");break;
       case 4:strcpy(s2,"帕");break;
       case 5:strcpy(s2,"个标准大气压");break;
      }
    switch(k1){
     case 1:
      switch(k2){
       case 1:m2=m1;break;
       case 2:m2=m1*1000;break;
       case 3:m2=m1*10000;break;
       case 4:m2=m1*10000000;break;
       case 5:m2=m1*9.86923267;break;
      }
      break;
     case 2:
      switch(k2){
       case 1:m2=m1/1000;break;
       case 2:m2=m1;break;
       case 3:m2=m1*10;break;
       case 4:m2=m1*1000;break;
       case 5:m2=m1*0.009869232;break;
      }
      break;
     case 3:
      switch(k2){
       case 1:m2=m1/10000;break;
       case 2:m2=m1/10;break;
       case 3:m2=m1;break;
       case 4:m2=m1*100;break;
       case 5:m2=m1*0.0009869232;break;
      }
      break;
     case 4:
      switch(k2){
       case 1:m2=m1/1000000;break;
       case 2:m2=m1/1000;break;
       case 3:m2=m1/100;break;
       case 4:m2=m1*1;break;
       case 5:m2=m1*0.00000986923;break;
      }
      break;
     case 5:
      switch(k2){
       case 1:m2=m1*0.101325;break;
       case 2:m2=m1*101.325;break;
       case 3:m2=m1*1013.25;break;
       case 4:m2=m1*101325;break;
       case 5:m2=m1*1;break;
      }
      break;
    }
    cout<<endl<<endl<<"转化后结果是："<<endl<<"  "<<m1<<" "<<s1<<" = "<<m2<<" "<<s2<<endl;
  
   ch='1';
   while(ch!='Y' && ch!='N'){ 
    cout<<"还想继续转换压力吗？（Y/N）:";
    cin>>ch;
      } 
    }
    break;
    case 5:
   while(ch=='Y'){
    cout<<endl<<"请输入时间数值是：";
    cin>>m1; 
    cout<<endl<<"1:年(yr)  2:月(month)  3:周(week)  4:天(day)  5:小时(h)  6:分钟(min)  7:秒(s)"<<endl;
    cout<<"你输入的数值单位是:(序号)";
       cin>>k1;
    switch(k1){
       case 1:strcpy(s1,"年");break;
       case 2:strcpy(s1,"月");break;
       case 3:strcpy(s1,"周");break;
       case 4:strcpy(s1,"天");break;
       case 5:strcpy(s1,"小时");break;
       case 6:strcpy(s1,"分钟");break;
       case 7:strcpy(s1,"秒");break;
      }       
    cout<<endl<<"1:年(yr)  2:月(month)  3:周(week)  4:天(day)  5:小时(h)  6:分钟(min)  7:秒(s)"<<endl;
    cout<<"你想转换到的单位是:(序号)"; 
    cin>>k2; 
    switch(k2){
       case 1:strcpy(s2,"年");break;
       case 2:strcpy(s2,"月");break;
       case 3:strcpy(s2,"周");break;
       case 4:strcpy(s2,"天");break;
       case 5:strcpy(s2,"小时");break;
       case 6:strcpy(s2,"分钟");break;
       case 7:strcpy(s2,"秒");break;
      } 
    switch(k1){
     case 1:
      switch(k2){
       case 1:m2=m1;break;
       case 2:m2=m1*12;break;
       case 3:m2=m1*52.1428523;break;
       case 4:m2=m1*364.9999977;break;
       case 5:m2=m1*8760.000007;break;
       case 6:m2=m1*525600.0010512;break;
       case 7:m2=m1*31536000;break;
      }
      break;
     case 2:
      switch(k2){
       case 1:m2=m1/12;break;
       case 2:m2=m1*12/12;break;
       case 3:m2=m1*52.1428523/12;break;
       case 4:m2=m1*364.9999977/12;break;
       case 5:m2=m1*8760.000007/12;break;
       case 6:m2=m1*525600.0010512/12;break;
       case 7:m2=m1*31536000/12;break;
      }
      break;
     case 3:
      switch(k2){
       case 1:m2=m1*0.0191781;break;
       case 2:m2=m1*0.0191781*12;break;
       case 3:m2=m1;break;
       case 4:m2=m1*7;break;
       case 5:m2=m1*168.0000001;break;
       case 6:m2=m1*10080.0000202;break;
       case 7:m2=m1*604800;break;
      }
      break;
     case 4:
      switch(k2){
       case 1:m2=m1*0.0027397;break;
       case 2:m2=m1*0.0027397*12;break;
       case 3:m2=m1*0.1428571;break;
       case 4:m2=m1*1;break;
       case 5:m2=m1*24;break;
       case 6:m2=m1*1440.0000029;break;
       case 7:m2=m1*86400;break;
      }
      break;
     case 5:
      switch(k2){
       case 1:m2=m1*0.0001142;break;
       case 2:m2=m1*0.0001142*12;break;
       case 3:m2=m1*0.0059524;break;
       case 4:m2=m1*0.0416667;break;
       case 5:m2=m1*1;break;
       case 6:m2=m1*60;break;
       case 7:m2=m1*3600;break;
      }
      break;
     case 6:
      switch(k2){
       case 1:m2=m1*0.0001142/60;break;
       case 2:m2=m1*0.0001142/5;break;
       case 3:m2=m1*0.00009920;break;
       case 4:m2=m1*0.0006944;break;
       case 5:m2=m1*0.0166667;break;
       case 6:m2=m1*1;break;
       case 7:m2=m1*60;break;
      }
      break;
     case 7:
      switch(k2){
       case 1:m2=m1*0.0001142/60/60;break;
       case 2:m2=m1*0.0001142/5/60;break;
       case 3:m2=m1*0.00009920/60;break;
       case 4:m2=m1*0.0006944/60;break;
       case 5:m2=m1*0.0166667/60;break;
       case 6:m2=m1/60;break;
       case 7:m2=m1;break;
      }
      break;
    }
    cout<<endl<<endl<<"转化后结果是："<<endl<<"  "<<m1<<" "<<s1<<" = "<<m2<<" "<<s2<<endl;
  
   ch='1';
   while(ch!='Y' && ch!='N'){ 
    cout<<"还想继续转换时间吗？（Y/N）:";
    cin>>ch;
      } 
    }
    break;
    case 6:
   while(ch=='Y'){
    cout<<endl<<"请输入速度数值是：";
    cin>>m1; 
    cout<<endl<<"1:米/秒(m/s)  2:千米/秒(km/s)  3:千米/小时(km/h)  4:光速(c)  5:马赫(mach)"<<endl;
    cout<<"你输入的数值单位是:(序号)";
       cin>>k1;
    switch(k1){
       case 1:strcpy(s1,"米/秒");break;
       case 2:strcpy(s1,"千米/秒");break;
       case 3:strcpy(s1,"千米/小时");break;
       case 4:strcpy(s1,"光速");break;
       case 5:strcpy(s1,"马赫");break;
      }       
   cout<<endl<<"1:米/秒(m/s)  2:千米/秒(km/s)  3:千米/小时(km/h)  4:光速(c)  5:马赫(mach)"<<endl;
    cout<<"你想转换到的单位是:(序号)"; 
    cin>>k2; 
    switch(k2){
       case 1:strcpy(s2,"米/秒");break;
       case 2:strcpy(s2,"千米/秒");break;
       case 3:strcpy(s2,"千米/小时");break;
       case 4:strcpy(s2,"光速");break;
       case 5:strcpy(s2,"马赫");break;
      }
    switch(k1){
     case 1:
      switch(k2){
       case 1:m2=m1;break;
       case 2:m2=m1*1000;break;
       case 3:m2=m1*3.6;break;
       case 4:m2=m1*3.3356e-9;break;
       case 5:m2=m1*0.0029386;break;
      }
      break;
     case 2:
      switch(k2){
       case 1:m2=m1*1000;break;
       case 2:m2=m1;break;
       case 3:m2=m1*3600;break;
       case 4:m2=m1*3.3356e-6;break;
       case 5:m2=m1*2.938584;break;
      }
      break;
     case 3:
      switch(k2){
       case 1:m2=m1*0.2777778;break;
       case 2:m2=m1*0.00027778;break;
       case 3:m2=m1;break;
       case 4:m2=m1*9.2657e-10;break;
       case 5:m2=m1*0.00081627;break;
      }
      break;
     case 4:
      switch(k2){
       case 1:m2=m1*299792458;break;
       case 2:m2=m1*299792.458;break;
       case 3:m2=m1*1079252848.8;break;
       case 4:m2=m1*1;break;
       case 5:m2=m1*880965.3203995;break;
      }
      break;
     case 5:
      switch(k2){
       case 1:m2=m1*340.3;break;
       case 2:m2=m1*0.3403;break;
       case 3:m2=m1*1225.08;break;
       case 4:m2=m1*1.1351e-6 ;break;
       case 5:m2=m1*1;break;
      }
      break;
    }
    cout<<endl<<endl<<"转化后结果是："<<endl<<"  "<<m1<<" "<<s1<<" = "<<m2<<" "<<s2<<endl;
  
   ch='1';
   while(ch!='Y' && ch!='N'){ 
    cout<<"还想继续转换速度吗？（Y/N）:";
    cin>>ch;
      } 
    }
    break;
    case 7:
   while(ch=='Y'){
    cout<<endl<<"请输入角度数值是：";
    cin>>m1; 
    cout<<endl<<"1:圆周  2:度(°)  3:分(')  4:秒('')  5:弧度(rad)"<<endl;
    cout<<"你输入的数值单位是:(序号)";
       cin>>k1;
    switch(k1){
       case 1:strcpy(s1,"个圆周");break;
       case 2:strcpy(s1,"度");break;
       case 3:strcpy(s1,"分");break;
       case 4:strcpy(s1,"秒");break;
       case 5:strcpy(s1,"弧度");break;
      }       
  cout<<endl<<"1:圆周  2:度(°)  3:分(')  4:秒('')  5:弧度(rad)"<<endl;
    cout<<"你想转换到的单位是:(序号)"; 
    cin>>k2; 
    switch(k2){
       case 1:strcpy(s2,"个圆周");break;
       case 2:strcpy(s2,"度");break;
       case 3:strcpy(s2,"分");break;
       case 4:strcpy(s2,"秒");break;
       case 5:strcpy(s2,"弧度");break;
      }
    switch(k1){
     case 1:
      switch(k2){
       case 1:m2=m1;break;
       case 2:m2=m1*360;break;
       case 3:m2=m1*21600;break;
       case 4:m2=m1*1296000;break;
       case 5:m2=m1*6.28318548;break;
      }
      break;
     case 2:
      switch(k2){
       case 1:m2=m1/360;break;
       case 2:m2=m1;break;
       case 3:m2=m1*60;break;
       case 4:m2=m1*3600;break;
       case 5:m2=m1*0.017453293;break;
      }
      break;
     case 3:
      switch(k2){
       case 1:m2=m1/21600;break;
       case 2:m2=m1/60;break;
       case 3:m2=m1;break;
       case 4:m2=m1*60;break;
       case 5:m2=m1*0.00029088;break;
      }
      break;
     case 4:
      switch(k2){
       case 1:m2=m1/1296000;break;
       case 2:m2=m1/3600;break;
       case 3:m2=m1/60;break;
       case 4:m2=m1*1;break;
       case 5:m2=m1*0.0004848/100;break;
      }
      break;
     case 5:
      switch(k2){
       case 1:m2=m1*0.159155;break;
       case 2:m2=m1*57.29578;break;
       case 3:m2=m1*3437.7468;break;
       case 4:m2=m1*206264.808;break;
       case 5:m2=m1*1;break;
      }
      break;
    }
    cout<<endl<<endl<<"转化后结果是："<<endl<<"  "<<m1<<" "<<s1<<" = "<<m2<<" "<<s2<<endl;
  
   ch='1';
   while(ch!='Y' && ch!='N'){ 
    cout<<"还想继续转换角度吗？（Y/N）:";
    cin>>ch;
      } 
    }
    break;
    case 8:
      m=0;
      break;
    }
    }
    return 0; 
}
