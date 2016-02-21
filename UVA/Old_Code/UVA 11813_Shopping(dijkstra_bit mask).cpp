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

#define MAX 100003

struct node
{
    int x,weight;
    node(){};
    node(int _x,int _weight){x=_x;weight=_weight;}
    bool operator<(const node&x) const {return weight>x.weight;}
};

vpii adj[MAX];
int N,M;
map<int,int>store;
int dis[12][12];
int cost[MAX];

void dijkstra(int s)
{
    for(int i=0;i<=N;i++) cost[i]=oo;

    priority_queue<node>Q;
    cost[s]=0;
    Q.push(node(s,0));

    while(!Q.empty())
    {
        node tmp=Q.top();Q.pop();
        int u=tmp.x;
        int w=tmp.weight;
        if(store.find(u)!=store.end()) dis[store[s]][store[u]]=w;

        for(int i=0;i<SZ(adj[u]);i++)
        {
            int v=adj[u][i].fs;
            int now_cost=adj[u][i].sc;
            if(cost[v]>cost[u]+now_cost)
            {
                cost[v]=cost[u]+now_cost;
                Q.push(node(v,cost[v]));
            }
        }
    }
}

int dp[12][1<<11];

int rec(int cur,int mask)
{
    if(mask==0) return dis[cur][0];
    int &ret=dp[cur][mask];
    if(ret!=-1) return ret;
    ret=oo;

    for(int i=0;i<M;i++)
    {
        if((mask &(1<<i)))
        {
            ret=min(ret,rec(i,mask^(1<<i))+dis[cur][i]);
        }
    }
    return ret;
}
int main()
{
    int cas=0,t;
    scanf("%d",&t);
    while(t--)
    {
        int p;
        scanf("%d %d",&N,&p);
        int a,b,c;
        for(int i=0;i<=N;i++) adj[i].clear();
        store.clear();

        for(int i=0;i<p;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            adj[a].pb(mp(b,c));
            adj[b].pb(mp(a,c));
        }
        scanf("%d",&M);for(int i=0;i<=M;i++) for(int j=0;j<=M;j++) dis[i][j]=oo;

        for(int i=0;i<M;i++)
        {
            scanf("%d",&a);
            store[a]=i+1;
        }
        store[0]=0;M++;

        map<int,int>::iterator it;
        for(it=store.begin();it!=store.end();it++)
        {
            int s=(*it).fs;
            dijkstra(s);
        }
        mem(dp,-1);
        int ans=rec(0,((1<<M)-1)^1);
        cout<<ans<<endl;
    }
    return 0;
}

