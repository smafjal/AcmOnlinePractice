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
const int MAX=109;

ll grid[MAX][MAX];
ll sum[MAX][MAX];
ll N,M,K;
ll MaxArea,MinCost;

int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        cin>>N>>M>>K;
        mem(sum,0);

        FOR(i,1,N+1)FOR(j,1,M+1) cin>>grid[i][j];
        FOR(i,1,N+1)FOR(j,1,M+1) sum[i][j]=sum[i][j-1]+grid[i][j];

        MaxArea=-INF;
        MinCost=INF;

        for(int c1=1;c1<=M;c1++)
        {
            for(int c2=c1;c2<=M;c2++)
            {
                ll area=0;
                ll cost=0;

                for(int r1=1,l=1;r1<=N;r1++)
                {
                    if(r1!=1) area-=(c2-c1+1);
                    cost-=(sum[r1-1][c2]-sum[r1-1][c1-1]);

                    for(;l<=N;l++)
                    {
                        int columnSum=sum[l][c2]-sum[l][c1-1];
                        if(cost+columnSum>K) break;
                        area+=(c2-c1+1);
                        cost+=columnSum;
                    }

                    //cout<<"AR: "<<area<<" "<<cost<<endl;
                    if(area>MaxArea)
                    {
                        MaxArea=area;
                        MinCost=cost;
                    }
                    else if(area==MaxArea) MinCost=min(MinCost,cost);
                }
            }
        }

        printf("Case #%d: %lld %lld\n",++cas,MaxArea,MinCost);
    }

    return 0;
}

