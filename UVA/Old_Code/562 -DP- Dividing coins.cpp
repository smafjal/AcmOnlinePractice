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
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<"  "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<"  "<<e2<<"  "<<e3<<endl;}

#define MAX 50009

int Abs(int n){return n<0?-1*n: n;}

int N,dp[MAX];

int main()
{
    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int _sum=0;
        scanf("%d",&N);
        bool fl=0;
        int arr[MAX];

        for(i=0;i<N;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]!=0) fl=1;
            _sum+=arr[i];
        }

        if(!fl) {printf("0\n");continue;}

        mem(dp,0);

        dp[0]=1;
        int res=1<<29;
        int mx=arr[0];

        for(i=0;i<N;i++)
        {
            int val=arr[i];
            for(j=_sum;j>=0;j--)
            {
                if(dp[j])
                {
                    if(j+val<MAX)
                    {
                        dp[j+val]=1;
                        res=min(Abs((_sum -(j+val))-(j+val)),res);
                    }
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
