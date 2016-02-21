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
#include<iomanip>
using namespace std;

#define READ(a) freopen(a,"r",stdin);
#define WRITE(a) freopen(a,"w",stdout);
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
#define onlyCPP ios_base::sync_with_stdio(0);cin.tie(0)

//#define FOREACH(it,x) for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

typedef long long ll;
typedef unsigned long long ull; //scanf("%llu",&N);
typedef vector<int>     VI;
typedef vector<string>  VS;
typedef pair<int,int>   PII;
typedef pair<int,PII >  DPII;
typedef vector<pair<int,int> >VPII;
typedef vector<pair<int,pair<int,int> > > VDPII;

const int INF=(1<<29);
const int MAX=109;

int n,A[MAX];
double dp[MAX];


double rec(int pos)
{
    if(pos>=n) return 0;
    if(pos+1==n) return A[pos];
    double &ret=dp[pos];
    if(ret>-0.5) return ret;
    ret=A[pos];

    int ase;
    if(n-pos-1>=6) ase=6;
    else ase=n-pos-1;

    for(int x=1;x<=6;x++)
    {
        ret=ret+rec(pos+x)*(1.0/ase);
    }
    return ret;
}

int main()
{
    onlyCPP;
    int t;cin>>t;
    int cas=0;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>A[i];

        for(int i=0;i<=n;i++) dp[i]=-1.0;
        double ans=rec(0);

       // printf("Case %d: %lf\n",++cas,ans);

        cout<<"Case "<<++cas<<": "<<fixed<<setprecision(6)<<ans<<endl;
    }
    return 0;
}

/*

3

1
101

2
10 3

3
3 6 9

**/

