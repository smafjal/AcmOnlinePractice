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
#include<time.h>
using namespace std;

#define popcount(a) __builtin_popcount(a)
#define mp          make_pair
#define pb          push_back
#define FOR(i,a,b)  for(int i=(a);i<=b;i++)
#define REV(i,a,b)  for(int i=a;i>=b;i--)
#define PI          (2*acos(0))
#define clr(a)       a.clear()
#define SZ(a)       (int)a.size()
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()
#define fs          first
#define sc          second
#define mem(a,b)    memset(a,b,sizeof(a))
#define ERR         1e-7
#define EQ(a,b)     (fabs(a-b)<ERR)

//#define FOREACH(it,x) for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
//int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     VI;
typedef vector<string>  VS;
typedef pair<int,int>   PII;
typedef pair<int,PII >  DPII;
typedef vector<pair<int,int> >VPII;
typedef vector<pair<int,pair<int,int> > > VDPII;

#define INF (1<<28)
#define MAX 100009

int A[102];
int dp[MAX];

int main()
{
    int n,t,x,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %d %d\n",++cas,a,b);
    }
    return 0;
}

