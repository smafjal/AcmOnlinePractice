#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#define sz 100

using namespace std;

typedef struct
{
    int x;
    int y;
    int z;
} tmp;

tmp start,end;
int l,r,c;
int v[sz][sz][sz];
int col[sz][sz][sz];
int dis[sz][sz][sz];
int rrr[]= {-1,0,1,0,0,0};
int ccc[]= {0,1,0,-1,0,0};
int zzz[]= {0,0,0,0,1,-1};

void inti(void)
{
    for(int i=0; i<sz; i++)
    {
        for(int j=0; j<sz; j++)
        {
            for(int k=0; k<sz; k++)
            {
                col[i][j][k]=0;
                dis[i][j][k]=0;
                v[i][j][k]=0;
            }
        }
    }
}

int cheack(int n,int m,int p)
{
    if((n<0 || m<0 || p<0) || (n>l || m>r || p>c))return 0;
    return 1;
}

int bfs(void)
{
    int i,j,k,n,m,p,hight,row,cul,phight,prow,pcul;
    tmp t1,t2;
    queue<tmp>Q;
    dis[start.x][start.y][start.z]=0;
    Q.push(start);
    while(!Q.empty())
    {
        t1=Q.front();
        Q.pop();
        col[t1.x][t1.y][t1.z]=1;
        prow=t1.x;
        pcul=t1.y;
        phight=t1.z;
        for(i=0;i<6;i++)
        {
            row=prow+rrr[i];
            cul=pcul+ccc[i];
            hight=phight+zzz[i];
            if(cheack(row,cul,hight))
            {
                if(v[row][cul][hight]==-2)return dis[prow][pcul][phight]+1;
                if(!col[row][cul][hight] && v[row][cul][hight])
                {
                    t2.x=row;
                    t2.y=cul;
                    t2.z=hight;
                    Q.push(t2);
                    col[row][cul][hight]=1;
                    dis[row][cul][hight]=dis[prow][pcul][phight]+1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    char p;
    while(scanf("%d %d %d",&l,&r,&c)==3)
    {
        if(!l && !r && !c)break ;
        for(int i=0; i<l; i++)
        {
            for(int j=0; j<r; j++)
            {
                for(int k=0; k<c; k++)
                {
                    scanf(" %c",&p);
                    if(p=='S')
                    {
                        start.x=i;
                        start.y=j;
                        start.z=k;
                        v[i][j][k]=-1;
                    }
                    else if(p=='#')v[i][j][k]=0;
                    else if(p=='.')v[i][j][k]=1;
                    else if(p=='E')
                    {
                        end.x=i;
                        end.y=j;
                        end.z=k;
                        v[i][j][k]=-2;
                    }
                }
            }
        }
        int ans=bfs();
        if(!ans)printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",ans);
        inti();
    }
    return 0;
}
