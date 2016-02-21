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

#define MAX 30

int dp[MAX];
int T,N;
bool col[MAX];bool fl;
map<vector<int>,int > M;

void proces()
{
    vector<int>v;
    for(int i=1;i<=N;i++)
    {
        if(col[i]) v.pb(dp[i]);
    }
    if(!M[v])  M[v]=1;
    else return;

    for(int i=0;i<SZ(v);i++)
    {
        fl=0;
        if(i)printf("+%d",v[i]);
        else printf("%d",v[i]);
    }
    puts("");
    return;
}

void rec(int cur,int sum)
{
    if(cur>N+1) return;
    if(sum>T) return;
    if(sum==T) {proces();return;}

    col[cur]=1;
    rec(cur+1,sum+dp[cur]);
    col[cur]=0;
    rec(cur+1,sum);
    return;
}

int main()
{
    int i,j,k;
    while(scanf("%d %d",&T,&N)==2)
    {
        if(!T and !N) break;
        for(i=1;i<=N;i++)scanf("%d",&dp[i]);

        mem(col,0);M.clear();
        fl=1;
        printf("Sums of %d:\n",T);
        rec(1,0);
        if(fl) printf("NONE\n");
    }
    return 0;
}
