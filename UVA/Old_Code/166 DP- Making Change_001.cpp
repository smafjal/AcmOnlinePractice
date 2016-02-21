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

#define MAX 2009

int arr[]={5,10,20,50,100,200};

int a1,a2,a3,a4,a5,a6;
int dp[MAX];vector<int>cent;
int shop[MAX];

void input()
{
    for(int i=1;i<=a1;i++) cent.pb(arr[0]);
    for(int i=1;i<=a2;i++) cent.pb(arr[1]);
    for(int i=1;i<=a3;i++) cent.pb(arr[2]);
    for(int i=1;i<=a4;i++) cent.pb(arr[3]);
    for(int i=1;i<=a5;i++) cent.pb(arr[4]);
    for(int i=1;i<=a6;i++) cent.pb(arr[5]);
    return;
}

void pre()
{
    shop[0]=1;int i,j;
    int k=0;
    for(i=arr[0];i<MAX;i+=arr[0]) shop[i]=++k;

    for(int i=1;i<6;i++)
    {
        int val=arr[i];
        for(j=0;j<MAX;j++)
        {
            if(shop[j]) if(val+j<MAX)
            {
                if(j==0) shop[val]=1;
                else if(shop[val+j]) shop[val+j]=min(shop[j]+1,shop[val+j]);
                else shop[val+j]=shop[j]+1;
            }
        }
    }
    return;
}

int main()
{
    int i,j,k,n;
    pre();
    while(scanf("%d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&a6)==6)
    {
        if(!a1 and !a2 and !a3 and !a4 and !a5 and !a6) break; mem(dp,0);cent.clear();
        input();
        double total,S ;scanf("%lf",&total);
        int T=(int)total; S=(total-T)+1e-7; T=(T*100)+(S*100) +1e-7;
        int mx=MAX-1;

        dp[0]=1;
        for(i=0;i<SZ(cent);i++)
        {
            int val=cent[i];
            for(j=mx;j>=0;j--)
            {
                if(dp[j])
                {
                    if(val+j<MAX)
                    {
                        if(j==0) dp[val]=1;
                        else if(dp[val+j]) dp[val+j]=min(dp[j]+1,dp[val+j]);
                        else dp[val+j]=dp[j]+1;
                    }
                }
            }
        }

        int mn=1<<29;
        if(dp[T]) mn=dp[T];

        for(i=T+1;i<MAX;i++)
        {
            if(dp[i])
            {
                int idx=i-T;
                if(shop[idx])
                {
                    mn=min(mn,shop[idx]+dp[i]);
                }
            }
        }
        printf("%3d\n",mn);
    }
    return 0;
}
