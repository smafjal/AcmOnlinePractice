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
#define oo (1<<30)
#define fs      first
#define sc      second
#define REP(i,n) for((i)=0;(i)<(int)n;(i)++)

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<"  "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<"  "<<e2<<"  "<<e3<<endl;}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define MAX 10001

ll S[MAX],dp[MAX];

void pre()
{
    ll i,j;
    for(i=1;i<MAX;i++)
    {
        S[i]=i*i;
        dp[i]=i;
    }

    for(i=2;i<MAX;i++)
    {
        ll val=S[i];
        if(val<MAX)dp[val]=1;
        else break;

        for(j=1;j<MAX;j++)
        {
            if(val+j<MAX) {dp[val+j]=min(dp[val+j],dp[j]+1);}
            else break;
        }
    }
    return;
}

int main()
{
    pre();
    int i,j,k,t,N;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        printf("%lld\n",dp[N]);
    }
    return 0;
}

