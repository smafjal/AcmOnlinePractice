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
int NodeId[MAX];
int used[MAX],Right[MAX],dfsTime;

void dfs_col(int u,int id)
{
    NodeId[u]=id;
    for(int i=0;i<SZ(G[u]);i++)
    {
        int v=G[u][i];
        if(NodeId[v]==-1) dfs_col(v,!id);
    }
    return;
}


bool dfs(int u)
{
    if(used[u]==dfsTime) return false;
    used[u]=dfsTime;
    for(int i=0;i<SZ(G[u]);i++)
    {
        int v=G[u][i];
        if(Right[v]==-1 || dfs(Right[v]))
        {
            Right[v]=u;
            return true;
        }
    }
    return false;
}


int BPM()
{
    int cnt=0;
    mem(Right,-1);mem(used,0);dfsTime=0;
    for(int i=1;i<=N;i++)
    {
        if(NodeId[i] and SZ(G[i]))
        {
            dfsTime++;
            if(dfs(i)) cnt++;
        }
    }

//    cout<<"Cnt: "<<cnt<<endl;

//    for(int i=1;i<=N;i++)
//    {
//        if(Right[i]!=-1)
//        {
//            cout<<Right[i]<<" -- "<<i<<endl;
//        }
//    }

    return (N-(cnt*2)+cnt);
}


int main(int args,char *argv[])
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&M);
        for(int i=0;i<N+2;i++) clr(G[i]);
        int a,b;

        for(int i=0;i<M;i++)
        {
            scanf("%d %d",&a,&b);
            G[a].pb(b);
            G[b].pb(a);
        }
        mem(NodeId,-1);
        for(int i=1;i<=N;i++)
        {
            if(NodeId[i]==-1)dfs_col(i,1);
        }

//        for(int i=1;i<=N;i++)
//        {
//            cout<<i<<" -- "<<NodeId[i]<<endl;
//        }

        int cnt=BPM();
        printf("Case %d: %d\n",++cas,cnt);
    }

    return 0;
}


