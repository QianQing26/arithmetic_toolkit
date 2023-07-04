//复多项式
#ifndef _COM_POLY_
#define _COM_POLY_

#include<iostream>
#include<fstream>
#include<cmath>
#include"complex.h"
using namespace std;

class com_poly:public complex
{
	private:
		int N;
		complex *p;
	public:
		com_poly(int nn=0,complex *pp=NULL)//构造函数
		{
			N=nn;
			p=pp;
		}
		void input();
		complex poly_value(complex);
		void com_poly_mul(com_poly&,com_poly&);
		void com_poly_div(com_poly&,com_poly&,com_poly&); 
};
 
void com_poly::input()//输入多项式
{
	int i;
	double a,b;
	cout<<"多项式复系数"<<endl;
	for(i=0;i<=N;i++)
	{
		cout<<"p("<<i<<") = ";
		cin>>a>>b;
		p[i]=complex(a,b);
	}
	return;
}

complex com_poly::poly_value(complex x)//求值
{
	int k;
	complex u;
	u=p[N];
	for(k=N-1;k>=0;k--)
	{
		u=u*x+p[k];
	}
	return u;
}


void com_poly::com_poly_mul(com_poly& q, com_poly& s) //相乘
{
    int i,j;
    complex tmp;
    for (i=0; i<=s.N; i++) s.p[i] = complex(0.0,0.0);
    for (i=0; i<=N; i++)
    for (j=0; j<=q.N; j++)
    {
    	tmp= p[i] * q.p[j];
    	s.p[i+j]= s.p[i+j] + tmp; 
	}
	return ;
}

void com_poly::com_poly_div(com_poly& q, com_poly& s, com_poly& r)//相除
{
	int i,j,mm,ll;
	complex tmp;
    for (i=0; i<=s.N; i++) s.p[i]=complex(0.0,0.0);
    if ( (q.p[q.N]).cfabs()+1.0==1.0)  return;
    ll=N;
    for (i=(s.N)+1; i>=1; i--)
    { 
		s.p[i-1]=p[ll]/(q.p[q.N]);
        mm=ll;
        for (j=1; j<=q.N; j++)
        { 
        	tmp=q.p[(q.N)-j] * s.p[i-1];
			p[mm-1]=p[mm-1] - tmp;
            mm=mm-1;
        }
        ll=ll-1;
    }
    for (i=0; i<=r.N; i++) r.p[i]=p[i];	  
	return;
}
#endif
