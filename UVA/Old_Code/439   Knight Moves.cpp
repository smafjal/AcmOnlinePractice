#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#define sz 10

using namespace std;

struct asd
{
    int r;
    int c;
};

typedef asd tmp;
tmp start,end;
int v[sz][sz];
int col[sz][sz];
int dis[sz][sz];
int rrr[]={-2,-2,2,2,-1,1,-1,1};
int ccc[]={-1,1,-1,1,2,2,-2,-2};

void inti(void)
{
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<sz;j++)
        {
            col[i][j]=0;
            dis[i][j]=0;
            v[i][j]=0;
        }
    }
}

int cheack(int r,int c)
{
    if(r<1 || c<1 || r>8 || c>8)return 0;
    return 1;
}

int bfs(void)
{
    int i,j,k,prow,pcul,row,cul;
    queue<tmp>Q;
    Q.push(start);
    tmp t1,t2;
    dis[start.r][start.c]=0;
    while(!Q.empty())
    {
        t1=Q.front();
        Q.pop();
        prow=t1.r;
        pcul=t1.c;
        col[prow][pcul]=1;
        for(i=0;i<8;i++)
        {
            row=prow+rrr[i];
            cul=pcul+ccc[i];
            if(cheack(row,cul))
            {
                if(!col[row][cul])
                {
                    t2.r=row;
                    t2.c=cul;
                    Q.push(t2);
                    col[row][cul]=1;
                    dis[row][cul]=dis[prow][pcul]+1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int i,j,k;
    char a[6],b[6];
    char c1,r1,c2,r2;
    int row1,cul1,row2,cul2;
    while(scanf("%s%s",&a,&b)==2)
    {
        cul1=1+a[0]-'a';
        row1=a[1]-'0';
        cul2=1+b[0]-'a';
        row2=b[1]-'0';
        start.r=row1;
        start.c=cul1;
        end.r=row2;
        end.c=cul2;
        v[row2][cul2]=-2;
        int ans=bfs();
        printf("To get from %s to %s takes %d knight moves.\n",a,b,dis[row2][cul2]);
        inti();
    }
    return 0;
}
