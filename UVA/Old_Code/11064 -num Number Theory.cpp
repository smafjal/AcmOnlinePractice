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
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define MAX 1000000

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

template<class T> int BigMod(T B,T P,T M)
{if(P==0)return 1;else if(P%2==0)return sqr(BigMod(B,P/2,M))%M;else return(B%M)*(BigMod(B,P-1,M))%M;}  /// (B^p)%M

template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}

bool flag[MAX];
int prime[MAX];
int d_ans,e_ans;

void sive()
{
    int i,j,k,r,total=1;
    flag[0]=flag[1]=1;
    prime[total]=2;

    for(i=3;i<MAX;i+=2)
    {
        if(!flag[i])
        {
            prime[++total]=i;
            r=i*2;
            if(MAX/i>=i)for(j=i*i;j<MAX;j+=r)flag[j]=1;
        }
    }
    return;
}

void euler(int n)
{
    int i,j,k,c,p;
    e_ans=1;d_ans=1;
    for(i=1;prime[i]<=n/prime[i];i++)
    {
        if(n%prime[i]==0)
        {
            c=0;
            p=1;
            while(n%prime[i]==0)
            {
                c++;
                n/=prime[i];
                p*=prime[i];
            }
            if(c==1)e_ans*=(prime[i]-1);
            else {k=p/prime[i];e_ans*=(p-k);}
            d_ans*=(c+1);
        }
    }
    if(n>1){e_ans*=(n-1);d_ans=d_ans*2;}
    return;
}

///2147483646

int main()
{
    sive();
    int i,j,k,n;
    while(scanf("%d",&n)==1)
    {
        euler(n);
        e_ans++;
        if(e_ans==n){printf("%d\n",0);continue;}
        d_ans-=2;
        int ans=n-(e_ans+d_ans);
        printf("%d\n",ans);
    }
    return 0;
}

