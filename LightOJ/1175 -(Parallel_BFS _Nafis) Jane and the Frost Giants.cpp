#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define INF (1<<30)

using namespace std;

int n, m;
char grid[205][205];
bool used[205][205];
int dis[205][205];
int xx[] = {-1, 0, 1, 0};
int yy[] = {0, -1, 0, 1};

void frbfs(int x, int y)
{
    memset(used, false, sizeof used);
    used[x][y] = true;
    queue<int>Q;
    Q.push(x);
    Q.push(y);
    dis[x][y] = 0;
    int nx, ny, ex, ey;
    while(!Q.empty())
    {
        nx = Q.front();
        Q.pop();
        ny = Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            ex = nx+xx[i];
            ey = ny+yy[i];
            if(ex>=0 && ex<n && ey>=0 && ey<m)
            {
                if(!used[ex][ey] && grid[ex][ey]!='#' && dis[ex][ey]>(dis[nx][ny]+1))
                {
                    used[ex][ey] = true;
                    dis[ex][ey] = dis[nx][ny]+1;
                    Q.push(ex);
                    Q.push(ey);
                }
            }
        }
    }
    return;
}

int jnbfs(int x, int y)
{
//    printf("In jnbfs start Node: %d %d\n",x,y);
    memset(used, false, sizeof used);
    used[x][y] = true;
    queue<int>Q;
    Q.push(x);
    Q.push(y);
    dis[x][y] = 0;
    int nx, ny, ex, ey;
    while(!Q.empty())
    {
        nx = Q.front();
        Q.pop();
        ny = Q.front();
        Q.pop();
        if(nx==0 || ny==0 || nx==n-1 || ny==m-1) {return dis[nx][ny]+1;}
        for(int i=0; i<4; i++)
        {
            ex = nx+xx[i];
            ey = ny+yy[i];
            if(ex>=0 && ex<n && ey>=0 && ey<m)
            {
                if(!used[ex][ey] && grid[ex][ey]!='#' && dis[ex][ey]>(dis[nx][ny]+1))
                {
//                    printf("%d %d\n",ex,ey);
                    used[ex][ey] = true;
                    dis[ex][ey] = dis[nx][ny]+1;
                    Q.push(ex);
                    Q.push(ey);
                }
            }
        }
    }
    return -1;
}

void disview()
{
    printf("\nDistance array\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='#') printf("# ");
            else printf("%d ",dis[i][j]);
        }
        puts("");
    }
    puts("");
}

void usedview()
{
    printf("\nUsed Array\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",used[i][j]);
        }
        puts("");
    }
    puts("");
}

int main()
{
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        int i, j, k;
        scanf("%d%d ", &n, &m);
        for(i=0; i<n; i++)
            scanf("%s", &grid[i]);
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                dis[i][j] = INF;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(grid[i][j]=='F')
                {
                    frbfs(i, j);
//                    disview();
//                    usedview();
                }
            }
        }
        int ans;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(grid[i][j]=='J')
                {
                    ans = jnbfs(i, j);
                    break;
                }
            }
        }
        csprnt;
        if(ans!=-1)
            printf("%d\n", ans);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}

