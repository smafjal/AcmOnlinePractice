/**

"""""""""""""""""""" 1215 - Finding LCM"""""""""""""""""""""""""""""""""""""""""""

LCM is an abbreviation used for Least Common Multiple in Mathematics.
We say LCM (a, b, c) = L if and only if L is the least integer which is divisible by a, b and c.
You will be given a, b and L. You have to find c such that LCM (a, b, c) = L.
If there are several solutions, print the one where c is as small as possible. If there is no solution, report so.

Input:
Input starts with an integer T (≤ 325), denoting the number of test cases.
Each case starts with a line containing three integers a b L (1 ≤ a, b ≤ 106, 1 ≤ L ≤ 1012).

Output:
For each case, print the case number and the minimum possible value of c. If no solution is found, print 'impossible'.

Sample Input:

3
3 5 30
209475 6992 77086800
2 6 10

Output for Sample Input:
Case 1: 2
Case 2: 1
Case 3: impossible

**/

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

#define oo 1<<29
#define ERR 1e-7
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define PI (2*acos(0))
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
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

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
typedef vector<pair<int,pair<int,int> > > vDi;
typedef vector<pair<double,pair<double,double> > >  vDd;

#define MAX 1000009

bool flag[MAX];
vi prime;
vpii v;
ll a,b,c,l;
int a1[MAX];
int b1[MAX];
int aprime,bprime,lprime;

void sive()
{
    int i,j,k,r,c;
    flag[0]=flag[1]=1;
    prime.pb(2);
    for(i=3;i<MAX;i+=2)
    {
        if(!flag[i])
        {
            prime.pb(i);
            r=i*2;
            if(i<MAX/i)for(j=i*i;j<MAX;j+=r) flag[j]=1;
        }
    }
}

void factor(ll n,int id)
{
    for(int i=0;prime[i]<=sqrt(n) and i<SZ(prime);i++)
    {
        if(n%prime[i]==0)
        {
            int cnt=0;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
            }
            if(id==2){v.pb(mp(prime[i],cnt));lprime++;}
            else if(id==0) {a1[prime[i]]=cnt;aprime++;}
            else if(id==1) {b1[prime[i]]=cnt;bprime++;}
        }
    }

    if(n>1)
    {
        if(id==2){v.pb(mp(n,1));lprime++;}
        else if(id==0) {a1[n]=1;aprime++;}
        else if(id==1) {b1[n]=1;bprime++;}
    }
}

ll make()
{
    ll ans=1;
    for(int i=0;i<SZ(v);i++)
    {
        int p=v[i].fs;
        int cnt=v[i].sc;

        int k1=a1[p];
        int k2=b1[p];
        if(k1!=0) aprime--;
        if(k2!=0) bprime--;

        int k=max(k1,k2);
        if(k>cnt) return -1;
        int st=cnt;
        if(k==cnt) st=0;
        ans=ans*power(p,st);
    }
    if(aprime==0 and bprime==0) return ans;
    else return -1;
}

int main()
{
    sive();
    int cas=0,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&a,&b,&l);
        v.clear();
        mem(a1,0);mem(b1,0);

        aprime=0;bprime=0;lprime=0;
        factor(a,0);
        factor(b,1);
        factor(l,2);

        ll ans=make();
        if(ans==-1) printf("Case %d: impossible\n",++cas);
        else printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
