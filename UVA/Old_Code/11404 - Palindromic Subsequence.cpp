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
template<class T>inline T MOD(T a,T b) {return (((a%b)+b)%b);} /// (a%b) for all positive and Negative number.
void BINARY(int n){cout<<"In Binary _10 bit: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

#define MAX 1004

string dp[MAX][MAX];
string S;
int vis[MAX][MAX];
int loop=1;

string Min(string a,string b)
{
    if(a=="") return b;
    if(b=="") return a;
    if(SZ(a)==SZ(b)) return (a<b)?a:b;
    if(SZ(a)<SZ(b)) return b;
    return a;
}

string rec(int i,int j)
{
    string p;
    if(i==j) {p+=S[i];return p;}
    if(i>j) return "";

    string &ret=dp[i][j];
    if(vis[i][j]==loop) return ret;
    vis[i][j]=loop;

    if(S[i]==S[j]) ret=S[i]+rec(i+1,j-1)+S[j];
    else
    {
        string s1,s2;
        s1=rec(i+1,j);
        s2=rec(i,j-1);
        ret=Min(s1,s2);
    }
    return ret;
}

int  main()
{
    while(cin>>S)
    {
        string ans=rec(0,SZ(S)-1);
        loop++;
        cout<<ans<<endl;
    }
    return 0;
}
