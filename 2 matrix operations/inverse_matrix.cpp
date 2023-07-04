//��������.cpp
//ʹ��Gauss-Jordan������������ 
#include<iostream>
#include<camth>
#include"complex.h"
using namespace std;

double ffabs(double p) //����ʵ���ľ���ֵ 
{
	double q;
	q=fabs(p);
	return q;
} 

double ffabs(complex p) //���㸴����ģ 
{
	double q;
	q=p.cfabs();
	return q;
}

double ff(double p)//����ʵ���ĵ��� 
{
	double q;
	q=1.0/p;
	return q;
}

complex ff(complex p)//���㸴���ĵ��� 
{
	complex q;
	q=complex(1.0,0.0) / p;
	return q;
}

//aΪԭ���󣬷��غ�Ϊ����� 
//nΪ����Ľ���
template <class T> //ģ������TΪ���Ͳ��� 
int inv(T a,int n)//����������죬�򷵻ر�־ֵ0�����򷵻ط�0 
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
		for(i=k;i<n;i++)//ѡ��Ԫ 
		for(j=k;j<n;j++)
		{
			l=i*n+j;
			q=ffabs(a[l]);//����Ԫ�صľ���ֵ(ģ)
			if(q>d)
			{
				d=q;
				is[k]=i;
				js[k]=j;
			}
			if(d+1.0 == 1.0)//�������� 
			{
				delete[] is;
				delete[] js;
				cout<<"��������"<<endl;
				return 0;
			}
			if(is[k]!=k)
			{
				for(j=0;j<n;j++)//�н��� 
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
				for(i=0;i<n;i++)//�н��� 
				{
					u=i*n+k;
					v=i*n+js[k];
					p=a[u];
					a[u]=a[v];
					a[v]=p;
				}
			}
			l=k*n+k;
			a[l]=ff(a[l]);//����1/a[l]
			for(j=0;j<n;j++)//��һ�� 
			{
				if(j!=k)
				{
					u=k*n+j;
					a[u]=a[u]*a[l];
				}
			}
			for(i=0;i<n;i++)//��Ԫ���� 
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
	for(k=n-1;k>=0;k--)//�ָ����н��� 
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
