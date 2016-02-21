#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<algorithm>
#include<sstream>
using namespace std;

#define oo          (1<<30)
#define mem(a,b)    memset(a,b,sizeof(a))
#define mp          make_pair
#define pb          push_back
#define clr(a)      a.clear()
#define SZ(a)       (int)a.size()
#define fs          first
#define sc          second
#define mem(a,b)    memset(a,b,sizeof(a))
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> paii;

#define MAX 450

int R,C;
vector<pair<int,int> >store;
int grid[50][50];
int col[409];
int N,par[MAX];
vector<int>adj[MAX];

int dfs(int u)
{
    col[u]=1;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        int v=adj[u][i];
        if(par[v]==-1)
        {
            par[v]=u;
            return 1;
        }
        if(col[par[v]]==0 && dfs(par[v]))
        {
            par[v]=u;
            return 1;
        }
    }
    return 0;
}

int BPM()
{
    int cnt=0;
    mem(par,-1);
    for(int i=0;i<N;i++)
    {
        mem(col,0);
        if(dfs(i)) cnt++;
    }
    return cnt;
}

int main(void)
{
    int t;
    cin>>t;int cas=0;
    while(t--)
    {
        cin>>R>>C;
        clr(store);

        char c;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                scanf(" %c",&c);
                grid[i][j]=c;
                if(grid[i][j]=='*') store.pb(mp(i,j));
            }
        }

        N=SZ(store);
        for(int i=0;i<N+3;i++) clr(adj[i]);

        for(int i=0;i<SZ(store);i++)
        {
            for(int j=0;j<SZ(store);j++)
            {
                if(i==j) continue;
                int d1=abs(store[i].fs-store[j].fs);
                int d2=abs(store[i].sc-store[j].sc);
                if(d1+d2==1) adj[i].pb(j);
            }
        }

        int cnt=BPM();

//        cout<<"Cnt: "<<cnt<<endl;

        int ans=N-cnt/2;
        printf("Case %d: %d\n",++cas,ans);
    }

    return 0;
}
/**

2
7 9
ooo**oooo
**oo*ooo*
o*oo**o**
ooooooooo
*******oo
o*o*oo*oo
*******oo

**/
