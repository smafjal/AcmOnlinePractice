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

char mat[sz][sz];
bool col[sz][sz];
int dis[sz][sz];
int n;
int rrr[]= {0,-1,0,1};
int ccc[]= {1,0,-1,0};


bool ch(int r,int c,char c1,char c2)
{
    if(r<1||c<1||r>n||c>n)return 0;
    if(c1=='#')return 0;
    if(c1>c2)return 0;
    return 1;
}

int bfs(int &s1,int &s2,char c)
{
    int i,j,k,u,v,pu,pv;
    queue<int>Q;
    Q.push(s1);
    Q.push(s2);

    col[s1][s2]=1;
    dis[s1][s2]=0;
    bool fl=0;
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        v=Q.front();Q.pop();
        for(i=0;i<4;i++)
        {
            pu=rrr[i]+u;
            pv=ccc[i]+v;
            if(ch(pu,pv,mat[pu][pv],c))
            {
                if(!col[pu][pv])
                {
                    Q.push(pu);
                    Q.push(pv);
                    dis[pu][pv]=dis[u][v]+1;
                    col[pu][pv]=1;
                    if(mat[pu][pv]==c){s1=pu;s2=pv;return dis[pu][pv];}
                }
            }
        }
    }
    return 0;
}
int main(void)
{
    int i,j,k,loop,x,y,w;
    scanf("%d",&loop);
    for(k=1;k<=loop;k++)
    {
        scanf(" %d",&n);
        int count =0;int s1,s2;
        for(i=0;i<=n+5;i++){mem(dis[i],0);mem(col[i],0);mem(mat[i],0);}

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                char c;
                scanf(" %c",&c);
                mat[i][j]=c;
                if(c>='A'&& c<='Z')count++;
                if(c=='A'){s1=i;s2=j;}
            }
        }
        if(count==1){printf("Case %d: %d\n",k,0);continue;}
        int ans;bool fl=1;
        int res=0;

        for(i=1;i<count;i++)
        {
            ans=bfs(s1,s2,'A'+i);
            if(!ans){fl=0;break;}
            res+=ans;

            for(j=0;j<=n+5;j++){mem(dis[j],0);mem(col[j],0);}
        }
        if(!fl)printf("Case %d: Impossible\n",k);
        else printf("Case %d: %d\n",k,res);
    }
    return 0;
}
