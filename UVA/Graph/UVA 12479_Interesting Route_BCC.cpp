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

#define mp          make_pair
#define pb          push_back
#define clr(a)      a.clear()
#define SZ(a)       (int)a.size()
#define fs          first
#define sc          second
#define mem(a,b)    memset(a,b,sizeof(a))


#define MAXN 30009
#define MAXE 60009

int Fo[MAXE],To[MAXE],Ne[MAXE],Fin[MAXE],nEdg;
int N,E;
stack<pair<int,int> >S;
int used[MAXN],col[MAXN],dfsTime,low[MAXN],idx[MAXN];
pair<int,int>store[MAXE];
vector<int>G[MAXN];
int road,city;

inline void addEdge(int u,int v)
{
    Fo[nEdg]=u;To[nEdg]=v;Ne[nEdg]=Fin[u];Fin[u]=nEdg++;
    Fo[nEdg]=v;To[nEdg]=u;Ne[nEdg]=Fin[v];Fin[v]=nEdg++;
    return;
}

void sol_bcc(int u,int v)
{
    /// take a biconnected component's elements.
    int tot=0,nu,nv;pair<int,int>e;
    while(!S.empty())
    {
        e=S.top();S.pop();
        nu=e.fs;
        nv=e.sc;
        G[nu].clear();G[nv].clear();
        store[tot]=mp(nu,nv); tot++;
        if((nu==u && nv==v) || (nu==v && nv==u)) break;
    }

    if(tot<=1) return;  /// one edge
    mem(col,0);
    for(int i=0;i<tot;i++)
    {
        int nu=store[i].fs;
        int nv=store[i].sc;
        used[nu]=used[nv]=1;
        G[nu].pb(nv);
        G[nv].pb(nu);
    }

    /// check for odd cycle.
    queue<int>Q;
    Q.push(nu);
    col[nu]=1;
    while(!Q.empty())
    {
        nu=Q.front();Q.pop();
        for(int i=0;i<SZ(G[nu]);i++)
        {
            nv=G[nu][i];
            if(col[nv]==0)
            {
                col[nv]=3-col[nu];
                Q.push(nv);
            }
            if(col[nu]==col[nv]) return;
        }
    }
    road++;
    return;
}

void dfs(int u,int p)
{
    low[u]=idx[u]=++dfsTime;
    for(int i=Fin[u];i>=0;i=Ne[i])
    {
        int v=To[i];
        if(v==p)continue;
        if(idx[v]==0)
        {
            S.push(mp(u,v));
            dfs(v,u);
            low[u]=min(low[u],low[v]);

            if(low[v]>=idx[u]) sol_bcc(u,v);
        }
        else if(idx[v]<idx[u])
        {
            S.push(mp(u,v));
            low[u]=min(low[u],idx[v]);
        }
    }
    return;
}

void BCC()
{
    mem(idx,0);mem(used,0);dfsTime=0; road=0;city=0;
    for(int i=0;i<N;i++)
    {
        if(idx[i]) continue;
        dfs(i,i);
    }
    for(int i=0;i<N;i++)
    {
        if(used[i]==0)
        {
            road+=3;
            city+=2;
        }
    }
    return;
}

int main(void)
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&E);   /// number of node and edge.
        mem(Fin,-1);
        nEdg=0; /// edge counter.
        int a,b;
        for(int i=0;i<E;i++)
        {
            scanf("%d %d",&a,&b);
            addEdge(a,b);  /// make graph
        }
        BCC();  /// take the result...
        printf("Case %d: %d %d\n",++cas,road,city);
    }
    return 0;
}


