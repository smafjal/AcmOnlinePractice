/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
**/

/*****

You will be given a square grid of size N × N. The top-left square has a coordinate of (1, 1) and that of bottom-right is (N, N).
Your job is to walk from (1, 1) to (N, N). Very easy, right? That’s why you have to follow some rules when walking.

You can only move left, right or down. (i, j-1) is left of (i, j), (i, j+1) is right of (i, j) and (i+1, j) is down of (i, j).
You can never move outside the grid. You can not step on a cell more than once. Every cell has an integer associated with it.
You have to make sure the sum of integers of the path is maximized.
You can step on at most k negative integers from source to destination.

Input:
Each case will start with two integers N and k. N ≤ 75 and k ≤ 5. Each of the next N lines will contain N integers
each given in row major order. That is, the first integer of the first row is (1, 1) and the last integer of last row is (N, N).
Input terminates with two zeros on a line.

Output:
For every case output the case number. If it’s not possible to reach the destination meeting the above rules then
output “impossible”, else print the maximum sum of integers of the path.

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

#define pi (2*acos(0))
#define oo (ll)1<<61
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

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

#define MAX 80

ll grid[MAX][MAX];
ll dp[MAX][MAX][7][3];
ll  vis[MAX][MAX],N,K;

int  pass[3][2]={{0,1},{1,0},{0,-1}};

bool cheack(int r,int c) {return (r>=1 and r<=N and c>=1 and c<=N);}

ll f(int x,int y,int k,int b)
{
    ll &ret=dp[x][y][k][b];
    if(ret!=-1) return ret;

    if(((x==N and y==N)) or(k==0))
    {
        if(k==0) ret=-(oo);
        else ret=grid[x][y];
        return ret;
    }
    ret=-(oo);

    for(ll i=0;i<3;i++)
    {
        if((b==0 and i==2) or (i==0 and b==2)) continue;

        ll xx=x+pass[i][0];ll yy=y+pass[i][1];
        ll t=((grid[x][y]<0) ? -1: 0);

        if(cheack(xx,yy) and !vis[xx][yy])
        {
            vis[xx][yy]=1;
            ll ans =f(xx,yy,k+t,i);
            if(ans!= -(oo)) ret=max(ret,ans+grid[x][y]);
            vis[xx][yy]=0;
        }
    }
    return ret;
}


int main()
{
    int cas=0;
    while(cin>>N>>K)
    {
        if(!N and !K) break;
        for(ll i=1;i<=N;i++) for(ll j=1;j<=N;j++) cin>>grid[i][j];
        mem(dp,-1);
        mem(vis,0);
        if(grid[N][N]<0) K--;

        ll ans=f(1,1,K+1,1);
        if(ans!= -(oo))printf("Case %d: %lld\n",++cas,ans);
        else printf("Case %d: impossible\n",++cas);
    }
    return 0;
}



/***

4 1
1 2 3 -5
-10 6 0 -1
-10 -10 -10 2
0 0 0 1

4 0
1 2 3 -5
-10 6 0 -1
-10 -10 -10 2
0 0 0 1

**/



