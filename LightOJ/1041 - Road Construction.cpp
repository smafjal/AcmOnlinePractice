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

#define MAX 200

int N;
vector<pair<int,pair<int,int > > >node;
int rank[MAX],par[MAX];

void Make_set(int x)
{
    par[x]=x;
    rank[x]=0;
    return;
}

int Find_set(int x)
{
    if(x!=par[x]) par[x]=Find_set(par[x]);
    return par[x];
}

void Union_set(int x,int y)
{
    if(rank[x]>rank[y]) par[y]=x;
    else par[x]=y;

    if(rank[x]==rank[y]) rank[y]++;
}

void Link(int x,int y)
{
    Union_set(Find_set(x),Find_set(y));
}

int MST(int E,vector<paii> vv)
{
    int i,j,k,u,v; int cnt=0;int edge_num=0;

    for(i=1;i<=E;i++) Make_set(i);

    for(i=0;i<SZ(vv);i++)
    {
        u=vv[i].fs;v=vv[i].sc;
        if(Find_set(u)!=Find_set(v))
        {
            edge_num++;
            Link(u,v);
        }
    }

    for(i=0;i<SZ(node);i++)
    {
        u=node[i].sc.fs;
        v=node[i].sc.sc;
        if(Find_set(u)!=Find_set(v))
        {
            edge_num++;
            Link(u,v);
            cnt+=node[i].fs;
        }
    }
    if(edge_num<E-1) return -1;
    return cnt;
}

int main()
{
    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        string s1,s2;int cost; map<string,int> node_map; node.clear();
        scanf("%d",&N);

        k=0;
        vector<paii>pre_node;

        for(i=1;i<=N;i++)
        {
            cin>>s1>>s2>>cost;
            if(cost)
            {
                if(!node_map[s1]) node_map[s1]=++k;
                if(!node_map[s2]) node_map[s2]=++k;
                node.pb(mp(cost,mp(node_map[s1],node_map[s2])));
                node.pb(mp(cost,mp(node_map[s2],node_map[s1])));
            }
            else
            {
                if(!node_map[s1]) node_map[s1]=++k;
                if(!node_map[s2]) node_map[s2]=++k;
                pre_node.pb(mp(node_map[s1],node_map[s2]));
            }
        }
        sort(all(node));
        int ans=MST(k,pre_node);
        if(ans>=0) printf("Case %d: %d\n",++cas,ans);
        else printf("Case %d: Impossible\n",++cas);

    }
    return 0;
}
