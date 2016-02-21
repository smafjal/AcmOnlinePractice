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

#define MAX 3200000000

vs v;
vector<vector<int> >adj[15];
int N;
map<string,int>M;

void rec()
{
    for(int mask=1;mask<(1<<N);mask++)
    {
        int p=popcount(mask);
        vector<int>tm;

        for(int i=0;i<N;i++)
        {
            if(Check(mask,i))
            {
                tm.pb(M[v[i]]);
            }
        }
        adj[p].pb(tm);
    }
    return;
}

bool com(vector<string>a,vector<string>b)
{
    return M[a[0]]<M[b[0]];
}

void view()
{
    FOR(i,0,N+1)
    {

        int l=SZ(adj[i]);
        if(l==0) continue;

        deb("I:--->>> ",i,l);
        FOR(j,0,l)
        {
            FOR(k,0,SZ(adj[i][j]))
            {
                cout<<adj[i][j][k]<<"  ";
            }
            puts("New");
        }
        puts("Then New");
    }
}
void output(string s)
{
//    sort(all(v));
    N=SZ(v);
    rec();
//    deb("Aslam: ",SZ(s));lookalike;
//    view();lookalike;

    if(SZ(s)==1 and s[0]=='*')
    {
        for(int i=1;i<=N;i++)
        {
            printf("Size %d\n",i);
            sort(adj[i].begin(),adj[i].end());
            for(int j=0;j<SZ(adj[i]);j++)
            {
                for(int k=0;k<SZ(adj[i][j]);k++)
                {
                    if(!k)cout<<v[adj[i][j][k]-1];
                    else cout<<", "<<v[adj[i][j][k]-1];
                }
                puts("");
            }
            puts("");
        }
        return;
    }

    stringstream ss;ss<<s; vi tmp; int k;
    while(ss>>k)
    {
        tmp.pb(k);
    }
    if(SZ(tmp)==2)
    {
//        deb("aslam in 2");lookalike;
        for(int i=tmp[0];i<=tmp[1];i++)
        {
            printf("Size %d\n",i);
            sort(adj[i].begin(),adj[i].end());
            for(int j=0;j<SZ(adj[i]);j++)
            {
//                sort(all())
                for(int k=0;k<SZ(adj[i][j]);k++)
                {
                    if(!k)cout<<v[adj[i][j][k]-1];
                    else cout<<", "<<v[adj[i][j][k]-1];
                }
                puts("");
            }
            puts("");
        }

        return;
    }

    printf("Size %d\n",tmp[0]);
    int i=tmp[0];
    sort(adj[i].begin(),adj[i].end());
    for(int j=0;j<SZ(adj[i]);j++)
    {
        for(int k=0;k<SZ(adj[i][j]);k++)
        {
            if(!k)cout<<v[adj[i][j][k]-1];
            else cout<<", "<<v[adj[i][j][k]-1];
        }
        puts("");
    }
    puts("");
    return;
}

int main()
{
    string s,str;int t,cas=0;
    scanf("%d",&t);
    cin.ignore();
    getline(cin,str);
    while(t--)
    {
        M.clear();
        getline(cin,str);
        while(getline(cin,s) and s!="")
        {
//            deb("Size:-->> ",SZ(M));
            M[s]=SZ(M);
            v.pb(s);
        }
        output(str);
        FOR(i,0,15) clr(adj[i]);
        v.clear();
        if(t)puts("");
//        cin.ignore();
    }
    return 0;
}


/***


*
Times
Herald-Tribune
Post
New Advocate

**/

