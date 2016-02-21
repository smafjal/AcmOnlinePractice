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

#define MAX 128

int N,M;
string path[MAX][MAX];
int grid[128][128];

void fld()
{
    for(int k='A';k<='Z';k++)
    {
        for(int i='A';i<='Z';i++)
        {
            for(int j='A';j<='Z';j++)
            {
                if(grid[i][j]>grid[i][k]+grid[k][j])
                {
                    grid[i][j]=grid[i][k]+grid[k][j];
                    path[i][j]=path[i][k]+path[k][j].substr(1);
                }
            }
        }
    }
    return;
}

int main()
{
    while(scanf("%d %d",&N,&M)==2)
    {
        mem(grid,-1);

        for(int i='A';i<='Z';i++)for(int j='A';j<='Z';j++)
        {
            path[i][j]="";
            grid[i][j]=oo;
            if(i==j)grid[i][j]=0;
        }

        char a,b;int c;
        for(int i=0;i<M;i++)
        {
            scanf(" %c %c %d",&a,&b,&c);
            grid[a][b]=c;
            grid[b][a]=c;
            path[a][b].pb(a);
            path[a][b].pb(b);
            path[b][a].pb(b);
            path[b][a].pb(a);
        }

        fld();
        int p;
        scanf("%d",&p);
        for(int i=0;i<p;i++)
        {
            scanf(" %c %c",&a,&b);
            string s=path[a][b];

            for(int k=0;k<SZ(s);k++)
            {
                if(k)cout<<" ";
                cout<<s[k];
            }
            puts("");
        }
    }
    return 0;
}

