
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
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
const int MAX=20;

int n,m,dis[MAX][MAX],deg[MAX];
int dp[(1<<15)+2];


int rec(int mask)
{
    if(mask==(1<<n)-1) return 0;
    int &ret=dp[mask];
    if(ret!=-1) return ret;

    ret=INF;
    for(int i=0;i<n;i++)
    {
        if(!(mask&(1<<i)))
        {
            for(int j=0;j<n ;j++)
            {
                if(!(mask&(1<<j)) and i!=j)
                {
                    ret=min(ret,rec((mask|(1<<i))|(1<<j))+dis[i][j]);
                }
            }
        }
    }
    return ret;
}


void FloydWarshall()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    return;
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)
        {
            if(i!=j)dis[i][j]=INF;
            else dis[i][j]=0;
        }
        mem(deg,0);
        int ans=0;
        for(int i=0,u,v,c;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            u--;v--;
            dis[u][v]=dis[v][u]= min(dis[u][v],min(dis[v][u],c));
            deg[u]++;deg[v]++;
            ans+=c;
        }

        FloydWarshall();
        int mask=0;
        for(int i=0;i<n;i++)
        {
            if((deg[i]&1)==0) mask|=(1<<i);
        }

        mem(dp,-1);
        ans+=rec(mask);
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}


