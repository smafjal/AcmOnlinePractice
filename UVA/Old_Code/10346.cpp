#include<stdio.h>

int main()
{
    int n,k,x,j,sum;
    while(scanf("%d %d", &n,&k)==2)
    {
        sum=n;
        while(n>=k)
        {
            j=n/k;
            sum+=j;
            x=n%k;
            n=x+j;
        }
        printf("%d\n",sum);
    }
    return 0;
}
