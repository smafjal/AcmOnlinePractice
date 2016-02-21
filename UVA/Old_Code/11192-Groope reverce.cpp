#include<stdio.h>
#include<string.h>
#define sz 1000

int main()
{
    int n,k,i,j,l;
    char arr[sz];
    while(scanf("%d",&n)==1)
    {
        if(!n)break;
        scanf(" %s",arr);
        l=strlen(arr);
        k=l/n;
        int p=k;
        int m=0;
        while(n--)
        {
            for(i=k-1;i>=m;i--)
            {
                printf("%c",arr[i]);
            }
            m=k;
            k=p+m;
        }
        printf("\n");
    }
    return 0;
}
