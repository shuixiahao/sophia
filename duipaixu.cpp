#include <iostream>
#include <cstdio> 
#include <ctime>
#include <cstdlib>
using namespace std;
void shift(int a[] , int i , int m)
{
int k , t;

    t = a[i]; k = 2 * i + 1;
    while (k < m)
    {
        if ((k < m - 1) && (a[k] < a[k+1])) k ++;
        if (t < a[k]) {a[i] = a[k]; i = k; k = 2 * i + 1;}
        else break;
 }
    a[i] = t;
}

void heap(int a[] , int n)  //a 为排序数组，n为数组大小（编号0-n-1）
{
	int i , k;
	for (i = n/2-1; i >= 0; i --) 
		shift(a , i , n); 
    for (i = n-1; i >= 1; i --)
    {
		k = a[0]; 
		a[0] = a[i]; 
		a[i] = k;
		shift(a , 0 , i);
    }
}
void main() 
{ 
	int a[10],i;
	clock_t start,finish;
	double totaltime;
	cout<<"排序数据为："<<endl;
	for(i=0;i<10;i++)
	{ 
		a[i]= rand();
		cout<<a[i]<<endl;
	}
	cout<<"堆排序为："<<endl;
	start=clock();
	for(int t=1;t<=10000;t++){
		heap(a,10);
	}
	finish=clock();
	for(i=0;i<10;i++)
		cout<<a[i]<<endl;
    totaltime=finish-start;
	cout<<"迭代时间："<<totaltime<<endl;
}