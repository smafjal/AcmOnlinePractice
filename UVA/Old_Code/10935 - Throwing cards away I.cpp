#include<stdio.h>
#define sz 600

int queue[sz];
int f=1;int r;
int check(void)
{
    if(r==f)return 1;
    return 0;
}
int pop()
{
    int p;
    p=queue[f];
    f++;
    return p;
}
void pushintial(int i)
{
    queue[1]=1;
}

void push(int i)
{
    queue[++r]=i;
}

int main()
{
    int i,j,n;
    int arr[sz];
    int k;
    while(scanf("%d",&n)==1)
    {
        if(!n)break;
        if(n==1)
        {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
            continue;
        }
        r=n;
        for(i=1;i<=n;i++)queue[i]=i;
        k=0;
        while(!check())
        {
            arr[k++]=pop();
            push(pop());
        }
        for(i=0;i<k;i++)
        {
            if(i==0)
            {
                printf("Discarded cards: 1");

                continue;
            }
            printf(",");
            printf(" %d",arr[i]);
        }
        printf("\n");
        printf("Remaining card: %d\n",queue[r]);
        f=1;
    }
    return 0;
}
