//随机数类.h
#ifndef _RND_
#define _RND_

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

class RND
{
	private:
		int R;//随机数种子
	public:
		RND(int r=1)//构造函数 
		{
			R=r;
		}
		double rnd1()//产生0~1均匀分布的一个随机数 
		{
			int m;
			double s,u,v,p;
			s=65536.0;
			u=2053.0;
			v=13849.0;
			m=(int)(R/s);
			R=R-m*s;
			R=u*R+v;
			m=(int)(R/s);
			R=(int)(R-m*s);;
			p=R/s;
			return p;
		}
		
		double rndab(int a,int b)//产生区间[a,b]内均匀分布的随机数 
		{
			int i,j,k,m,p;
			k=b-a+1;
			j=2;
			while(j<k)j*=2;
			m=4*j;
			k=R;
			i=1;
			while(i<=1)
			{
				k*=5;
				k%=m;
				j=k/4 + a;
				if(j<=b)
				{
					p=j;
					i++;
				}
			}
			R=k;
			return(p);
		}
		
		double rndg(double u,double g)//产生符合正态分布 N(u,g^2) 的一个随机数
		{
			int i,m;
			double s,w,v,t;
            s=65536.0; w=2053.0; v=13849.0;
            t=0.0;
            for(i=1;i<=12;i++)
            {
            	R=R*w+v;
            	m=(int)(R/s);
            	R-=m*s;
            	t+=R/s;
			}
			t=u+g*(t-6.0);
			return t;
		} 
};
#endif
