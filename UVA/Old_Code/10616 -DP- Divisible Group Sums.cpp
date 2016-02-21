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

#define MAX 222

ll N,D,M,Q;
ll dp[211][30][22],num[MAX];


ll rec(ll cur,ll l,ll sum)
{
    if(cur==N)
    {
        if(l==M)
        {
            if(sum%D==0)
            {
                return (ll)1;
            }
            else return (ll)0;
        }
        else return 0;
    }
    ll &ret=dp[cur][l][sum];
    if(ret!=-1) return ret;
    ll ans=0;
    if(l+1<=M)ans+=rec(cur+1,l+1,(((sum+num[cur])%D)+D)%D);
    ans+=rec(cur+1,l,sum);
    ret=ans;
    return ans;
}

int main()
{
    ll i,j,k,cas=0;
    while(scanf("%lld %lld",&N,&Q)==2)
    {
        if(!N and !Q) break;

        for(i=0;i<N;i++) scanf("%lld",&num[i]);

        printf("SET %lld:\n",++cas);
        for(i=1;i<=Q;i++)
        {
            scanf("%lld %lld",&D,&M);
            mem(dp,-1);
            ll res=rec(0,0,0);
            printf("QUERY %lld: %lld\n",i,res);
        }
    }
    return 0;
}

/**
10 2
1
2
3
4
5
6
7
8
9
10
5 1
5 2
5 1
2
3
4
5
6
6 2
5 3
2
3
4
5
6
7 1
7 2
7 3
3 2
3
3
4
6 2
7 2
4 1
1
2
3
4
10 5
100 10
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
3 1
1
1
1
1 5
5 3
2147483647
2147483647
2147483647
2
-2147483648
5 2
5 3
5 4
10 6
12
14
41
65
34
27
84
26
99
34
2 1
2 2
2 3
3 1
3 2
3 3

*/
