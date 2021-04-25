#include <iostream>
using namespace std;
class Superprime{
	public:
		void shell(){
			    for(a=100;a<=999;a++){
    	b=2;
    	while(1){
    	    if(a%b==0){
    		    break;
		    }else b++;
		    if(b==a){
		    	m[a]++;
		    	break; 
			}
	    }
	}
	for(a=100,b=2;a<=999;a++){
		b=2;
		c[0]=c[1]=c[2]=0;
		if(m[a]!=0){
			c[0]=(a%100)%10;//个位
			c[1]=(a%100)/10;//十位
			c[2]=a/100;//百位 
			n[0]=c[0]*c[0];
			n[1]=c[1]*c[1];
			n[2]=c[2]*c[2];
			sum[0]=c[0]+c[1]+c[2]; //各位数的和 
			sum[1]=n[0]+n[1]+n[2]; //各位数平方的和 
			p=c[0]*c[1]*c[2]; //所有数字之积 
		}
		if(m[a]==0){
			continue;
		}
		while(1){
    	    if(sum[0]%b==0){
    	    	m[a]=0;
    		    break;
		    }else b++;
		    if(b==sum[0]){
		    	break;
			}
	    }
	    if(m[a]==0){
	    	continue;
		}
	    b=2;
	    while(1){
    	    if(p%b==0){
    	    	m[a]=0;
    		    break;
		    }else b++;
		    if(b==p){
		    	break;
			}
	    }
	    if(m[a]==0){
	    	continue;
		}
		b=2;
		while(1){
    	    if(sum[1]%b==0){
    	    	m[a]=0;
    		    break;
		    }else b++;
		    if(b==sum[1]){
		    	break;
			}
			}
		if(m[a]==0){
	    	continue;
		}
	    }
	for(a=100;a<=999;a++){
		if(m[a]==1){
			j++;
			sum[2]=sum[2]+a;
			max=a;
		}
	}
	cout<<"超级素数的个数为"<<j<<endl;
	cout<<"所有超级素数之和为"<<sum[2]<<endl;
	cout<<"最大的超级素数为"<<max<<endl;
		}
	private:
		int a,b=2,c[3]={0},m[1001]={0},n[3]={0},i=0,j=0,sum[3]={0},p=0,max=0;
};
int main() {
  Superprime mine;
	mine.shell();
	return 0;
}
