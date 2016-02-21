///Bismillahir Rahmanir Rahim
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

#define pi (2*acos(0))
#define oo 1<<29
#define pb push_back
#define popb pop_back
#define mp make_pair
#define mem(a,b)  memset(a,b,sizeof(a))
#define SZ(a)  (int)a.size()
#define fs first
#define sc second
#define CLR(a) a.clear()
#define contain(x,item) (x).find(item)!=(x).end()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define popcount(a) __builtin_popcount(a)
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define lookalike scanf("%*d")

using namespace std;
typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int> vii;
typedef pair<int,int> paii;

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

template<class T> inline T sqr(T n)
{
    return n*n;
}
template<class T> T Abs(T x)
{
    return (x>0)?x:-x;
}
template<class T>inline double LOG(T a,T b)
{
    return (log(a)/log(b));
}
template<class T> T power(T B,T P)
{
    return (P==0)? 1: B*(power(B,P-1));    /// B^P
}
template<class T> inline T gcd(T a,T b)
{
    if(a<0)return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template<class T> int BigMod(T B,T P,T M)
{
    if(P==0)return 1;    /// (B^p)%M
    else if(P%2==0)return sqr(BigMod(B,P/2,M))%M;
    else return(B%M)*(BigMod(B,P-1,M))%M;
}
template<class T> inline T lcm(T a,T b)
{
    if(a<0)return lcm(-a,b);
    if(b<0)return lcm(a,-b);
    return a*(b/(gcd(a,b)));
}
template<class T>inline T MOD(T a,T b)
{
    return (((a%b)+b)%b);    /// (a%b) for all positive and Negative number.
}
void BINARY(int n)
{
    cout<<"In Binary _10 bit: ";
    for(int i=10; i>=0; i--) if(n&(1<<i))cout<<1;
        else cout<<0;
    cout<<endl;
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

#define MAX 1009
int N,M;

vector<pair<int,int> >node;
vector<pair<int,int> >pre;
vector<pair<double,pair<int,int> > >tak;

int par[MAX];
int rank[MAX];

double dist(int x1,int y1,int x2,int y2)
{
    return sqrt(((x1-x2)*(x1-x2)) +((y1-y2)*(y1-y2)));
}

void make_set(int x)
{
    rank[x]=0;
    par[x]=x;
}

int find_set(int x)
{
    if(x!=par[x]) par[x]=find_set(par[x]);
    return par[x];
}

void link(int x,int y)
{
    if(rank[x]>rank[y]) par[y]=x;
    else par[x]=y;

    if(rank[x]==rank[y]) rank[x]++;
}

double MST()
{
    for(int i=0; i<=N; i++) make_set(i);

    for(int i=0; i<SZ(pre); i++)
    {
        int u=pre[i].fs;
        int v=pre[i].sc;
        if(find_set(u)!=find_set(v))
        {
            link(find_set(u),find_set(v));
        }
    }

    double cost=0.0;
    for(int i=0; i<SZ(tak); i++)
    {
        int u=tak[i].sc.fs;
        int v=tak[i].sc.sc;
        if(find_set(u)!=find_set(v))
        {
            link(find_set(u),find_set(v));
            cost+=tak[i].fs;
        }
    }
    return cost;
}
int main()
{
    while(cin>>N)
    {
        pre.clear();
        node.clear();
        tak.clear();
        int x,y;
        for(int i=1; i<=N; i++)
        {
            cin>>x>>y;
            node.pb(mp(x,y));
        }

        cin>>M;
        for(int i=0; i<M; i++)
        {
            cin>>x>>y;
            pre.pb(mp(x,y));

        }

        for(int i=0; i<SZ(node); i++)
        {
            for(int j=0; j<SZ(node); j++)
            {
                if(i==j) continue;
                double d=dist(node[i].fs,node[i].sc,node[j].fs,node[j].sc);
                tak.pb(mp(d,mp(i+1,j+1)));
            }
        }
        sort(all(tak));

        double ans=MST();
        printf("%0.2lf\n",ans);
    }

    return 0;
}
