#include<stdio.h>
#define ll long long
#include<string.h>
#define mem(a,b) memset(a,b,sizeof(a))

ll dp[10009];
ll cur;
ll MOD = 10000007;

ll rec(ll n)
{
    if(n<0) return (ll)0;
    if(dp[n]!=-1) return dp[n];
    if(dp[n]==-1){dp[n]=((rec(n-1)%MOD + rec(n-2)%MOD + rec(n-3)%MOD + rec(n-4)%MOD + rec(n-5)%MOD + rec(n-6)%MOD)%MOD);return dp[n];}
}

int main()
{
    ll i,t,cas=0;
    scanf("%lld",&t);

    while(t--)
    {
        mem(dp,-1);
        for(i=0;i<6;i++) {scanf("%lld",&dp[i]);dp[i]=dp[i]%MOD;}

        scanf("%lld",&cur);
        ll res=rec(cur);
        printf("Case %lld: %lld\n",++cas,res);
    }
    return 0;
}
