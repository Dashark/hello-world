#include<stdio.h>
int main(){
    int sushu(int );
    int i=100,k=0,geshu=0,he=0,zuida=0,cj[100]; 
    for(;i<1000;i++){
                     int ge,shi,bai;
                     ge=i%10;shi=(i%100)/10;bai=i/100; 
                     if(sushu(i))
                        if( sushu(ge+shi+bai))
                           if(sushu(ge*shi*bai)) 
                              if(sushu(ge*ge+shi*shi+bai*bai))
                                  cj[k++]=i;
                     }
                     for(int i=0;i<k;i++){
                              
                               he=he+cj[i];
                             }
                             printf("���������ĸ�����%d\n",k);
                             printf("���г�������֮��:%d\n",he);
                             printf("���ĳ���������%d",cj[k-1]);
                             return 0;
                  
                     
}


int sushu(int a){
    for(int b=2;b<a;b++){
            if(a%b==0)
            return 0;
            }
    return 1;
}

