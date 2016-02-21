/*
    if(n>=4) we can expres that p1+p2=n where p1 && p2 is prime Number & p1<=p2;
    and we have p1<=n/2.
    To solve this problem  we nead to find the pairs(i,n-i) where 2<=i<=n/2
*/

#include<stdio.h>
#include<iostream>
#include<math.h>

#define MAX 10000009
#define MAX_N 700000
using namespace std;

bool flag[MAX];
int prime[MAX_N];

void sive()
{
    int i,j,k,r,total=1;
    flag[0]=flag[1]=1;
    prime[total]=2;

    for(i=3;i<MAX;i+=2)
    {
        if(!flag[i])
        {
            prime[++total]=i;
            r=i*2;
            if(MAX/i>=i)for(j=i*i;j<MAX;j+=r)flag[j]=1;
        }
    }
//    printf("%d\n",total);
    return;
}

bool ch(int n)
{
    if(n==2)return 1;
    if((n%2) && (!flag[n]))return 1;
    return 0;
}

int Goldbach_conjecture(int n)
{
    int count=0,i;

    for(i=1;prime[i]<=n/2;i++)
    {
        if(ch(n-prime[i])) count++;
    }
    return count;
}

int main()
{
    sive();
    int i,j,k;int n;
    int t,cas=0;
    scanf("%d",&t);

    while(t--)
    {
       scanf("%d",&n);
       int ans = Goldbach_conjecture(n);
       printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
