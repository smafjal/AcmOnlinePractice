#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
#define SZ(a) (int)a.size()
#define all(a) (a).begin(),(a).end()
#define fs first
#define sc second
const int INF=(1<<29);
const int MAX=109;

vector<int>G[MAX];
vector<int>RG[MAX];
vector<int>col,order,com;
int N,out[MAX];
map<string,int> M;
string store[MAX+MAX];
set<string>V;

inline int ok(string s)
{
    if(M.count(s)<1)
    {
        M[s]=M.size();
    }
    return M[s];
}

void dfs(int u)
{
    col[u]=true;
    for(int i=0;i<SZ(G[u]);i++)
    {
        int v=G[u][i];
        if(!col[v])  dfs(v);
    }
    order.pb(u);
    return;
}


void dfs_com(int u)
{
    col[u]=true;
    com.pb(u);
    for(int i=0;i<SZ(RG[u]);i++)
    {
        int v=RG[u][i];
        if(!col[v])
        {
            dfs_com(v);
        }
    }
    return;
}

void dfs_final(int u)
{
    V.insert(store[u]);
    col[u]=true;
    for(int i=0;i<SZ(G[u]);i++)
    {
        int v=G[u][i];
        if(!col[v])
        {
            dfs_final(v);
        }
    }
    return;
}

int main()
{
    while(scanf("%d",&N)==1 and N)
    {
        for(int i=0;i<=N;i++ ) G[i].clear(),RG[i].clear();


        M.clear();mem(out,0);
        string uu,vv,str;
        getline(cin,str);

        for(int i=0;i<N;i++)
        {
            stringstream ss;
            getline(cin,str);
            ss<<str;ss>>uu;
            while(ss>>vv)
            {
                G[ok(uu)].pb(ok(vv));
                RG[ok(vv)].pb(ok(uu));
                out[ok(uu)]++;
            }
            store[ok(uu)]=uu;

        }



        col.assign(N+2,0);
        order.clear();
        for(int i=1;i<=N;i++)
        {
            if(!col[i]) dfs(i);
        }


        col.assign(N+2,0);
        set<int>words;
        for(int i=SZ(order)-1;i>=0;i--)
        {
            int u=order[i];
            if(!col[u])
            {
                com.clear();
                dfs_com(u);

                if(SZ(com)>1 || out[u]==0) for(int j=0;j<SZ(com);j++) words.insert(com[j]);
            }
        }

        col.assign(N+2,0);V.clear();
        for(set<int> :: iterator it=words.begin();it!=words.end();it++)
        {
            int u=(*it);
            dfs_final(u);
        }

        cout<<SZ(V)<<endl;
        for(set<string>:: iterator it=V.begin();it!=V.end();it++)
        {
            string ans=(*it);
            if(it!=V.begin()) printf(" ");
            cout<<ans;
        }
        cout<<endl;
    }
    return 0;
}



/**

5
aue oizer piqoi oizer
doy oizer hweqlo hweqlo
hweqlo piqoi aue
oizer piqoi
piqoi aue aue


**/
