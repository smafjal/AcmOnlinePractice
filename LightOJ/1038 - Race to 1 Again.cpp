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
const int MAX=100009;

double dp[MAX];

double rec(int n)
{
    //cout<<n<<endl;
    if(n==1) return 0;
    double &ret=dp[n];
    if(ret>-0.5) return ret;
    ret=0;

    int div=0,i;
    for(i=1;i*i<n;i++)
    {
        if(n%i==0)
        {
            ret+=rec(n/i)+1.0;
            ret+=rec(i)+1.0;
            div+=2;
        }
    }
    if(i*i==n)
    {
        div++;
        ret+=rec(i)+1.0;
    }
    ret=ret*1.0/(div-1);

    return ret;
}

int main()
{
    onlyCPP;
    int t;cin>>t;
    int cas=0;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++) dp[i]=-1.0;
        double ans=rec(n);
        cout<<"Case "<<++cas<<": "<<fixed<<setprecision(6)<<ans<<endl;
    }

    return 0;
}


