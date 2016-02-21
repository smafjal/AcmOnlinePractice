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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> paii;

#define PI (2*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
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
int BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;} /// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

//#include <conio.h>
//#define wait getch()

#define MAX 1000009
#define MAX_N 98499

bool flag[MAX];
ll prime[MAX_N];

vector<ll>v[2];
vector<ll>alldivisors;
ll total_prime_in_div;
ll a,n,co=0;

void sive()
{
    ll i,j,k,r,total=1;
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
//    deb("Total Prime: ",total);
    return;
}

void divisors(ll n)
{
    ll i,j,c;
    for(i=1;prime[i]<=n/prime[i];i++)
    {
        if(n%prime[i]==0)
        {
            c=0;
            while(n%prime[i]==0)
            {
                c++;
                n/=prime[i];
            }
            v[0].pb(prime[i]);
            v[1].pb(c);
        }
    }
    if(n>1)
    {
        v[0].pb(n);
        v[1].pb(1);
    }
    return;
}

void generate(ll cur,ll num)
{
    ll i,val;
    if(cur==total_prime_in_div)
    {
        alldivisors.pb(num);
        return;
    }

    val=1;
    for(i=0;i<=v[1][cur];i++)
    {
        generate(cur+1,val*num);
        val=val*v[0][cur];
    }
    return;
}

ll worke()
{
    ll i,j=0,k;

    for(i=0;i<SZ(alldivisors);i++)
    {
        if(alldivisors[i]>=a)
        {
            if(n/alldivisors[i]>alldivisors[i]) j++;
            else break;
        }
    }
    return j;
}

int main()
{
    sive();
    ll i,j,k;
    ll cas=0,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&a);
        ll tmp=n;
        divisors(tmp);
        total_prime_in_div=SZ(v[0]);
        generate(0,1);
        sort(all(alldivisors));
        ll ans=worke();
        printf("Case %lld: %lld\n",++cas,ans);
        v[0].clear();v[1].clear();alldivisors.clear();
    }
    return 0;
}
