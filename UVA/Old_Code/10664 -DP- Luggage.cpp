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

#define MAX 50009

int Abs(int n){return n<0?-1*n: n;}

int N,dp[MAX];

int main()
{
    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int _sum=0;string s; char str[MAX];

        scanf(" %[^\n]",str);s=str;
//        puts(str);

        bool fl=0;
        int arr[MAX];

        stringstream ss; ss<<s;

        i=0;
        while(ss>>N)
        {
            if( N!=0 ) fl=1;
            arr[++i]=N;
            _sum+=N;
        }
        N=i;

//        for(i=1;i<=N;i++) printf("%d  ",arr[i]);
        ss.clear();
        if(!fl ) {printf("YES\n");continue;}
        if(_sum%2) {printf("NO\n");continue;}

        mem(dp,0);

        dp[0]=1;
        int res=1<<29;
        int mx=arr[0];

        for(i=1;i<=N;i++)
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
        if(!res)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
