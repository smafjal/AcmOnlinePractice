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

#define sz 1000999
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

void sive()
{
    int i,j,k,r,total=1;
    flag[0]=flag[1]=1;

    prime[total]=2;

    for(i=3; i<sz; i+=2)
    {
        if(!flag[i])
        {
            prime[++total]=i;
            r=i*2;
            if(sz/i>=i)for(j=i*i; j<sz; j+=r)flag[j]=1;
        }
    }
}

int pre_ge(long long  n)
{
    int i,j,k;
    int count,ans=1;
    for(i=1; prime[i]<=n/prime[i]; i++)
    {
        if(n%prime[i]==0)
        {
            count=0;
            while(n%prime[i]==0)
            {
                count++;
                n/=prime[i];
            }
            ans*=(count+1);
        }
    }
    if(n>1)
    {
        ans=(ans*2);
    }
    return ans;
}

int main()
{
    int i,j,k,t;
    long long n;
    sive();
    scanf("%d",&t);
    for(k=1; k<=t; k++)
    {
        scanf("%lld",&n);
//        if(n==1)
//        {
//            printf("Case %d: %d\n",k,1);
//            continue;
//        }
        int ans=pre_ge(n);
        printf("Case %d: %d\n",k,ans-1);
    }
    return 0;
}

