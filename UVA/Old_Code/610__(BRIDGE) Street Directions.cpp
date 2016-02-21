/*Bismillahir Rahmanir Rahim*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<sstream>

#define all(a) (a).begin(),(a).end()
#define mem(a,b)  memset(a,b,sizeof(a))
#define fs first
#define sc second
#define oo 1<<29
#define ERR 1e-7
#define EQ(a,b)(fabs(a-b)<ERR)
#define mp make_pair
#define pb push_back
#define PI (2*acos(0.0))
#define SZ(a)  (int)a.size()
#define reall(a) (a).rbegin(),(a).rend()
#define lookalike scanf("%*d")

using namespace std;

void BINARY(int n){cout<<"Mask: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef pair<int,int>   pii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpi;

#define MAX 1009

int N,E;
vector<int>adj[MAX];
int ti[MAX],col[MAX],low[MAX];
int cnt=0;
vector<pair<int,int> >vi;
int grid[MAX][MAX];

bool cheack(int r,int c)
{
    if(grid[r][c]  or grid[c][r]) return 0;return 1;
}

void DFS(int u,int par)
{
    col[u]=1;
    ti[u]=low[u]=++cnt;

    for(int i=0;i<SZ(adj[u]);i++)
    {
        int v=adj[u][i];
        if(v==par) continue;
        if(col[v]==0)
        {
            DFS(v,u);
            low[u]=min(low[u],low[v]);
            if(cheack(u,v))
            {
                vi.pb(mp(u,v));
                grid[u][v]=1;
            }

            if(low[v]>ti[u])
            {
                vi.pb(mp(v,u));
                grid[v][u]=1;
            }
        }
        else
        {
            low[u]=min(low[u],ti[v]);
            if(cheack(u,v))
            {
                vi.pb(mp(u,v));
                grid[u][v]=1;
            }
        }
    }
    return;
}


void Bridge()
{
//    for(int i=0;i<=N;i++)for(int j=0;j<=N;i++) {}
    mem(ti,0);mem(low,0); mem(col,0); cnt=0;vi.clear();mem(grid,0);

    for(int i=1;i<=N;i++)
    {
        if(col[i]==0)
        {
            DFS(i,-1);
        }
    }
    return;
}

int main()
{
    int cas=0;
    while(scanf("%d %d",&N,&E)==2)
    {
        if(N==0 and E==0) break;
        for(int i=0;i<=N;i++)adj[i].clear();

        int x,y;
        for(int i=0;i<E;i++)
        {
            scanf("%d %d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }

        Bridge();
        sort(all(vi));
        printf("%d\n\n",++cas);
        for(int i=0;i<SZ(vi);i++)
        {
            cout<<vi[i].fs<<" "<<vi[i].sc<<endl;
        }
        cout<<"#"<<endl;
    }
    return 0;
}

