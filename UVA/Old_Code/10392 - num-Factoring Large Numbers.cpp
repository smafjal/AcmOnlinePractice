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

#define sz 5000000
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
ll prime[sz];

/// 2^64= 18446744073709551616
/// sqrt(2^64) = 4294967296

void sive()
{
    ll i,j,k,r,total=1;
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

void factoring(ll n)
{
    ll i,j,k,p;
    for(i=1;prime[i]<=n/prime[i];i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                printf("    %lld\n",prime[i]);
                n/=prime[i];
            }
        }
    }
    if(n>1)printf("    %lld\n",n);

    return;
}

int main()
{
    sive();
    ll i,j,k,n;
    bool fl=0;
    while(scanf("%lld",&n)==1)
    {
        if(n<0)break;
        factoring(n);
        printf("\n");
        fl=1;
    }
    return 0;
}
