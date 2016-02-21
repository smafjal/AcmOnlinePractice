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

#define MAX 101

int dp[MAX][MAX];
char str[MAX];int l;

int palim(int i,int j)
{
    if(i>=j)return 1;
    if(i>=l or j<0) return oo;
    int &ret=dp[i][j];
    if(ret!=-1) return ret;
    if(str[i]==str[j]) return ret=palim(i+1,j-1);
    else return ret=min(palim(i+1,j)+1,palim(i,j-1)+1);
}

int main()
{
    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        l=strlen(str);
        for(i=0;i<=l;i++) for(j=0;j<=l;j++) dp[i][j]=-1;

        int ret=palim(0,l-1);
        printf("Case %d: %d\n",++cas,ret-1);
    }
    return 0;
}
