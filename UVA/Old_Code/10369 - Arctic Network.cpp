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

#define MAX 600

int S,P;
vector<pair<int,int> >store;
int rank[MAX],par[MAX];
vector<pair<double,pair<int,int > > >v;

double take(int x1,int y1,int x2,int y2)
{
    double x=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return sqrt(x);
}

void makeset()
{
    for(int i=1;i<=P;i++) {rank[i]=0;par[i]=i;}
}

int findset(int x)
{
    if(par[x]==x) return x;
    else return par[x]=findset(par[x]);
}

void unionset(int x,int y)
{
    if(rank[x]<rank[y]) par[x]=y;
    else par[y]=x;
    if(rank[x]==rank[y]) rank[x]++;
}

void linkedge(int x,int y)
{
    unionset(findset(x),findset(y));
}

double MST()
{
    makeset();
    int fl=0;
    double cnt=0;

    for(int i=0;i<SZ(v);i++)
    {
        int u1=v[i].sc.fs;
        int v1=v[i].sc.sc;
        if(fl==(P-S))break;
        if(findset(u1)!=findset(v1))
        {
            linkedge(u1,v1);
            cnt=max(cnt,v[i].fs);
            fl++;
        }
    }
    return cnt;
}

int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&S,&P);
        store.clear();v.clear();
        int x,y;

        for(int i=0;i<P;i++)
        {
            scanf("%d %d",&x,&y);
            store.pb(mp(x,y));
        }

        for(int i=0;i<P;i++)
        {
            for(int j=0;j<P;j++)
            {
                if(i==j)continue;
                double cost=take(store[i].fs,store[i].sc,store[j].fs,store[j].sc);
                v.pb(mp(cost,mp(i+1,j+1)));
            }
        }
        sort(all(v));

        double ans=MST();
        printf("%.2lf\n",ans);
    }
    return 0;
}

