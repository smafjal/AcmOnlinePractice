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

int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

//#include<conio.h>
//#define wait getch()

#define MAX 1999

struct info
{
    pair<int,int>xy;
    int id;
    int dis;
    info(){};
    info(pair<int,int> n,int p,int d){xy=n;id=p;dis=d;}
};

int row,cul;
char node[MAX][MAX];
int col[MAX][MAX][3];


bool cheack(int r,int c)
{
    if(r>=row || c>=cul || r<0 || c<0) return 0;
    return 1;
}

int BFS()
{
    int i,j,k,u,v,pu,pv,cst,type; queue<info>Q;

    for(i=0;i<row;i++)
    {
        for(j=0;j<cul;j++)
        {
            if(node[i][j]=='J')
            {
                Q.push(info(mp(i,j),0,0));
                col[i][j][0]=1;
            }
            else if(node[i][j]=='F')
            {
                Q.push(info(mp(i,j),1,0));
                col[i][j][1]=1;
            }
        }
    }
    info  tmp;

    while(!Q.empty())
    {
        tmp=Q.front();Q.pop();
        u=tmp.xy.fs;v=tmp.xy.sc; type=tmp.id;cst=tmp.dis;

        if(type==0 and node[u][v]=='F') continue;
        for(i=0;i<4;i++)
        {
            pu=u+rrr[i];
            pv=v+ccc[i];
            if(type==0 and !cheack(pu,pv)) {return cst+1;}
            if(cheack(pu,pv))
            {
                if(col[pu][pv][type]==0 and node[pu][pv]!='#')
                {
                    if(type==1 or (type==0 and node[pu][pv]!='F'))
                    {
                        Q.push(info(mp(pu,pv),type,cst+1));
                        col[pu][pv][type]=1;
                        if(type) node[pu][pv]='F';
                    }
                }
            }
        }
    }
    return oo;
}

int main()
{
    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&row,&cul); char c;

        for(i=0;i<row;i++)
        {
            for(j=0;j<cul;j++)
            {
                scanf(" %c",&c);
                node[i][j]=c;
                col[i][j][0]=0;
                col[i][j][1]=0;
            }
        }
        int  ans = BFS();
        if(ans>=oo)printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}

/**
4 5
##.##
#JF.#
#...#
#...#
3 3
###
#J.
#.F
**/
