/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
**/


/***
1068 - Investigation:

Time Limit: 2 second(s)	 Memory Limit: 32 MB

An integer is divisible by 3 if the sum of its digits is also divisible by 3.
For example, 3702 is divisible by 3 and 12 (3+7+0+2) is also divisible by 3.
This property also holds for the integer 9.
In this problem, we will investigate this property for other integers.

Input:
Input starts with an integer T (≤ 200), denoting the number of test cases.
Each case contains three positive integers A, B and K (1 ≤ A ≤ B < 231 and 0 < K < 10000).

Output:
For each case, output the case number and the number of integers in the range [A, B] which are divisible by K and the sum of its digits is also divisible by K.

Sample Input:

3
1 20 1
1 20 2
1 1000 4
Case 1: 20
Case 2: 5
Case 3: 64

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

#define oo 1<<29
#define ERR 1e-7
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define pi (2*acos(0))
#define Clr(a) a.clear()
#define SZ(a)  (int)a.size()
#define lookalike scanf("%*d")
#define EQ(a,b)(fabs(a-b)<ERR)
#define all(a) (a).begin(),(a).end()
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define maximum(v) *max_element(all(v))
#define minimum(v) *min_element(all(v))
#define mem(a,b)  memset(a,b,sizeof(a))
#define reall(a) (a).rbegin(),(a).rend()
#define popcount(a) __builtin_popcount(a)
#define contain(x,item) (x).find(item)!=(x).end()
#define rep(i,a,b) for(__typeof(a) i=(a);i<b;i++)
#define FOREACH(it,x) for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
using namespace std;

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
void BINARY(int n){cout<<"Mask: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isVowel(char c){c=tolower(c);if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')return 1;return 0;}

struct node{int x,w;node(){;}node(int _x,int _w){x=_x;w=_w;}};
struct pq{int px,pw;pq(){;}pq(int _x,int _w){px=_x;pw=_w;}bool operator<(const pq &x)const{return pw>x.pw;}};//Min Priority_queue

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector<ll>      vl;
typedef pair<int,int>   pii;
typedef vector<string>  vs;
typedef map<int,int>    mii;
typedef map<string,int> msi;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpi;
typedef vector<pair<double,pair<double,double> > >  vDpd;

#define MAX 502

int K;
ll dp[12][82][82];
int vis[12][82][82];
int loop=1;

ll rec(int len,int sum,int mod)
{
    if(len==0)
    {
        if(sum==0 and mod==0) return 1;
        return 0;
    }

    ll &ret=dp[len][sum][mod];
    int &v=vis[len][sum][mod];
    if(v==loop) return ret;
    v=loop;

    ret=0;
    for(int i=0;i<10;i++)
    {
        int d=(mod*10+i);
        if(d>=K)d=d%K;
        ret+=rec(len-1,(sum+i)%K,d);
    }
    return ret;
}

ll calc(ll A)
{
    string a;
    stringstream ss;
    ss<<A;
    ss>>a;
    Clr(ss);

    int len=SZ(a);
    ll ans=0;

    for(int i=1;i<len;i++)
    {
        for(int j=1;j<10;j++)
        {
            ans+=rec(i-1,j%K,(j%K));
        }
    }

    for(int i=1;i<a[0]-'0';i++)
    {
        ans+=rec(len-1,i%K,(i%K));
    }

    int pre=(a[0]-'0')%K;
    int sum=pre;

    for(int i=1;i<len;i++)
    {
        for(int j=0;j<a[i]-'0';j++)
        {
            ans+=rec(len-(i+1),(sum+j)%K,((pre*10)+j)%K);
        }
        pre=((pre*10)+(a[i]-'0'))%K;
        sum=(sum+(a[i]-'0'))%K;
    }
    return ans;
}

int main()
{
    ll A,B;
    int cas=0;int t;
    cin>>t;
    while(t--)
    {
        cin>>A>>B>>K;
        ll ans=0;
        if(K<=82) ans=calc(B+1) - calc(A);
        printf("Case %d: %lld\n",++cas,ans);
        loop++;
    }
    return 0;
}

/**

12
1 1000 4

**/
