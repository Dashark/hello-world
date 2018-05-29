#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

//学习几大算法以及已有模板使用总结；
//插入排序：直接插入和希尔排序；
//选择排序：直接选排序和堆排序；
//交换排序：冒泡排序和快速排序（递归）；
//归并排序和基数排序；

void print(int a[], int n ,int i){
	cout<<i <<":";
	for(int j= 0; j<5; j++){
		cout<<a[j] <<" ";
	}
	cout<<endl;
}

//....插排....//

void InsertSort(int a[], int n)//O(n^2)复杂度 
{
	for(int i= 1; i<n; i++){
		if(a[i] < a[i-1]){               //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
			int j= i-1;	
			int x = a[i];		 //复制存储待排序元素
			a[i] = a[i-1];           //先后移一个元素
			while(x < a[j]){	 //查找在有序表的插入位置
				a[j+1] = a[j];
				j--;		 //元素后移
			}
			a[j+1] = x;		 //插入到正确位置
		}
		print(a,n,i);			//打印每趟排序的结果
	}
	
}

//....希尔排序....// 缩小增量排序
void ShellInsertSort(int a[], int n, int dk)
{
	for(int i= dk; i<n; ++i){
		if(a[i] < a[i-dk]){			//若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
			int j = i-dk;	
			int x = a[i];			//复制为存储待排序元素
			a[i] = a[i-dk];			//首先后移一个元素
			while(x < a[j]){		//查找在有序表的插入位置
				a[j+dk] = a[j];
				j -= dk;			 //元素后移
			}
			a[j+dk] = x;			//插入到正确位置
		}
		print(a, n,i );
	}
	
}

/**
 * 先按增量d（n/2,n为要排序数的个数进行希尔排序
 *
 */
void shellSort(int a[], int n){

	int dk = n/2;
	while( dk >= 1  ){
		ShellInsertSort(a, n, dk);
		dk = dk/2;
	}
} 

//....选择排序....//
void selectsort(int a[],int n){
	
	for(int i=0;i<n;i++){
		int max=i;
		
		for(int j=i+1;j<n;j++){
			if(a[j]>=a[max]){
				max=j;
			}
		}
		if(max!=i){
			int swap=a[max];a[max]=a[i];a[i]=swap;
		}
	}
}
void SelectSort(int r[],int n) //选排优化 同时记录最大最小值 
{
	int i ,j , min ,max, tmp;
	for (i=1 ;i <= n/2;i++) {  
		// 做不超过n/2趟选择排序 
		min = i; max = i ; //分别记录最大和最小关键字记录位置
		for (j= i+1; j<= n-i; j++) {
			if (r[j] > r[max]) { 
				max = j ; continue ; 
			}  
			if (r[j]< r[min]) { 
				min = j ; 
			}   
	  }  
	  //该交换操作还可分情况讨论以提高效率
	  tmp = r[i-1]; r[i-1] = r[min]; r[min] = tmp;
	  tmp = r[n-i]; r[n-i] = r[max]; r[max] = tmp; 

	} 
}

//.....冒泡排序.....//
//不能再手写错；
void bubbleSort(int a[], int n){
	for(int i =0 ; i< n-1; ++i) {
		for(int j = 0; j < n-i-1; ++j) {
			if(a[j] > a[j+1])
			{
				int tmp = a[j] ; a[j] = a[j+1] ;  a[j+1] = tmp;
			}
		}
	}
}


//可以同过增加指示符来判断时候已经有序 或者标记已经有序的位置；
void Bubble_1 ( int r[], int n) {
	int i= n -1;  //初始时,最后位置保持不变
	while ( i> 0) { 
		int pos= 0; //每趟开始时,无记录交换
		for (int j= 0; j< i; j++)
			if (r[j]> r[j+1]) {
				pos= j; //记录交换的位置 
				int tmp = r[j]; r[j]=r[j+1];r[j+1]=tmp;
			} 
		i= pos; //为下一趟排序作准备
	 } 
}  


//通过前后冒泡来减少遍历次序； 
void Bubble_2 ( int r[], int n){
	int low = 0; 
	int high= n -1; //设置变量的初始值
	int tmp,j;
	while (low < high) {
		for (j= low; j< high; ++j) //正向冒泡,找到最大者
			if (r[j]> r[j+1]) {
				tmp = r[j]; r[j]=r[j+1];r[j+1]=tmp;
			} 
		--high;					//修改high值, 前移一位
		for ( j=high; j>low; --j) //反向冒泡,找到最小者
			if (r[j]<r[j-1]) {
				tmp = r[j]; r[j]=r[j-1];r[j-1]=tmp;
			}
		++low;					//修改low值,后移一位
	} 
}  

//.....快速排序.....//
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int a[], int low, int high)
{
	int privotKey = a[low];								//基准元素
	while(low < high){								    //从表的两端交替地向中间扫描
		while(low < high  && a[high] >= privotKey) --high;  //从high 所指位置向前搜索，至多到low+1 位置。将比基准元素小的交换到低端
		swap(&a[low], &a[high]);
		while(low < high  && a[low] <= privotKey ) ++low;
		swap(&a[low], &a[high]);
	}
	print(a,10,10);
	return low;
}


void quickSort(int a[], int low, int high){
	if(low < high){
		int privotLoc = partition(a,  low,  high);  //将表一分为二
		quickSort(a,  low,  privotLoc -1);			//递归对低子表递归排序
		quickSort(a,   privotLoc + 1, high);		//递归对高子表递归排序
	}
}

//......另一种c实现快排........//
void quick_Sort(int array[],int left,int right)
{

   if(left>right)

          return;


 /*取最左边的值为pivot(基准)*/
     int i=left,j=right,pivot=array[left];
  

    while(i<j)
    {
         while( (i<j) && (pivot <= array[j]) )
            j--;
         if(i<j)
            array[i++]=array[j];
  
  while( (i<j) && (array[i] <= pivot) )
             i++;
         if(i<j)
             array[j--]=array[i];
 }

     array[j]=pivot;/*也可以是 array[i]=piovt。因为此时i=j*/

    quick_Sort(array,left,i-1);
    quick_Sort(array,i+1,right);
}
 
//.....qsort.....//

//一、对int类型数组排序 
//
//int num[100]; 
//
//Sample: 
//
//int cmp ( const void *a , const void *b ) 
//{ 
//return *(int *)a - *(int *)b; 
//} 
//
//qsort(num,100,sizeof(num[0]),cmp); 
//
//二、对char类型数组排序（同int类型） 
//
//char word[100]; 
//
//Sample: 
//
//int cmp( const void *a , const void *b ) 
//{ 
//return *(char *)a - *(int *)b; 
//} 
//
//qsort(word,100,sizeof(word[0]),cmp); 
//
//三、对double类型数组排序（特别要注意） 
//
//double in[100]; 
//
//int cmp( const void *a , const void *b ) 
//{ 
//return *(double *)a > *(double *)b ? 1 : -1; 
//} 
//
//qsort(in,100,sizeof(in[0]),cmp)； 
//
//四、对结构体一级排序 
//
//struct In 
//{ 
//double data; 
//int other; 
//}s[100] 
//
////按照data的值从小到大将结构体排序,关于结构体内的排序关键数据data的类型可以很多种，参考上面的例子写 
//
//int cmp( const void *a ,const void *B) 
//{ 
//return (*(In *)a)->data > (*(In *)B)->data ? 1 : -1; 
//} 
//
//qsort(s,100,sizeof(s[0]),cmp); 
//
//五、对结构体二级排序 
//
//struct In 
//{ 
//int x; 
//int y; 
//}s[100]; 
//
////按照x从小到大排序，当x相等时按照y从大到小排序 
//
//int cmp( const void *a , const void *b ) 
//{ 
//struct In *c = (In *)a; 
//struct In *d = (In *)b; 
//if(c->x != d->x) return c->x - d->x; 
//else return d->y - c->y; 
//} 
//
//qsort(s,100,sizeof(s[0]),cmp); 
//
//六、对字符串进行排序 
//
//struct In 
//{ 
//int data; 
//char str[100]; 
//}s[100]; 
//
////按照结构体中字符串str的字典顺序排序 
//
//int cmp ( const void *a , const void *b ) 
//{ 
//return strcmp( (*(In *)a)->str , (*(In *)B)->str ); 
//} 
//
//qsort(s,100,sizeof(s[0]),cmp); 
//
//七、计算几何中求凸包的cmp 
//
//int cmp(const void *a,const void *B) //重点cmp函数，把除了1点外的所有点，旋转角度排序 
//{ 
//struct point *c=(point *)a; 
//struct point *d=(point *)b; 
//if( calc(*c,*d,p[1]) < 0) return 1; 
//else if( !calc(*c,*d,p[1]) && dis(c->x,c->y,p[1].x,p[1].y) <  dis(d->x,d->y,p[1].x,p[1].y)) //如果在一条直线上，则把远的放在前面 
//return 1; 
//else return -1; 
//} 
//: 
//
//c++中加载头文件 "iostream"
//
//c中qsort函数包含在<stdlib.h>的头文件里，strcmp包含在<string.h>的头文件里 


//.....sort.....//需添加头文件#include<algorithm>
 
//int cmp(int a,int b)
//{
//      return a<b;   //升序排列；改为return a>b，则为降序
//  
//}
//  
//int main()
//{
//     int a[20],i;
//     for(i=0;i<20;i++)
//       cin>>a[i];
//     sort(a,a+20,cmp);
//     for(i=0;i<20;i++)
//       cout<<a[i]<<endl;
//     return 0;
//} 

//......不同数据类型的模板排序使用......// 

//升序：sort(begin,end,less<data-type>());
//降序：sort(begin,end,greater<data-type>());

//....归并排序.....//
//将r[i…m]和r[m +1 …n]归并到辅助数组rf[i…n]
//void Merge(ElemType *r,ElemType *rf, int i, int m, int n)
//{
//	int j,k;
//	for(j=m+1,k=i; i<=m && j <=n ; ++k){
//		if(r[j] < r[i]) rf[k] = r[j++];
//		else rf[k] = r[i++];
//	}
//	while(i <= m)  rf[k++] = r[i++];
//	while(j <= n)  rf[k++] = r[j++];
//	print(rf,n+1);
//}
//
//void MergeSort(ElemType *r, ElemType *rf, int lenght)
//{ 
//	int len = 1;
//	ElemType *q = r ;
//	ElemType *tmp ;
//	while(len < lenght) {
//		int s = len;
//		len = 2 * s ;
//		int i = 0;
//		while(i+ len <lenght){
//			Merge(q, rf,  i, i+ s-1, i+ len-1 ); //对等长的两个子表合并
//			i = i+ len;
//		}
//		if(i + s < lenght){
//			Merge(q, rf,  i, i+ s -1, lenght -1); //对不等长的两个子表合并
//		}
//		tmp = q; q = rf; rf = tmp; //交换q,rf，以保证下一趟归并时，仍从q 归并到rf
//	}
//}
//
//void MSort(ElemType *r, ElemType *rf,int s, int t)
//{ 
//	ElemType *rf2;
//	if(s==t) r[s] = rf[s];
//	else
//	{ 
//		int m=(s+t)/2;			/*平分*p 表*/
//		MSort(r, rf2, s, m);		/*递归地将p[s…m]归并为有序的p2[s…m]*/
//		MSort(r, rf2, m+1, t);		/*递归地将p[m+1…t]归并为有序的p2[m+1…t]*/
//		Merge(rf2, rf, s, m+1,t);	/*将p2[s…m]和p2[m+1…t]归并到p1[s…t]*/
//	}
//}
//void MergeSort_recursive(ElemType *r, ElemType *rf, int n)
//{   /*对顺序表*p 作归并排序*/
//	MSort(r, rf,0, n-1);
//} //两路归并

 
 

int main(){
	int a[5]={4,32,1,6,5};
	InsertSort(a, 5);//插入排序 
	print(a,5,5);
	
	int b[5]={5,2,32,52,2};
	shellSort(b,5); //希尔插入排序
	print(b,5,5);
	
	int c[8]={2,45,34,26,63,35,5,4};
	selectsort(c,8); //选择排序 
	print(c,8,8);
	
	return 0;
}
