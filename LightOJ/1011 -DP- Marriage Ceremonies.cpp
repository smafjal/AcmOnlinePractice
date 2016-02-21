/// Bismillahir Rahmanir Rahim
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

#define mem(a,b)  memset(a,b,sizeof(a))
#define MAX 65538

int N,dp[20][MAX];
int grid[20][20];

int rec(int man,int mask)
{
    int &ret=dp[man][mask];
    if(ret!=-1) return ret;

    ret=0;
    for(int i=0;i<N;i++)
    {
        if((mask & (1<<i))==0) ret=max(ret,rec(man+1,mask|(1<<i))+grid[man][i]);
    }
    return ret;
}


int main()
{
    int cas=0,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++) scanf("%d",&grid[i][j]);
        }
        mem(dp,-1);
        int ans=rec(0,0);
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
