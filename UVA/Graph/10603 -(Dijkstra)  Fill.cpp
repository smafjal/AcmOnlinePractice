/*Bismillahir Rahmanir Rahim*/
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

#define mp          make_pair
#define pb          push_back
#define popcount(a) __builtin_popcount(a)
#define contain(x,item) (x).find(item)!=(x).end()
#define FOR(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define PI          (2*acos(0))
#define Clr(a)       a.clear()
#define SZ(a)       (int)a.size()
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()
#define maximum(v)  *max_element(all(v))
#define minimum(v)  *min_element(all(v))
#define FOREACH(it,x)for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
#define mem(a,b)    memset(a,b,sizeof(a))
#define oo          1<<29
#define ERR         1e-7
#define fs          first
#define sc          second
#define lookalike   scanf("%*c")

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<string>  vs;
typedef pair<int,int>   pii;
typedef pair<int,pii >  Dpii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpii;

#define MAX 202

int a,b,c,d;

struct pq
{
    int a, b,c,sum;
    pq(){};
    pq(int _a,int _b,int _c,int _sum){ a=_a,b=_b,c=_c,sum=_sum;}
    bool operator < (const pq &x)const {return sum>x.sum;}
};

pii Solve()
{
    map<Dpii,int >M; Clr(M);
    priority_queue<pq>Q;
    Q.push(pq(0,0,c,0));

    int minsum=0;
    int nowd=d;
    int nowdist=oo;

    while(!Q.empty())
    {
        pq tmp=Q.top();Q.pop();

        if(M.count(mp(tmp.a,mp(tmp.b,tmp.c)))>0 and tmp.sum>=M[mp(tmp.a,mp(tmp.b,tmp.c))]) continue;
        M[mp(tmp.a,mp(tmp.b,tmp.c))]=tmp.sum;


        if(tmp.a==d or tmp.b==d or tmp.c==d)
        {
            nowd=d;
            minsum=tmp.sum;
            break;
        }
        if(d-tmp.a>0 and d-tmp.a<nowdist)
        {
            nowdist=d-tmp.a;
            nowd=tmp.a;
            minsum=tmp.sum;
        }
        if(d-tmp.b>0 and d-tmp.b<nowdist)
        {
            nowdist=d-tmp.b;
            nowd=tmp.b;
            minsum=tmp.sum;
        }

        if(d-tmp.c>0 and d-tmp.c<nowdist)
        {
            nowdist=d-tmp.c;
            nowd=tmp.c;
            minsum=tmp.sum;
        }


        int exchange=0; pq inter;
        if(tmp.a>0)
        {
            if(tmp.b<b)
            {
                exchange=min(b-tmp.b,tmp.a);
                inter=pq(tmp.a-exchange,tmp.b+exchange,tmp.c,tmp.sum+exchange);
                Q.push(inter);
            }

            if(tmp.c<c)
            {
                exchange=min(c-tmp.c,tmp.a);
                inter=pq(tmp.a-exchange,tmp.b,tmp.c+exchange,tmp.sum+exchange);
                Q.push(inter);
            }
        }

        if(tmp.b>0)
        {
            if(tmp.a<a)
            {
                exchange=min(a-tmp.a,tmp.b);
                inter=pq(tmp.a+exchange,tmp.b-exchange,tmp.c,tmp.sum+exchange);
                Q.push(inter);
            }

            if(tmp.c<c)
            {
                exchange=min(c-tmp.c,tmp.b);
                inter=pq(tmp.a,tmp.b-exchange,tmp.c+exchange,tmp.sum+exchange);
                Q.push(inter);
            }
        }

        if(tmp.c>0)
        {
            if(tmp.b<b)
            {
                exchange=min(b-tmp.b,tmp.c);
                inter=pq(tmp.a,tmp.b+exchange,tmp.c-exchange,tmp.sum+exchange);
                Q.push(inter);
            }

            if(tmp.a<a)
            {
                exchange=min(a-tmp.a,tmp.c);
                inter=pq(tmp.a+exchange,tmp.b,tmp.c-exchange,tmp.sum+exchange);
                Q.push(inter);
            }
        }
    }
    return mp(minsum,nowd);
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        pii ans;
        if(c<=d) ans=mp(0,d);
        else ans=Solve();
        printf("%d %d\n",ans.fs,ans.sc);
    }
    return 0;
}


