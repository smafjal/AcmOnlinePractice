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

#define mp          make_pair
#define pb          push_back
#define popcount(a) __builtin_popcount(a)
#define contain(x,item) (x).find(item)!=(x).end()
#define FOR(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define REV(i,a,b) for(__typeof(a) i=a;i>=0;i--)
#define PI          (2*acos(0))
#define clr(a)       a.clear()
#define SZ(a)       (int)a.size()
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()
#define FOREACH(it,x)for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
#define fs          first
#define sc          second
#define mem(a,b)    memset(a,b,sizeof(a))

#define oo          1<<30
#define ERR         1e-7
#define lookalike   scanf("%*d")

using namespace std;

typedef long long ll;
template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction

#define MAX 100005


int N;

int par[MAX][20],level[MAX],col[MAX],dis[MAX][20];
vector<int>adj[MAX];
int arr[MAX];



void build_lca()
{
    for(int j=1;(1<<j)<=N;j++)
    {
        for(int i=0;i<N;i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j]=par[par[i][j-1]][j-1];
                dis[i][j]=min(dis[i][j-1],dis[par[i][j-1]][j-1]);
            }
        }
    }
    return;
}


int find_sol(int k,int v)
{
    int r=k;

//    deb("stop");lookalike;

    while(true)
    {
        bool fl=0;
        for(int i=0;(1<<i)<=N;i++)
        {
            if(par[r][i]!=-1)
            {
                if(dis[r][i]>=v)
                {
                    r=par[r][i];
                    fl=1;
                }
            }
        }

        if(fl==0) break;
    }

    return r;
}


int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int q,a,b;
        scanf("%d %d",&N,&q);
        FOR(i,0,N+1)for(int j=0;(1<<j)<=N;j++){  par[i][j]=-1;dis[i][j]=0;}

        arr[0]=1;
        for(int i=1;i<N;i++)
        {
            scanf("%d %d",&a,&b);
            par[i][0]=a;
            arr[i]=b;
            dis[i][0]=min(b,arr[a]);
        }

        build_lca();

        printf("Case %d:\n",++cas);
        int k,v;
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&k,&v);
            int cnt=find_sol(k,v);
            printf("%d\n",cnt);
        }
    }
    return 0;
}




