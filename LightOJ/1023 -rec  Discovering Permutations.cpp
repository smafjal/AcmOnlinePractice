#include<stdio.h>
#include<iostream>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int n,k;int tmp;
int dp[200];

void permotation(int cur)
{
    if(cur==n)
    {
        if(tmp==k)return;
        for(int i=0;i<n;i++)
        {
            printf("%c",dp[i]+'A');
        }
        printf("\n");
        tmp++;
        return;
    }

    int i,j;
    for(i=0;i<n;i++)
    {
        if(tmp==k)return;
        for(j=0;j<cur;j++)if(dp[j]==i)break;
        if(j==cur)
        {
            dp[cur]=i;
            permotation(cur+1);
        }
    }
}

int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        tmp=0;
        printf("Case %d:\n",++cas);
        permotation(0);
        mem(dp,0);
    }
    return 0;
}
