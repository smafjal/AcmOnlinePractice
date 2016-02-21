#include<stdio.h>
#include<string.h>
#include<math.h>
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

int DP[MAX];int M=100000007;

int main()
{
    int i,j,t,cas=0; int N,K;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&K); mem(DP,0); vector<int>coin,num; int v;

        for(i=1;i<=N;i++){scanf("%d",&v);coin.pb(v);}
        for(i=1;i<=N;i++) {scanf("%d",&v);num.pb(v);}
//        sort(all(coin));

        DP[0]=1;
        for(i=0;i<SZ(coin);i++)
        {
            int val=coin[i];if(val>K) continue;
            int t = num[i];
            for(j = K;j>=0;j--)
            {
                if(DP[j])
                {
                    int cnt=0;
                    int j_val=j;
                    int base=DP[j];
                    while(cnt<t and (val+j_val<=K))
                    {
                        int p=DP[val+j_val]+base;
                        if(p>M) p=p%M;
                        DP[val+j_val]=p;
                        cnt++;
                        j_val=j_val+val;
                    }
                }
            }
        }
        printf("Case %d: %d\n",++cas,DP[K]);
    }
    return 0;
}

