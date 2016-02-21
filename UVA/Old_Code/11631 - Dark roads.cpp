#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#define sz 200099
#define pb(a) push_back(a)
#define mp make_pair

using namespace std;

int j,r;
vector<pair<int,pair<int,int> > >vec;
int par[sz];
int rank[sz];

void make_set(int x)
{
    par[x]=x;
    rank[x]=0;
}
int find_set(int x)
{
    if(x!=par[x]) par[x]=find_set(par[x]);

    return par[x];
}
void Link(int x,int y)
{
    if(rank[x]>rank[y])par[y]=x;
    else par[x]=y;

    if(rank[x]==rank[y])rank[y]++;
}

void union_set(int x,int y)
{
    Link(find_set(x),find_set(y));
}

int MST_Kruskal(void)
{
    int i,k,pu,pv,u,v,w,cost=0;

    for(i=0;i<r;i++)make_set(i);

    for(i=0;i<vec.size();i++)
    {
        u=vec[i].second.first;
        v=vec[i].second.second;
        w=vec[i].first;
        pu=find_set(u);
        pv=find_set(v);
        if(pu!=pv)
        {
            cost+=w;
            union_set(pu,pv);
        }
    }
    return cost;
}

int main()
{
    int i,k,x,y,w;
    while(scanf("%d %d",&j,&r)==2)
    {
        if(!j && !r)break;
        int cost=0;

        vec.clear();

        for(i=0;i<r;i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            vec.pb(mp(w,mp(x,y)));
            cost+=w;
        }
        sort(vec.begin(),vec.end());

        int ans=MST_Kruskal();
        printf("%d\n",cost-ans);

    }
    return 0;
}
