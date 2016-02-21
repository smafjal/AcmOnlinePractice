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

#define Read(a) freopen(a,"r",stdin)
#define Write(a) freopen(a,"w",stdout)
#define PI (2*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define reall(x)  (x).rbegin(),(x).rend()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<30)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<e5<<endl;
}

template<class T> T Abs(T x)
{
    return x > 0 ? x : -x;
}
template<class T> inline T sqr(T x)
{
    return x*x;
}
ll Pow(ll B,ll P)
{
    ll R=1;    /// B^P
    while(P>0)
    {
        if(P%2==1)R=(R*B);
        P/=2;
        B=(B*B);
    }
    return R;
}
int BigMod(ll B,ll P,ll M)
{
    ll R=1;    /// (B^P)%M
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return (int)R;
}
template<class T> inline T lcm(T a,T b)
{
    if(a<0)return lcm(-a,b);
    if(b<0)return lcm(a,-b);
    return a*(b/(gcd(a,b)));
}
template<class T> inline T gcd(T a,T b)
{
    if(a<0)return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}

bool isUpperCase(char c)
{
    return c>='A' && c<='Z';
}
bool isLowerCase(char c)
{
    return c>='a' && c<='z';
}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month


#define MAX 590

struct info
{
    int nod,weight;
    info() {};
    info(int n,int w)
    {
        nod=n;
        weight=w;
    }
    bool  operator <(const info &x)const
    {
        return weight>x.weight;
    }
};

vector<int>fire_station;
vector<pair<int,int> >node[MAX];
int N;
int col[MAX];
int dis[MAX];


bool relux(int u,int v,int w)
{
    if(dis[v]>dis[u]+w)
    {
        dis[v]=dis[u]+w;
        return 1;
    }
    return 0;
}

int Dijkstra(int s)
{
    int i,j,u,v,d;
    priority_queue<info>Q;
    info tmp;
    for(i=1; i<=N; i++) dis[i]=oo;

    dis[s]=0;
    Q.push(info(s,0));

    for(i=0; i<SZ(fire_station); i++)
    {
        Q.push(info(fire_station[i],0) );
        dis[fire_station[i]]=0;
    }

    while(!Q.empty())
    {
        tmp=Q.top(),Q.pop();
        u=tmp.nod;//d=tmp.weight;

        for(i=0; i<SZ(node[u]); i++)
        {
            if(relux(u,node[u][i].fs,node[u][i].sc))
            {
                Q.push(info(node[u][i].fs,dis[node[u][i].fs] )  );
            }
        }
    }
    int mx;
    mx=*max_element(&dis[0],&dis[N+1]);
    return mx;
}

void worke()
{
    int i,k,mx;
    mx=oo;
    int nod=1;

    for(i=1; i<=N; i++)
    {
        if(col[i]) continue;
        k=Dijkstra(i);
        if(k<mx)
        {
            mx=k;
            nod=i;
        }
    }
    printf("%d\n",nod);
}

int main()
{
    int i,j,k,t;
    bool fl=0;
    scanf("%d",&t);
    while(t--)
    {
        int x,y,w;
        string str;
        int fire;
        if(fl) printf("\n");
        fl=1;

        scanf("%d %d",&fire,&N);
        for(i=0; i<=N; i++) node[i].clear();
        fire_station.clear();
        mem(col,0);

        for(i=1; i<=fire; i++)
        {
            scanf("%d",&x);
            fire_station.pb(x);
            col[x]=1;
        }
        getchar();

        while(getline(cin,str))
        {
            if(SZ(str)==0)
            {
                break;
            }
            stringstream ss;
            ss<<str;
            ss>>x>>y>>w;
            ss.clear();

            node[x].pb(mp(y,w));
            node[y].pb(mp(x,w));
        }
        worke();
    }
    return 0;
}



