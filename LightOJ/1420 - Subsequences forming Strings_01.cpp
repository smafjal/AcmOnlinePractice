/*Bismillahir Rahmanir Rahim*/ /// Sm19

/******
Given three strings A, B and C you have to count the number of ways you can construct C by combining two subsequences
from A and B.
After deleting 0 or more characters from a string we can get its subsequence.
For example "a", "b", "c", "ab", "ac", "bc", "abc", "" (empty string) are the subsequences of "abc".

Now, suppose there are two subsequences "abc" and "de". By combining them you can get the following strings
"abcde", "abdce", "abdec", "adbce", "adbec", "adebc", "dabce", "dabec", "daebc" and "deabc".

Input:
Input starts with an integer T (≤ 100), denoting the number of test cases.
Each case starts with a line containing three strings A, B and C.
The strings will contains only lowercase letters and the lengths of the strings are between 1 and 100 (inclusive).

Output:
For each case, print the case number and the number of ways you can construct C from the first two strings:
A and B by the above way. The result can be large, so print the result modulo 1000000007.

****/

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

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<string>  vs;
typedef pair<int,int>   pii;
typedef pair<int,pii >  Dpii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpii;

#define MAX 102

ll Mod = 1000000007;
int matA[MAX][129];
int matB[MAX][129];
ll dp[MAX][MAX][MAX][3];
string a,b,c;

void doit()
{
    mem(matA,-1);
    mem(matB,-1);

    REV(i,SZ(a)-1,0)
    {
        FOR(j,0,128)
        {
            matA[i][j]=matA[i+1][j];
        }
        matA[i][a[i]]=i;
    }

    REV(i,SZ(b)-1,0)
    {
        FOR(j,0,128)
        {
            matB[i][j]=matB[i+1][j];
        }
        matB[i][b[i]]=i;
    }
    return;
}


ll rec(int i,int j,int k,int id)
{
    if(k==SZ(c) and id==0) return 1;
    ll &ret=dp[i][j][k][id];
    if(ret!=-1) return ret;

    ret=0;
    if(id==0)
    {
        if(matA[i][c[k]]!=-1) ret=(ret+rec(matA[i][c[k]]+1,j,k+1,1))%Mod;
        if(matB[j][c[k]]!=-1) ret=(ret+rec(i,matB[j][c[k]]+1,k+1,2))%Mod;
    }
    else
    {
        ret=(ret+rec(i,j,k,0))%Mod;
        if(id==1)
        {
            if(matA[i][c[k-1]]!=-1) ret=(ret+rec(matA[i][c[k-1]]+1,j,k,1))%Mod;
        }
        else
        {
            if(matB[j][c[k-1]]!=-1) ret=(ret+rec(i,matB[j][c[k-1]]+1,k,2))%Mod;
        }
    }

    return ret%Mod;
}

int main()
{
    int cas=0;int t;
    scanf(" %d ",&t);

    while(t--)
    {
        cin>>a>>b>>c;

        doit();
        mem(dp,-1);
        ll ans=rec(0,0,0,0)%Mod;
        printf("Case %d: %lld\n",++cas,ans);
    }

    return 0;
}




