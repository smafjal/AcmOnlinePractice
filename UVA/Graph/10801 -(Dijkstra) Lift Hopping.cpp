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

#define MAX 105

struct info
{
    int liftt;
    int flornum[MAX];
};

struct pq
{
    int flor;
    int elevator;
    int weight;
    pq(){;}
    pq(int _flor,int _ele,int _weight) { flor=_flor,elevator=_ele,weight=_weight;}
    bool operator <(const pq &x)const { return weight>x.weight;}
};

int N,stop;
int dis[7][MAX];
struct info arr[7];

void doit(string s,int elvat)
{
    stringstream ss;ss<<s;
    int now;
    while(ss>>now)
    {
        arr[elvat].flornum[now]=1;
    }
    return;
}

int Dijkstra()
{
    FOR(i,0,7) FOR(j,0,MAX) dis[i][j]=oo;
    priority_queue<pq>Q;
    pq tmp;

    FOR(i,0,7)
    {
        if(arr[i].flornum[0]==1)
        {
            Q.push(pq(0,i,0));
        }
    }

    while(!Q.empty())
    {
        tmp=Q.top();Q.pop();
        FOR(i,0,100)
        {
            int cost=tmp.weight+arr[tmp.elevator].liftt*abs(tmp.flor-i);
            if(arr[tmp.elevator].flornum[i] and dis[tmp.elevator][i]>cost)
            {
                dis[tmp.elevator][i]=cost;
                Q.push(pq(i,tmp.elevator,cost));
            }
        }
        FOR(i,0,N)
        {
            if(arr[i].flornum[tmp.flor]==1)
            {
                int cost=tmp.weight+60;
                if(dis[i][tmp.flor]>cost)
                {
                    dis[i][tmp.flor]=cost;
                    Q.push(pq(tmp.flor,i,cost));
                }
            }
        }
    }
    int minx=oo;
    FOR(i,0,N)
    {
        minx=min(dis[i][stop],minx);
    }
    return minx;
}

void reset()
{
    FOR(i,0,7)
    {
        arr[i].liftt=0;
        mem(arr[i].flornum,0);
    }
}

int main()
{
    while(scanf("%d %d",&N,&stop)==2)
    {
        reset();
        FOR(i,0,N) scanf("%d ",&arr[i].liftt);
        string s;
        FOR(i,0,N)
        {
            getline(cin,s);
            doit(s,i);
        }

        int ans=Dijkstra();
        if(ans==oo) printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
