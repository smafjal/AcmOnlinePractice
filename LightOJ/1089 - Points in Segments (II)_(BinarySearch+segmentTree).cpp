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
#define reall(a)    (a).rbegin(),(a).rend()
#define popcount(a) __builtin_popcount(a)
#define contain(x,item) (x).find(item)!=(x).end()
#define rep(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define PI          (2*acos(0))
#define Clr(a)       a.clear()
#define SZ(a)       (int)a.size()
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define maximum(v)  *max_element(all(v))
#define minimum(v)  *min_element(all(v))
#define FOREACH(it,x)for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
#define mem(a,b)    memset(a,b,sizeof(a))
#define oo          1<<29
#define ERR         1e-7
#define fs          first
#define sc          second
#define lookalike   scanf("%*d")

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector<ll>      vl;
typedef vector<string>  vs;
typedef pair<int,int>   pii;
typedef pair<int,pii >  Dpii;
typedef map<int,int>    mii;
typedef map<string,int> msi;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpii;
typedef vector<pair<double,pair<double,double> > >  vDpdd;

#define MAX 50005

vi tree[4*MAX];
vpii store;int n;

int BinarySearch_Forupper(int x)
{
    int left=0;int right=SZ(store)-1;
    while(left<right)
    {
        int mid=(left+right+1)/2;
        if(store[mid].fs>x) right=mid-1;
        else left=mid;
    }
    return left;
}

int BinarySearch_Forlower(int node,int x)
{
    int left=0;int right=SZ(tree[node])-1;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(tree[node][mid]<x) left=mid+1;
        else right=mid;
    }
    return left;
}

void mama(int node)
{
    tree[node].clear();
    vi::iterator it1,it2; vi v;
    it1=tree[node*2].begin();
    it2=tree[node*2+1].begin();
    int num;bool bl=1;
    while(bl)
    {
        if((*it1)<(*it2))
        {
            tree[node].pb((*it1));it1++;
        }
        else
        {
            tree[node].pb((*it2));it2++;
        }
        if(it1==tree[node*2].end())while(it2!=tree[node*2+1].end()){tree[node].pb(*it2);it2++; bl=0;}
        if(it2==tree[node*2+1].end())while(it1!=tree[node*2].end()){tree[node].pb(*it1);it1++; bl=0;}
    }
    return;
}

void build(int node,int left,int right)
{
    if(left==right)
    {
        Clr(tree[node]);
        tree[node].pb(store[left].sc);
        return;
    }
    int mid=(left+right)/2;
    build(node*2,left,mid);
    build(node*2+1,mid+1,right);
    mama(node);
    return;
}

int quary(int node,int left,int right,int i,int j,int val)
{
    if(left>j or right<i)
    {
        return 0;
    }
    if(left>=i and right<=j)
    {
        int idx=BinarySearch_Forlower(node,val);
        if(tree[node][idx]<val)return 0;
        return SZ(tree[node])-idx;
    }

    int mid=(left+right)/2;
    int p=quary(node*2,left,mid,i,j,val);
    int q=quary(node*2+1,mid+1,right,i,j,val);
    return p+q;
}

int main()
{
    int cas=0,t,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        store.clear();int x,y;

        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            store.pb(mp(x,y));
        }

        sort(all(store));
        build(1,0,n-1);
        printf("Case %d:\n",++cas);

        for(int i=0;i<q;i++)
        {
            scanf("%d",&x);
            int idx=BinarySearch_Forupper(x);
            if(store[idx].fs>x) {printf("0\n");continue;}
            int ans=quary(1,0,n-1,0,idx,x);
            printf("%d\n",ans);
        }
    }
    return 0;
}


