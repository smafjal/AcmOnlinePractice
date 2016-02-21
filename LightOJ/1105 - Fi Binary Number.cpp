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
const int MAX=100;

int M=1000000000;
int dp[MAX][2];
int V[MAX];

int rec(int len,int pre)
{
    if(len==0) return 1;
    int &ret=dp[len][pre];
    if(ret!=-1) return ret;

    ret=0;
    if(pre==1) ret+=rec(len-1,0);
    else
    {
        ret+=rec(len-1,0);
        ret+=rec(len-1,1);
    }
    return ret;
}

void sol(int len,int pre,int n)
{
    if(len==0) return;
    if(pre==1)
    {
        printf("0");
        sol(len-1,0,n);
    }
    else
    {
        int ret=rec(len-1,0);
        if(n<=ret)
        {
            printf("0");
            sol(len-1,0,n);
        }
        else
        {
            printf("1");
            sol(len-1,1,n-ret);
        }
    }
    return;
}

int main()
{
    mem(dp,-1);
    int cnt=0;
    for(int len=1;;len++)
    {
        V[len]=rec(len-1,1);
        cnt+=V[len];
        if(cnt>M) break;
    }

    int t,cas=0,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: ",++cas);
        for(int len=1;;len++)
        {
            if(V[len]>=n)
            {
                printf("1");
                sol(len-1,1,n);
                break;
            }
            n-=V[len];
        }
        puts("");
    }
    return 0;
}

