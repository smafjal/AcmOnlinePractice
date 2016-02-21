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

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}

#define MAX 2000097
#define MOD  1000000007
ll res[MAX+2];

ll BigMod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

int main()
{
    int j,k,t,cas=0;
    ll i; res[0]=(ll)1;res[1]=(ll)1;
    for(i=2;i<MAX;i++) res[i] = (res[i-1] *(i%MOD))%MOD;

    scanf("%d",&t);
    while(t--)
    {
        ll N,K;
        scanf("%lld %lld",&N,&K);
        ll up = res[N+K-1];
        ll down =(res[N] * res[K-1])%MOD;
        ll ans=(up * (BigMod(down,MOD-2,MOD)))%MOD;
        printf("Case %d: %lld\n",++cas,ans);
    }
    return 0;
}
