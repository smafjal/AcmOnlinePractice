#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>

#define sz 100099
#define pb(a) push_back(a)

using namespace std;

bool col[sz];
vector<int>vec[sz];
int n,e;

void dfs(int s)
{
    col[s]=1;
    for(int i=0;i<vec[s].size();i++)
    {
        if(!col[vec[s][i]])dfs(vec[s][i]);
    }
    return;
}

int main()
{
    int i,j,k,loop,x,y;
    scanf("%d",&loop);
    for(k=1;k<=loop;k++)
    {
        scanf("%d %d",&n,&e);

        vector<int>li;
        for(i=0;i<=n+10;i++){col[i]=0;vec[i].clear();}

        for(i=0;i<e;i++)
        {
            scanf("%d %d", &x ,&y);
            vec[x].pb(y);
        }
        for(i=1;i<=n;i++)
        {
            if(!col[i])
            {
                li.push_back(i);
                dfs(i);
            }
        }

        for(i=0;i<=n+10;i++)col[i]=0;
        int m=0;

        for(i=(int)li.size()-1;i>=0;i--)
        {

            if(!col[li[i]])
            {
                m++;
                dfs(li[i]);
            }
        }
        printf("Case %d: %d\n",k,m);
    }
    return 0;
}
