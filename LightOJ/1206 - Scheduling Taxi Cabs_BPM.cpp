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

#define oo          (0x7f7f7f7f)
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

#define MAX 509

struct abc
{
    int Time,x1,x2,y1,y2;
    abc(){;}
    abc(int t,int _x1,int _x2,int _y1,int _y2)
    {
        Time=t;x1=_x1;x2=_x2;y1=_y1;y2=_y2;
    }
};

int M;
vector<abc>store;
vector<int>G[MAX];
int used[MAX],Right[MAX],dfsTime=0;

bool dfs(int u)
{
    if(used[u]==dfsTime) return false;
    used[u]=dfsTime;

    for(int i=0;i<SZ(G[u]);i++)
    {
        int v=G[u][i];
        if(Right[v] ==-1 ||  dfs(Right[v]))
        {
            Right[v]=u;
            return true;
        }
    }
    return false;
}

int BPM()
{
    mem(Right,-1); int cnt=0;
    for(int i=0;i<M;i++)
    {
        if(SZ(G[i]))
        {
            dfsTime++;
            if(dfs(i)) cnt++;
        }
    }

    return M-cnt;
}


int main(void)
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&M);
        int Houre,Minite;clr(store);
        int x1,x2,y1,y2;

        for(int i=0;i<M;i++)
        {
            scanf("%d:%d",&Houre,&Minite);
            scanf("%d %d %d %d",&x1,&x2,&y1,&y2);
            store.pb(abc(Houre*60+Minite,x1,x2,y1,y2));
        }

        for(int i=0;i<=M;i++) clr(G[i]);

        for(int i=0;i<SZ(store);i++)
        {
            int start=store[i].Time+abs(store[i].x1-store[i].y1)+abs(store[i].x2-store[i].y2);
            for(int j=0;j<SZ(store);j++)
            {
                if(i==j) continue;

                int end=abs(store[i].y1-store[j].x1)+abs(store[i].y2-store[j].x2);
                if(start+end<store[j].Time)
                {
                    G[i].pb(j);
                }
            }
        }

        int cnt=BPM();
        printf("Case %d: %d\n",++cas,cnt);
    }

    return 0;
}


/**

12
4
02:00 0 5 5 0
02:11 5 0 10 5
02:23 10 5 15 10
02:35 15 10 20 15


**/

