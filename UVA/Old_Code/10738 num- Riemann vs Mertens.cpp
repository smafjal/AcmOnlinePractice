#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>

#define sz 1000099
#define ll long long
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))
#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<"  "<<b<<endl
#define print3(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl
#define all(a) a.begin(),a.end()
#define reall(a) a.rbegin(),a.rend()

using namespace std;

bool flag[sz];
int prime[sz];
int mu[sz],M[sz];

void sive()
{
    int i,j,k,r,total=1;
    flag[0]=flag[1]=1;
    prime[total]=2;

    for(i=3;i<sz;i+=2)
    {
        if(!flag[i])
        {
            prime[++total]=i;
            r=i*2;
            if(sz/i>=i)for(j=i*i;j<sz;j+=r)flag[j]=1;
        }
    }
    return;
}

bool ch(int n)
{
    if((n%2) && !flag[n])return 1;
    return 0;
}

int factoring(int n)
{
    int i,j,k,p,c=0;
    for(i=1;i<=n/prime[i];i++)
    {
        if(n%prime[i]==0)
        {
            p=0;
            while(n%prime[i]==0)
            {
                p++;
                n/=prime[i];
                if(p==2)return 0;
            }
            c++;
        }
    }
    if(n>1) c++;
    return (c%2)?-1:1;
}

void Riemann_vs_Mertens()
{
    int i,j,k,n;
    bool man;
    mu[1]=M[1]=1;
    mu[2]=-1;M[2]=0;

    for(i=3;i<sz;i++)
    {
        man=ch(i);
        if(man)
        {
            mu[i]=-1;
            M[i]=M[i-1]-1;
        }
        else
        {
            k=factoring(i);
            mu[i]=k;
            M[i]=M[i-1]+k;
        }
    }
    return;
}

int main()
{
    sive();
    Riemann_vs_Mertens();
    int k,n;
    while(scanf("%d",&n)==1)
    {
        if(!n)break;
        printf("%8d%8d%8d\n",n,mu[n],M[n]);
    }
    return 0;
}


