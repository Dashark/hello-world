#include<iostream>
using namespace std;
template <class T>
void sort(T* a, int n)
{
 int t;
 T temp; 
 for (int i=0; i<n-1; i++) 
 { 
  t=i;
  for (int j=i+1; j<n; j++) 
  { 
   if (*(a+t)>*(a+j))
    t=j; 
  } 
  temp=*(a+i);
  *(a+i)=*(a+t); 
  *(a+t)=temp; 
 }
}
static float arr0[6]={2.0,65.0,9.0,78.0,88.0,-2.0};
static double arr1[6]={558.0,999.0,123.0,222.0,55.0,456.0};
static int arr2[6]={123,456,789,654,321,5};
int main()
{
	int i;
 cout<<"float exp."<<endl;
 for (int i=0; i<6; i++)
 {
  cout<<arr0[i]<<" ";
 }
 cout<<endl;
 sort(arr0, 6);
 for (i=0; i<6; i++)
 {
  cout<<arr0[i]<<" ";
 }
 cout<<endl;
 cout<<"double exp."<<endl;
 for (i=0; i<6; i++)
 {
  cout<<arr1[i]<<" ";
 }
 cout<<endl;
 sort(arr1, 6);
 for (i=0; i<6; i++)
 {
  cout<<arr1[i]<<" ";
 }
 cout<<endl;
 cout<<"int exp."<<endl;
 for (i=0; i<6; i++)
 {
  cout<<arr2[i]<<" ";
 }
 cout<<endl;
 sort(arr2, 6);
 for (i=0; i<6; i++)
 {
  cout<<arr2[i]<<" ";
 }
 cout<<endl;
}
