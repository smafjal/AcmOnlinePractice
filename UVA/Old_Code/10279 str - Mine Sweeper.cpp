#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>

#define sz 599
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))
#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<"  "<<b<<endl
#define print3(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl
#define all(a) a.begin(),a.end()
#define reall(a) a.rbegin(),a.rend()


using namespace std;

struct tmp
{
    int r;int c;
};

struct tmp t1;
int m=0;
int row;
int v[sz][sz];
int col[sz][sz];
char vec[sz][sz];
int rrr[]={0,-1,-1,-1,0,1,1,1};
int ccc[]={1,1,0,-1,-1,-1,0,1};

void inti(void)
{
    for(int i=0;i<=row+5;i++)
    {
        for(int j=0;j<=row+5;j++)
        {
            v[i][j]=0;
            col[i][j]=0;
            vec[i][j]=0;
        }
    }
    m=0;
}

int cheack(int r,int c)
{
    if(r<1 || c<1 || r>row || c>row)return 1;
    return 0;
}

void bfs(void)
{
    int i,j,k;
    int prow,pcul,r,c;
    tmp t2;
    queue<tmp>Q;
    Q.push(t1);
    while(!Q.empty())
    {
        t2=Q.front();Q.pop();
        prow=t2.r;
        pcul=t2.c;
        for(i=0;i<8;i++)
        {
            r=prow+rrr[i];
            c=pcul+ccc[i];
            if(!cheack(r,c))
            {
                if(v[r][c]!=-2)
                {
                    v[r][c]++;
                }
            }
        }
        col[prow][pcul]=0;
    }
}

void maincheack(void)
{
    int i,j,k,fl=1;
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=row;j++)
        {
            if(col[i][j]==-2)
            {
                t1.r=i;
                t1.c=j;
                fl==0;
                break;
            }
        }
        if(!fl)break;
    }
}

void ch_view(bool p)
{
    int i,j;
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=row;j++)
        {
            if(p)
            {
                if(v[i][j]==-2)printf("*");
                else if(vec[i][j]=='x')printf("%d",v[i][j]);
                else printf(".");
            }
            else
            {
                if(v[i][j]!=-2 && vec[i][j]=='x')printf("%d",v[i][j]);
                else printf(".");
            }
        }
        printf("\n");
    }
}
bool ch(void)
{
    int i,j,k;
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=row;j++)
        {
            if(v[i][j]==-2 && vec[i][j]=='x')return 1;
        }
    }
    return 0;
}

int main()
{
    int i,j,k,loop;
    int fl=0;char c;

    scanf(" %d ",&loop);
    for(k=1;k<=loop;k++)
    {
        scanf(" %d ",&row);
        inti();

        t1.r=0;t1.c=0;
        for(i=1;i<=row;i++)
        {
            for(j=1;j<=row;j++)
            {
                scanf(" %c",&c);
                if(c=='*'){v[i][j]=-2;t1.r=i;t1.c=j;col[i][j]=-2;}
                else if(c=='.')v[i][j]=0;
            }
        }

        for(i=1;i<=row;i++)
        {
            for(j=1;j<=row;j++)
            {
                scanf(" %c",&c);
                vec[i][j]=c;
            }
        }

        while(t1.r!=0 && t1.c!=0)
        {
            bfs();
            t1.r=0;t1.c=0;
            maincheack();
        }
        bool p=ch();
        if(fl)printf("\n");
        ch_view(p);
        fl=1;
    }
    return 0;
}

