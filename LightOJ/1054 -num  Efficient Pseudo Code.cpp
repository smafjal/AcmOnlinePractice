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
template<class T> T power(T B,T P){return (P==0)? 1: B*(power(B,P-1));}  /// B^P

#define MAX 90000
#define MAX_N 100000


bool flag[MAX];
ll prime[MAX_N];
ll MOD=1000000007;

ll square(ll n) {return n*n;}

void sive()
{
    ll i,j,k,r,total=1;
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


ll BigMod(ll b,ll p, ll m)    /// b^p%m
{
    if(p==0)return 1;
    else if(p%2==0) return square(BigMod(b,p/2,m))%m;
    else return (b%m)*(BigMod(b,p-1,m))%m;
}

ll pseudo_code(ll n,ll m)
{
    ll i,c,p,res=1;ll ans=1;
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
            ll po=(c*m)+1;
            ll upmod=(((BigMod(prime[i],po,MOD))+MOD)-1)%MOD;
            ll downmod=BigMod(prime[i]-1,MOD-2,MOD);
            res =(upmod * downmod)%MOD;
            ans=(ans*res)%MOD;
        }
    }
    if(n>1)
    {
        ll po=m+1;
        ll upmod =((BigMod(n,po,MOD)+MOD)-1)%MOD;
        ll downmod =BigMod(n-1,MOD-2,MOD);
        res =(upmod * downmod)%MOD;
        ans=(ans*res)%MOD;
    }
    return ans;
}

int main()
{
    sive();
    ll i,j,k,n,m,t;
    scanf("%lld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%lld %lld",&n,&m);
        ll ans=pseudo_code(n,m);
        printf("Case %lld: %lld\n",k,ans);
    }
    return 0;
}
