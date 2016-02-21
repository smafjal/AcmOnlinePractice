#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>

#define sz 190
#define pb(a) push_back(a)

using namespace std;

int e;
int mat[sz][sz];
int col[sz];
int dis[sz];
int count;

void bfs(int s,int tle)
{
    int i,t,k,p,q;
    t=tle;
    col[s]=1;

    queue<int>Q;
    Q.push(s);
    dis[s]=0;

    while(!Q.empty())
    {
        k=Q.front();
        Q.pop();

        for(i=1; i<=count; i++)
        {
            if(!col[i] && mat[k][i])
            {
                if(dis[i]<=t)
                {
                    dis[i]=dis[k]+1;
                    col[i]=1;
                    Q.push(i);
                }
            }
        }
    }
    return;
}

void reset()
{
    int i,j,k;
    for(i=0; i<=count+3; i++)
    {
        dis[i]=0;
        col[i]=0;
        for(j=0; j<=count+3; j++)
        {
            mat[i][j]=0;
        }
    }
    e=0;
    count=0;
}
int result(int t)
{
    int m=0,i;
    for(i=0;i<=count;i++)
    {
        if(dis[i]<=t && dis[i])m++;
    }
    return m;
}

int main()
{
    int i,j,k,x,y,loop,p,q,ca=0;
    while(scanf(" %d",&e)==1)
    {
        if(!e)break;
        map<int,int>m;
        k=0;

        for(i=0; i<e; i++)
        {
            scanf(" %d %d",&x,&y);
            if(!m[x])m[x]=++k;
            if(!m[y])m[y]=++k;

            mat[m[x]][m[y]]=1;
            mat[m[y]][m[x]]=1;
        }
        count=k;
        int start,tle,n,res;
        map<int,int>::iterator it;

        while(scanf(" %d %d",&n,&tle)==2)
        {
            if(!n && !tle)break;
            it= m.find(n);
            start=(*it).second;
            bfs(start,tle);
            res=result(tle)+1;
            ca++;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",ca,count-res,n,tle);
            for(i=0;i<=count+3;i++){col[i]=0;dis[i]=0;}
        }
        reset();
    }
    return 0;
}
