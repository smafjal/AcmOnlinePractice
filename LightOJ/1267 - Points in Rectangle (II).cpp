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

#define oo          1<<30
#define ERR         1e-7
#define lookalike   scanf("%*c")

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

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<string>  vs;
typedef pair<int,int>   pii;
typedef pair<int,pii >  Dpii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpii;

#define MAX 50006

int n,q;
struct abc
{
    vi store;
};

abc tree[4*MAX];
vi adj[MAX];
map<int,int>M;
int K;
vector<int>v;


void build(int node,int left,int right)
{
    tree[node].store.clear();
    if(left==right)
    {
        int idx=M[v[left]];
        sort(all(adj[idx]));
//        for(int i=0;i<SZ(adj[idx]);i++) tree[node].store.pb(adj[idx][i]);
        tree[node].store.assign(adj[idx].begin(),adj[idx].end());
        return;
    }
    int mid=(left+right)/2;
    build(node*2,left,mid);
    build(node*2+1,mid+1,right);
    merge(tree[node*2].store.begin(),tree[node*2].store.end(),tree[node*2+1].store.begin(),tree[node*2+1].store.end(),back_inserter(tree[node].store));
}


int quary(int node,int left,int right,int x1,int y1,int x2,int y2)
{
    if(v[left]>x2 or v[right]<x1) return 0;
    if(v[left]>=x1 and v[right]<=x2)
    {
        if(tree[node].store[0]>y2) return 0;
        if(tree[node].store[SZ(tree[node].store)-1]<y1) return 0;

        int x=((lower_bound(tree[node].store.begin(),tree[node].store.end(),y1)) - tree[node].store.begin());
        int y=((upper_bound(tree[node].store.begin(),tree[node].store.end(),y2)) - tree[node].store.begin());

//        FOR(i,0,SZ(tree[node].store))
//        {
//            deb(i," <<--:--->> ",tree[node].store[i]);
//        }
//        cout<<tree[node].store[0]<<" "<<tree[node].store[SZ(tree[node].store)-1]<<" ";
//        deb("x and y:-->>> ",node,x,y);lookalike;

        return y-x;
    }
    int  mid=(left+right)/2;

    int m1=quary(node*2,left,mid,x1,y1,x2,y2);
    int m2=quary(node*2+1,mid+1,right,x1,y1,x2,y2);
    return m1+m2;
}

int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        clr(M);clr(v);
        FOR(i,0,n+1) clr(adj[i]);

        K=0; int x1,y1,x2,y2;
        FOR(i,0,n)
        {
            scanf("%d %d",&x1,&y1);
            if(M.count(x1)<1)
            {
                M[x1]=++K;
                adj[M[x1]].pb(y1);
            }
            else
            {
                adj[M[x1]].pb(y1);
            }
        }

        v.pb(-1);
        FOREACH(it,M)
        {
            v.pb((*it).fs);
        }

//        deb("V:--->>>>> ",K);
//        for(int i=0;i<SZ(v);i++)
//        {
//            deb(i,v[i]);
//        }
//        lookalike;

        build(1,1,K);

        printf("Case %d:\n",++cas);
        FOR(i,0,q)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            int cnt=quary(1,1,K,x1,y1,x2,y2);
            printf("%d\n",cnt);
        }
    }
    return 0;
}
