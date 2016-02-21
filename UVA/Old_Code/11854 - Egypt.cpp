#include<stdio.h>

int main()
{
    int a,b,c,k;
    int max,p,q;
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        if(!a && !b && !c)break;
        if(a>b && a>c)
        {
            max=a;
            p=b;
            q=c;
        }
        else if(b>a && b>c)
        {
            max=b;
            p=a;
            q=c;
        }
        else if(c>a && c>b)
        {
            max=c;
            p=b;
            q=a;
        }
        if(p*p + q*q==max*max)printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}
