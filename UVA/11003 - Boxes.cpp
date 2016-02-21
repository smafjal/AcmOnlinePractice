#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<sstream>

typedef long long ll;
typedef unsigned long long ull; //scanf("%llu",&N);
#define FOR(i,a,b)  for(int i=(a);i<b;i++)
#define REV(i,a,b)  for(int i=a;i>=b;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define clr(a) a.clear()
#define mp make_pair
#define pb push_back
#define SZ(a) (int)a.size()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define fs first
#define sc second
#define PI (2*acos(0.0))
#define ERR (1e-7)
#define EQ(a,b) (fabs(a-b)<ERR)
//#define FOREACH(it,x) for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

using namespace std;
typedef vector<int>     VI;
typedef vector<string>  VS;
typedef pair<int,int>   PII;
typedef pair<int,PII >  DPII;
typedef vector<pair<int,int> >VPII;
typedef vector<pair<int,pair<int,int> > > VDPII;

const int INF=(1<<29);
const int MAX=1009;

int A[MAX],B[MAX];
int dp[MAX][MAX*3];
int n;

int rec(int cur,int load)
{
    if(cur<0) return 0;
    if(load>3000) return 0;

    int &ret=dp[cur][load];
    if(ret!=-1) return ret;
    ret=0;

    if(B[cur]>=load)
    {
        ret=max(ret,rec(cur-1,load+A[cur])+1);
    }
    ret=max(ret,rec(cur-1,load));

    return ret;
}

int main()
{
    while(scanf("%d",&n)==1 && n)
    {
        mem(dp,-1);
        for(int i=0;i<n;i++)scanf("%d %d",&A[i],&B[i]);
        int cnt=rec(n-1,0);
        printf("%d\n",cnt);
    }
    return 0;
}

/**

5
19 15
7 13
5 7
6 8
1 2

***/

