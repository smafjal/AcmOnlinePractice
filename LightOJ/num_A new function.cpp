#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;

#define ll long long

ll Harmonic(ll n)
{
    ll val=sqrt(n);
    ll i,end,ans,tmp,add,pos;
    ans=0;end=n;

    for(i=1;i<=val;i++)
    {
        ans = ans + ((n/i)*i);
        tmp = n/(i+1);
        if(tmp<i) tmp=i;
        add = ((end + (end*(end-1))/2) - (tmp + (tmp*(tmp-1))/2)) * i;
        ans += add;
        end=tmp;
    }
    return ans;
}

int main()
{
    ll i,k,t,cas,n,p;
    scanf("%lld",&t);
    cas=0;
    while(t--)
    {
        scanf("%lld",&n);
        if(!n) {printf("Case %lld: %lld\n",++cas,(ll)0);continue;}
        k=(n*(n+1))/2 + (n-1);
        ll ans = Harmonic(n);
        ans = ans-k;
        printf("Case %lld: %lld\n",++cas,ans);
    }
    return 0;
}

