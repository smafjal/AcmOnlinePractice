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

#define sz 50009
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

bool flag[sz];
int prime[sz];

void sive()
{
    int i,j,k,r,total=1;
    flag[0]=flag[1]=1;
    prime[total]=2;

    for(i=3;i<sz;i+=2)
    {
        if(!flag[i])
        {
            prime[++total]=i;
            r=i*2;
            if(sz/i>=i)for(j=i*i;j<sz;j+=r)flag[j]=1;
        }
    }
//    print2("Last Prime: ",prime[total]);
//    for(i=1;i<sz;i++)printf(" %d  ",prime[i]);
}

int ch(int i,int x)
{
    if(i==1)return 0;
    if(i==2 && x==2)return 1;
    if(i==2 && (x%2) && !flag[x])return 1;
    if((x%2) && !flag[x] && (i%2) && !flag[i]) return 1;
    return 0;
}
int main()
{
    sive();
    int i,j,k,n;
    while(scanf(" %d",&n)==1)
    {
        if(!n)break;
        k=n/2+1;
//        print1(k);

        int ans=0;int b=0;
        set<pair<int,int> >S;
        for(i=1;i<=k;i++)
        {
            if(i<=n-i)
            {
                b=ch(i,n-i);
                if(b)
                {
//                    print2(i,n-i);
                    ans+=b;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

