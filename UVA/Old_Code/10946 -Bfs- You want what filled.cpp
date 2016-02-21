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
ll Pow(ll B,ll P){ ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}  /// B^P
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

#define MAX 1000
int row,cul;
int maze[MAX][MAX];
int col[MAX][MAX];

bool  cheack(int r,int c)
{
    if(r>row || c>cul || r<0 || c<0) return 0;
    return 1;
}

int bfs(int s1,int s2)
{
    int i,j,k,u,v,pu,pv,count=0;
    queue<int>Q;
    Q.push(s1);
    Q.push(s2);
    col[s1][s2]=1;
    char key=maze[s1][s2];

    while(!Q.empty())
    {
        count++;
        pu=Q.front();Q.pop();
        pv=Q.front();Q.pop();
        for(i=0;i<4;i++)
        {
            u=rrr[i]+pu;
            v=ccc[i]+pv;
            if(cheack(u,v))
            {
                if(!col[u][v] && maze[u][v]==key)
                {
                    col[u][v]=1;
                    Q.push(u);Q.push(v);
                }
            }
        }
    }
    return count;
}

bool com(pair<int,char>x, pair<int,char>y)
{
    if(x.fs==y.fs) return x.sc<y.sc;
    return x.fs>y.fs;
}

int main()
{
    int i,j,k;char c;int cas=0;
    while(scanf("%d %d",&row,&cul)==2)
    {
        if(!row && !cul) break;
        for(i=0;i<row;i++)
        {
            for(j=0;j<cul;j++)
            {
                scanf(" %c",&c);
                maze[i][j]=c;
            }
        }
        vector<pair<int,char> >node;

        for(i=0;i<row;i++)
        {
            int count=0;
            for(j=0;j<cul;j++)
            {
                if(!col[i][j] && maze[i][j]!='.')
                {
                    count=bfs(i,j);
                    node.pb(mp(count,maze[i][j]));
                }
            }
        }
        sort(all(node),com);
        printf("Problem %d:\n",++cas);
        for(i=0;i<SZ(node);i++)
        {
            printf("%c %d\n",node[i].sc,node[i].fs);
        }

        mem(col,0);mem(maze,0);
    }
    return 0;
}
