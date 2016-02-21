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

#define oo          1<<30
#define ERR         1e-7
#define lookalike   scanf("%*d")

using namespace std;
template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}

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

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<string>  vs;
typedef pair<int,int>   pii;
typedef pair<int,pii >  Dpii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpii;

#define MAX 195

vpii adj[MAX];
vpii revadj[MAX];

int cnt;
int first;

void dfs(int u,int par)
{
//    deb("U:--->> ",u,par,first);lookalike;

    if(u==first) return;

    int id=0;
//    cout<<"sZ:-->> "<<SZ(adj[u])<<" "<<SZ(revadj[u])<<endl;

    for(int i=0;i<(SZ(adj[u]));i++)
    {
        int v=adj[u][i].fs;
        if(v==par) continue;
        int w=adj[u][i].sc;
        dfs(v,u);
        return;
    }
    for(int i=0;i<(SZ(revadj[u]));i++)
    {
        int v=revadj[u][i].fs;
        if(v==par) continue;
        int w=revadj[u][i].sc;
        dfs(v,u);
        cnt+=revadj[u][i].sc;
        return;
    }
    return;
}

int N;

void view()
{
    FOR(i,1,N+1)
    {

        if(SZ(revadj[i]))
        {
            cout<<"Node:-->> "<<i<<endl;
            FOR(j,0,SZ(revadj[i]))
            {
                cout<<revadj[i][j].fs<<" ";
            }
            puts("");
        }
    }
}
int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    int t,cas=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&N);
        int x,y,w;
        FOR(i,0,N+2) {clr(adj[i]);clr(revadj[i]);}
        int total=0;
        FOR(i,0,N)
        {
            scanf("%d %d %d",&x,&y,&w);
            adj[x].pb(mp(y,w));
            revadj[y].pb(mp(x,w));
            total+=w;
        }
//        view();
//        lookalike;

        int ans=oo;cnt=0;first=1;
        if(SZ(adj[1])) dfs(adj[1][0].fs,1);
        else
        {
            dfs(revadj[1][0].fs,1);
            cnt+=revadj[1][0].sc;
        }


//        deb("cnt:---->> ",cnt,total);

        ans=min(ans,cnt);
        ans=min(total-cnt,ans);

//        FOR(i,1,N+1)
//        {
//            first=i;
//            if(SZ(adj[i]))
//            {
//                cnt=0;
//                dfs(adj[i][0].fs,-1);
//                deb("Cnt:-->> ",cnt);
//                ans=min(cnt,ans);
//            }
//            else
//            {
//                cnt=0;
//                dfs(revadj[i][0].fs,-1);
//                deb("Cnt:-->> ",cnt);
//                ans=min(cnt+revadj[i][0].sc,ans);
//            }
////            puts("Finished");
//        }

        printf("Case %d: %d\n",++cas,ans);
    }

    return 0;
}



/*****

32
21 6 48
6 16 41
15 16 55
26 15 75
2 26 76
1 2 24
1 9 27
13 9 45
18 13 92
18 28 86
27 28 57
7 27 48
7 19 73
19 23 40
23 24 91
5 24 24
5 4 1
4 3 12
30 3 44
30 17 61
11 17 44
25 11 82
12 25 71
12 8 49
8 20 99
20 14 31
14 29 16
29 32 23
10 32 33
10 31 50
22 31 69
21 22 13


*****/
