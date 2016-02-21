/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
Date:
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
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<e5<<endl;}

template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){ll R=1;while(P>0){if(P%2==1)R=(R*B);P/=2;B=(B*B);}return R;}  /// B^P
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


#define MAX 1000

struct info
{
    int nod;
    int dist;
    info(){};
    info(int x,int d){nod=x;dist=d;}
    bool operator <(const info &x)const {return dist>x.dist;}
};

vector<pair<int,int> >node[MAX];
int col[MAX],dis[MAX],par[MAX];
int N;

bool relux(int u,int v,int d)
{
    if(dis[v]>dis[u]+d)
    {
        dis[v]=dis[u]+d;
        return 1;
    }
    return 0;
}

void Dijkstra(int s)
{
    int i,u,d;priority_queue<info>Q;struct info tmp;

    par[s]=s;
    dis[s]=0;
    Q.push(info(s,0));

    while(!Q.empty())
    {
        tmp=Q.top();Q.pop();
        u=tmp.nod;d=tmp.dist;

        for(i=0;i<SZ(node[u]);i++)
        {
            if(relux(u,node[u][i].fs,node[u][i].sc))
            {
                Q.push(info(node[u][i].fs,dis[node[u][i].sc]));
                par[node[u][i].fs]=u;
            }
        }
    }
    return;
}

void path(int s,int t)
{
    if(s==t or t==-1) printf(" %d",s);
    else
    {
        path(s,par[t]);
        printf(" %d",t);
    }
}


void print(int cas,int s,int t)
{
    int i,j,k;
    printf("Case %d: ",cas);
    printf("Path =" );
    path(s,t);
    printf("; ");
    printf("%d second delay\n",dis[t]);
}

int main()
{
    int i,j,k,cas=0;
    while(scanf("%d",&N)==1 and N)
    {
        int m,x,w;
        for(i=1;i<=N;i++)
        {
            node[i].clear();col[i]=0;dis[i]=oo;par[i]=-1;

            scanf("%d",&m);
            if(m==0) continue;

            for(j=1;j<=m;j++)
            {
                scanf("%d %d",&x,&w);
                node[i].pb(mp(x,w));
            }
        }
        int S,T;

        scanf("%d %d",&S,&T);
        Dijkstra(S);
        print(++cas,S,T);
    }
    return 0;
}
