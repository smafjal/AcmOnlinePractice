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

#define MAX 5999

struct info
{
    int cost, node;
    info(){;}
    info(int n, int c){cost=c, node=n;}
    bool operator<(const info &b)const { return (cost>b.cost); }
};

vector<info>a[MAX];
int dist[MAX];
int mn[MAX];
vector<pair<int,int> >node[MAX];

void dijkstra(int s)
{
    int i,len,now,end,cst,nc;
    priority_queue<info>Q;
    dist[s] = 0;
    Q.push(info(s,0));
    info Z;

    while(!Q.empty())
    {
        Z = Q.top();
        Q.pop();
        now = Z.node;
        nc = Z.cost;
        len = node[now].size();
        for(i=0; i<len; i++)
        {
            end = node[now][i].fs;
            cst = node[now][i].sc;
            if(mn[end]>(nc+cst))
            {
                if(dist[end]>(nc+cst))
                {
                    mn[end] = dist[end];
                    dist[end] = nc + cst;
                    Q.push(info(end,dist[end]));
                }
                else if(dist[end]!=(nc+cst))
                {
                    mn[end] = nc + cst;
                    Q.push(info(end,mn[end]));
                }
            }
        }
    }

}


int main()
{
    int t,o;
    scanf("%d",&t);
    for(o=1; o<=t; o++)
    {
        int N,R;
        int u,v,w,i;
        scanf("%d %d",&N,&R);

        for(i=0; i<N+3; i++) a[i].clear(),mn[i]=oo,dist[i]=oo,node[i].clear();

        for(i=0; i<R; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            node[u].pb(mp(v,w));
            node[v].pb(mp(u,w));
        }
        dijkstra(1);
        printf("Case %d: %d\n",o,mn[N]);
    }
}


