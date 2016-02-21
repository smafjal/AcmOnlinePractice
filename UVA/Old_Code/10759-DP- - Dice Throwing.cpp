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

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<"  "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<"  "<<e2<<"  "<<e3<<endl;}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define MAX 133

ULL N,X,DP[25][150];vector<ULL>st;

ULL rec(ULL cur,ULL sum)
{
    if(cur>N)
    {
        if(sum>=X)return 1;
        else return 0;
    }
    if(DP[cur][sum]!=-1) return DP[cur][sum];
    ULL ans=0;
    for(ULL i=1;i<=6;i++)
    {
        ans+=rec(cur+1,sum+i);
    }
    DP[cur][sum]=ans;
    return ans;
}

void pre()
{
    ULL i;st.pb(0);ULL ans=6;
    for(i=1;i<=24;i++)
    {
        st.pb(ans);
        ans*=6;
    }
    return;
}

int main()
{
    pre();
    int i,j,cas=0;
    while(scanf("%llu %llu",&N,&X)==2)
    {
        if(N==0 and X==0) break;
        mem(DP,-1);
        ULL ans=rec(1,0);
        if(ans%st[N]==0) printf("%llu\n",(ans/st[N]));
        else
        {
            ULL g=__gcd(ans,st[N]);
            printf("%llu/%llu\n",(ans/g),(st[N]/g));
        }
    }
    return 0;
}
