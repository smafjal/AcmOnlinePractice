#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#define sz 100

using namespace std;

struct asd
{
    int r;
    int c;
};

typedef asd tmp;

tmp t1;
int row;
int v[sz][sz];
int col[sz][sz];
int rrr[]={0,-1,-1,-1,0,1,1,1};
int ccc[]={1,1,0,-1,-1,-1,0,1};

int cheack(int r,int c)
{
    if(r<1 || c<1 || r>row || c>row)return 1;
    return 0;
}

void bfs(void)
{
    int i,j,k,r1,c1,r2,c2;
    tmp t2;
    queue<tmp>Q;
    Q.push(t1);
    while(!Q.empty())
    {
        t2=Q.front();Q.pop();
        r1=t2.r;
        c1=t2.c;
        col[r1][c1]=1;
        v[r1][c1]=0;
        for(i=0;i<8;i++)
        {
            r2=r1+rrr[i];
            c2=c1+ccc[i];
            if(!cheack(r2,c2))
            {
                if(v[r2][c2] && !col[r2][c2])
                {
                    t2.r=r2;
                    t2.c=c2;
                    Q.push(t2);
                    col[r2][c2]=1;
                }
            }
        }
    }
}

void  maincheack(void)
{
    int i,j,fl=1;
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=row;j++)
        {
            if(v[i][j])
            {
                t1.r=i;
                t1.c=j;
                fl=0;
                break;
            }
        }
        if(!fl)break;
    }
}

void finalinti(void)
{
    for(int i=1;i<sz;i++)
    {
        for(int j=1;j<sz;j++)
        {
            col[i][j]=0;
            v[i][j]=0;
        }
    }
    t1.r=0;t1.c=0;
}


int main()
{
    int i,j,k,m,n;
    char c;
    k=1;
    while(scanf("%d",&row)==1)
    {
        t1.r=0;t1.c=0;
        for(i=1;i<=row;i++)
        {
            for(j=1;j<=row;j++)
            {
                scanf(" %c",&c);
                if(c=='1'){v[i][j]=1;t1.r=i;t1.c=j;}
                else if(c=='0')v[i][j]=0;
            }
        }
        m=0;
        while(t1.r && t1.c)
        {
            bfs();
            t1.r=0;t1.c=0;
            maincheack();
            m++;
        }
        printf("Image number %d contains %d war eagles.\n",k,m);
        k++;
        finalinti();
    }
    return 0;
}
