#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>


using namespace std;
int col[110];
vector<int>adj[110];
int dag;vector<int>order;

void dfs(int a)
{
    if(col[a]==1) dag=1;
    if(col[a]) return;
    col[a]=1;
    for(int i=0;i<adj[a].size();i++)
    {
        dfs(adj[a][i]);
    }
    col[a]=2;
    order.push_back(a);    /// Store Node in Reverse order.
    return;
}

int main()
{
    int i,j,k;int n,e;int x,y;
    while(scanf("%d %d",&n,&e)==2)
    {
        if(!n && !e) break;
        for(i=1;i<=e;i++)
        {
            scanf("%d %d",&x,&y);
            adj[x].push_back(y);   /// Store node in Directed G.
        }

//        dag=0; /// No cycle.

        for(i=1;i<=n;i++)
        {
            if(!col[i]) dfs(i);
//            if(dag)break;
        }

//        if(dag) {printf("Impossible\n");continue;} /// cycle found
        reverse(order.begin(),order.end());

        for(i=0;i<order.size();i++)
        {
            cout<<order[i]<<" ";
        }

        cout<<endl;
        order.clear();for(i=0;i<n;i++) adj[i].clear();memset(col,0,sizeof(col)); ///reset
    }
    return 0;
}

/**
Input:
5 4
1 2
2 3
1 3
1 5

5 3
1 2
2 3
3 1

output:
4 1 5 3 2
Impossible
**/

