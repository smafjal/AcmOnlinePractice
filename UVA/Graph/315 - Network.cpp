#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<sstream>

#define mp          make_pair
#define pb          push_back
#define FOR(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define SZ(a)       (int)a.size()
#define all(a)      (a).begin(),(a).end()
#define clr(a)       a.clear()
#define mem(a,b)    memset(a,b,sizeof(a))

using namespace std;

#define MAX  10005
int N,m,ti;
int tin[MAX],fup[MAX],col[MAX],Artpoint[MAX];
vector<int> adj[MAX];

void dfs(int u,int p=-1)
{
    col[u]=1;tin[u]=fup[u]=++ti; int subtree=0;
    FOR(i,0,SZ(adj[u]))
    {
        int v=adj[u][i];
        if(v==p)continue;
        if(col[v]) tin[u]=min(tin[u],fup[v]);
        else
        {
            subtree++;
            dfs(v,u);
            tin[u]=min(tin[v],tin[u]);
            if(tin[v]>=fup[u] and p!=-1)Artpoint[u]=1;
        }
    }
    if(p==-1 and subtree>1) Artpoint[u]=1;
    return;
}

int Articulationpoint()
{
    FOR(i,0,N+1) {tin[i]=fup[i]=col[i]=Artpoint[i]=0;}

    int numofArt=0; ti=0;
    FOR(i,1,N+1)
    {
        if(col[i]==0)dfs(i);
    }
    FOR(i,1,N+1) if(Artpoint[i]) numofArt++;
    return numofArt;
}


int main()
{
    int cas=0;
    while(scanf("%d",&N)==1 and N)
    {
        FOR(i,0,N+1) clr(adj[i]);
        string s;
        while(getline(cin,s))
        {
            if(s=="0") break;
            stringstream ss;ss<<s;int u,v; ss>>u;
            while(ss>>v)
            {
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        int cnt=Articulationpoint();
        cout<<cnt<<endl;
    }
    return 0;
}







