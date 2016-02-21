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

#define oo          1<<30
#define ERR         1e-7
#define lookalike   scanf("%*d")

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

#define MAX 22

int M,C;
int dp[209][22];
//int vis[209][(1<<20)+2];
int arr[MAX][MAX];
//int loop=1;

int rec(int money,int mask)
{
    if(money<0) return -oo;
    if(mask==C) return 0;

    int &ret=dp[money][mask];
//    if(vis[money][mask]==loop) return ret;
    //    vis[money][mask]==loop;
    if(ret!=-1) return ret;

    ret=-oo;
    for(int i=1;i<=arr[mask][0];i++)
    {
        ret=max(rec(money-arr[mask][i],mask+1)+arr[mask][i],ret);
    }
    dp[money][mask]=ret;
    return ret;
}


int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    int x,y,k;
    int cas=0;int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&M,&C);
        for(int i=0;i<C;i++)
        {
            scanf("%d",&k);
            arr[i][0]=k;
            for(int j=1;j<=k;j++) scanf("%d",&arr[i][j]);
        }

        mem(dp,-1);
        int cnt=rec(M,0);
        if(cnt<0) puts("no solution");
        else cout<<cnt<<endl;
//        loop++;
    }


    return 0;
}



/****

#include <stdio.h>
#include <vector>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

vector<int> G[20];
int dp[201][21];

int buy(int m, int c){
  if (m<0) return -2;      // negative money means no solution
  if (c==0) return 0;      // no more garment to buy, this is a solution
  int &ret = dp[m][c];     // ret is an alias of dp[m][c]
  if (ret!=-1) return ret; // if the current state is already visited, return immediately
  ret = -2;                // initialize this state as having no solution (-2)
  REP(i,G[c-1].size()){    // for all model of this garment
    int ci = G[c-1][i];             // the price of model ci of garment c-1
    if (buy(m-ci, c-1) != -2)       // if this model can produce a solution
      ret >?= buy(m-ci, c-1) + ci;  // update the maximum money spent
  }
  return ret;
}

int main(){
  int N,M,C,K;
  scanf("%d",&N);
  while (N--){
    scanf("%d %d",&M,&C);
    REP(i,C){
      scanf("%d",&K);
      G[i].resize(K);                        // resize the vector to size K
      REP(j,K) scanf("%d",&G[i][j]);
    }
    memset(dp,-1,sizeof(dp));
    if (buy(M,C) == -2) puts("no solution"); // -2 means no solution
    else printf("%d\n", buy(M,C));           // this will return the memoized solution
  }
}

****/
