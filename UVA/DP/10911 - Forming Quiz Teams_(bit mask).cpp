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

int N;
double dp[(1<<16)+2];
int vis[(1<<16)+2];
int loop=0;
int X[20],Y[20];

double rec(int mask)
{
//    BINARY(mask);int x;cin>>x;

    if(mask==0) return 0.0;
    double &ret=dp[mask];
    if(vis[mask]==loop) return ret;
    vis[mask]=loop;

    ret=oo;
    for(int i=0;i<N;i++)
    {
        if((mask&(1<<i)))
        {
            for(int j=0;j<N;j++)
            {
                if(i!=j && ((mask&(1<<j))))
                {
                    int m=mask;
                    m=(m^(1<<i));
                    m=(m^(1<<j));
                    double d=sqrt(((X[i]-X[j])*((X[i]-X[j])))+((Y[i]-Y[j])*((Y[i]-Y[j]))));
                    ret=min(ret,rec(m)+d);
                }
            }
        }
    }

    return ret;
}


int main(void)
{
    int cas=0;
    while(scanf("%d",&N)==1 && N)
    {
        loop++;
        string s;N=N*2;
        for(int i=0;i<N;i++)
        {
            cin>>s;
            scanf("%d %d",X+i,Y+i);
        }

        int mask=(1<<N)-1;
        double cnt=rec(mask);
        printf("Case %d: %.2lf\n",++cas,cnt);
    }
    return 0;
}


/**

5
sohel 10 10
mahmud 20 10
sanny 5 5
prince 1 1
per 120 3
mf 6 6
kugel 50 60
joey 3 24
limon 6 9
manzoor 0 0
1
derek 9 9
jimmy 10 10

*/

