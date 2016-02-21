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
#define MAX 50

queue<int>Q;
int vis[MAX];
VI G[MAX];

int BFS(int n)
{
    int d,cnt=0,ans=0;
    while(!Q.empty())
    {

        int u=Q.front();Q.pop();
        d=Q.front();Q.pop();
        ans=max(d,ans);
        cnt++;

        for(int i=0;i<SZ(G[u]);i++)
        {
            int v=G[u][i];vis[v]++;
            if(vis[v]==3)
            {
                Q.push(v);
                Q.push(d+1);
            }
        }
    }
    if(cnt==n) return ans;
    return -1;
}


int main()
{
    int n,m,x;
    while(scanf("%d %d",&n,&m)==2)
    {
        string s;
        cin>>s;
        while(!Q.empty()) Q.pop(); mem(vis,0);
        for(int i=0;i<=26;i++) clr(G[i]);

        for(int i=0;i<SZ(s);i++) {Q.push(s[i]-'A');Q.push(0);vis[s[i]-'A']=3;}

        char a,b;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a-'A'].pb(b-'A');
            G[b-'A'].pb(a-'A');
        }

        int d=BFS(n);
        if(d!=-1) printf("WAKE UP IN, %d, YEARS\n", d);
        else puts("THIS BRAIN NEVER WAKES UP");
    }
    return 0;
}

