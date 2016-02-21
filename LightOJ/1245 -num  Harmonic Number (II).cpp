#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<algorithm>
#include<sstream>

using namespace std;

#define pi (2*cos(0))
#define ll long long
#define CUBE(X) (X*X*X)
#define rep(i,n) for(i=0;i<(n);i++)
#define rep1(i,a,n) for(i=a;i<=(n);i++)
#define oo 1<<29
#define pb push_back
#define popb pop_back
#define mp make_pair
#define mem(a,b)  mamset(a,b,sizeof(a))
#define SZ(a)  (int)a.size()
#define fs first
#define sc second
#define contain(x,item) (x).find(item)!=(x).end()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbigin(),(a).rend()

int main()
{
    ll i,j,k,n,t;
    scanf("%lld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%lld",&n);
        if(n==1){printf("Case %lld: %lld\n",k,(ll)1);continue;}
        if(n==2){printf("Case %lld: %lld\n",k,(ll)3);continue;}
        ll start,tmp,end=n,val,ans=0;
        val =sqrt(n);
        for(i=1;i<=val;i++)
        {
            ans+=n/i;
            tmp=n/(i+1);
            if(tmp<i)tmp=i;
            ans+=((end-tmp)*i);
            end=tmp;
        }
        printf("Case %lld: %lld\n",k,ans);
    }
    return 0;
}

