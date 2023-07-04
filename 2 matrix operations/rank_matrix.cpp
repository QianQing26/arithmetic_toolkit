//矩阵求秩.cpp
#include<cmath>
#include<iostream>
using namespace std;
//a[m][n] 存放m×n矩阵A的值，返回时被破坏
//函数返回矩阵A的秩 
int rank(double a[],int m,int n)
{
	int i,j,k,nn,is,js,l,ll,u,v;
	double q,d;
	nn=m;
	if(m>=n) nn=n;
	k=0;
	for(l=0; l<nn; l++)
	{
		q=0.0;
		for(i=l;i<m;i++)
			for(j=l; j<n; j++)
			{
				ll=i*n+j;
				d=fabs(a[ll]);
				if(d>q)
				{
					q=d;
					is=i;
					js=j;
				}
			}
		if(q+1.0 == 1.0)
			return k;
		k++;
		if(is!=l)
		{
			for(j=l; j<n; j++)
			{
				u=l*n+j;
				v=is*n+j;
				d=a[u];
				a[u]=a[v];
				a[v]=d
			}
		}
		if(js!=1)
		{
			for(i=l; i<m; i++)
			{
				u=i*n+js;
				v=i*n+l;
				d=a[u];
				a[u]=a[v];
				a[v]=d;
			}
		}
		ll=l*n+l;
		for(i=l+1; i<n; i++)
		{
			d=a[i*n+l]/a[ll];
			for(j=l+1; j<n; j++)
			{
				u=i*n+j;
				a[u]=a[u]-d*a[l*n+j];
			}
		}
	}
	return k;
}
