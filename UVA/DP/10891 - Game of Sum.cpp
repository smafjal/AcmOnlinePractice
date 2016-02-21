#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<vector>
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
#define FOREACH(it,x)for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
#define fs          first
#define sc          second
#define mem(a,b)    memset(a,b,sizeof(a))

#define oo          1<<30
#define ERR         1e-7
#define lookalike   scanf("%*d")

using namespace std;

typedef long long ll;
template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction

#define MAX 3200000000


int dp[101][101];int N;
int arr[101],sum[101];

int get(int i,int j)
{
    return (sum[j]-sum[i]+arr[i]);
}

int rec(int l,int r)
{
    if(l>r) return 0;
    int &ret=dp[l][r];
    if(ret!=-1) return ret;
    ret=-oo;
    for(int i=l;i<=r;i++)
    {
        ret=max(ret,get(l,i)-rec(i+1,r));
    }
    for(int i=r;i>=l;i--)
    {
        ret=max(ret,get(i,r)-rec(l,i-1));
    }
    return ret;
}


int main()
{
    int x;
    while(cin>>N and N)
    {
        FOR(i,0,N) scanf("%d",arr+i);
        sum[0]=arr[0];
        FOR(i,1,N) sum[i]=sum[i-1]+arr[i];
        mem(dp,-1);
        int cnt=rec(0,N-1);
        cout<<cnt<<endl;
    }
    return 0;
}

