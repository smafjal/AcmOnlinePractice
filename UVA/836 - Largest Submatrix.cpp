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
int n,m;

int main()
{
    int t,cas=0;
    string str;VS V;
    scanf("%d",&t);
    getchar();
    getchar();

    while(t--)
    {
        clr(V);
        while(getline(cin,str))
        {
            if(str.empty()) break;
            V.pb(str);
        }
        n=SZ(V);
        m=SZ(V[0]);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) sum[i][j]=sum[i][j-1]+V[i-1][j-1]-'0';
        }

        int ans=0;
        for(int k=1;k<=m;k++)
        {
            for(int j=k;j<=m;j++)
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

        if(cas) puts("");cas++;
        cout<<ans<<endl;
    }
    return 0;
}

/**

000
000
000
001

*/
