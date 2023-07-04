//矩阵求逆.cpp
//使用Gauss-Jordan方法求解逆矩阵 
#include<iostream>
#include<camth>
#include"complex.h"
using namespace std;

double ffabs(double p) //计算实数的绝对值 
{
	double q;
	q=fabs(p);
	return q;
} 

double ffabs(complex p) //计算复数的模 
{
	double q;
	q=p.cfabs();
	return q;
}

double ff(double p)//计算实数的倒数 
{
	double q;
	q=1.0/p;
	return q;
}

complex ff(complex p)//计算复数的倒数 
{
	complex q;
	q=complex(1.0,0.0) / p;
	return q;
}

//a为原矩阵，返回后为逆矩阵 
//n为矩阵的阶数
template <class T> //模板声明T为类型参数 
int inv(T a,int n)//如果矩阵奇异，则返回标志值0，否则返回非0 
{
	int *is,*js;
	int i,j,k,l,u,v;
	double d,q;
	T p;
	is=new int[n];
	js=new int[n];
	for(k=0;k<n;k++)
	{
		d=0.0;
		for(i=k;i<n;i++)//选主元 
		for(j=k;j<n;j++)
		{
			l=i*n+j;
			q=ffabs(a[l]);//计算元素的绝对值(模)
			if(q>d)
			{
				d=q;
				is[k]=i;
				js[k]=j;
			}
			if(d+1.0 == 1.0)//矩阵奇异 
			{
				delete[] is;
				delete[] js;
				cout<<"矩阵奇异"<<endl;
				return 0;
			}
			if(is[k]!=k)
			{
				for(j=0;j<n;j++)//行交换 
				{
					u=k*n+j;
					v=is[k]*n+j;
					p=a[u];
					a[u]=a[v];
					a[v]=p;
				}
			}
			if(js[k]!=k)
			{
				for(i=0;i<n;i++)//列交换 
				{
					u=i*n+k;
					v=i*n+js[k];
					p=a[u];
					a[u]=a[v];
					a[v]=p;
				}
			}
			l=k*n+k;
			a[l]=ff(a[l]);//计算1/a[l]
			for(j=0;j<n;j++)//归一化 
			{
				if(j!=k)
				{
					u=k*n+j;
					a[u]=a[u]*a[l];
				}
			}
			for(i=0;i<n;i++)//消元计算 
			{
				if(i!=k)
				{
					for(j=0;j<n;j++)
					{
						if(j!=k)
						{
							u=i*n+j;
							a[u]=a[u]-(a[i*n+k]*a[k*n+j]);
						}
					}
				}
			}
			for(i=0;i<n;i++)
			{
				if(i!=k)
				{
					u=i*n+k;
					a[u]=(a[u]-a[u]-a[u])*a[l];
				}
			}
		}
	}
	for(k=n-1;k>=0;k--)//恢复行列交换 
	{
		if(js[k]!=k)
			for(j=0;j<n;j++)
			{
				u=k*n+j;
				v=js[k]*n+j;
				p=a[u];
				a[u]=a[v];
				a[v]=p;
			}
		if(is[k]!=k)
			for(i=0;i<n;i++)
			{
				u=i*n+k;
				v=i*n+is[k];
				p=a[u];
				a[u]=a[v];
				a[v]=p;
			}
	}
	delete[] is;
	delete[] js;
	return 1;
} 
