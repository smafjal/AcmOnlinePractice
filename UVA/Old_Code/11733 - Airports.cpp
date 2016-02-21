/*Bismillahir Rahmanir Rahim*/
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
#include<algorithm>
#include<sstream>

#define all(a) (a).begin(),(a).end()
#define mem(a,b)  memset(a,b,sizeof(a))
#define fs first
#define sc second
#define oo 1<<29
#define ERR 1e-7
#define EQ(a,b)(fabs(a-b)<ERR)
#define mp make_pair
#define pb push_back
#define PI (2*acos(0.0))
#define SZ(a)  (int)a.size()
#define reall(a) (a).rbegin(),(a).rend()
#define lookalike scanf("%*d")

using namespace std;

void BINARY(int n){cout<<"Mask: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef pair<int,int>   pii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpi;

#define MAX 10009

vector<pair<int,pair<int,int> > >v1;
int N,M,A,air,cost;
int rank[MAX],par[MAX];

void makeset()
{
    for(int i=1;i<=N;i++)
    {
        rank[i]=0;par[i]=i;
    }
    return;
}

int findset(int x)
{
    if(par[x]==x) return x;
    else return par[x]=findset(par[x]);
}

void link(int x,int y)
{
    if(rank[x]>rank[y]) par[y]=x;
    else par[x]=y;
    if(rank[x]==rank[y]) rank[y]++;
    return;
}

void unionset(int x,int y)
{
    link(findset(x),findset(y));
    return ;
}

void MST()
{
    makeset();
    cost=0;air=N;
    for(int i=0;i<SZ(v1);i++)
    {
        int u=v1[i].sc.fs;
        int v=v1[i].sc.sc;
        int cnt=v1[i].fs;
//        cout<<i<<" "<<cnt<<endl;

        if(findset(u)!=findset(v))
        {
            unionset(u,v);
            if(cnt>=A)
            {
            }
            else
            {
                cost+=cnt;
                air--;
            }
        }
    }
    return;
}

int main()
{
    int cas=0;int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d",&N,&M,&A);
        int x,y,w;
        v1.clear();

        for(int i=0;i<M;i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            v1.pb(mp(w,mp(x,y)));
        }
        sort(all(v1));
        MST();
        printf("Case #%d: %d %d\n",++cas,cost+(air*A),air);
    }
    return 0;
}
