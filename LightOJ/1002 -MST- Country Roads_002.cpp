/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
Date: 3/6/2012.
**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ULL;   /// scanf("%llu",&n);
typedef vector<int> vi;
typedef pair<int,int> paii;

#define FOR(a,b,n,c) for(__typeof(a) a=b;a<n;a+=c)
#define PI (2*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define reall(x)  (x).rbegin(),(x).rend()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}

template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}  /// B^P
int BigMod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return (int)R;} /// (B^P)%M
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

//#include<conio.h>
//#define wait getch()

#define MAX 1000

int n,e,dist[MAX];
bool col[MAX];
vector<pair<int,pair<int ,int> > >mst_value;
vector<pair<int,int> >adj[MAX];
int par[MAX],rank[MAX];


void make_set(int x)
{
    par[x]=x;
    rank[x]=0;
    return;
}

int find_set(int x)
{
    if(par[x]!=x) return par[x]=find_set(par[x]);
    return par[x];
}
void Union(int x,int y)
{
    if(rank[x]>rank[y])
    {
        par[y]=x;
    }
    else par[x]=y;
    if(rank[x]==rank[y]) rank[y]++;
    return;
}


void Link(int x,int y)
{
    Union(find_set(x),find_set(y));
}

void MST()
{
    int i,k,u,v;
    for(i=0;i<=n;i++)make_set(i);

    for(i=0;i<SZ(mst_value);i++)
    {
        u=find_set(mst_value[i].sc.fs);
        v=find_set(mst_value[i].sc.sc);
        if(u!=v)
        {
            Link(mst_value[i].sc.fs,mst_value[i].sc.sc);
            adj[mst_value[i].sc.fs].pb(mp(mst_value[i].fs, mst_value[i].sc.sc));
            adj[mst_value[i].sc.sc].pb(mp(mst_value[i].fs, mst_value[i].sc.fs));
        }
    }
}

void rec(int s)
{
    col[s]=1;
    for(int i=0;i<SZ(adj[s]);i++)
    {
        if(!col[adj[s][i].sc])
        {
            dist[adj[s][i].sc]=max(adj[s][i].fs,dist[s]);
            rec(adj[s][i].sc);
        }
    }
    return;
}

int main()
{
    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int x,y,w;
        scanf("%d %d",&n,&e);
        for(i=0;i<n+10;i++) {adj[i].clear();} mst_value.clear();

        for(i=1;i<=e;i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            mst_value.pb(mp(w,mp(x,y)));
        }
        sort(all(mst_value));
        MST();
        for(i=0;i<n+10;i++) {dist[i]=-1;col[i]=0;}

        int start;
        scanf("%d",&start);
        dist[start]=0;
        rec(start);
        printf("Case %d:\n",++cas);
        for(i=0;i<n;i++)
        {
            if(dist[i]==-1) printf("Impossible\n");
            else printf("%d\n",dist[i]);
        }
    }
    return 0;
}
