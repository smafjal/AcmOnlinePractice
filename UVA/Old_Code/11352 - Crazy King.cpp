#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
#define sz 110

using namespace std;

typedef struct
{
    int r;
    int c;
}tmp;

int row,cul;
int v[sz][sz];
tmp start,end,t1;
queue<tmp>Q;
int col[sz][sz];
int rrr[]={-1,1,2,2,1,-1,-2,-2};
int ccc[]={2,2,1,-1,-2,-2,-1,1};
int r1[]={-1,0,1,0,-1,1,1,-1};
int c1[]={0,1,0,-1,1,1,-1,-1};
int dis[sz][sz];


int ch(int r,int c)
{
    if(r<0 || c<0 || r>row-1 || c>cul-1) return 1;
    return 0;
}

void bfs(void)
{
    int i,j,k,pr,pc,r,c;
    while(!Q.empty())
    {
        t1=Q.front();Q.pop();
        r=t1.r;
        c=t1.c;
        for(i=0;i<8;i++)
        {
            pr=r+rrr[i];
            pc=c+ccc[i];
            if(!ch(pr,pc) && v[pr][pc]!=-2)
            {
                v[pr][pc]=1;
            }
        }
    }
}

void bfs_2(void)
{
    int i,j,k;
    int r,c,pr,pc;
    queue<tmp>q;
    q.push(start);
    dis[start.r][start.c]=0;
    while(!q.empty())
    {
        t1=q.front();q.pop();
        r=t1.r;
        c=t1.c;
        col[r][c]=1;
        for(i=0;i<8;i++)
        {
            pr=r+r1[i];
            pc=c+c1[i];
            if(!ch(pr,pc))
            {
                if((v[pr][pc]==-2 || !v[pr][pc]) && !col[pr][pc])
                {
                    t1.r=pr;
                    t1.c=pc;
                    q.push(t1);
                    col[pr][pc]=1;
                    dis[pr][pc]=dis[r][c]+1;
                }
            }
        }
    }

}

void inti(void)
{
    for(int i=0;i<row;i++)
    {

        for(int j=0;j<cul;j++)
        {
            col[i][j]=0;
            dis[i][j]=0;
            v[i][j]=0;
        }
    }
    while(!Q.empty())Q.pop();
}
int main()
{
    int i,j,k;
    int n,m;
    char c;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d %d",&row,&cul);
        for(i=0;i<row;i++)
        {
            for(j=0;j<cul;j++)
            {
                scanf(" %c",&c);
                if(c=='A')
                {
                    start.r=i;
                    start.c=j;
                    v[i][j]=-2;
                }
                else if(c=='B')
                {
                    end.r=i;
                    end.c=j;
                    v[i][j]=-2;
                }
                else if(c=='Z')
                {
                    t1.r=i;
                    t1.c=j;
                    Q.push(t1);
                    v[i][j]=1;
                }
                else v[i][j]=0;
            }
        }
        bfs();
        bfs_2();
        i=end.r;
        j=end.c;
        int m=dis[i][j];
        if(m)printf("Minimal possible length of a trip is %d\n",m);
        else printf("King Peter, you can't go now!\n");
        inti();
    }
    return 0;
}
