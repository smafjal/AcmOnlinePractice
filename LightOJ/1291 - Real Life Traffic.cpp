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

#define oo          (0x7f7f7f7f)
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

#define MAX 10009

int N,M;
vector<int>G[MAX];
int used[MAX],mark[MAX],comp,low[MAX],idx[MAX],T;
stack<int>S;
int deg[MAX];

void dfs(int u,int p)
{
    used[u]=1;
    low[u]=idx[u]=++T;
    S.push(u);
    for(int i=0;i<SZ(G[u]);i++)
    {
        int v=G[u][i];
        if(v==p) continue;
        if(!used[v])
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],idx[v]);
    }
    if(low[u]==idx[u])
    {
        while(!S.empty())
        {
            int t=S.top();S.pop();
            mark[t]=comp;
            if(t==u)break;
        }
        comp++;
    }
    return;
}

int doit()
{
    comp=0;T=0;
    mem(used,0);
    while(!S.empty()) S.pop();
    dfs(0,-1);
    mem(deg,0);

    for(int u=0;u<N;u++)
    {
        for(int i=0;i<SZ(G[u]);i++)
        {
            int v=G[u][i];
            if(mark[u]==mark[v]) continue;
            deg[mark[u]]++;
            deg[mark[v]]++;
        }
    }
    int cnt=0;
    for(int i=0;i<comp;i++)
    {
        if(deg[i]==2) cnt++;
    }
    return (cnt+1)/2;
}

int main(void)
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&M);
        int a,b;
        for(int i=0;i<=N;i++) clr(G[i]);
        for(int i=0;i<M;i++)
        {
            scanf("%d %d",&a,&b);
            G[a].pb(b);
            G[b].pb(a);
        }
        int cnt=doit();
        printf("Case %d: %d\n",++cas,cnt);
    }
    return 0;
}




