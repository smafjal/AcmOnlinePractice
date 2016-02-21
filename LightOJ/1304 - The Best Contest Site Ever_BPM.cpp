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

#define oo          (0x7f7f7f7f)
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

#define MAX 105
#define MAX_N 6009

int R,C,N;
char grid[MAX][MAX],c;
int used[MAX_N],Right[MAX_N];
pair<int,int>col[MAX][MAX];
vector<int>G[MAX_N];
int colTime=0;

void make_RC()
{
    int cnt=0;

    for(int i=0;i<R;i++,cnt++)
    {
        int id=0;
        FOR(j,0,C)
        {
            if(grid[i][j]=='W') id=1;
            else
            {
                if(id)cnt++;
                id=0;
                col[i][j].fs=cnt;
            }
        }
    }

    N=cnt;cnt=0;
    for(int i=0;i<C;i++,cnt++)
    {
        int id=0;
        FOR(j,0,R)
        {
            if(grid[j][i]=='W') id=1;
            else
            {
                if(id)cnt++;
                id=0;
                col[j][i].sc=cnt;
            }
        }
    }


//    puts("\n Then \n");
//    FOR(i,0,R)FOR(j,0,C)
//    {
//        printf(" %3d %d --",col[i][j].fs,col[i][j].sc);
//        if(j==C-1) puts("");
//    }

    FOR(i,0,R)FOR(j,0,C)
    {
        if(grid[i][j]=='W' || grid[i][j]=='R') continue;
        int u=col[i][j].fs;
        int v=col[i][j].sc;
        G[u].pb(v);
    }
    return;
}

bool dfs(int u)
{
    if(used[u]==colTime) return false;
    used[u]=colTime;
    FOR(i,0,SZ(G[u]))
    {
        int v=G[u][i];
        if(Right[v]==-1 || dfs(Right[v]))
        {
            Right[v]=u;
            return true;
        }
    }
    return false;
}

int BPM()
{
    int cnt=0;
    mem(Right,-1);
    FOR(i,0,N)
    {
        if(SZ(G[i]))
        {
            colTime++;
            if(dfs(i))cnt++;
        }
    }
    return cnt;
}

int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&R,&C);

        FOR(i,0,R)FOR(j,0,C)
        {
            scanf(" %c",&c);
            grid[i][j]=c;
        }
        make_RC();
        int cnt=BPM();
        printf("Case %d: %d\n",++cas,cnt);
        FOR(i,0,R)
        {
            FOR(j,0,C)
            {
                if(grid[i][j]=='W' || grid[i][j]=='R') printf("%c",grid[i][j]);
                else
                {
                    int u=col[i][j].fs;
                    int v=col[i][j].sc;
                    if(Right[v]==u)
                        printf("T");
                    else printf(".");
                }
            }
            puts("");
        }

        FOR(i,0,N+3) G[i].clear();
    }
    return 0;
}

