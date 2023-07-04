//对称正定矩阵求逆.cpp

#include<iostream>
#include<cmath>
#include"复数类.h"
using namespace std;

//a[n][n] 用来存放正定矩阵，并且返回逆矩阵到该数组
//函数返回标志值 等于0表示失败，大于0表示成功
int ssgj(double a[],int n)
{
	int i,j,k,m;
	double w,g,*b;
	b=new double[n];
	for(k=0;k<n;k++)
	{
		w=a[0];
		if(fabs(w)+1.0 == 1.0)
		{
			delete[] b;
			cout<<"fail!"<<endl;
			return 0;
		}
		m=n-k-1;
		for(i=0;i<n;i++)
		{
			g=a[i*n];
			b[i]=g/w;
			if(i<=m)b[i]=-b[i];
			for(j=1;j<=i;j++)
			{
				a[(i-1)*n+j-1]=a[i*n+j]+g*b[j];
			}
			a[n*n-1]=1.0/w;
			for(i=1;i<n;i++)
			{
				a[(n-1)*n+i-1]=b[i];
			}
		}
	}
	for(i=0;i<=n-2;i++)
		for(j=i+1;j<n;j++)
			a[i*n+j]=a[j*n+i];
	delete[] b;
	return 1;
} 
