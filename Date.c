/*struct Date {
  int year;
  int month;
  int day;
};
void next_day(struct Date day);
void previous_day(struct Date day);
int equal(struct Date one, struct Date day);
void show(struct Date day) {
  printf();
}
int main() {
  struct Date today = {2018,3,20};
  struct Date day = {2018,3,20};
  show(day);
  for(int i=0;i<30;i++)
    next_day(day);
  show(day);
  for(int i=0;i<30;i++)
    previous_day(day);
  show(day);
  if(equal(today, day))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}*/
#include<iostream>
using namespace std;
template<typename T>
void sort(T *a,int n)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				T temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++) cout<<a[i]<<" ";
}
int main()
{
	int n;
	int a[100],temp,i;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	n=sizeof(a)/sizeof(int);
	sort(a,n);
	/*for(i=0;i<;i++){
		cout<<a[i];
	}*/
	return 0;
} 
