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

#define sz 2097152
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

// 2097150
using namespace std;

double arr[sz];

void digite(void)
{
    ll i;
    arr[1]=log(1);
    for(i=2;i<sz;i++)
    {
        arr[i]=arr[i-1]+log(i);
    }
//    for(i=1;i<50;i++)printf("%lf   ",arr[i]);
    return;
}

int main()
{
    digite();
    ll n,b,noz,dig,j,p,c,k;

    while(scanf("%lld %lld",&n,&b)==2)
    {
        noz=n;
        j=b;
        for(ll i=2;i<=b;i++)
        {
            if(j%i==0)
            {
                p=0;
                while(j%i==0)
                {
                    p++;
                    j/=i;
                }
                c=0;
                k=n;
                while(k/i>0)
                {
                    c+=k/i;
                    k/=i;
                }
                noz=min(noz,c/p);
            }
        }
        double ans=arr[n];
        ans=ans/log(b);ans=ans+1.0;
        ans=floor(ans);
        printf("%lld %.0lf\n",noz,ans);
    }
    return 0;
}

