#include<stdio.h>

int arr[10];

void worke(int n)
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        k=i;
        while(k)
        {
            j=k%10;
            arr[j]++;
            k/=10;
        }

    }

}
int main()
{
    int n,i,k;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&n);
        worke(n);
        for(i=0;i<=9;i++)
        {
            if(!i) printf("%d",arr[i]);
            else printf(" %d",arr[i]);
        }
        printf("\n");
        for(i=0;i<=9;i++)arr[i]=0;
    }
    return 0;
}
