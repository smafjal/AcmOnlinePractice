#include<stdio.h>
#define sz 1000005

int dprime[sz+1];
bool num[sz+1];
int p[sz+1];

void dchack(int n)
{
    int k,d;
    k=n;d=0;
    while(n)
    {
        d+=(n%10);
        n/=10;
    }
    if(d==2)dprime[k]=1;
    else if(d%2)
    {
        if(!num[d])dprime[k]=1;
    }
}
void sive(void)
{
    int i,j,k,r;
    num[0]=num[1]=1;
    dprime[0]=dprime[1]=0;
    dprime[2]=1;
    for(i=3;i<sz;i+=2)
    {
        if(!num[i])
        {
            dchack(i);
            r=2*i;
            if(i<sz/i)for(j=i*i;j<sz;j+=r)num[j]=1;
        }
    }
    int in=0;
    p[0]=p[1]=0;
    for(i=2;i<=sz;i++)
    {
        if(dprime[i])
        {
            in++;
            p[i]=in;
        }
        else p[i]=in;
    }
}

int main()
{
    sive();
    int n,n1,n2,sum;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
        scanf("%d %d",&n1,&n2);
        if((p[n1-1]==p[n1]))sum =0;
        else sum=1;
        sum+=p[n2]-p[n1];

        printf("%d\n",sum);
    }
    return 0;
}
