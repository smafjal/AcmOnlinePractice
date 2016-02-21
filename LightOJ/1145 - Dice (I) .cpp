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
const int MAX= 15009;

int N,K,S;
int dp[2][MAX];
int Mod=100000007;

int rec(int n,int s)
{
    if(n==0) return (s==0);
    if(s<0) return 0;
    return dp[n&1][s];
}

int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&N,&K,&S);
        for(int n=1;n<=N;n++)
        {
            for(int s=0;s<=S;s++)
            {
                int &ret=dp[n&1][s];
                ret=(rec(n-1,s-1)+rec(n,s-1)-rec(n-1,s-K-1)+Mod)%Mod;
            }
        }
        printf("Case %d: %d\n",++cas,rec(N,S));
    }
    return 0;
}



