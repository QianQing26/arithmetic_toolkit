//�Գ����������choleskey�ֽ�
#include<iostream>
#include<cmath>
using namespace std;
//a[n][n] ��ŶԳ���������A
// ����ʱ�������Ǵ�ŷֽ�õ�����������L������Ԫ�ؾ�Ϊ0
//�������ر�־ֵ��������0�����ʾʧ�ܣ�������0�����ʾ�ɹ�
int chol(double a[],int n)
{
	int i,j,k,u,l;
	if((a[0]+1.0 == 1.0)||(a[0]<0.0))
	{
		cout<<"fail!\n";
		return 0;
	}
	a[0]=sqrt(a[0]);
	for(i=1; i<n; i++)
	{
		u=i*n;
		a[u]/=a[0];
	}
	for(j=1; j<n; j++)
	{
		l=j*n+j;
		for(k=0; k<j;k++)
		{
			u=j*n+k;
			a[l]-=a[u]*a[u];
		}
		if((a[l]+1.0 == 1.0)||a[l]<0.0)
		{
			cout<<"fail!";
			return 0;
		}
		a[l]=sqrt(a[l]);
		for(i=j+1; i<n; i++)
		{
			u=i*n+j;
			for(k=0; k<j; k++)
				a[u]=a[u]-a[i*n+k]*a[j*n+k];
			a[u]=a[u]/a[l];
		} 
	}
	for(i=0; i<=n-2 ;i++)
		for(j=i+1; j<n; j++)
			a[i*n+j]=0.0;
	return 1;
} 
