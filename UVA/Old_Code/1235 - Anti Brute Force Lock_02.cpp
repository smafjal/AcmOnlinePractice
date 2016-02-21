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
typedef vector<pair<int,pair<int,int> > > vDi;

#define MAX 505

vDi store;
int N;
int par[MAX],rank[MAX];

int take(string a,string b)
{
    if(a==b) return 0;
    int cost=0;
    for(int i=0;i<SZ(a);i++)
    {
        int t1=a[i];
        int t2=b[i];
        cost+=min(abs(t1-t2),(10-abs(t1-t2)));
    }
    return cost;
}

void makeset(int n)
{
    for(int i=0;i<=n;i++) rank[i]=0,par[i]=i;
}

int findset(int x)
{
    if(x!=par[x]) par[x]=findset(par[x]);
    return par[x];
}

void Link(int x,int y)
{

}

void unionset(int x,int y)
{
    if(rank[x]<rank[y]) par[x]=y;
    else par[y]=x;
    if(rank[x]==rank[y]) rank[y]++;
    return;
}

void linkset(int u,int v)
{
    unionset(findset(u),findset(v));
}

int MST()
{
    makeset(N);
    int cnt=0;
    for(int i=0;i<SZ(store);i++)
    {
        int u=store[i].sc.fs;
        int v=store[i].sc.sc;
        if(findset(u)!=findset(v))
        {
            linkset(u,v);
            cnt+=store[i].fs;
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
        scanf("%d",&N); store.clear();
        vector<string>v; string s;

        for(int i=0;i<N;i++)
        {
            cin>>s;
            v.pb(s);
        }

        for(int i=0;i<SZ(v);i++)
        {
            for(int j=0;j<SZ(v);j++)
            {
                if(i==j) continue;
                int cost=take(v[i],v[j]);
                store.pb(mp(cost,mp(i,j)));
            }
        }
        sort(all(store));
        int ans=MST();
        int p=oo;
        for(int i=0;i<SZ(v);i++)
        {
            p=min(p,take("0000",v[i]));
        }
        cout<<ans+p<<endl;
    }
    return 0;
}
