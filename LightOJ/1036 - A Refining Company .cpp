#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<sstream>

using namespace std;
typedef long long ll;
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
#define SZ(a) (int)a.size()
#define all(a) (a).begin(),(a).end()
#define fs first
#define sc second

const int INF=(1<<29);
const int MAX=509;

int A[MAX][MAX],B[MAX][MAX],dp[MAX][MAX];
int R,C;

int rec(int n,int m)
{
    if(n==-1 || m==-1) return 0;
    int &ret=dp[n][m];
    if(ret!=-1) return ret;

    ret=0;
    ret=max(ret,rec(n,m-1)+B[n][m]);
    ret=max(ret,rec(n-1,m)+A[n][m]);
    return ret;
}

int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&R,&C);
        for(int i=0;i<=R;i++)for(int j=0;j<=C;j++) A[i][j]=0,B[i][j]=0;
        for(int i=0;i<R;i++)for(int j=0;j<C;j++) scanf("%d",&A[i][j]);
        for(int i=0;i<R;i++)for(int j=0;j<C;j++) scanf("%d",&B[i][j]);
        for(int i=0;i<R;i++)for(int j=1;j<C;j++) A[i][j]+=A[i][j-1];
        for(int i=1;i<R;i++)for(int j=0;j<C;j++) B[i][j]+=B[i-1][j];

        mem(dp,-1);
        int ans=rec(R,C);
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}


