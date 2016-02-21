#include<stdio.h>

int arr[120];
int worke(void)
{
    int i,j,k;
    if(arr[0]>arr[1])k=1;
    else k=0;
    if(k)
    {
        for(i=1;i<10;i++)
        {
            if(arr[i-1]>arr[i])j=1;
            else
            {
                j=0;
                break;
            }
        }
    }
    else
    {
        for(i=1;i<10;i++)
        {
            if(arr[i-1]<arr[i])j=1;
            else
            {
                j=0;
                break;
            }
        }
    }
    return j;
}
int main()
{
    int i,j,k;
    scanf("%d",&k);
    printf("Lumberjacks:\n");
    while(k--)
    {
        for(i=0;i<10;i++)scanf("%d",&arr[i]);
        i=worke();
        if(i)printf("Ordered\n");
        else printf("Unordered\n");
    }
}
