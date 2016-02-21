/*Bismillahir Rahmanir Rahim*/ /// Sm19

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>

#define mp          make_pair
#define pb          push_back
#define FOR(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define clr(a)       a.clear()
#define mem(a,b)    memset(a,b,sizeof(a))
#define SZ(a) a.size()
using namespace std;
int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction

typedef vector<string> vs;

vs grid;
bool ch(int r,int c)
{
    if(r>=0 and r<SZ(grid) and c>=0 and c<SZ(grid[r])) return 1;
    return 0;
}

void fill(int x,int y)
{
    grid[x][y]='#';
    for(int i=0;i<4;i++)
    {
        int r=x+rrr[i];
        int c=ccc[i]+y;
        if(ch(r,c) and (grid[r][c]==' ' or grid[r][c]=='*'))
        {
//            grid[r][c]='#';
            fill(r,c);
        }
    }

    return;
}

void output(string s)
{
    bool fl=1;
    for(int i=0;i<SZ(grid) and fl;i++)
    {
        for(int j=0;j<SZ(grid[i]) and fl;j++)
        {
            if(grid[i][j]=='*') {fill(i,j);fl=0;}
        }
    }

    for(int i=0;i<SZ(grid);i++)
    {
        for(int j=0;j<SZ(grid[i]);j++)
        {
            printf("%c",grid[i][j]);
        }
        puts("");
    }
    cout<<s<<endl;
    grid.clear();
}

int main()
{
    string s; int t;
    scanf("%d\n",&t);

    while(t--)
    {
        while(getline(cin,s))
        {
            if(s[0]=='_') break;
            grid.pb(s);
        }
        output(s);
    }
    return 0;
}

