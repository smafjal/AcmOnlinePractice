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

#define oo          (0x7f7f7f7f)
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

int dp[4][4][(1<<16)+2];
//int vis[(1<<16)+2];
int loop=0;
int grid[5][5];
int R,C,N;

int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction

int flip(int i,int j,int mask)
{
    return mask^=(1<<(i*C+j));
}

int get(int i,int j,int mask)
{
    return (mask&(1<<(i*C+j)));
}

int ok(int r,int c)
{
    return (r>=0 && r<R && c>=0 && c<C);
}

void BINARY(int n){cout<<"Mask: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}

int rec(int mask)
{
//    BINARY(mask);int x;cin>>x;
    if(__builtin_popcount(mask)==1) return 1;
    int &ret=dp[R-1][C-1][mask];
    if(ret!=-1) return ret;
//    if(vis[mask]==loop) return ret;
//    vis[mask]=loop;

    ret=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(get(i,j,mask))
            {
                for(int k=0;k<8;k++)
                {
                    int x1=i+rrr[k];
                    int y1=j+ccc[k];
                    int x2=i+2*rrr[k];
                    int y2=j+2*ccc[k];
                    if(ok(x1,y1) && ok(x2,y2) && get(x1,y1,mask) && !get(x2,y2,mask))
                    {
                        int now=mask;
                        now=flip(i,j,now);
                        now=flip(x1,y1,now);
                        now=flip(x2,y2,now);
                        ret+=rec(now);
                    }
                }
            }
        }
    }

    return ret;
}


int main(void)
{
    int t,cas=0;
    scanf("%d",&t);
    mem(dp,-1);

    while(t--)
    {
//        loop++;
        scanf("%d %d %d",&R,&C,&N);
        int x,y;
        int mask=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d %d",&x,&y);
            x--;y--;
            mask=flip(x,y,mask);
        }
        int cnt=rec(mask);
        printf("Case %d: %d\n",++cas,cnt);
    }
    return 0;
}


/**

12
1 2 1
1 1
3 3 8
2 3
2 1
1 2
3 3
3 2
3 1
1 1
1 3
3 3 3
3 1
2 2
1 2

**/

