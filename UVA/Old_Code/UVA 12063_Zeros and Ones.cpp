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

int N,K;
ll dp[80][40][113];

ll rec(int cur,int one,ll mod)
{
//    cout<<cur<<" "<<one<<" "<<mod<<endl;lookalike;

    if(N%2 or one>N/2) return (ll)0;
    if(cur<0)
    {
        if(one==N/2 and mod==0)return (ll)1;
        return (ll)0;
    }

    ll &ret=dp[cur][one][mod];
    if(ret!=-1) return ret;

    ret=0;
    ret=rec(cur-1,one+1,((mod+((ll)(1LL<<cur)))%K)%K);
    ret+=(ll)rec(cur-1,one,mod);
    return ret;
}

int main()
{
    int cas=0;int t;cin>>t;
    while(t--)
    {
        scanf("%d %d",&N,&K);
        ll ans;
        if(K)
        {
            mem(dp,-1);
            ans=rec(N-2,1,((ll)((1LL<<(N-1)))) % K);
        }
        else ans=0;
        printf("Case %d: ",++cas);cout<<ans<<endl;
    }
    return 0;
}


