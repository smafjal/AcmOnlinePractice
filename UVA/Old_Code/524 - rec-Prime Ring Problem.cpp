#include<stdio.h>
#include<string.h>
#include<math.h>

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

#define MAX 200

bool flag[MAX];
bool col[MAX];
int res[MAX];

bool Prime_cheack(int n)
{
    if(n==2)return 1;
    if((n%2) && !flag[n]) return 1;
    return 0;
}

void sive()
{
    int i,j,k,r,total=1;
    flag[0]=flag[1]=1;
    for(i=3;i<MAX;i+=2)
    {
        if(!flag[i])
        {
            r=i*2;
            if(MAX/i>=i)for(j=i*i;j<MAX;j+=r)flag[j]=1;
        }
    }
    return;
}

void rec(int n,int dep)
{
    int i;
    if(dep==n+1)
    {
        if(Prime_cheack(1+res[dep-1]))
        {
            for(i=1;i<=dep-1;i++)if(i!=1)printf(" %d",res[i]);else printf("%d",res[i]);
            printf("\n");
        }
        return;
    }
    for(i=2;i<=n;i++)
    {
        if(col[i]==0)
        {
            if(Prime_cheack(res[dep-1]+i))
            {
                res[dep]=i;
                col[i]=true;
                rec(n,dep+1);
                col[i]=false;
            }
        }
    }
}
int main()
{
    sive();
    int i,j,k,n;bool fl=0;int cas=0;
    while(scanf("%d",&n)==1)
    {
        if(fl)printf("\n");fl=1;
        printf("Case %d:\n",++cas);
        res[1]=1;
        rec(n,2);
    }
    return 0;
}
