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

int arr[22],N,len;
int dp[5][(1<<20)+2];
int vis[5][(1<<20)+2];
int loop;

int rec(int side,int mask,int l)
{
    if(l==len) return rec(side+1,mask,0);
    if(side==4) return 1;
    int &ret=dp[side][mask];

    if(vis[side][mask]==loop) return ret;
    vis[side][mask]=loop;

    ret=0;

    for(int i=0;i<N;i++)
    {
        if(!(mask&(1<<i)))
        {
            if(l+arr[i]<=len) ret|=rec(side,mask^(1<<i),l+arr[i]);
            if(ret) return ret;
        }
    }
    return  ret;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    loop=0;

    while(t--)
    {
        loop++;
        scanf("%d",&N);
        int sum=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",arr+i);
            sum+=arr[i];
        }
        if(sum%4) {puts("no");continue;}
        else len=sum/4;

        int cnt=rec(0,0,0);
        if(cnt) puts("yes");
        else puts("no");
    }

    return 0;
}




