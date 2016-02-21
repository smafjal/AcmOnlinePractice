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
    int i,j,k,r,c;
    c=1;
    prime[c]=2;
    flag[0]=flag[1]=1;
    for(i=3;i<sz;i+=2)
    {
        if(!flag[i])
        {
            r=i*2;
            prime[++c]=i;
            if(sz/i>=i)for(j=i*i;j<sz;j+=r)flag[j]=1;
        }
    }
}

int factors_factorial(int n,int num)
{
    int ans=0;
    while(n)
    {
        ans+=(int)(n/num);
        n/=num;
    }
    return ans;
}

int main()
{
    int i,j,k;
    sive();
    while((scanf(" %d",&k)==1) && k)
    {
        int ans,count;
        printf("%3d! =",k);
        int m=1;
        for(i=1;prime[i]<=k;i++)
        {
            ans=factors_factorial(k,prime[i]);
            if(!m){printf("%9d",ans);m=1;}
            else printf("%3d",ans);
            if(i==15)
            {
                printf("\n");
                m=0;
            }
        }
        if(((i-1)%15)!=0)printf("\n");
    }
    return 0;
}
