//实矩阵的QR分解.cpp

#include<iostream>
#include<cmath>
using namespace std;
//a[m][n] 存放m×n实矩阵A，并且要求m>=n 
//返回时其右上角存放QR分解中的上三角阵R 
//b[m][m] 返回QR分解中的正交矩阵Q 
//函数返回标志值，如果返回值为0，说明失败，如果不为0，说明成功

int maqr(double a[],int m,int n,double q[])
{
	int i,j,k,l,nn,p,jj;
    double u,alpha,w,t;
    if(m<n)
    {
        cout<<"fail!";
        return 0;
    }
    for(i=0; i<m; i++)
        for(j=0;j<m; j++)
        {
            l=i*m+j;
            q[l]=0.0;
            if(i==j)
                q[l]=1.0;
        }
    nn=n;
    if(m==n)
        nn=m-1;
    for(k=0; k<nn;k++)
    {
        u=0.0;
        l=k*n+k;
        for(i=k; i<m; i++)
        {
            w=fabs(a[i*n+k]);
            if(w>u)
                u=w;
        }
        alpha=0.0;
        for(i=k; i<m; i++)
        {
            t=a[i*n+k]/u;
            alpha+= t*t;
        }
        if(a[l]>0.0)
            u=-u;
        alpha=u*sqrt(alpha);
        if(fabs(alpha)+1.0 == 1.0)
        {
            cout<<"fail!";
            return 0;
        }
        u=sqrt(2.0*alpha*(alpha-a[l]));
        if(u+1.0 !=1.0)
        {
            a[l]=(a[l]-alpha)/u;
            for(i=k+1; i<m; i++)
            {
                p=i*n+k;
                a[p]=a[p]/u;
            }
            for(j=0; j<m; j++)
            {
                t=0.0;
                for(jj=k; jj<m; jj++)
                    t=t+a[jj*n+k]*q[jj*m+j];
                for(i=k; i<m; i++)
                {
                    p=i*n+j;
                    a[p]=a[p]-2.0*t*a[i*n+k];
                }
            }
            a[l]=alpha;
            for(i=k+1; i<m; i++)
                a[i*n+k]=0.0;

        }
    }
    for(i=0; i<m-1; i++)
        for(j=i+1; j<m; j++)
        {
            p=i*m+j; l=j*m+i;
            t=q[p];
            q[p]=q[l];
            q[l]=t;
        }
    return 1;
} 
