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

#define sz 30000
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int dis[sz];
vector<int>vec[sz];
int n,e;
bool col[sz];

void DFS(int s)
{
    int i;
    col[s]=1;
    dis[s]++;
    for(i=0;i<SIZE(vec[s]);i++)
    {
        if(!col[vec[s][i]])
        {
            DFS(vec[s][i]);
        }
    }
}
int result(int k)
{
    int i,j;
    int count=0;
    for(i=1;i<=n;i++)
    {
        if(dis[i]==k)count++;
    }
    return count;
}
int main()
{
    int i,j,k,loop,x,y,w;
    scanf("%d",&loop);
    for(k=1;k<=loop;k++)
    {
        scanf(" %d %d %d",&w,&n,&e);
        vector<int>v;
        for(i=0;i<=n+10;i++)vec[i].clear();
        mem(dis,0);

        for(i=0;i<w;i++){scanf("%d",&j);v.pb(j);}

        for(i=0;i<e;i++)
        {
            scanf("%d %d",&x,&y);
            vec[x].pb(y);
        }
        for(i=0;i<SIZE(v);i++)
        {
            DFS(v[i]);
            mem(col,0);
        }
        int ans=result(w);
        printf("Case %d: %d\n",k,ans);
    }
    return 0;
}
