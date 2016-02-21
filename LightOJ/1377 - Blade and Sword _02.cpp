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
int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
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

#define MAX 209

char grid[MAX][MAX];
int N,M,col[MAX][MAX],Sdis[MAX][MAX],Ddis[MAX][MAX],SDdis[MAX][MAX];
int stri,strj;
vpii star;
vpii sv,ev;
int Sdiscover,Ediscover;

bool  ch(int r,int c)
{
    return r>=0 and r<N and c>=0 and c<M;
}

void Dbfs(int si,int sj)
{
    mem(col,0);mem(Ddis,0);
    queue<int>Q;
    Q.push(si);
    Q.push(sj);
    col[si][sj]=1;
    Ddis[si][sj]=0;

    while(!Q.empty())
    {
        int pr=Q.front();Q.pop();
        int pc=Q.front();Q.pop();
        if(grid[pr][pc]=='*') continue;


        FOR(i,0,4)
        {
            int r=rrr[i]+pr;
            int c=ccc[i]+pc;
            if(ch(r,c) and grid[r][c]!='#' and col[r][c]==0)
            {
                Ddis[r][c]=Ddis[pr][pc]+1;
                col[r][c]=1;
                Q.push(r);
                Q.push(c);
            }
        }
    }
    return;
}

void Sbfs(int si,int sj)
{
    mem(col,0);mem(Sdis,0);
    queue<int>Q;
    Q.push(si);
    Q.push(sj);
    col[si][sj]=1;
    Sdis[si][sj]=0;
    Sdiscover=-1;

    while(!Q.empty())
    {
        int pr=Q.front();Q.pop();
        int pc=Q.front();Q.pop();
        if(grid[pr][pc]=='*')
        {
//            if(Sdiscover==-1) {Sdiscover=Sdis[pr][pc];sv.pb(mp(pr,pc));}
//            else if(Sdiscover==Sdis[pr][pc]) {sv.pb(mp(pr,pc));}
            continue;
        }

        FOR(i,0,4)
        {
            int r=rrr[i]+pr;
            int c=ccc[i]+pc;
            if(ch(r,c) and grid[r][c]!='#' and col[r][c]==0)
            {
                Sdis[r][c]=Sdis[pr][pc]+1;
                col[r][c]=1;
                Q.push(r);
                Q.push(c);
            }
        }
    }
    return;
}

int  SDbfs(int si,int sj,int edi,int edj)
{
    mem(col,0);mem(SDdis,0);
    queue<int>Q;
    Q.push(si);
    Q.push(sj);
    col[si][sj]=1;
    SDdis[si][sj]=0;

    while(!Q.empty())
    {
        int pr=Q.front();Q.pop();
        int pc=Q.front();Q.pop();
        if(pr==edi and pc==edj) return SDdis[pr][pc];
        FOR(i,0,4)
        {
            int r=rrr[i]+pr;
            int c=ccc[i]+pc;
            if(ch(r,c) and grid[r][c]!='#' and col[r][c]==0 and grid[r][c]!='*')
            {
                SDdis[r][c]=SDdis[pr][pc]+1;
                col[r][c]=1;
                Q.push(r);
                Q.push(c);
            }
        }
    }
    return oo;
}

int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&M);
        int sti,stj,edi,edj; clr(star);clr(sv);clr(ev);

        FOR(i,0,N)
        {
            FOR(j,0,M)
            {
                scanf(" %c",&grid[i][j]);
                if(grid[i][j]=='P')
                {
                    sti=i;stj=j;
                }
                else if(grid[i][j]=='D')
                {
                    edi=i;edj=j;
                }
                else if(grid[i][j]=='*') star.pb(mp(i,j));
            }
        }

        Sbfs(sti,stj);
        Dbfs(edi,edj);
        int SD=SDbfs(sti,stj,edi,edj);

        FOR(i,0,SZ(star))
        {
            FOR(j,0,SZ(star))
            {
                if(i==j) continue;

                int u1=star[i].fs;
                int v1=star[i].sc;
                int u2=star[j].fs;
                int v2=star[j].sc;

                if(Sdis[u1][v1]==0) continue;
                int cnt=0;
                if(Ddis[u2][v2]==0)
                {
                    if(Ddis[u1][v1]==0) continue;
                    else cnt=Ddis[u1][v1]+1;
                }
                SD=min(SD,Sdis[u1][v1]+Ddis[u2][v2]+1+cnt);
            }
        }

        if(SD!=oo) printf("Case %d: %d\n",++cas,SD);
        else printf("Case %d: impossible\n",++cas);
    }

    return 0;
}

/**


3 9
#########
#P.#..D.#
#########

*/

