#include<stdio.h>
#include<stdlib.h>
#define sz 59990990

int tail,front,element;
int queue[sz];
int sz1;

int pop()
{
    element--;
    int i=queue[front];
    front++;
    if(front>=sz)front=1;
    return i;
}

void push(int item)
{
    element++;
    tail++;
    if(tail>=sz)tail=1;
    queue[tail]=item;
    return;
}

int jose(int telement,int d)
{
    int i;
    for(i=1;i<=telement;i++)queue[i]=i;
    i=0;
    front=1;
    tail=telement;
    sz1=telement;
    element=telement;

    while(element!=1)
    {
        push(pop());
        pop();
    }
    return queue[front];
}

int main()
{
    int i,m,k,j,n;
    int totalelement;
    scanf("%d",&n);
    int man=1;
    while(n--)
    {
        i=0;
        scanf("%d",&k);
        totalelement=k;
        m=jose(totalelement,1);
        while(m!=totalelement)
        {
            totalelement=m;
            m=jose(m,1);
            i++;
        }
        printf("Case %d:",man);
        printf(" %d %d\n",i,abs(totalelement-tail)+1);
        man++;
    }
    return 0;
}
