#include<stdio.h>
#include<math.h>
#define ll long long

ll worke(ll n)
{
    ll i,j;
    ll count=0,k;
    k=(ll)sqrt(n);
    for(i=1;i<=k;i++)
    {
        if(n%i==0)
        {
            if(n/i==i)count++;
            else count+=2;
        }
    }
    return count;
}

int main()
{
    ll n,m,i,j,k;
    scanf("%lld",&k);
    while(k--)
    {
        ll max=0,num=0,p;
        scanf("%lld %lld",&n,&m);
        for(i=n;i<=m;i++)
        {
            p=worke(i);
            if(p>max)
            {
                max=p;
                num=i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",n,m,num,max);
    }
    return 0;
}
