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

#define sz 39999
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

struct node
{
    int nodes;
    int weight;
};

int n;
vector<node>vec[sz];
int col[sz];
int dis[sz];

void dfs(int s,int d1)
{
    int i;
    col[s]=1;
    for(i=0;i<SIZE(vec[s]);i++)
    {
        if(!col[vec[s][i].nodes])
        {
           dis[vec[s][i].nodes]=d1+vec[s][i].weight;
           dfs(vec[s][i].nodes,dis[vec[s][i].nodes]);
        }
    }
    return;
}

int main()
{
    int i,j,k,x,y,w,loop;
    scanf("%d",&loop);
    for(k=1;k<=loop;k++)
    {
        scanf(" %d",&n);
        struct node tmp;
        for(i=0;i<n+10;i++)vec[i].clear();
        mem(col,0);mem(dis,0);

        for(i=1;i<n;i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            tmp.nodes=y;tmp.weight=w;
            vec[x].pb(tmp);tmp.nodes=x;
            vec[y].pb(tmp);
        }

        for(i=0;i<n;i++)
        {
            if(!col[i])
            {
                dis[i]=0;
                dfs(i,dis[i]);
            }
        }
        mem(col,0);
        vector<pair<int,int> >p;

        for(i=0;i<n;i++)p.pb(makp(dis[i],i));
        sort(p.rbegin(),p.rend());
        mem(dis,0);
        for(i=0;i<SIZE(p);i++)
        {
            if(!col[p[i].second])
            {
                dis[p[i].second]=0;
                dfs(p[i].second,dis[p[i].second]);
            }
        }

        int m=0;
        for(i=0;i<n;i++)
        {
            if(dis[i]>m)m=dis[i];
        }
        printf("Case %d: %d\n",k,m);
    }
}
