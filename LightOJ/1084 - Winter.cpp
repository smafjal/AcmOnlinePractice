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
//cout<<fixed<<setprecision(6)<<1.0<<endl;
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


int A[MAX];
int dp[MAX];
int n,k;

int rec(int idx)
{
    if(idx>n) return 0;
    int &ret=dp[idx];
    if(ret!=-1) return ret;
    ret=INF;

    for(int i=idx+2;i<=n;i++)
    {
        int d=A[i]-A[idx];
        if(d<=2*k) ret=min(ret,rec(i+1)+1); // triangle inequality.
        else break;
    }
    return ret;
}

int main()
{
    #if 0
        READ("IN.txt");
    #endif // 1

    onlyCPP;
    int t;cin>>t;
    int cas=0;

    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>A[i];
        mem(dp,-1);
        sort(A+1,A+n+1);

        int ans=rec(1);
        if(ans>=INF) ans=-1;
        cout<<"Case "<<++cas<<": "<<ans<<endl;
    }

    return 0;
}




