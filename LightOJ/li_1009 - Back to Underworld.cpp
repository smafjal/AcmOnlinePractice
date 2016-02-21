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

#define sz 100099
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

vector<int>vec[sz];
bool col[sz];
int dis[2];
int e;

void dfs(int s,int id)
{
    int i;
    col[s]=1;
    dis[id]++;
    for(i=0;i<SIZE(vec[s]);i++)
    {
        if(!col[vec[s][i]])
        {
            dfs(vec[s][i],!id);
        }
    }
    return;
}

int main()
{
    int i,j,k;
    int loop;
    scanf(" %d",&loop);
    for(k=1;k<=loop;k++)
    {
        scanf(" %d",&e);
        set<int>S;
        int x;int y;
        for(i=0;i<sz;i++)vec[i].clear();
        mem(col,0);

        for(i=0;i<e;i++)
        {
            scanf("%d %d",&x,&y);
            vec[x].push_back(y);
            vec[y].pb(x);
            S.insert(x);
            S.insert(y);
        }
        int sum=0;
        dis[1]=dis[0]=0;
        for(set<int>::iterator it=S.begin();it!=S.end();it++)
        {
//            printf("%d\n",*it);
            if(!col[*it])
            {
                dfs(*it,true);
//                printf("%d %d\n",dis[0],dis[1]);
                sum+=(dis[0]>dis[1])?dis[0]:dis[1];
                dis[0]=dis[1]=0;
            }
        }
        printf("Case %d: %d\n",k,sum);
    }
    return 0;
}
