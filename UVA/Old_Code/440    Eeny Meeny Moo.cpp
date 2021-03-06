#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define clr(a) a.clear()
#define SZ(a) (int)a.size()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define fs first
#define sc second
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
#define ll long long

#define INF (1<<29)
#define sz 175

int tail,front,element;
int queue[sz];

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
    element=telement;

    if(telement>1)pop();
    while(element!=1)
    {
        if(i!=d)
        {
            i++;
            push(pop());
        }
        else
        {
            pop();
            i=0;
        }
    }
    return queue[front];
}

int main()
{
    int i,m,k;
    int totalelement;
    while(scanf("%d",&k)==1)
    {
        totalelement=k;
        if(!k)break;
        if(k==2)printf("1\n");
        else
        {
            m=1;
            while(jose(totalelement,m++)!=2);
            printf("%d\n",m);
        }
    }
    return 0;
}
