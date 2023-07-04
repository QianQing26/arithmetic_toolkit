//矩阵相乘.cpp

#include<iostream>
#include<cmath>
#include"complex.h"
using namespace std;

double init(double p)//实数初始化 
{
	p=0.0;
	return p;
}

complex init(complex p)//复数初始化 
{
	p=complex(0.0,0.0);
	return p;
}

//a,ma,na  矩阵A[ma][na]
//b,mb,nb  矩阵B[mb][nb] 
//c,ma,nb  乘积矩阵 C[ma][nb]=A[ma][na]*B[mb][nb]
template<class T>
void tmul(T a[],int ma,int na,T b[],int mb,int nb,T c[])
{
	int i,j,k,u;
	T tmp;
	if(na!=mb)
	{
		cout<<"矩阵不能相乘"<<endl;
		return;
	}
	for(i=0;i<ma;i++)
		for(j=0;j<nb;j++)
		{
			u=i*nb+j;
			c[u]=init(c[u]);//矩阵元素初始化
			for(k=0;k<mb;k++)
			{
				tmp=a[i*na+k]*b[k*nb+j];
				c[u]=c[u] + tmp;
			}
		}
	return;
}
