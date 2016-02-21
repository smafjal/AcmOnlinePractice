#include<stdio.h>
#include<iostream>
#include<vector>

#define MAX 120

using namespace std;

int dp[MAX];
bool col[MAX];
vector<int>res;
int mx,ans,total;
int track_num,track_long;

void CD(int cur)
{
    if(cur==track_num)
    {
        int sum=0;
        for(int i=0;i<track_num;i++)
        {
            if(col[i])sum+=dp[i];
        }
        int mi=min(mx,(total-sum));

        if(sum<=track_long && mi<mx)
        {
            res.clear();
            for(int i=0;i<track_num;i++)
            {
                if(col[i]) res.push_back(dp[i]);
            }
            ans=sum;
            mx=mi;
        }
        return;
    }
    col[cur]=1;
    CD(cur+1);
    col[cur]=0;
    CD(cur+1);
}

void print()
{
    int i,j,k;
    for(i=0;i<res.size();i++)
    {
        if(i) printf(" %d",res[i]);
        else printf("%d",res[i]);
    }
    printf(" sum:%d\n",ans);
}

int main()
{
    int i,j;
    while(scanf("%d",&track_long)==1)
    {
        scanf("%d",&track_num);total=0;
        for(i=0;i<track_num;i++) {scanf("%d",&dp[i]);total+=dp[i];}
        mx=1<<25;
        CD(0);
        print();
    }
    return 0;
}
