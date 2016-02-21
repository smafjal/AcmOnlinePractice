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

#define sz 200000000
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

int main()
{
    ll i,j,k,n;
    while(scanf(" %lld",&n)==1)
    {
        if(!n)break;
        if(n<0)n=(-1)*n;

        vector<ll>v;
        ll val=sqrt(n);

        for(i=2;i<=val;)
        {
            if(n%i==0)
            {
                v.pb(i);
                n/=i;
            }
            else i++;
        }
        if(n>1)v.pb(n);
        if(SIZE(v)==0){printf("-1\n");continue;}
        ll max_ans=v[0];
        int count=0;
        for(i=0;i<SIZE(v);i++)
        {
            if(v[0]==v[i])count++;
            if(max_ans<v[i])max_ans=v[i];
        }
        if(SIZE(v)==count)printf("-1\n");
        else printf("%lld\n",max_ans);
    }
    return 0;
}

