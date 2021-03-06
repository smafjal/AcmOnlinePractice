/*Bismillahir Rahmanir Rahim*//// Sm19

/******

Wavio is a sequence of integers. It has some interesting properties.
�  Wavio is of odd length i.e. L = 2*n + 1.
�  The first (n+1) integers of Wavio sequence makes a strictly increasing sequence.
�  The last (n+1) integers of Wavio sequence makes a strictly decreasing sequence.
�  No two adjacent integers are same in a Wavio sequence.
For example 1, 2, 3, 4, 5, 4, 3, 2, 0 is an Wavio sequence of length 9.
But 1, 2, 3, 4, 5, 4, 3, 2, 2 is not a valid wavio sequence. In this problem, you will be given a sequence of integers.
You have to find out the length of the longest Wavio sequence which is a subsequence of the given sequence.
Consider, the given sequence as :

1 2 3 2 1 2 3 4 3 2 1 5 4 1 2 3 2 2 1.

Here the longest Wavio sequence is : 1 2 3 4 5 4 3 2 1. So, the output will be 9.

Input:
The input file contains less than 75 test cases. The description of each test case is given below:
Input is terminated by end of file.
Each set starts with a postive integer, N(1<=N<=10000). In next few lines there will be N integers.

Output:
For each set of input print the length of longest wavio sequence in a line.
*****/

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
#define lookalike   scanf("%*c")

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<string>  vs;
typedef pair<int,int>   pii;
typedef pair<int,pii >  Dpii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpii;

#define MAX 10009

vi arr;
int N;
int lis[MAX],lds[MAX],I[MAX];

int longestBiotonicSequence()
{
    /** LIS part  ****/
    I[0]=-1*oo;
    FOR(i,1,N+1) I[i]=oo;

    int maxl=0;
    FOR(i,0,N)
    {
        int low=0;
        int high=maxl;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(I[mid]<arr[i]) low=mid+1;
            else high=mid-1;
        }
        I[low]=arr[i];
        lis[i]=low;
        maxl=max(maxl,low);
    }

    FOR(i,0,N)
    {
        deb(i,lis[i]);
    }
    puts("Finished");

    /*** LDS part ***/

    reverse(all(arr));
    I[0]=-1*oo;
    FOR(i,1,N+1) I[i]=oo;

    maxl=0;
    FOR(i,0,N)
    {
        int low=0;
        int high=maxl;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(I[mid]<arr[i]) low=mid+1;
            else high=mid-1;
        }
        I[low]=arr[i];
        lds[i]=low;
        maxl=max(maxl,low);
    }
//
    FOR(i,0,N)
    {
        deb(i,lds[i]);
    }
    puts("Finished");

    maxl=0;
    FOR(i,0,N)
    {
        int c1=lis[i];
        int c2=lds[N-i-1];
        maxl=max(maxl,min(c1,c2));
    }
    return maxl*2-1;
}

int main()
{
    int cas=0;int t;
    while(scanf("%d",&N)==1)
    {
        clr(arr);
        int a;
        FOR(i,0,N)
        {
            scanf("%d",&a);
            arr.pb(a);
        }
        int cnt=longestBiotonicSequence();
        printf("%d\n",cnt);
    }
    return 0;
}

/***

19
1 2 3 7 8 2 3 4 3 2 1 5 4 1 2 3 2 2 1

***/
