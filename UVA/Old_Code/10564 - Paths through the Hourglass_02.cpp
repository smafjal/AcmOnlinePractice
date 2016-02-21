/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
**/
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

#define pi (2*acos(0))
#define oo 1<<29
#define pb push_back
#define popb pop_back
#define mp make_pair
#define mem(a,b)  memset(a,b,sizeof(a))
#define SZ(a)  (int)a.size()
#define fs first
#define sc second
#define CLR(a) a.clear()
#define contain(x,item) (x).find(item)!=(x).end()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define popcount(a) __builtin_popcount(a)
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define lookalike scanf("%*d")

using namespace std;
typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int> vii;
typedef pair<int,int> paii;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<e5<<endl;}

template<class T> inline T sqr(T n){return n*n;}
template<class T> T Abs(T x){return (x>0)?x:-x;}
template<class T>inline double LOG(T a,T b){return (log(a)/log(b));}
template<class T> T power(T B,T P){return (P==0)? 1: B*(power(B,P-1));}  /// B^P
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> int BigMod(T B,T P,T M)
{if(P==0)return 1;else if(P%2==0)return sqr(BigMod(B,P/2,M))%M;else return(B%M)*(BigMod(B,P-1,M))%M;}  /// (B^p)%M
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}
template<class T>inline T MOD(T a,T b) {return (((a%b)+b)%b);} /// (a%b) for all positive and Negative number.
void BINARY(int n){cout<<"In Binary _10 bit: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

#define MAX 50

int N,S;
ll dp[45][45][503];
int grid[MAX][MAX];
string str;

ll rec(int x,int y,int sum)
{
    if(sum<0) return 0;
    if(x==(2*N-2)) return grid[x][y]==sum;

    ll &ret=dp[x][y][sum];
    if(ret!=-1) return ret;

    ret=0;
    if(x<N-1)
    {
        if(y-1>=0 and grid[x+1][y-1]!=-1) ret+=rec(x+1,y-1,sum-grid[x][y]);
        if(grid[x+1][y]!=-1) ret+=rec(x+1,y,sum-grid[x][y]);
    }
    else
    {
        if(grid[x+1][y+1]!=-1) ret+=rec(x+1,y+1,sum-grid[x][y]);
        if(grid[x+1][y]!=-1) ret+=rec(x+1,y,sum-grid[x][y]);
    }
    return ret;
}

void print(int x,int y,int sum)
{
//    deb(x,y,sum);

    if(x==(2*N-2)) return;

    if(x<N-1)
    {
        if(y-1>=0 and grid[x+1][y-1]!=-1 and rec(x+1,y-1,sum-grid[x][y])>0)
        {
            str+="L";
            print(x+1,y-1,sum-grid[x][y]);
        }
        else if(grid[x+1][y]!=-1 and rec(x+1,y,sum-grid[x][y])>0)
        {
            str+="R";
            print(x+1,y,sum-grid[x][y]);
        }
    }

    else
    {
        if(grid[x+1][y]!=-1 and rec(x+1,y,sum-grid[x][y])>0)
        {
            str+="L";
            print(x+1,y,sum-grid[x][y]);
        }
        else if(grid[x+1][y+1]!=-1 and rec(x+1,y+1,sum-grid[x][y]))
        {
            str+="R";
            print(x+1,y+1,sum-grid[x][y]);
        }
    }
    return;
}

int main()
{
    while(cin>>N>>S)
    {
        if(N==0 and S==0) break;
        mem(dp,-1);mem(grid,-1);
        int k=-1,x;
        bool fl=1,flag=1;

        for(int i=0;i<(2*N-1);i++)
        {
            k++;
            for(int j=0;(j<=N-k-1 and flag==1)or(fl==0 and j<k);j++)
            {
                cin>>grid[i][j];
            }
            if(i==N-1) {fl=0;k=1;flag=0;}
        }

        ll ans=0,p;fl=1;int row;

        for(int i=0;i<N;i++)
        {
            p=rec(0,i,S);
            if(p>0 and fl)
            {
                fl=0;
                print(0,i,S);
                row=i;
            }
            ans+=p;
        }

        cout<<ans<<endl;
        if(fl==0) cout<<row<<" "<<str<<endl;
        else cout<<endl;
        str.clear();
    }
    return 0;
}

/***

6 41
6 7 2 3 6 8
1 8 0 7 1
2 6 5 7
3 1 0
7 6
8
8 8
6 5 3
9 5 9 5
6 4 4 1 3
2 6 9 4 3 8

2 7
3 1
2
3 5

5 26
2 8 7 2 5
3 6 0 2
1 3 4
2 5
3
7 2
2 9 3
1 0 4 4
4 8 7 2 3

0 0

***/

