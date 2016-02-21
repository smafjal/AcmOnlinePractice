
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

#define sz 1000002
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
int arr[sz];

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
}

int cheack(int n)
{
    int i;
    if(n==1)return 0;
    if(n==2)return 1;
    if((n%2) && !flag[n])return 1;
    for(i=2;i<=n;i++)
    {
        if((n%i)==0)return arr[n/i]+1;
    }
}

void memo(void)
{
    for(int i=1;i<sz;i++)
    {
        arr[i]=cheack(i);
    }
//    for(int i=1;i<=100;i++)printf("%d   ",arr[i]);
}

void sum_all(void)
{
    for(int i=2;i<sz;i++)
    {
        arr[i]=arr[i]+arr[i-1];
    }
    return;
}
int main()
{
    int i,j,k,n;
    sive();
    memo();
    sum_all();

    while(scanf("%d",&n)==1)
    {
        int ans=0;
        printf("%d\n",arr[n]);
    }
    return 0;
}
