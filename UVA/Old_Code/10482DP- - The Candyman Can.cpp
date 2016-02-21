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

#define MAX 642

int DP[MAX][MAX],N;

int main()
{
    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);mem(DP,0); vector<int>coin; int sum=0;

        for(i=1;i<=N;i++){scanf("%d",&k);sum+=k;coin.pb(k);}

        int mn=(1<<29);
        DP[0][0]=1;
        for(i=0;i<N;i++)
        {
            int val=coin[i]; if(val>sum) continue;
            for(j=sum;j>=0;j--)
            {
                for(k=sum;k>=0;k--)
                {
                    if(DP[j][k]!=0)
                    {
                        if(j+val<=sum)
                        {
                            DP[j+val][k]=1;
                            int mx1=max(j+val,max(k,abs(sum -(j+val+k))));
                            int mn1=min(j+val,min(k,abs(sum-(j+val+k))));

                            mn=min(mn,(mx1-mn1));
                        }
                        if(k+val<=sum)
                        {
                            DP[j][k+val]=1;
                            int mx1=max(j,max(k+val,abs(sum -(j+val+k))));
                            int mn1=min(j,min(k+val,abs(sum-(j+val+k))));
                            mn=min(mn,(mx1-mn1));
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n",++cas,mn);
    }
    return 0;
}

