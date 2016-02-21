#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SZ(a) (int)a.size()
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;

#define MAX 10001
ll DP[MAX];int M=100000007;

int main()
{
    int i,j,t,N,K,v,cas=0; ll p;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&N,&K); mem(DP,0);vector<int>coin;
        for(i=1;i<=N;i++) {scanf("%d",&v);coin.pb(v);} sort(all(coin));

        DP[0]=1;
        for(i=0;i<N;i++)
        {
            int val=coin[i]; if(val>K)continue;
            for(j=0;j<=K-val;j++)
            {
                if(DP[j])
                {
                    if(val+j<=K)
                    {
                        p=DP[val+j]+DP[j];
                        if(p>M) p=p-(p/M)*M;  //p%M;
                        DP[val+j]=p;
                    }
                }
            }
        }
        printf("Case %d: %lld\n",++cas,DP[K]%M);
    }
    return 0;
}
