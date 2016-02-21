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
const int MAX=150;

int sum[MAX][MAX];
int grid[MAX][MAX];
int n,m;


void view()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf(" %d",grid[i][j]);
        }
        puts("");
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int x1,x2,y1,y2;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) grid[i][j]=1;

        for(int i=0;i<m;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            for(int j=x1;j<=x2;j++)
                for(int k=y1;k<=y2;k++) grid[j][k]=0;
        }

        //view();

        sum[1][0]=0;
        FOR(i,1,n+1)
        FOR(j,1,n+1)
        {
            sum[i][j]=sum[i][j-1]+grid[i][j];
        }

        int ans=0;
        for(int k=1;k<=n;k++)
        {
            for(int j=k;j<=n;j++)
            {
                //1D-K;
                int cnt=0;
                int x=(j-k+1);
                for(int i=1;i<=n;i++)
                {
                    int val=sum[i][j]-sum[i][k-1];
                    if(val==x) cnt++;
                    else
                    {
                        ans=max(cnt*x,ans);
                        cnt=0;
                    }
                }
                ans=max(cnt*x,ans);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

/**

3
10
3
2 2 5 3
8 3 9 7
3 6 3 8
20
1
1 1 1 1
10
2
5 1 5 10
1 5 10 5
*/


