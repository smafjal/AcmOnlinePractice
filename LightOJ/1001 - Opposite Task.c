#include<stdio.h>

int main()
{
    int n,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n<10) printf("0 %d\n",n);
        else printf("%d %d\n",10,(n-10));
    }
    return 0;
}
