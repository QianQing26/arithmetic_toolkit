//������.h

#ifndef _COM_
#define _COM_

#include<iostream>
#include<cmath>
using namespace std;
class complex
{
	private:
		double R;//ʵ�� 
		double I;//�鲿
	
	public:
		complex(double real=0,double imag=0)//���캯��
		{
			R=real;
			I=imag;	
		}
		
		void prt()//������� 
		{
			cout<<"("<<R<<","<<I<<")";	
			return;
		}
		
		double cfabs()//����ģ 
		{
			double y;
			y=sqrt(R*R+I*I);
			return y;
		}
		
		double angle()//�������� 
		{
			double y;
			y=atan2(I,R);
			return y;
		}
		
		complex operator + (complex& c2)//�����ӷ� 
		{
			complex c;
			c.R=R+c2.R;
			c.I=I+c2.I;
			return c;
		}
		
		complex operator - (complex& c2)//�������� 
		{
			complex c;
			c.R=R-c2.R;
			c.I=I-c2.I;
			return c;
		}
		
		complex operator * (complex& c2)//�����˷� 
		{
			complex c;
			c.R=R*c2.R-I*c2.I;
			c.I=I*c2.R+R*c2.I;
			return c;
		}
		
		complex operator / (complex& c2)//�������� 
		{
			complex c;
			double p,q,s,w;
			p=R*c2.R;
			q=-I*c2.I;
			s=(R+I)*(c2.R-c2.I);
			w=(c2.R)*(c2.R)+(c2.I)*(c2.I);
			
			if(w+1.0 != 1.0)
			{
				c.R=(p-q)/w;
				c.I=(s-p-q)/w;
			}
			else
			{
				c.R=1e+300;
				c.I=1e+300;
			}
			return c;
		}
		
		complex cpower(int n)//������ 
		{
			complex c;
			double r,q;
			q=atan2(I,R);
			r=sqrt(R*R+I*I);
			if(r+1.0 != 1.0)
			{
				r=n*log(r);
				r=exp(r);
			}
			c.R=r*cos(n*q);
			c.I=r*sin(n*q);
			return c;
		}
		
		void croot(int n,complex *p)//�������� 
		{
			complex c;
			int k;
			double r,q,t;
			if(n<1)return;
			q=atan2(I,R);
			r=sqrt(R*R+I*I);
			if(r+1.0 != 1.0)
			{
				r=(1.0/n)*log(r);
				r=exp(r);
			}
			for(k=0;k<n;k++)
			{
				t=(2*k*3.1415926535897+q)/n;
				c.R=r*cos(t);
				c.I=r*sin(t);
				p[k]=c;
			}
		}
		
		complex cexp()//��eΪ�׵ĸ���ָ�� 
		{
			complex c;
			double p;
			p=exp(R);
			c.R=p*cos(I);
			c.I=p*sin(I);
			return c;
		}
		
		complex clog()//������Ȼ���� 
		{
			complex c;
			double p;
			p=R*R+I*I;
			p=log(sqrt(p));
			c.R=p;
			c.I=atan2(I,R);
			return c;
		}
		
		complex csin()//�������� 
		{
			complex c;
			double p,q;
			p=exp(I);
			q=exp(-I);
			c.R=sin(R)*(p+q)/2;
			c.I=cos(R)*(p-q)/2;
			return c;
		}
		
		complex ccos()//�������� 
		{
			complex c;
			double p,q;
			p=exp(I);
			q=exp(-I);
			c.R=cos(R)*(p+q)/2;
			c.I=-sin(R)*(p-q)/2;
			return c;
		}
};
#endif
