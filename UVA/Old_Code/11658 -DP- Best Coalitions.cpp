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
#define oo (1<<29)
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

int cost[MAX];
int dp[MAX];


int main()
{
    int i,j,k,N,idx;
    while(scanf("%d %d",&N,&idx)==2)
    {
        if(N==0 and idx==0) break;
        mem(dp,0);

        int x1,x2;
        for(i=1;i<=N;i++)
        {
            scanf("%d.%d",&x1,&x2);
            int t=(x1*100)+x2;
            cost[i]=t;
        }
        int val=cost[idx];

        int cnt=(100*100)-val+1;
        dp[0]=1;
        for(i=1;i<=N;i++)
        {
            if(i==idx) continue;
            int p=cost[i];
            for(j=cnt;j>=0;j--)
            {
                if(dp[j])if(p+j<MAX)
                {
                    dp[p+j]=1;
                }
            }
        }

        int x=5000-val+1;
        for(i=x;i<MAX;i++)
        {
            if(dp[i]==1) break;
        }
        double res=((val*100.0)/(i+val));
        printf("%.2lf\n",res);
    }
    return 0;
}
