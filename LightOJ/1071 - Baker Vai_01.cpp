///Bismillahir Rahmanir Rahim
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define pb push_back
#define mem(a,b)  memset(a,b,sizeof(a))
#define SZ(a)  (int)a.size()

using namespace std;

#define MAX 102

int dp[MAX][MAX][203];
int grid[MAX][MAX];
int R,C;

int rec(int x1,int x2,int t)
{
    int y1=t-x1;
    int y2=t-x2;
    if(x1==R or y1==C) return 0;
    if(x2==R or y2==C) return 0;

    int &ret=dp[x1][x2][t];
    if(ret!=-1) return ret;
    ret=0;

    int k=((x1!=x2 and y1!=y2)?grid[x1][y1]+grid[x2][y2]:grid[x1][y1]);

    ret=max(ret,rec(x1,x2,t+1)+k);
    ret=max(ret,rec(x1+1,x2,t+1)+k);
    ret=max(ret,rec(x1,x2+1,t+1)+k);
    ret=max(ret,rec(x1+1,x2+1,t+1)+k);
    return ret;
}

int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        cin>>R>>C;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)cin>>grid[i][j];
        }
        mem(dp,-1);
        int ans=rec(0,0,0);
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}

