/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
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


#define MAX 30009

int N,dis1[MAX],dis2[MAX];
bool col[MAX];
vector<pair<int,int > >node[MAX];

void DFS(int s)
{
    col[s]=1;
    for(int i=0;i<SZ(node[s]);i++)
    {
        if(!col[node[s][i].fs])
        {
            dis1[node[s][i].fs]=dis1[s]+node[s][i].sc;
            DFS(node[s][i].fs);
        }
    }
    return;
}

int main()
{
    int i,j,k,t,x,y,w,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        for(i=0;i<=N;i++) dis1[i]=0,dis2[i]=0,node[i].clear(),col[i]=0;

        for(i=0;i<N-1;i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            node[x].pb(mp(y,w));
            node[y].pb(mp(x,w));
        }
        DFS(0);
        int mx=0,nod1=0,nod2=0;
        for(i=0;i<N;i++)
        {
            if(dis1[i]>mx){mx=dis1[i];nod1=i;}
        }
        mem(dis1,0),mem(col,0);
        DFS(nod1);
        mx=0;
        for(i=0;i<N;i++)
        {
            if(dis1[i]>mx) {mx=dis1[i];nod2=i;}
            dis2[i]=dis1[i];
        }
        mem(dis1,0);mem(col,0);
        DFS(nod2);
        printf("Case %d:\n",++cas);
        for(i=0;i<N;i++)
        {
            printf("%d\n",max(dis1[i],dis2[i]));
        }
    }
    return 0;

}
