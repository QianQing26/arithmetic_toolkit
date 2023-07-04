//�������.cpp

#include<iostream>
#include<cmath>
#include"������.h"
using namespace std;

double init(double p)//ʵ����ʼ�� 
{
	p=0.0;
	return p;
}

complex init(complex p)//������ʼ�� 
{
	p=complex(0.0,0.0);
	return p;
}

//a,ma,na  ����A[ma][na]
//b,mb,nb  ����B[mb][nb] 
//c,ma,nb  �˻����� C[ma][nb]=A[ma][na]*B[mb][nb]
template<class T>
void tmul(T a[],int ma,int na,T b[],int mb,int nb,T c[])
{
	int i,j,k,u;
	T tmp;
	if(na!=mb)
	{
		cout<<"���������"<<endl;
		return;
	}
	for(i=0;i<ma;i++)
		for(j=0;j<nb;j++)
		{
			u=i*nb+j;
			c[u]=init(c[u]);//�˻�����Ԫ�س�ʼ�� 
			for(k=0;k<mb;k++)
			{
				tmp=a[i*na+k]*b[k*nb+j];
				c[u]=c[u] + tmp;
			}
		}
	return;
}
