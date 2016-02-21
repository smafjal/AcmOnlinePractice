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

#define MAX 10009

int dp[MAX];

int main()
{
    int i,j,k,N,T,t;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&T,&N);

        int mx=0;vector<int>cent; mem(dp,0);
        for(i=1;i<=N;i++)
        {
            scanf("%d",&k);cent.pb(k);
            if(k<MAX) mx+=k;
        }
        sort(all(cent));

//        deb("Mx: ",mx);
        dp[0]=1;dp[cent[0]]=1;
        if(mx>MAX) mx=MAX;

        for(i=1;i<SZ(cent);i++)
        {
            int val=cent[i];
//            deb("Cent: ",val);
            for(j=mx;j>=0;j--)
            {
                if(dp[j])if(val+j<MAX)
                {
                    if(j==0) dp[val]=1;
                    else
                    {
                        if(dp[val+j]) dp[val+j] = min(dp[j]+1,dp[val+j]);
                        else dp[val+j] =dp[j]+1;
                    }
                }
            }
        }

        for(i=T;i<MAX;i++)
        {
            if(dp[i]) {printf("%d %d\n",i,dp[i]);break;}
        }
    }
    return 0;
}
