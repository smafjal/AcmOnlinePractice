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

#define MAX 30003

int N,value[MAX];
vector<int>adj[MAX];

vector<int>store[MAX];
int L[MAX],grand[MAX],par[MAX],heavy[MAX],subtree[MAX];
int pos[MAX];

int segnode[MAX];

int dfs(int u,int p,int level)
{
    L[u]=level;
    grand[u]=u;
    subtree[u]=1;
    par[u]=p;

    for(int i=0;i<SZ(adj[u]);i++)
    {
        int v=adj[u][i];
        if(v!=p)
        {
            subtree[u]+=dfs(v,u,level+1);
        }
    }

    for(int i=0;i<SZ(adj[u]);i++)
    {
        int v=adj[u][i];
        if(par[v]==u and subtree[v]*2>=subtree[u]) heavy[v]=1;
    }
    return subtree[u];
}

void make_grand(int u,int p)
{
    grand[u] = (heavy[u]) ? grand[par[u]]: u;
    store[grand[u]].pb(u);

    for(int i=0;i<SZ(adj[u]);i++)
    {
        int v=adj[u][i];
        if(v!=p)
        {
            make_grand(v,u);
        }
    }
    return;
}

int build(int node,int left,int right);

void HLD(int root)
{
    for(int i=0;i<=N;i++) {L[i]=0;par[i]=0;heavy[i]=0;subtree[i]=0;grand[i]=0;}
    par[root]=root;
    dfs(root,root,0);

    heavy[root]=1;
    make_grand(root,root);

    int id=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<SZ(store[i]);j++)
        {
            segnode[id]=store[i][j];
            pos[store[i][j]]=id;
            id++;
        }
    }

    build(1,0,N-1);
    return;
}


int tree[4*MAX];
int build(int node,int left,int right)
{
    if(left==right)
    {
        tree[node]=value[segnode[left]];
        return tree[node];
    }

    int mid=(left+right)/2;
    int p=build(node*2,left,mid);
    int q=build(node*2+1,mid+1,right);
    tree[node]=p+q;
    return tree[node];
}

int quary(int node,int left,int right,int l,int r)
{
    if(left>r or right<l) return 0;
    if(left>=l and right<=r) return tree[node];
    int mid=(left+right)/2;
    int p=quary(node*2,left,mid,l,r);
    int q=quary(node*2+1,mid+1,right,l,r);
    return p+q;
}


int update(int node,int left,int right,int idx,int val)
{
    if(left==right)
    {
        tree[node]=val;
        return tree[node];
    }

    int mid=(left+right)/2;
    int p,q;
    if(idx<=mid)
    {
        p=update(node*2,left,mid,idx,val);
        q=tree[node*2+1];
    }
    else
    {
        p=tree[node*2];
        q=update(node*2+1,mid+1,right,idx,val);
    }
    return tree[node]=p+q;
}

int calc(int a,int b)
{
    int ans=0;
    int p,q;
    while(grand[a]!=grand[b])
    {
        if(L[grand[a]]<L[grand[b]])
        {
            p=pos[b];q=pos[grand[b]];
            b=par[grand[b]];
            ans+=quary(1,0,N-1,min(p,q),max(p,q));
        }
        else
        {
            p=pos[grand[a]];q=pos[a];
            a=par[grand[a]];
            ans+=quary(1,0,N-1,min(p,q),max(p,q));
        }
    }

    int l=L[a]<L[b]?a:b;

    ans+=quary(1,0,N-1,min(pos[a],pos[l]),max(pos[a],pos[l]));
    ans+=quary(1,0,N-1,min(pos[b],pos[l]),max(pos[b],pos[l]));
    ans-=quary(1,0,N-1,pos[l],pos[l]);
    return ans;
}


int main(void)
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        for(int i=0;i<=N;i++) {clr(adj[i]);clr(store[i]);}

        int a,b;
        for(int i=0;i<N;i++) scanf("%d",value+i);

        for(int i=1;i<N;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        HLD(0);

        int q,id;
        scanf("%d",&q);
        printf("Case %d:\n",++cas);
        while(q--)
        {
            scanf("%d %d %d",&id,&a,&b);
            if(id==0)
            {
                int cnt=calc(a,b);
                printf("%d\n",cnt);
            }
            else update(1,0,N-1,pos[a],b);
        }
    }
    return 0;
}


