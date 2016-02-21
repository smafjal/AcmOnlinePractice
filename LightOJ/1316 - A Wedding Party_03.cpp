
/*Bismillahir Rahmanir Rahim*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<algorithm>
#include<sstream>

using namespace std;
template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}

void BINARY(int n){cout<<"Mask: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}
template<class T> inline T sqr(T n){return n*n;}
template<class T> T Abs(T x){return (x>0)?x:-x;}
template<class T>inline double LOG(T a,T b){return (log(a)/log(b));}
template<class T> T power(T B,T P){return (P==0)? 1: B*(power(B,P-1));}  /// B^P
template<class T> inline T gcd(T a,T b) {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> int BigMod(T B,T P,T M){if(P==0)return 1;else if(P%2==0)return sqr(BigMod(B,P/2,M))%M;else return(B%M)*(BigMod(B,P-1,M))%M;}  /// (B^p)%M
template<class T> inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}
template<class T>inline T MOD(T a,T b) {return (((a%b)+b)%b);} /// (a%b) for all positive and Negative number.

int Set(int n,int p) {return n=(n|(1<<p));}
int Clear(int n,int p) {return n=(n&~(1<<p));}
int Check(int n,int p) {return (n&(1<<p));}
int Toggle(int n,int p) {if(Check(n,p))return n=Clear(n,p);return n=Set(n,p);}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isVowel(char c){c=tolower(c);if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')return 1;return 0;}

////bool operator<(const pq &x)const{return pw>x.pw;}};             //Min Priority_queue
////priority_queue<int,vi,greater<int> >Q;                          // Min Priority queue for One element.
////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31};              //month

#define mp          make_pair
#define pb          push_back
#define popcount(a) __builtin_popcount(a)
#define contain(x,item) (x).find(item)!=(x).end()
#define FOR(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define PI          (2*acos(0))
#define Clr(a)       a.clear()
#define SZ(a)       (int)a.size()
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()
#define maximum(v)  *max_element(all(v))
#define minimum(v)  *min_element(all(v))
#define FOREACH(it,x)for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
#define mem(a,b)    memset(a,b,sizeof(a))
#define oo          1<<29
#define ERR         1e-7
#define fs          first
#define sc          second
#define lookalike   scanf("%*c")

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<string>  vs;
typedef pair<int,int>   pii;
typedef pair<int,pii >  Dpii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpii;

#define MAX 501

int N,M,S;
vpii adj[MAX];
vi shopstore;
pii dp[17][1<<17];
int dis[MAX][MAX];
int vis[17][1<<17];
int loop=0;

struct  pq
{
    int node;
    int weight;
    pq(){;}
    pq(int _n,int _w){ node=_n;weight=_w;}
    bool operator<(const pq &x)const {return weight>x.weight;}
};

void Dijkstra(int s)
{
    FOR(i,0,N) dis[s][i]=oo;
    priority_queue<pq>Q;
    dis[s][s]=0;
    Q.push(pq(s,0));

    while(!Q.empty())
    {
        pq tmp=Q.top();Q.pop();
        int u=tmp.node;
        int prew=tmp.weight;
        if(prew>dis[s][u]) continue;

        FOR(i,0,SZ(adj[u]))
        {
            int v=adj[u][i].fs;
            int w=adj[u][i].sc;

            if(dis[s][u]+w<dis[s][v])
            {
                dis[s][v]=dis[s][u]+w;
                Q.push(pq(v,dis[s][v]));
            }
        }
    }
    return;
}

pii rec(int cur,int mask)
{
//    cout<<"Cue:----->>>>  "<<cur<<"  ";BINARY(mask);lookalike;

    if(cur==SZ(shopstore)-1) return mp(0,0);
    if(vis[cur][mask]==loop) return dp[cur][mask];
    vis[cur][mask]=loop;

    pii tmp,p; p=mp(0,oo);

    FOR(i,0,SZ(shopstore))
    {
        if(Check(mask,i)==0)
        {
            int u=shopstore[cur];
            int v=shopstore[i];
            if(dis[u][v]==oo)continue;

            int d=dis[u][v];
            tmp=rec(i,mask|(1<<i));
            if(tmp.sc>=oo) continue;
            tmp.sc+=d;
            tmp.fs++;

            if(tmp.fs>p.fs) p=tmp;
            else if(tmp.fs==p.fs and tmp.sc<p.sc) p=tmp;
        }
    }
    dp[cur][mask]=p;
    return p;
}

int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&N,&M,&S);  loop++;

        FOR(i,0,N+1)Clr(adj[i]);
        Clr(shopstore);
        int x,y,w;
        bool fl0=0,fln=0;

        FOR(i,0,S)
        {
            scanf("%d",&x);
            shopstore.pb(x);
            if(x==0) fl0=1;
            if(x==N-1) fln=1;
        }

        if(fl0==0) shopstore.pb(0);
        if(fln==0) shopstore.pb(N-1);
        sort(all(shopstore));

        FOR(i,0,M)
        {
            scanf("%d %d %d",&x,&y,&w);
            adj[x].pb(mp(y,w));
        }

        FOR(i,0,SZ(shopstore))
        {
            Dijkstra(shopstore[i]);
        }
        pii ans=rec(0,0);

        if(fl0==0) ans.fs--;
        if(fln==0) ans.fs--;

        if(ans.sc>=oo) printf("Case %d: Impossible\n",++cas);
        else printf("Case %d: %d %d\n",++cas,ans.fs,ans.sc);
    }
    return 0;
}

/**

12

5 4 3
2 3 0
0 2 50
4 0 34
2 4 87
3 2 10

4 6 2
0 3
3 2 35
2 0 2
2 1 90
3 1 44
2 3 61
0 2 74

8 9 5
4 7 1 5 3
4 7 94
2 1 3
3 7 31
0 4 29
7 2 6
5 0 88
7 5 53
3 1 9
5 6 76



12
6 8 5
0 1 2 3 4
0 1 5
0 2 10
2 3 20
1 3 30
1 4 5
2 4 50
3 4 20
4 5 12


*/
