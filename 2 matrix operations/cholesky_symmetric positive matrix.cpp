//对称正定矩阵的choleskey分解
#include<iostream>
#include<cmath>
using namespace std;
//a[n][n] 存放对称正定矩阵A
// 返回时其下三角存放分解得到的下三角阵L，其余元素均为0
//函数返回标志值，若等于0，则表示失败，若大于0，则表示成功
int chol(double a[],int n)
{
	int i,j,k,u,l;
	if((a[0]+1.0 == 1.0)||(a[0]<0.0))
	{
		cout<<"fail!\n";
		return 0;
	}
	a[0]=sqrt(a[0]);
	for(i=1; i<n; i++)
	{
		u=i*n;
		a[u]/=a[0];
	}
	for(j=1; j<n; j++)
	{
		l=j*n+j;
		for(k=0; k<j;k++)
		{
			u=j*n+k;
			a[l]-=a[u]*a[u];
		}
		if((a[l]+1.0 == 1.0)||a[l]<0.0)
		{
			cout<<"fail!";
			return 0;
		}
		a[l]=sqrt(a[l]);
		for(i=j+1; i<n; i++)
		{
			u=i*n+j;
			for(k=0; k<j; k++)
				a[u]=a[u]-a[i*n+k]*a[j*n+k];
			a[u]=a[u]/a[l];
		} 
	}
	for(i=0; i<=n-2 ;i++)
		for(j=i+1; j<n; j++)
			a[i*n+j]=0.0;
	return 1;
} 
