#include<stdio.h>
#include<string.h>
#define sz 10

int num[sz];
char d1[]="one";
char arr[sz];

int  worke(void)
{
    int j=0,i;
    if(arr[0]=='o')num[0]=1;
    if(arr[1]=='n')num[1]=1;
    if(arr[2]=='e')num[2]=1;
    for(i=0;i<3;i++)
    {
        j+=num[i];
    }
    if(j>=2)return 1;
    else return 0;
}
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf(" %s",arr);
        if(strlen(arr)==5)printf("3\n");
        else
        {
            k=worke();
            if(k)printf("1\n");
            else printf("2\n");
        }
        for(i=0;i<=4;i++)num[i]=0;
    }
    return 0;
}
