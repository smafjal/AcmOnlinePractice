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
typedef vector<pair<int,pair<int,int> > > vDi;

#define MAX 105

vector<int>adj[MAX];
map<string,int>M;
int N,generation;
int col[MAX],ti[MAX],low[MAX],artic[MAX];
vector<string>store,v;

void DFS(int u,int par)
{
    col[u]=1;
    ti[u]=low[u]=++generation;
    int subtree=0;

    for(int i=0;i<SZ(adj[u]);i++)
    {
        int v=adj[u][i];
        if(!col[v])
        {
            subtree++;
            DFS(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=ti[u] and par!=-1)
            {
                artic[u]=1;
            }
        }
        else  low[u]=min(low[u],ti[v]);
    }
    if(par==-1 and subtree>=2)
    {
        artic[u]=1;
    }
    return;
}

int articulationpoint()
{
    for(int i=0;i<=N;i++) {col[i]=ti[i]=low[i]=0;artic[i]=0;}
    for(int i=1;i<=N;i++)
    {
        if(!col[i])
        {
            generation=0;
            DFS(i,-1);
        }
    }

    int cost=0;
    for(int i=1;i<=N;i++)
    {
        if(artic[i])
        {
            v.pb(store[i-1]);
            cost++;
        }
    }
    return cost;
}

void print()
{
    sort(all(v));
    for(int i=0;i<SZ(v);i++)
    {
        cout<<v[i]<<endl;
    }
    return;
}

int main()
{
    int cas=0;int t;
    while(scanf("%d",&N)==1 and N)
    {
        int cnt,x,y;
        string s1,s2,s;M.clear();
        for(int i=0;i<=N;i++) adj[i].clear();

        cnt=0;
        for(int i=0;i<N;i++)
        {
            cin>>s;
            M[s]=++cnt;
            store.pb(s);
        }
        store.clear();v.clear();

        int R;
        scanf("%d",&R);
        for(int i=0;i<R;i++)
        {
            cin>>s1>>s2;
            adj[M[s1]].pb(M[s2]);
            adj[M[s2]].pb(M[s1]);
        }
        if(cas)puts("");
        int ans=articulationpoint();
        printf("City map #%d: %d camera(s) found\n",++cas,ans);
        print();
    }
    return 0;
}
