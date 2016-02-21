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
int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
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

#define MAX 55

char grid[30][30];
vector<pair<int,int> > ghost,human;
int gn,hn;
vector<pair<int,int> >G[55];
int Left[MAX],used[MAX];
int Right[MAX];
int N,D[MAX][MAX];

void bfs(int x,int y)
{
    mem(D,-1);
    queue<int>Q;

    Q.push(x);
    Q.push(y);
    D[x][y]=0;

    while(!Q.empty())
    {
        x=Q.front();Q.pop();
        y=Q.front();Q.pop();

        FOR(i,0,4)
        {
            int r=rrr[i]+x;
            int c=ccc[i]+y;
            if(r>=0 and r<N and c>=0 and c<N)
            {
                if(D[r][c]==-1 && grid[r][c]!='#')
                {
                    D[r][c]=D[x][y]+1;
                    Q.push(r);
                    Q.push(c);
                }
            }
        }
    }
    return;
}

bool dfs(int u,int cc)
{
    if(used[u]) return false;
    used[u]=true;

    FOR(i,0,SZ(G[u]))
    {
        int v=G[u][i].fs;
        int w=G[u][i].sc;
        if(w>cc) continue;

        if(Right[v]==-1 || dfs(Right[v],cc))
        {
            Right[v]=u;
            Left[u]=v;
            return true;
        }
    }
    return false;
}

int BPM(int cc)
{
    mem(Right,-1);mem(Left,-1);
    bool done;int cnt=0;
    do
    {
        done=false;
        mem(used,0);
        FOR(i,0,hn)
        {
            if(Left[i]==-1 && !used[i])
            {
                done|=dfs(i,cc);
            }
        }
    }while(done);

    for(int i=0;i<gn;i++) if(Right[i]!=-1)cnt++;
    return cnt;
}

int sol()
{
    int start=0,end=1467;int ans=oo;

    while(start<end)
    {
        int mid=(start+end)>>1;
        int t=BPM(mid);
        if(t==hn)
        {
            ans=min(ans,mid);
            end=mid;
        }
        else start=mid+1;
    }
    if(ans>=oo) return -1;
    return start;
}

int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);char c;
        gn=0;hn=0;clr(ghost);clr(human);

        FOR(i,0,N)
        {
            FOR(j,0,N)
            {
                scanf(" %c",&c);
                if(c=='G') ghost.pb(mp(i,j));
                else if(c=='H') human.pb(mp(i,j));
                grid[i][j]=c;
            }
        }
        gn=SZ(ghost);hn=SZ(human);
        FOR(i,0,hn+3)clr(G[i]);

        FOR(j,0,gn)
        {
            bfs(ghost[j].fs,ghost[j].sc);
            FOR(i,0,hn)
            {

                int x=human[i].fs;
                int y=human[i].sc;
                if(D[x][y]!=-1) G[i].pb(mp(j,(2*D[x][y])+2));
            }
        }

        int cnt=sol();
        if(cnt!=-1)printf("Case %d: %d\n",++cas,cnt);
        else printf("Case %d: Vuter Dol Kupokat\n",++cas);
    }
    return 0;
}


