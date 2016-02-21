#include<stdio.h>
#define sz 146550  /**1000009*/
#include<math.h>
#define ll long long

ll prime[sz];
bool num[sz];
int c;

void sive(void)
{
    int i,j,r;
    c=1;
    prime[c]=2;
    num[0]=num[1]=1;
    for(i=3; i<=sz; i+=2)
    {
        if(!num[i])
        {
            prime[++c]=i;
            r=i*2;
            if(i<=sz/i)for(j=i*i; j<=sz; j+=r)num[j]=1;
        }
    }
}

int main()
{
    sive();
    int i,j,k;
    ll n1,n2;
    ll arr[100000];

    while(scanf("%lld",&n1)==1)
    {
        if(n1==0)break;
        k=0;
        if(n1<0)n2=-n1;
        else n2=n1;

        for(i=1;prime[i]<=sqrt(n2);)
        {
            if(n2%prime[i]==0)
            {
                arr[k++]=prime[i];
                n2=n2/prime[i];
            }
            else i++;
        }
        arr[k]=n2;

        if(n1<0)
        {
            printf("%lld = ",n1);
            for(i=0; i<=k; i++)
            {
                if(i==0)
                {
                    printf("-1");
                }
                printf(" x");
                printf(" %lld",arr[i]);
            }
            printf("\n");
        }

        else
        {
            printf("%lld = ",n1);
            for(i=0; i<=k; i++)
            {
                if(i==0)
                {
                    printf("%lld",arr[i]);
                }
                else printf(" x %lld",arr[i]);
            }
            printf("\n");

        }
    }
    return 0;
}
