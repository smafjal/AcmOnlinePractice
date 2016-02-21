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

#define pi (2*cos(0))
#define CUBE(X) (X*X*X)
#define rep(i,n) for(i=0;i<(n);i++)
#define rep1(i,a,n) for(i=a;i<=(n);i++)
#define oo 1<<29
#define pb push_back
#define popb pop_back
#define mp make_pair
#define mem(a,b)  mamset(a,b,sizeof(a))
#define SZ(a)  (int)a.size()
#define fs first
#define sc second
#define contain(x,item) (x).find(item)!=(x).end()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbigin(),(a).rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vii;
typedef pair<int,int> paii;

template<class T1>void print1(T1 e1){cout<<e1<<endl;}
template<class T1,class T2>void print2(T1 e1,T2 e2){cout<<e1<<"  "<<e2<<"  "<<endl;}
template<class T1,class T2,class T3>void print3(T1 e1,T2 e2,T3 e3){cout<<e1<<"  "<<e2<<"  "<<e3<<endl;}

template<class T> inline T sqr(T n){return n*n;}
template<class T> T Abs(T x){return (x>0)?x:-x;}
template<class T>inline double LOG(T a,T b){return (log(a)/log(b));}
template<class T> T power(T B,T P){return (P==0)? 1: B*(power(B,P-1));}  /// B^P

template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

template<class T> T BigMod(T B,T P,T M)
{if(P==0)return 1;else if(P%2==0)return sqr(BigMod(B,P/2,M))%M;else return(B%M)*(BigMod(B,P-1,M))%M;}  /// (B^p)%M

template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}

/// 2^64 = 18446744073709551616
/// sqrt(2^64)= 4294967296

//#define MAX 1000003
#define MAX_N 1000005

ll MAX=1000003;
ll fac[MAX_N];

void pre_fac()
{
    ll i;
    fac[0]=1;fac[1]=1;fac[2]=2;
    for(i=3;i<MAX_N;i++)
    {
        fac[i]=(fac[i-1]*(i%MAX))%MAX;
    }
    return;
}

ll worke_inverse(ll fn,ll fk)
{
    ll BigMod_ans=BigMod(fk,(ll)MAX-2,(ll)MAX);
    ll ans=((fn%MAX)*BigMod_ans)%(ll)MAX;
    return ans;
}

int main()
{
    ll i,j,k,n,t;
    pre_fac();
    scanf("%lld",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%lld %lld",&n,&k);
        ll down=((fac[k]%MAX)*(fac[n-k]%MAX))%MAX;
        ll ans=worke_inverse(fac[n],down);
        printf("Case %lld: %lld\n",j,ans);
    }
    return 0;
}

