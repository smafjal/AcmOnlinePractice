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
#include<algorithm>

#define sz 599
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int dis[sz];
int arr[sz][sz];
int n,m,q;
int col[sz][sz];
int rrr[]= {0,-1,0,1};
int ccc[]= {1,0,-1,0};

bool ch(int u,int v,char c)
{
    if(u<1 || u>m || v<1|| v>n)return 0;
    if(c=='#')return 0;
    return true;
}

int bfs(int s1,int s2,int flag)
{
    int i,j,k,u,v,pu,pv;
    col[s1][s2]=flag;
    queue<int>Q;

    Q.push(s1);
    Q.push(s2);
    int count=0;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        v=Q.front();
        Q.pop();
        if(arr[u][v]=='C')count++;

        for(i=0; i<4; i++)
        {
            pu=rrr[i]+u;
            pv=ccc[i]+v;
            if(ch(pu,pv,arr[pu][pv]))
            {
                if(!col[pu][pv])
                {
                    Q.push(pu);
                    Q.push(pv);
                    col[pu][pv]=flag;

                }
            }
        }
    }
    return  count;
}

void view()
{
    int i,j;
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            cout<<(char)arr[i][j]<<"  ";
        }
        puts("\n\n");
    }
}
int main()
{
    int i,j,k,loop,x,y,w;
    scanf("%d",&loop);
    for(k=1; k<=loop; k++)
    {
        scanf(" %d %d %d",&m,&n,&q);
//        for(i=0; i<m+10; i++){mem(arr[i],0);mem(col[i],0);}
        mem(arr,0);mem(col,0);

        for(i=1; i<=m; i++)
        {
            for(j=1; j<=n; j++)
            {
                char c;
                scanf(" %c",&c);
                arr[i][j]=c;
            }
        }
//        view();

        int mat[1011];
        mem(mat,0);

        printf("Case %d:\n",k);
        int ans;
        for(i=1; i<=q; i++)
        {
            scanf("%d %d",&x,&y);
            if(arr[x][y]=='#')
            {
                printf("0\n");
                continue;
            }
            if(col[x][y]) ans=mat[col[x][y]];
            else
            {
                ans=bfs(x,y,i);
                mat[i]=ans;
            }
            printf("%d\n",ans);

//            for(j=0; j<=m+10; j++)mem(col[i],0);
        }
    }
    return 0;
}
