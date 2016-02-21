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
#include<stack>
#include<algorithm>
#include<sstream>
using namespace std;

#define oo          (1<<30)
#define mem(a,b)    memset(a,b,sizeof(a))
#define mp          make_pair
#define pb          push_back
#define clr(a)      a.clear()
#define SZ(a)       (int)a.size()
#define fs          first
#define sc          second
#define mem(a,b)    memset(a,b,sizeof(a))
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> paii;

#define MAX 1000009


/**

    x y z
 x  y x z
 y  x y y
 z  z y x

***/

char C[102];
int dp[102][102];
int vis[102][102];
char grid[3][4];
string str;
int loop=1;

int rec(int l,int r)
{
    if(l>=r) return (1<<(str[l]-'X'));

    int &ret=dp[l][r];
    if(vis[l][r]==loop) return ret;
    vis[l][r]=loop;

    ret=0;
    for(int i=l;i<r;i++)
    {
        int left=rec(l,i);int right=rec(i+1,r);
        for(int j=0;j<3;j++)
        {
            if((left&(1<<j)))
            {
                for(int k=0;k<3;k++)
                {
                    if((right&(1<<k)))
                    {
                        ret|=(1<<grid[j][k]);
                    }
                    if(ret==7) break;
                }
            }
            if(ret==7) break;
        }
        if(ret==7) break;
    }

    return ret;
}


int main(void)
{
    grid[0][0]=1; grid[0][1]=0; grid[0][2]=2;
    grid[1][0]=0;grid[1][1]=1;grid[1][2]=1;
    grid[2][0]=2;  grid[2][1]=1;grid[2][2]=0;

    int t;
    scanf("%d",&t);

    while(t--)
    {
        loop++;
        scanf(" %s",C);
        str=C;
        int cnt=rec(0,SZ(str)-1);

//        cout<<"cnt: "<<cnt<<endl;
        int i;
        for(i=2;i>=0;i--)
        {
            if((cnt&(1<<i))) break;
        }

        cnt=i;
        if(cnt==0) puts("X");
        else if(cnt==1) puts("Y");
        else puts("Z");
    }

    return 0;
}

