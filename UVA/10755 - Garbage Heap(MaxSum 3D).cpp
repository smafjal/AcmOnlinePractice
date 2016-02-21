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

const ll INF=(1LL<<62);
const int MAX=100;

int X,Y,Z;
ll grid[MAX][MAX][MAX];
ll sum[MAX][MAX][MAX];

int main()
{
    int t;cin>>t;
    while(t--)
    {
        cin>>X>>Y>>Z;X++;Y++;Z++;
        FOR(i,1,X)FOR(j,1,Y)FOR(k,1,Z) scanf("%lld",&grid[i][j][k]);
        mem(sum,0);
        FOR(i,1,X)FOR(j,1,Y)FOR(k,1,Z) sum[i][j][k]=sum[i][j][k-1]+grid[i][j][k];
        FOR(i,1,X)FOR(j,1,Y)FOR(k,1,Z) sum[i][j][k]+=sum[i-1][j][k];

        ll ans=-INF;

        for(int z1=1;z1<Z;z1++)
        {
            for(int z2=z1;z2<Z;z2++)
            {
                for(int x1=1;x1<X;x1++)
                {
                    for(int x2=x1;x2<X;x2++)
                    {
                        ll val=0;
                        for(int y=1;y<Y;y++)
                        {
                            ll tmp=sum[x2][y][z2] - (sum[x2][y][z1-1]+sum[x1-1][y][z2]) + sum[x1-1][y][z1-1];
                            val+=tmp;
                            ans=max(val,ans);
                            if(val<0) val=0;
                        }
                    }
                }
            }
        }

        printf("%lld\n",ans);
        if(t) puts("");
    }

    return 0;
}

/**

1

2 2 2
-1 2 0 -3 -2 -1 1 5

*/

