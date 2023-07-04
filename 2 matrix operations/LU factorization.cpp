//矩阵的三角分解.cpp
#include<iostream>
#include<cmath>
using namespace std;
//a[n][n] 储存原本的n阶矩阵A，返回时储存矩阵Q
//l[n][n] 返回下三角矩阵L
//u[n][n] 返回上三角矩阵U
int lluu(double a[],int n,double l[],double u[])
{
	int i,j,k,w,v,ll;
	for(k=0; k<n-1; k++)
	{
		ll=k*n+k;
		if(fabs(a[ll])+1.0 == 1.0)
		{
			cout<<"fail!";
			return 0;
		}
		for(i=k+1; i<n; i++)
		{
			w=i*n+k;
			a[w]=a[w]/a[ll];
		}
		for(i=k+1; i<n; i++)
		{
			w=i*n+k;
			for(j=k+1; j<n; j++)
			{
				v=i*n+j;
				a[v]=a[v]-a[w]*a[k*n+j];
			}
		}
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<i; j++)
		{
			w=i*n+j;
			l[w]=a[w];
			u[w]=0.0;
		}
		w=i*n+i;
		l[w]=1.0; u[w]=a[w];
		for(j=i+1; j<n; j++)
		{
			w=i*n+j;
			l[w]=0.0;
			u[w]=a[w];
		}
	}
	return 1;
} 
 
