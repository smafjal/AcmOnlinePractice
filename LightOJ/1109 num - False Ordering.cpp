#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<algorithm>
#include<sstream>

using namespace std;

#define pi (2*cos(0))
#define CUBE(X) (X*X*X)
#define rep(i,n) for(i=0;i<(n);i++)
#define rep1(i,a,n) for(i=a;i<=(n);i++)
#define oo 1<<29
#define pb push_back
#define popb pop_back
#define mp make_pair
#define mem(a,b)  mamset(a,b,sizeof(a))
#define SZ(a)  (int)a.size()
#define fs first
#define sc second
#define contain(x,item) (x).find(item)!=(x).end()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbigin(),(a).rend()

#define MAX 10099

struct info
{
    int num;
    int div;
};

vector<info>v;
bool flag[MAX];
int prime[MAX];

void sive()
{
    int i,j,k,r,total=1;
    flag[0]=flag[1]=1;
    prime[total]=2;

    for(i=3;i<MAX;i+=2)
    {
        if(!flag[i])
        {
            prime[++total]=i;
            r=i*2;
            if(MAX/i>=i)for(j=i*i;j<MAX;j+=r)flag[j]=1;
        }
    }
    return;
}

int numofdivisor(int n)
{
    int i,j,k,c,ans=1;
    for(i=1;prime[i]<=n/prime[i];i++)
    {
        if(n%prime[i]==0)
        {
            c=0;
            while(n%prime[i]==0)
            {
                c++;
                n/=prime[i];
            }
            ans*=(c+1);
        }
    }
    if(n>1)ans*=2;
    return ans;
}
void divisor(void)
{
    int i,j,k;bool fl;
    struct info tmp;
    tmp.num=0;tmp.div=0;v.pb(tmp);
    tmp.num=1;tmp.div=1;v.pb(tmp);
    tmp.num=2;tmp.div=2;v.pb(tmp);
    tmp.num=3;tmp.div=2;v.pb(tmp);
    for(i=4;i<=1000;i++)
    {
        j=numofdivisor(i);
        tmp.num=i;
        tmp.div=j;
        v.pb(tmp);
    }
    return;
}

bool com(const info &x,const info &y)
{
    if(x.div<y.div) return 1;
    if(x.div==y.div && x.num>y.num) return  1;
    return 0;
}

int main()
{
    sive();
    divisor();
    sort(v.begin(),v.end(),com);
    int i,j,k;
    int t,n;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",k,v[n]);
    }
    return 0;
}

