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

struct abc
{
    int a,b,c,s;
    abc(){;}
    abc(int _a,int _b,int _c,int _s){ a=_a;b=_b;c=_c;s=_s;}
};

abc st[90];
int n;
int dp[82][(1<<9)+1];

int rec(int cur,int mask)
{
    if(cur==n) if(mask==0) return 0; else return -(oo);
    int &ret=dp[cur][mask];
    if(ret!=-1) return ret;
    ret=-(oo);
    ret=max(ret,rec(cur+1,mask));
    int i=cur;
    if((mask&(1<<st[i].a)) && (mask&(1<<st[i].b)) && (mask&(1<<st[i].c)))
        ret=max(ret,rec(cur+1,((mask^(1<<st[i].a))^(1<<st[i].b))^(1<<st[i].c))+st[i].s);
    return ret;
}

int main(void)
{
    int cas=0;
    while(scanf("%d",&n)==1 && n)
    {
        int a,b,c,s;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d %d",&a,&b,&c,&s);
            a--;b--;c--;
            st[i]=abc(a,b,c,s);
        }
        mem(dp,-1);
        int cnt=rec(0,(1<<9)-1);
        if(cnt>=0) printf("Case %d: %d\n",++cas,cnt);
        else printf("Case %d: -1\n",++cas);
    }

    return 0;
}



