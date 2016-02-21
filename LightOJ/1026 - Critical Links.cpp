#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<sstream>

#define FOREACH(it,x)for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
#define mp          make_pair
#define pb          push_back
#define FOR(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define SZ(a)       (int)a.size()
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()
#define fs          first
#define sc          second
#define clr(a)       a.clear()
#define mem(a,b)    memset(a,b,sizeof(a))
#define oo          1<<30

using namespace std;
#define MAX 10005

int low[MAX],idx[MAX],ti,N;
vector<int> adj[MAX];map<pair<int,int>,int>M;
vector<pair<int,int> > store;
int col[MAX];

void dfs(int u,int p=-1)
{
    low[u]=++ti;
    idx[u]=ti;

    col[u]=1;
    FOR(i,0,SZ(adj[u]))
    {
        int v=adj[u][i];
        if(v==p) continue;
        if(col[v]==0)
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>idx[u])
            {
                store.pb(mp(min(u,v),max(u,v)));
            }
        }
        else low[u]=min(low[u],idx[v]);
    }
    return;
}

void Articulation()
{
    FOR(i,0,N)
    {
        low[i]=idx[i]=0;
    }
    ti=0;
    mem(col,0);
    FOR(i,0,N)
    {
        if(col[i]==0) dfs(i);
    }
    return;
}

int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        string a;
        scanf("%d ",&N);
        FOR(i,0,N) adj[i].clear();M.clear();store.clear();

        FOR(i,0,N)
        {
            getline(cin,a);
            int num=0;
            int j,k;
            for(j=0;j<SZ(a);j++)
            {
                if(a[j]==' ')break;
                num=num*10+a[j]-'0';
            }
            k=0;
            for(;j<SZ(a);j++)
            {
                if(a[j]==' ' or a[j]=='(') continue;
                if(a[j]==')') break;
                k=k*10+a[j]-'0';
            }
            if(k==0) continue;

            int x;j+=2;
            a=a.substr(j);
            stringstream ss;ss<<a;
            while(ss>>x)
            {
                adj[num].pb(x);
            }
            ss.clear();
            a.clear();
        }

        Articulation();
        sort(all(store));
        printf("Case %d:\n",++cas);
        printf("%d critical links\n",SZ(store));
        FOR(i,0,SZ(store))
        {
            printf("%d - %d\n",store[i].fs,store[i].sc);
        }
    }
    return 0;
}

