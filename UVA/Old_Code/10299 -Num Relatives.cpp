
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

#define sz 100009
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

    for(i=3;i<sz;i+=2)
    {
        if(!flag[i])
        {
            prime[++total]=i;
            r=i*2;
            if(sz/i>=i)for(j=i*i;j<sz;j+=r)flag[j]=1;
        }
    }
//    print2("Last Prime: ",prime[total]);
}

bool ch(int n)
{
    if(n==2)return 1;
    ll val=sqrt(n)+1;
    if(n<sz)
    {
        if((n%2) && !flag[n])return 1;
        else return 0;
    }
    for(int i=1;prime[i]<val;i++)
    {
        if(n%prime[i]==0)return 0;
    }
    return 1;
}

ll generate(ll n)
{
    int i,count;
    ll ans=1,k=n,p;
    ll val=sqrt(n)+1;
    for(i=1;prime[i]<val;i++)
    {
        if(n%prime[i]==0)
        {
            count=0;
            p=1;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                p*=prime[i];
                count++;
            }
            if(count==1){ans=ans*(prime[i]-1);}
            else {k=p/prime[i];ans=ans*(p-k);}
        }
    }
    if(n>1)ans=ans*(n-1);
    return ans;
}

int main()
{
    sive();
    ll n,k;
    while(scanf("%lld",&n)==1)
    {
        if(!n)break;
        if(n==1){printf("%d\n",0);continue;}
        bool ans=ch(n);
        if(ans){printf("%lld\n",n-1);continue;}
        ll d=generate(n);
        printf("%lld\n",d);
    }
    return 0;
}
