/*Bismillahir Rahmanir Rahim*/ /// Sm19

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
#include<time.h>

#define mp          make_pair
#define pb          push_back
#define popcount(a) __builtin_popcount(a)
#define contain(x,item) (x).find(item)!=(x).end()
#define FOR(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define REV(i,a,b) for(__typeof(a) i=a;i>=0;i--)
#define PI          (2*acos(0))
#define clr(a)       a.clear()
#define SZ(a)       (int)a.size()
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()
#define maximum(v)  *max_element(all(v))
#define minimum(v)  *min_element(all(v))
#define FOREACH(it,x)for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
#define fs          first
#define sc          second
#define mem(a,b)    memset(a,b,sizeof(a))

#define oo          (1<<30)
#define ERR         1e-7
#define lookalike   scanf("%*c")

using namespace std;
template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}

void BINARY(int n){cout<<"Mask: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}  /// BitPrint
template<class T>inline double LOG(T a,T b){return (log(a)/log(b));}
template<class T> T power(T B,T P){return (P==0)? 1: B*(power(B,P-1));}  /// B^P
template<class T> inline T gcd(T a,T b) {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> T BigMod(T B,T P,T M){if(P==0)return 1;else if(P%2==0)return sqr(BigMod(B,P/2,M))%M;else return(B%M)*(BigMod(B,P-1,M))%M;}  /// (B^p)%M
template<class T> inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}
template<class T>inline T MOD(T a,T b) {return (((a%b)+b)%b);} /// (a%b) for all positive and Negative number.

//String Operation
string toString(int a) {stringstream ss;ss<<a;string p;ss>>p;return p;}
string toStringL(long long a)  {stringstream ss;ss<<a;string p;ss>>p;return p;}
int toInt(string a){ stringstream ss;ss<<a;int p;ss>>p;return p;}
long long toLong(string a){ stringstream ss;ss<<a;long long p;ss>>p;return p;}
vector<int> toIntV(string a) {stringstream ss;ss<<a;int p;vector<int>v;while(ss>>p)v.push_back(p);return v;}
vector<long long > toLongV(string a)
{stringstream ss;ss<<a;long long p;vector<long long>v;while(ss>>p)v.push_back(p);return v;}


int Set(int n,int p) {return n=(n|(1<<p));}
int Clear(int n,int p) {return n=(n&~(1<<p));}
int Check(int n,int p) {return (n&(1<<p));}
int Toggle(int n,int p) {if(Check(n,p))return n=Clear(n,p);return n=Set(n,p);}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isVowel(char c){c=tolower(c);if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')return 1;return 0;}

////bool operator<(const pq &x)const{return pw>x.pw;}};             //Min Priority_queue
////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31};              //month

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<string>  vs;
typedef pair<int,int>   pii;
typedef pair<int,pii >  Dpii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpii;

#define MAX 100009


int N;
vpii adj[MAX];
int P[MAX][20],L[MAX],dis[MAX][20][2],col[MAX];


void dfs(int u,int level)
{
    col[u]=1;
    L[u]=level;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        int v=adj[u][i].fs;
        int w=adj[u][i].sc;
        if(col[v]==0)
        {
            P[v][0]=u;
            dis[v][0][0]=w;
            dis[v][0][1]=w;
            dfs(v,level+1);
        }
    }
    return;
}

void build_lca()
{
    for(int i=0;i<=N;i++)
    {
        L[i]=0;col[i]=0;
        for(int j=0;j<20;j++) { P[i][j]=-1;dis[i][j][0]=0;dis[i][j][1]=oo;}
    }
    dfs(1,0);

    for(int j=1;(1<<j)<=N;j++)
    {
        for(int i=1;i<=N;i++)
        {
            if(P[i][j-1]!=-1)
            {
                dis[i][j][0]=max(dis[i][j-1][0],dis[P[i][j-1]][j-1][0]);
                dis[i][j][1]=min(dis[i][j-1][1],dis[P[i][j-1]][j-1][1]);
                P[i][j]=P[P[i][j-1]][j-1];
            }
        }
    }
    return;
}

pair<int ,int > lca_quary(int a,int b)
{
    if(L[a]<L[b]) swap(a,b);
    int log=log2(L[a]);

    int minv=oo,maxv=0;
    for(int i=log;i>=0;i--)
    {
        if(L[a]-(1<<i)>=L[b])
        {
            maxv=max(maxv,dis[a][i][0]);
            minv=min(minv,dis[a][i][1]);
            a=P[a][i];
        }
    }
    if(a==b) return mp(maxv,minv);

    for(int i=log;i>=0;i--)
    {
        if(P[a][i]!=-1 and P[a][i]!=P[b][i])
        {
            maxv=max(maxv,max(dis[a][i][0],dis[b][i][0]));
            minv=min(minv,min(dis[a][i][1],dis[b][i][1]));
            a=P[a][i];
            b=P[b][i];
        }
    }
    maxv=max(maxv,max(dis[a][0][0],dis[b][0][0]));
    minv=min(minv,min(dis[a][0][1],dis[b][0][1]));
    return mp(maxv,minv);
}

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);


    int t,cas=0,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        for(int i=0;i<=N;i++) clr(adj[i]);

        int x,y,w;
        for(int i=1;i<N;i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            adj[x].pb(mp(y,w));
            adj[y].pb(mp(x,w));
        }
        build_lca();

        printf("Case %d:\n",++cas);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            pair<int ,int >cnt=lca_quary(x,y);
            printf("%d %d\n",cnt.sc,cnt.fs);
        }
    }

    return 0;
}

