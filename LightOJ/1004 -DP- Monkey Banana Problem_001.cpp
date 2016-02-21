#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

#define pb push_bach
#define SZ(a) (int)a.size()
#define MAX 209
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int res[MAX][MAX]; int N;
vector<int>dp[MAX];

int main()
{
    int i,j,k,t,cas=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&N);
        int first;



        bool fl=1;
        for(i=1;i<=N;i++)
        {
            dp[i].clear();
            for(j=1;j<=i;j++)
            {
                scanf("%d",&k);
                if(fl){first=k;fl=0;}
                dp[i].push_back(k);
                res[i][j-1]=0;
            }
        }

        int p=N-1;
        for(i=N+1;i<=(2*N-1);i++)
        {
            dp[i].clear();
            for(j=1;j<=p;j++) {scanf("%d",&k); dp[i].push_back(k);res[i][j-1]=0;} p--;
        }
        res[1][0]=first;

        int limit=(2*N-1)-1;

        for(i=1;i<N;i++)
        {
            for(j=0;j<SZ(dp[i]);j++)
            {
                if(j)
                {
                    int val=res[i][j];
                    res[i+1][j]=max(res[i+1][j],val+dp[i+1][j]);
                    res[i+1][j+1]=max(res[i+1][j+1],val+dp[i+1][j+1]);
                }
                else
                {
                    int val=res[i][j];
                    res[i+1][j]=val+dp[i+1][j];
                    res[i+1][j+1]=val+dp[i+1][j+1];
                }
            }
        }

        for(i=N;i<=limit;i++)
        {
            for(j=0;j<SZ(dp[i]);j++)
            {
                if(j==SZ(dp[i])-1)
                {
                    int val=res[i][j];
                    res[i+1][j-1]=max(res[i+1][j-1],val+dp[i+1][j-1]);
                }

                else if(j)
                {
                    int val=res[i][j];
                    res[i+1][j-1]=max(res[i+1][j-1],val+dp[i+1][j-1]);
                    res[i+1][j]=max(res[i+1][j],val+dp[i+1][j]);
                }

                else
                {
                    int val=res[i][j];
                    res[i+1][j]=max(val+dp[i+1][j],res[i+1][j]);
                }
            }
        }
        printf("Case %d: %d\n",++cas,res[2*N-1][0]);
    }
    return 0;
}
