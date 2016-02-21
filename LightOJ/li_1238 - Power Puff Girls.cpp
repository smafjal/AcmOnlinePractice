#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>

#define sz 100
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

//vector<int>vec[sz];
char arr[sz][sz];
int dis[sz][sz];
int col[sz][sz];
int m,n;
int rrr[]= {0,-1,0,1};
int ccc[]= {1,0,-1,0};

bool ch(int r,int c,char c1)
{
    if(r<1||c<1|| r>m||c>n)return 0;
    if(c1=='#')return 0;
    if(c1=='m')return 0;
    return 1;
}

void bfs(int s1,int s2)
{
    int i,j,k,u,v,pu,pv;
    queue<int>Q;
    Q.push(s1);
    Q.push(s2);

    col[s1][s2]=1;
    dis[s1][s2]=0;

    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        v=Q.front();Q.pop();
        for(i=0;i<4;i++)
        {
            pu=rrr[i]+u;
            pv=ccc[i]+v;
            if(ch(pu,pv,arr[pu][pv]))
            {
                if(!col[pu][pv])
                {
                    Q.push(pu);
                    Q.push(pv);
                    dis[pu][pv]=dis[u][v]+1;
                    col[pu][pv]=1;
                }
            }
        }
    }
}

int main()
{
    int i,j,k,loop,x,y,w;
    scanf("%d",&loop);
    for(k=1;k<=loop;k++)
    {
        scanf(" %d %d",&m,&n);
        vector<int>li;

        for(i=0;i<sz;i++){mem(arr[i],0);mem(dis[i],0);}

        int home1,home2;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                char c;
                scanf(" %c",&c);
                arr[i][j]=c;
                if(c=='a' || c=='b' || c=='c'){li.push_back(i);li.push_back(j);}
                if(c=='h'){home1=i;home2=j;}
            }
        }
        int u,v;
        int ans=0;
        for(int it=0;it<(int)li.size();it+=2)
        {
            u=li[it];
            v=li[it+1];
            bfs(u,v);
            int reans=dis[home1][home2];
            if(ans<reans)ans=reans;

            for(i=0;i<m+1;i++){mem(dis[i],0);mem(col[i],0);}
        }
        printf("Case %d: %d\n",k,ans);
    }

    return 0;
}
