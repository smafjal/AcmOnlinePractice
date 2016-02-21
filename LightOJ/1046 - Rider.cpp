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
int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef pair<int,int>   pii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpi;

#define MAX 12

struct node
{
    int numknight;
    int move;
    int idnum;
    node(){;}
    node(int _numk,int _move,int _idnum){numknight=_numk;move=_move;idnum=_idnum;}
};

struct node store[12][12];
int grid[12][12];
int row,cul;int total;

int cheack(int r,int c)
{
    return (r>=1 and r<=row and c>=1 and c<=cul);
}

void BFS(int si,int sj,int id)
{
    int col[MAX][MAX];mem(col,0);
    queue<int>Q;
    col[si][sj]=1;
    Q.push(si);
    Q.push(sj);
    store[si][sj].numknight++;

    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        int v=Q.front();Q.pop();
        for(int i=0;i<8;i++)
        {
            int r=rrr[i]+u;
            int c=ccc[i]+v;
            if(col[r][c]==0 and cheack(r,c))
            {
                store[r][c].numknight++;
                store[r][c].idnum=store[u][v].idnum+1;
                Q.push(r);Q.push(c);
                col[r][c]=1;
            }
        }
    }

    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=cul;j++)
        {
            int co=store[i][j].idnum;
            if(co%id) co=(co/id)+1;
            else co=co/id;
            store[i][j].move+=co;
            store[i][j].idnum=0;
        }
    }

    return;
}

int output()
{
    int minx=oo; bool fl=0;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=cul;j++)
        {
            if(store[i][j].numknight==total)
            {
                minx=min(minx,store[i][j].move);
                fl=1;
            }
        }
    }
    if(fl) return minx;
    return -1;
}


int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&row,&cul);
        char c;
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=cul;j++)
            {
                scanf(" %c",&c);
                if(c=='.') grid[i][j]=11;
                else grid[i][j]=c-'0';

                store[i][j].idnum=0;
                store[i][j].move=0;
                store[i][j].numknight=0;
            }
        }

        total=0;
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=cul;j++)
            {
                if(grid[i][j]<=9)
                {
                    total++;
                    BFS(i,j,grid[i][j]);
                }
            }
        }
        if(total==1) {printf("Case %d: %d\n",++cas,0);continue;}
        int ans=output();
        if(ans>=0)printf("Case %d: %d\n",++cas,ans);
        else printf("Case %d: %d\n",++cas,-1);
    }
    return 0;
}

