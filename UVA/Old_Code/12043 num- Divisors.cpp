/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
Date:
**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ULL;   /// scanf("%llu",&n);
typedef vector<int> vi;
typedef pair<int,int> paii;

#define PI (2*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define reall(x)  (x).rbegin(),(x).rend()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}

template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}  /// B^P
int BigMod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return (int)R;} /// (B^P)%M
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

//#include<conio.h>
//#define wait getch()

#define MAX 500
#define MAX_N  100009

bool flag[MAX];
int prime[MAX];
int div_dp[MAX_N];
int sum_div_dp[MAX_N];

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
//    deb("Last Prime: ",prime[total]);
    return;
}

void numOfdivisors()
{
    int i,j,n,m;int k,p;

    for(i=4;i<MAX_N-1;i++)
    {
        n=m=i;
        for(j=1;prime[j]<=sqrt(n);j++)
        {
            if(n%prime[j]==0)
            {
                k=0;p=1;
                while(n%prime[j]==0)
                {
                    k++;p*=prime[j];
                    n/=prime[j];
                }
                k=k+1;p*=prime[j];
                p=(p-1)/(prime[j]-1);
                div_dp[m]=k*div_dp[n];
                sum_div_dp[m]=p*sum_div_dp[n];
                break;
            }
        }
        if(n==m)
        {
            sum_div_dp[m]=n+1;
            div_dp[m]=2;
        }
    }
    return;
}

void view()
{
    int i,j;
    printf("NUm: \n");
    for(i=0;i<100;i++)
    printf("%d  ",div_dp[i]);
    printf("\n\nSUM: \n");
    for(i=0;i<100;i++)
    printf("%d  ",sum_div_dp[i]);
    puts("");
}

int main()
{
    sive();
    div_dp[0]=0;div_dp[1]=1;div_dp[2]=2;div_dp[3]=2;
    sum_div_dp[0]=0;sum_div_dp[1]=1;sum_div_dp[2]=3;sum_div_dp[3]=4;
    numOfdivisors();

    int i,j,k;int a,b,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&k);
        ll ans1=0,ans2=0;
        for(i=a;i<=b;i++)
        {
            if(i%k==0)
            {
                ans1+=div_dp[i];
                ans2+=sum_div_dp[i];
            }
        }
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}


