#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>

#define sz 599
#define ll long long
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))
#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<"  "<<b<<endl
#define print3(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl
#define all(a) a.begin(),a.end()
#define reall(a) a.rbegin(),a.rend()

using namespace std;

ll square(ll n){return n*n;}

ll R_bigmod(ll b,ll p,ll m)
{
    if(p==0)return 1;
    else if(p%2==0) return square(R_bigmod(b,p/2,m))%m;
    else return (b%m)*R_bigmod(b,p-1,m)%m;
}

int main()
{
    ll b,p,m;
    while(scanf("%lld %lld %lld",&b,&p,&m)==3)
    {
        ll ans=R_bigmod(b,p,m);
        printf("%lld\n",ans);
    }
    return 0;
}
