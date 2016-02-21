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

#define MAX 1000009

bool flag[MAX];
int prime[MAX];
bool pre[MAX];
int sum[MAX];

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

bool isPrime(int n)
{
    if(n==2)return 1;
    if(n<MAX){if((n%2) && !flag[n]) return 1;return 0;}
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%prime[i]==0) return 0;
    }
    return 1;
}

bool doit(int x)
{
    string s1,s2,s;char c;
    stringstream  ss;ss<<x;ss>>s;
    for(int i=0;i<SZ(s);i++)
    {
        string t=s;
        ss.clear();ss<<t;ss>>x;
        if(!isPrime(x)) return 0;
        s1=s;c=s[0];
        s1.erase(0,1);
        s=s1+c;
//        deb("Next:-- >> ",s);
    }
//    cin>>x;

    return 1;
}

int main()
{
    sive();
    int a,b;
    sum[99]=0;
    for(int i=100;i<MAX;i++)
    {
        if(doit(i))
        {
            pre[i]=1;
        }
        else pre[i]=0;
        sum[i]=sum[i-1]+pre[i];
    }
    while(scanf("%d",&a)==1)
    {
        if(a==-1) break;
        scanf("%d",&b);
        int x=sum[b]-sum[a-1];
        if(x==0) puts("No Circular Primes.");
        else if(x==1) puts("1 Circular Prime.");
        else printf("%d Circular Primes.\n",x);
    }
    return 0;
}

