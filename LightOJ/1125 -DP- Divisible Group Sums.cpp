/// Bismillahir Rahmanir Rahim.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include<iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
#include <vector>
#include<sstream>

using namespace std;
typedef long long ll;
typedef unsigned long long ULL;   /// scanf("%llu",&n);
#define PI (2*acos(0))
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define reall(x)  (x).rbegin(),(x).rend()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define fs      first
#define sc      second
#define REP(i,n) for((i)=0;(i)<(int)n;(i)++)
#define lookalike scanf("%*c")

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<"  "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<"  "<<e2<<"  "<<e3<<endl;}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define MAX 202

ll N,D,M,Q;
ll dp[201][11][21],num[MAX];


ll rec(ll cur,ll l,ll sum)
{
    if(cur==N)
    {
        if(l==M)if(sum%D==0)return (ll)1;
        return 0;
    }
    ll &ret=dp[cur][l][sum];
    if(ret!=-1) return ret;
    ll ans=0;
    if(l+1<=M)ans+=rec(cur+1,l+1,(((sum+num[cur])%D)+D)%D);
    ans+=rec(cur+1,l,sum);
    return ret=ans;
}

int main()
{
    ll i,j,k,t,cas=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&N,&Q);
        for(i=0;i<N;i++) scanf("%lld",&num[i]);

        printf("Case %lld:\n",++cas);
        for(i=1;i<=Q;i++)
        {
            scanf("%lld %lld",&D,&M);
            mem(dp,-1);
            ll res=rec(0,0,0);
            printf("%lld\n",res);
        }
    }
    return 0;
}

