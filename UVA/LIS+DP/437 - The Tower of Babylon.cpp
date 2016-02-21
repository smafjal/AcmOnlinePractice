/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
**/

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
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define lookalike scanf("%*d")

using namespace std;
typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int> vii;
typedef pair<int,int> paii;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<e5<<endl;}

template<class T> inline T sqr(T n){return n*n;}
template<class T> T Abs(T x){return (x>0)?x:-x;}
template<class T>inline double LOG(T a,T b){return (log(a)/log(b));}
template<class T> T power(T B,T P){return (P==0)? 1: B*(power(B,P-1));}  /// B^P
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> int BigMod(T B,T P,T M)
{if(P==0)return 1;else if(P%2==0)return sqr(BigMod(B,P/2,M))%M;else return(B%M)*(BigMod(B,P-1,M))%M;}  /// (B^p)%M
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

#define MAX 200

struct block
{
    int x,y,h;
    block();
    block(int _x,int _y,int _h) {x=_x;y=_y;h=_h;return;}
};

vector<block>val;
int dp[MAX][MAX];
int N;

int rec(int now,int pre)
{
    if(now>=SZ(val)) return 0;

    int &ret=dp[now][pre];
    if(ret!=-1) return ret;
    ret=0;

    int x=val[now].x;int y=val[now].y;

    for(int i=0;i<SZ(val);i++)
    {
        if(val[i].x<x and val[i].y<y) ret=max(ret,rec(i,now)+val[i].h);
    }
    return ret;
}

int main()
{
    int i,j,k,cas=0;
    while(scanf("%d",&N)==1)
    {
        if(N==0) break;
        int a,b,c;val.clear();

        val.pb(block(oo,oo,oo));

        for(i=0;i<N;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            val.pb(block(b,c,a));
            val.pb(block(c,b,a));
            val.pb(block(a,c,b));
            val.pb(block(c,a,b));
            val.pb(block(b,a,c));
            val.pb(block(a,b,c));
        }
        mem(dp,-1);
        int ans=rec(0,0);

//        cout<<ans<<endl;
        printf("Case %d: maximum height = %d\n",++cas,ans);
    }
    return 0;
}

/**

5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27

**/

