#include <iostream>  
using namespace std;  
  
void swap(int &a,int &b){  
    int temp=a;  
    a=b;  
    b=temp;  
}  
  
void pai_xu(int a[],int m,int n){  
    if(m==n){  
        for(int i=1;i<=n;i++){  
            cout<<a[i];  
        }  
        cout<<endl;   
    }  
    else{  
        for(int i=m;i<=n;i++){  
            swap(a[i],a[m]);  
            pai_xu(a,m+1,n);  
            swap(a[i],a[m]);  
        }  
    }  
}  
  
int main(){  
    int n,m=1,a[10];  
    while(cin>>n){
    	for(int i=1;i<=n;i++){  
        a[i]=i;  
    }  
    pai_xu(a,m,n);  
	}  
    
    return 0;  
}  
