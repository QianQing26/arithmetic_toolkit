//实多项式.h

#ifndef _POLY_
#define _POLY_

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

class poly
{
	private:
		int N;//多项式系数
		double *p;//多项式系数储存空间首地址
	
	public:
		poly(int nn=0,double *pp=NULL)//构造函数
		{
			N=nn;
			p=pp;	
		}
		void input();
		double poly_value(double);
		void poly_mul(poly&,poly&);
		void poly_div(poly&,poly&,poly&);
}; 

void poly::input()//输入多项式系数 
{
	int i;
	cout<<"多项式系数"<<endl;
	for(i=0;i<N;i++)
	{
		cout<<"(p"<<i<<")=";
		cin>>p[i];
	}
}

double poly::poly_value(double x)//多项式求值p(x)
{
	int k;
	double u;
	u=p[N];
	for(k=N-1;k>=0;k--)
	{
		u=u*x+p[k];
	}
	return u;
}

void poly::poly_mul(poly& q,poly &s)//多项式乘法s=p*q
{
	int i,j;
	for(i=0;i<=s.N;i++)
		s.p[i]=0.0;
	for(i=0;i<=N;i++)
		for(j=0;j<=q.N;j++)
			s.p[i+j]+=p[i]*q.p[j];
	return;
} 

void poly::poly_div(poly& q,poly& s,poly& r)//多项式相除 s=p/q+r 
{
	int i,j,mm,ll;
	for(i=0;i<=s.N;i++)s.p[i]=0.0;
	if(q.p[q.N]+1.0==1.0)return;
	ll=N;
	for(i=(s.N)+1;i>=1;i--)
	{
		s.p[i-1]=p[ll]/(q.p[q.N]);
		mm=ll;
		for(j=1;j<=q.N;j++)
		{
			p[mm-1]=p[mm-1]-s.p[i-1]*(q.p[(q.N)-1]);
			mm--;
		}
		ll--;
	}
	for(i=0;i<=r.N;i++)r.p[i]=p[i];
	return;
}
#endif
