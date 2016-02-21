/*Bismillahir Rahmanir Rahim*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<sstream>

#define all(a) (a).begin(),(a).end()
#define mem(a,b)  memset(a,b,sizeof(a))
#define fs first
#define sc second
#define oo 1<<29
#define ERR 1e-7
#define EQ(a,b)(fabs(a-b)<ERR)
#define mp make_pair
#define pb push_back
#define PI (2*acos(0.0))
#define SZ(a)  (int)a.size()
#define reall(a) (a).rbegin(),(a).rend()
#define lookalike scanf("%*d")

using namespace std;

void BINARY(int n){cout<<"Mask: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef pair<int,int>   pii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDi;

#define MAX 100000

ll dp[22][(1<<16)+2];
int flag[22][(1<<16)+2];
int b;string s;int K,N;
int loop=1;

int take(char c)
{
    if(isdigit(c)) return c-'0';
    return c-'A'+10;
}

ll rec(int mod,int mask)
{
    if(mask==0) return (mod==0);
    ll &ret=dp[mod][mask];
    if(flag[mod][mask]==loop) return ret;
    flag[mod][mask]=loop;

    ret=0;
    for(int i=0;i<N;i++)
    {
        if((mask&(1<<i)))
        {
            int cost=take(s[i]);
            cost=(mod*b)+cost;
            ret+=rec(cost%K,mask^(1<<i));
        }
    }
    return ret;
}

int main()
{
   int cas=0;int t;
   scanf("%d",&t);char arr[20];

   while(t--)
   {
        scanf("%d %d",&b,&K);
        scanf(" %s",arr);
        s=arr;

        N=SZ(s);
        ll ans=0;
        for(int i=0;i<N;i++)
        {
            int cost=take(s[i]);
            ans+=rec(cost%K,((1<<N)-1)^(1<<i));
        }
        printf("Case %d: %lld\n",++cas,ans);
        loop++;
   }
   return 0;
}


