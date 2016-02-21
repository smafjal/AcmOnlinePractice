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

//template<class T1> void deb(T1 e1){cout<<e1<<endl;}
//template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
//template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
//template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}

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

#define MAX 300

int col[MAX];
vector<int>node[MAX];
int dis1[MAX],dis2[MAX];
int n,e;

void bfs1(int s)
{
    int i,j,k,u,v;
    queue<int>Q;

    dis1[s]=0;
    Q.push(s);
    col[s]=1;

    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        for(i=0;i<SZ(node[u]);i++)
        {
            if(!col[node[u][i]])
            {
                dis1[node[u][i]]=dis1[u]+1;
                Q.push(node[u][i]);
                col[node[u][i]]=1;
            }
        }
    }
    return;
}

void bfs2(int s,int end)
{
    int i,j,k,u,v;
    queue<int>Q;

    dis2[s]=0;
    Q.push(s);
    col[s]=1;

    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        if(u==end) return ;
        for(i=0;i<SZ(node[u]);i++)
        {
            if(!col[node[u][i]])
            {
                dis2[node[u][i]]=dis2[u]+1;
                Q.push(node[u][i]);
                col[node[u][i]]=1;
            }
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
        int x,y;
        scanf("%d %d",&n,&e);
        for(i=0;i<n+10;i++) {node[i].clear();col[i]=0;dis1[i]=0;dis2[i]=0;}

        for(i=0;i<e;i++)
        {
            scanf("%d %d",&x,&y);
            node[x].pb(y);
            node[y].pb(x);
        }

        int start,end;
        scanf("%d %d",&start,&end);
        bfs1(start);

        mem(col,0);
        for(i=0;i<n;i++)
        {
            bfs2(i,end);
            dis1[i]=dis2[end]+dis1[i];
            mem(dis2,0);mem(col,0);
        }
        int *p=max_element(&dis1[0],&dis1[n]);
        int ans=(*p);p=NULL;

        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
