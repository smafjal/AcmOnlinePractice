#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<sstream>

using namespace std;
typedef long long ll;

#define pi (2*acos(0))
#define oo (1<<30)
#define pb push_back
#define SZ(a) (int)a.size()
#define mp make_pair
#define mem(a,b) memset(a,b,sizeof(a))
#define all(a) a.begin(),a.end()
#define reall(a) a.rbegin(),a.rend()
#define lookalike scanf("%*d")

int rrr[]={1,0,-1,0};
int ccc[]={0,1,0,-1};

#define MAX 89

vector<string>grid;
bool col[MAX][MAX];
int row;
char c;

bool ch(string s)
{
    for(int i=0;i<SZ(s);i++)
    {
        if(s[i]!='_') return 0;
    }
    return 1;
}

void BFS(int s1,int s2)
{
    queue<int>Q;
    col[s1][s2]=1;
    Q.push(s1);
    Q.push(s2);

    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        int v=Q.front();Q.pop();
        for(int i=0;i<4;i++)
        {
            int uu=u+rrr[i];
            int vv=v+ccc[i];
            if(uu<row and uu>=0 and vv>=0 and vv<SZ(grid[uu]))
            {
                if(!col[uu][vv] and grid[uu][vv]==' ')
                {
                    grid[uu][vv]=c;
                    col[uu][vv]=1;
                    Q.push(uu);
                    Q.push(vv);
                }
            }
        }
    }
}
string op;

void output()
{
//    for(int i=0;i<SZ(grid);i++) {cout<<grid[i]<<endl;}
    row=SZ(grid);

    mem(col,0);

    for(int i=0;i<SZ(grid);i++)
    {
        for(int j=0;j<SZ(grid[i]);j++)
        {
            if(grid[i][j]!='X' and grid[i][j]!=' ')
            {
                if(!col[i][j])
                {
                    c=grid[i][j];
                    BFS(i,j);
                }
            }
        }
    }

    for(int i=0;i<SZ(grid);i++)
    {
        cout<<grid[i]<<endl;
    }
    cout<<op<<endl;
    grid.clear();
}

int main()
{
    string s;
    grid.clear();

    while(getline(cin,s))
    {
        bool id=ch(s);
        if(id){op=s; output();}
        if(!id)grid.pb(s);
    }
    return 0;
}
