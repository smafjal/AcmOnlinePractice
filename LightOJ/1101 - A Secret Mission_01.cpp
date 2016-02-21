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
#include<stack>
#include<algorithm>
#include<sstream>

using namespace std;
#define oo          (1<<30)
#define mem(a,b)    memset(a,b,sizeof(a))
#define mp          make_pair
#define pb          push_back
#define clr(a)      a.clear()
#define SZ(a)       (int)a.size()
#define fs          first
#define sc          second
#define mem(a,b)    memset(a,b,sizeof(a))
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> paii;

#define MAX 50002

int N;
vector<pair<int,int> >adj[MAX];
vector<pair<int,pair<int,int> > >edge;
int par[MAX][25];
int dis[MAX][25];

struct Kruskal
{
    int Node,E,Rank[MAX],Par[MAX];
    Kruskal(){;}
    Kruskal(int _N,int _E=0){Node=_N;E=_E;}   /// 0 based index.
    void Makeset(){ for(int i=0;i<Node;i++) {Par[i]=i;Rank[i]=0;}}
    int Findset(int x){ if(Par[x]==x) return x;else return Par[x]=Findset(Par[x]);}
    void Unionset(int x,int y)
    {
        if(Rank[x]>Rank[y]) Par[y]=x;
        else Par[x]=y;
        if(Rank[x]==Rank[y])Rank[y]++;
    }
    void Link(int x,int y){ Unionset(Findset(x),Findset(y));}
};


void _mst()
{
    sort(all(edge));

    Kruskal mst(N);
    mst.Makeset();
    int numOfedge=0;
    for(int i=0;i<SZ(edge);i++)
    {
        int u=edge[i].sc.fs;
        int v=edge[i].sc.sc;
        int w=edge[i].fs;
        if(mst.Findset(u)!=mst.Findset(v))
        {
            mst.Link(u,v);
            numOfedge++;
            adj[u].pb(mp(v,w));
            adj[v].pb(mp(u,w));
        }
    }
    return;
}

int L[MAX],col[MAX];

void dfs(int u,int p,int level)
{
    L[u]=level;
    col[u]=1;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        if(adj[u][i].fs!=p and col[adj[u][i].fs]==0)
        {
            par[adj[u][i].fs][0]=u;
            dis[adj[u][i].fs][0]=adj[u][i].sc;
            dfs(adj[u][i].fs,u,level+1);
        }
    }
    return;
}

void build_lca()
{
    mem(dis,0),mem(par,-1);mem(L,0);mem(col,0);
    for(int i=0;i<=N;i++)
    {
        L[i]=0;col[i]=0;
        for(int j=0;j<25;j++) par[i][j]=-1,dis[i][j]=0;
    }

    dfs(0,0,0);

    for(int j=1;(1<<j)<N;j++)
    {
        for(int i=0;i<N;i++)
        {
            if(par[i][j-1]!=-1)
            {
                dis[i][j]=max(dis[i][j-1],dis[par[i][j-1]][j-1]);
                par[i][j]=par[par[i][j-1]][j-1];
            }
        }
    }
    return;
}

int lca_quary(int a,int b)
{
    int cnt=0;
    if(L[a]<L[b]) swap(a,b);
    int log=log2(L[a]);

    for(int i=log;i>=0;i--)
    {
        if(L[a]-(1<<i)>=L[b])
        {
            cnt=max(cnt,dis[a][i]);
            a=par[a][i];
        }
    }
    if(a==b) return cnt;

    for(int i=log;i>=0;i--)
    {
        if(par[a][i]!=-1 and par[a][i]!=par[b][i])
        {
            cnt=max(cnt,max(dis[a][i],dis[b][i]));
            a=par[a][i];
            b=par[b][i];
        }
    }
    return max(cnt,max(dis[a][0],dis[b][0]));
}


int main(void)
{
    int t,m,q,x,y,d,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&m);
        for(int i=0;i<=N;i++) clr(adj[i]);
        clr(edge);

        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&d); x--;y--;
            edge.pb(mp(d,mp(x,y)));
        }
        _mst();
        build_lca();
        scanf("%d",&q);

        printf("Case %d:\n",++cas);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            x--;y--;
            int cnt=lca_quary(x,y);
            printf("%d\n",cnt);
        }
    }
    return 0;
}



