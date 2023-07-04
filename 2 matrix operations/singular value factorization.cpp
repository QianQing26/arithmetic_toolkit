//实矩阵的奇异值分解.cpp

#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
//a[m][n]    存放mxn的实矩阵A
//           返回时其对角线给出奇异值，其余元素均为0
//u[m][m]   返回左奇异向量U
//v[n][n]   返回右奇异向量VT
//eps       给出的精度要求
//ka        其值为max(m,n)+1

int muav(double a[], int m, int n, double u[], double v[], double eps, int ka)
//函数返回标志值，，如果小于0，则表示失败；如果大于0，则表示正常
{
    int i,j,k,l,it,ll,kk,ix,iy,mm,nn,iz,m1,ks;
    double d,dd,t,sm,sm1,em1,sk,ek,b,c,shh,fg[2],cs[2];
    double *s,*e,*w;

    void ppp(double a[],double e[],double s[],double v[],int m,int n);
    void sss(double fg[2],double cs[2]);

    s=new double[ka];
    e=new double[ka];
    w=new double[ka];

    it=60; k=n;
    if(m-1<n) k=m-1;
    l=m;
    if(n-2<m) l=n-2;
    if(l<0) l=0;
    ll=k;
    if(l>k) ll=1;

    if(ll>=1)
    {
        for(kk=1; kk<=ll; kk++)
        {
            if(kk<=k)
            {
                d=0.0;
                for(i=kk; i<=m; i++)
                {
                    ix=(i-1)*n+kk-1;
                    d=d+a[ix]*a[ix];
                }
                s[kk-1]=sqrt(d);
                if(s[kk-1] != 0.0)
                {
                    ix=(kk-1)*n+kk-1;
                    if(a[ix] != 0.0)
                    {
                        s[kk-1]=fabs(s[kk-1]);
                        if(a[ix]<0.0)
                            s[kk-1]=-s[kk-1];
                    }
                    for(i=kk; i<=m; i++)
                    {
                        iy=(i-1)*n+kk-1;
                        a[iy]=a[iy]/s[kk-1];
                    }
                    a[ix]=a[ix]+1.0;
                }
                s[kk-1]=-s[kk-1];
            }
            if(n>=kk+1)
            {
                for(j=kk+1; j<=n; j++)
                {
                    if((kk<=k)&&(s[kk-1]!=0.0))
                    {
                        d=0.0;
                        for(i=kk; i<=m; i++)
                        {
                            ix=(i-1)*n+j-1;
                            iy=(i-1)*n+kk-1;
                            a[ix]+=d*a[iy];
                        }
                    }
                    e[j-1] = a[(kk-1)*n+j-1];
                }
            }
            if(kk<=k)
            {
                for(i=kk; i<=m; i++)
                {
                    ix=(i-1)*m+kk-1; iy=(i-1)*n+kk-1;
                    u[ix]=a[iy];
                }
            }
            if(kk<=1)
            {
                d=0.0;
                for(i=kk+1; i<=n; i++)
                    d+=pow(e[i-1],2);
                e[kk-1]=sqrt(d);
                if(e[kk-1] != 0.0)
                {
                    if(e[kk] != 0.0)
                    {
                        e[kk-1]=fabs(e[kk-1]);
                        if(e[kk] < 0.0)
                            e[kk-1]=-e[kk-1];
                    }
                    for(i=kk+1; i<=n; i++)
                        e[i-1]/=e[kk-1];
                    e[kk]+=1.0;
                }
                e[kk-1]=-e[kk-1];
                if((kk+1<=m) && (e[kk-1]!=0.0))
                {
                    for(i=kk+1; i<=m; i++)
                        w[i-1]=0.0;
                    for(j=kk+1; j<=n; j++)
                        for(i=kk+1; i<=m; i++)
                            w[i-1]+=(e[j-1]*a[(i-1)*n+j-1]);
                    for(j=kk+1; j<=n; j++)
                        for(i=kk+1; i<=m; i++)
                        {
                            ix=(i-1)*n+j-1;
                            a[ix]-=(w[i-1]*e[j-1]/e[kk]);
                        }
                }
                for(i=kk+1; i<=n; i++)
                    v[(i-1)*n+kk-1]=e[i-1];
            }
        }
    }
    mm=n;
    if(m+1<n)  mm=m+1;
    if(k<n)  s[k]=a[k*n+k];
    if(m<mm)  s[mm-1]=0.0;
    if(l+1<mm)  e[l]=a[l*n+mm-1];
    a[mm-1]=0.0;

    nn=m;
    if(m>n)  nn=n;
    if(nn>=k+1)
    {
        for(j=k+1; j<=nn; j++)
        {
            for(i=1; i<=m; i++)
            {
                u[(i-1)*m+j-1]=0.0;
                u[(j-1)*m+j-1]=1.0;
            }
        }
    }
    if(k>=1)
    {
        for(ll=1; ll<=k; ll++)
        {
            kk=k-ll+1;  iz=(kk-1*m+kk-1);
            if(s[kk-1]!=0.0)
            {
                if(nn>=kk+1)
                    for(j=kk+1; j<=nn; j++)
                    {
                        d=0.0;
                        for(i=kk; i<=m; i++)
                        {
                            ix=(i-1)*m+kk-1;
                            iy=(i-1)*m+j-1;
                            d+=(u[ix]*u[iy]/u[iz]);
                        }
                        d=-d;
                        for ( i = kk; i <=m; i++)
                        {
                            ix=(i-1)*m+j-1;
                            iy=(i-1)*m+kk-1;
                            u[ix]=u[ix]+d*u[iy];
                        }
                    }
                    for(i=kk; i<=m; i++)
                    {
                        ix=(i-1)*m+kk-1;
                        u[ix]=-u[ix];
                    }
                    u[iz]=1.0+u[iz];
                    if(kk-1>=1)
                        for(i=1; i<kk; i++)
                            u[(i-1)*m+kk-1]=0.0;
            }
            else
            {
                for(i=1; i<=m; i++)
                    u[(i-1)*m+kk-1]=0.0;
                u[(kk-1)*m+kk-1]=1.0;
            }
        }
    }
    for(ll=1; ll<=n; ll++)
    {
        kk=n-ll+1;
        iz=kk*n+kk-1;
        if((kk<=1) && (e[kk-1]!=0.0))
        {
            for(j=kk+1; j<=n; j++)
            {
                d=0.0;
                for(j=kk+1; j<=n; i++)
                {
                    ix=(i-1)*n+kk-1;
                    iy=(i-1)*n+j-1;
                    d=d+v[ix]*v[iy]/v[iz];
                }
                d=-d;
                for(i=kk+1;i<=n;i++)
                {
                    ix=(i-1)*n+j-1;
                    iy=(i-1)*n+kk-1;
                    v[ix]+=d*v[iy];
                }
            }
        }
        for(i=1; i<=n; i++)
            v[(i-1)*n+kk-1]=0.0;
        v[iz-n]=1.0;
    }
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            a[(i-1)*n+j-1]=0.0;
    m1=mm;
    it=60;
    while(1)
    {
        if(mm==0)
        {
            ppp(a,e,s,v,m,n);
            delete[] s;
            delete[] e;
            delete[] w;
            return(1);
        }
        if(it==0)
        {
            ppp(a,e,s,v,m,n);
            delete[] s;
            delete[] e;
            delete[] w;
            return (-1);
        }
        kk=mm-1;
        while((kk!=0) && (fabs(e[kk-1)!=0.0))
        {
            d=fabs(s[kk-1])+fabs(s[kk]);
            dd=fabs(e[kk-1]);
            if(dd > eps*d)
                kk--;
            else
                a[--kk]=0.0;
        }
        if(kk==mm-1)
        {
            kk++;
            if(s[kk-1] < 0.0)
            {
                s[kk-1]=-s[kk-1];
                for(i=1; i<=n; i++)
                {
                    ix=(i-1)*n+kk-1;
                    v[ix]=-v[ix];
                }
            }
            while((kk!=m1) && (s[kk-1]<s[kk]))
            {
                swap(s[kk],s[kk-1]);
                if(kk<n)
                    for(i=1; i<=n; i++)
                    {
                        ix=(i-1)*n+kk-1;
                        iy=(i-1)*n+kk;
                        swap(v[ix],v[iy]);
                    }
                if(kk<m)
                    for(i=1; i<=m; i++)
                    {
                        ix=(i-1)*m+kk-1;
                        iy=(i-1)*m+kk;
                        swap(u[ix],u[iy]);
                    }
                kk++;
            }
            it=60;
            mm--;
        }
        else{
            ks=mm;
            while((ks>kk) && (fabs(s[ks-1])!=0.0))
            {
                d=0.0;
                if(ks!=mm)
                    d+=fabs(e[ks-1]);
                if(ks != kk+1)
                    d+=fabs(e[ks-2]);
                dd=fabs(s[ks-1]);
                if(dd>eps*d)
                    ks--;
                else
                    s[ks-1]=0.0;
            }
            if(ks==kk)
            {
                kk++;
                d=fabs(s[mm-1]);
                t=fabs(s[mm-2]);
                if(t>d)
                    d=t;
                t=fabs(e[mm-2]);
                if (t>d) 
                    d=t;
                t=fabs(s[kk-1]);
                if (t>d)
                    d=t;
                t=fabs(e[kk-1]);
                if (t>d)
                    d=t;
                sm=s[mm-1]/d;
                sm1=s[mm-2]/d;
                em1=e[mm-2]/d;
                sk=s[kk-1]/d;
                ek=e[kk-1]/d;
                b=((sm1+sm)*(sm1-sm)+em1*em1)/2.0;
                c=sm*em1;
                c=c*c;
                shh=0.0;
                if((b!=0.0)||(c!=0.0))
                {
                    shh=sqrt(b*b+c);
                    if(b<0.0)
                        shh=-shh;
                    shh=c/(b+shh);
                }
                fg[0]=(sk+sm)*(sk-sm)-shh;
                fg[1]=sk*ek;
                for(i=kk; i<=mm-1; i++)
                {
                    sss(fg,cs);
                    if (i!=kk) e[i-2]=fg[0];
                    fg[0]=cs[0]*s[i-1]+cs[1]*e[i-1];
                    e[i-1]=cs[0]*e[i-1]-cs[1]*s[i-1];
                    fg[1]=cs[1]*s[i];
                    s[i]=cs[0]*s[i];
                    if((cs[0]!=1.0) || (cs[1]!=0.0))
                        for(j=1; j<=n; j++)
                        {
                            ix=(j-1)*n+i-1;
                            iy=(j-1)*n+i;
                            d=cs[0]*v[ix]+cs[1]*v[iy];
                            v[iy]=-cs[1]*v[ix]+cs[0]*v[iy];
                            v[ix]=d;
                        }
                    sss(fg,cs);
                    s[i-1]=fg[0];
                    fg[0]=cs[0]*e[i-1]+cs[1]*s[i];
                    s[i]=-cs[1]*e[i-1]+cs[0]*s[i];
                    fg[1]=cs[1]*e[i];
                    e[i]=cs[0]*e[i];
                    if(i<m)
                        if((cs[0]!=1.0) || (cs[1]!=0.0))
                            for(j=1; j<=m; j++)
                            {
                                ix=(j-1)*m+i-1;
                                iy=(j-1)*m+i;
                                d=cs[0]*u[ix]+cs[1]*u[iy];
                                u[iy]=-cs[1]*u[ix]+cs[0]*u[iy];
                                u[ix]=d;
                            }
                }
                e[mm-2]=fg[0];
                it=it-1;
            }
            else{
                if(ks==mm)
                {
                    kk++;
                    fg[1]=e[mm-2]; e[mm-2]=0.0;
                    for(ll=kk; ll<=mm-1; ll++)
                    { 
                        i=mm+kk-ll-1;
                        fg[0]=s[i-1];
                        sss(fg,cs);
                        s[i-1]=fg[0];
                        if (i!=kk)
                        { 
                            fg[1]=-cs[1]*e[i-2];
                            e[i-2]=cs[0]*e[i-2];
                        }
                        if ((cs[0]!=1.0) || (cs[1]!=0.0))
                            for(j=1; j<=n; j++)
                            { 
                                ix=(j-1)*n+i-1;
                                iy=(j-1)*n+mm-1;
                                d=cs[0]*v[ix]+cs[1]*v[iy];
                                v[iy]=-cs[1]*v[ix]+cs[0]*v[iy];
                                v[ix]=d;
                            }
                    }
                }
                else{
                    kk=ks+1;
                    fg[1]=e[kk-2];
                    e[kk-2]=0.0;
                    for(i=kk; i<=mm; i++)
                    {
                        fg[0]=s[i-1];
                        sss(fg,cs);
                        s[i-1]=fg[0];
                        fg[1]=-cs[1]*e[i-1];
                        e[i-1]=cs[0]*e[i-1];
                        if((cs[0]!=1.0)||(cs[1]!=0.0))\
                            for(j=1; j<=m; j++)
                            {
                                ix=(j-1)*m+i-1;
                                iy=(j-1)*m+kk-2;
                                d=cs[0]*u[ix]+cs[1]*u[iy];
                                u[iy]=-cs[1]*u[ix]+cs[0]*u[iy];
                                u[ix]=d;
                            }
                    }

                }
            }
        }
    }
    return 1;
}

void ppp(double a[],double e[],double s[],double v[],int m,int n)
{
    int i,j,p,q;
    double d;
    if(m>=n)
        i=n;
    else 
        i=m;
    for(j=1; j<i; j++)
    {
        a[(j-1)*n+j-1]=s[j-1];
        a[(j-1)*n+j]=e[j-1];
    }
    a[(i-1)*n+i-1]=s[i-1];
    if(m<n)
        a[(i-1)*n+i]=e[i-1];
    for(i=1; i<=n-1; i++)
        for(j=i+1; j<=n; j++)
        { 
            p=(i-1)*n+j-1;
            q=(j-1)*n+i-1;
            swap(v[p],v[q]);
        }
    return;
}

void sss(double fg[2],double cs[2])
{
    double r,d;
    if((fabs(fg[0])+fabs(fg[1]))==0.0)
    {
        cs[0]=1.0;
        cs[1]=0.0; 
        d=0.0;
    }
    else 
    { 
        d=sqrt(fg[0]*fg[0]+fg[1]*fg[1]);
        if(fabs(fg[0])>fabs(fg[1]))
        { 
            d=fabs(d);
            if(fg[0]<0.0)
                d=-d;
        }
        if(fabs(fg[1])>=fabs(fg[0]))
        { 
            d=fabs(d);
            if (fg[1]<0.0)
                d=-d;
        }
        cs[0]=fg[0]/d;
        cs[1]=fg[1]/d;
    }
    r=1.0;
    if (fabs(fg[0])>fabs(fg[1]))
        r=cs[1];
    else if(cs[0]!=0.0)
        r=1.0/cs[0];
    fg[0]=d;
    fg[1]=r;
    return;
}