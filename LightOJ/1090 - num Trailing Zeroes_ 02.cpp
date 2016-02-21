#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<algorithm>
#include<sstream>

using namespace std;

#define ll long long
#define pi (2*acos(0))
#define CUBE(X) (X*X*X)
#define oo 1<<29
#define pb push_back
#define popb pop_back
#define mp make_pair
#define mem(a,b)  mamset(a,b,sizeof(a))
#define SZ(a)  (int)a.size()
#define fs first
#define sc second
#define contain(x,item) (x).find(item)!=(x).end()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define Read(a) freopen(a,"r",stdin)
#define Write(a) freopen(a,"w",stdout)

template<class T1>void dev(T1 e1){cout<<e1<<endl;}
template<class T1,class T2>void dev(T1 e1,T2 e2){cout<<e1<<"  "<<e2<<"  "<<endl;}
template<class T1,class T2,class T3>void dev(T1 e1,T2 e2,T3 e3){cout<<e1<<"  "<<e2<<"  "<<e3<<endl;}

#define MAX 1000099
int arr2[MAX];
int arr5[MAX];
bool flag[MAX];
int prime[MAX];
int val2=0,val5=0;

void sive()
{
    int i,j,k,r,total=1;
    flag[0]=flag[1]=1;
    prime[total]=2;

    for(i=3;i<MAX;i+=2)
    {
        if(!flag[i])
        {
            prime[++total]=i;
            r=i*2;
            if(MAX/i>=i)for(j=i*i;j<MAX;j+=r)flag[j]=1;
        }
    }
    return;
}

int fac5(int n)
{
    int ans=0;
    while(n)
    {
        ans+=(n/5);
        n/=5;
    }
    return ans;
}

int fac2(int n)
{
    int ans=0;
    while(n)
    {
        ans+=(n/2);
        n/=2;
    }
    return ans;
}
void pre()
{
    int i,j,k;
    for(i=0;i<MAX;i++)
    {
        arr5[i]=fac5(i);
        arr2[i]=fac2(i);
    }
    return;
}
void po(int n,int q)
{
    int i,j,k,c,ans;
    for(i=1;prime[i]<=n/prime[i];i++)
    {
        if(n%prime[i]==0)
        {
            c=0;
            while(n%prime[i]==0)
            {
                c++;
                n/=prime[i];
            }
            if(prime[i]==5)val5=c*q;
            else if(prime[i]==2)val2=c*q;
        }
    }
    if(n==5) val5=q;
    else if(n==2) val2=q;
}

int main()
{
    pre();
    sive();
    int i,j,k,t,n,m,p,q,r;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d %d %d %d",&n,&r,&p,&q);
        po(p,q);
        int uv2,uv5;
        uv2=arr2[n]+val2;
        uv5=arr5[n]+val5;
        int dv2,dv5;
        dv2=arr2[r]+arr2[n-r];
        dv5=arr5[r]+arr5[n-r];
        int ans=min(uv2-dv2,uv5-dv5);
        printf("Case %d: %d\n",k,ans);
        val2=0;val5=0;
    }
    return 0;
}
