#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;

#define MAX 505

int tree[4*MAX][4*MAX],grid[MAX][MAX];
int N;

void build_y(int vx,int lx,int rx,int vy,int ly,int ry)
{
    if(ly==ry)
    {
        if(lx==rx) tree[vx][vy]=grid[lx][ly];
        else tree[vx][vy]=max(tree[vx*2][vy],tree[vx*2+1][vy]);
        return;
    }

    int my=(ly+ry)/2;
    build_y(vx,lx,rx,vy*2,ly,my);
    build_y(vx,lx,rx,vy*2+1,my+1,ry);
    tree[vx][vy]=max(tree[vx][vy*2],tree[vx][vy*2+1]);
}

void build_x(int vx,int lx,int rx)
{
    if(lx!=rx)
    {
        int mx=(lx+rx)/2;
        build_x(vx*2,lx,mx);
        build_x(vx*2+1,mx+1,rx);
    }
    build_y(vx,lx,rx,1,1,N);
}

int max_y(int vx,int vy,int tly,int _try,int ly,int ry)
{
    if(ry<tly or ly>_try) return 0;
    if(tly>=ly and _try<=ry)
    {
        int t=tree[vx][vy];
        return t;
    }

    int tmy=(tly+_try)/2;
    int m1=max_y(vx,vy*2,tly,tmy,ly,ry);
    int m2=max_y(vx,vy*2+1,tmy+1,_try,ly,ry);
    return max(m1,m2);
}

int max_x(int vx,int tlx,int trx,int lx,int rx,int ly,int ry)
{
    if(rx<tlx or lx>trx) return 0;
    if(tlx>=lx and trx<=rx)
    {
        int t=max_y(vx,1,1,N,ly,ry);
        return t;
    }
    int tmx=(tlx+trx)/2;
    int m1=max_x(vx*2,tlx,tmx,lx,rx,ly,ry);
    int m2=max_x(vx*2+1,tmx+1,trx,lx,rx,ly,ry);
    return max(m1,m2);
}


int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int q;
        scanf("%d %d",&N,&q);
        for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
        {
            scanf("%d",&grid[i][j]);
        }
        build_x(1,1,N);
        int s1,s2,s;

        printf("Case %d:\n",++cas);
        for(int i=1;i<=q;i++)
        {
            scanf("%d %d %d",&s1,&s2,&s);
            int cnt=max_x(1,1,N,s1,s1+s-1,s2,s2+s-1);
            printf("%d\n",cnt);
        }
    }
    return 0;
}


