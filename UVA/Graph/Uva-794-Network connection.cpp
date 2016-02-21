#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<sstream>
#include<time.h>
using namespace std;

#define popcount(a) __builtin_popcount(a)
#define mp          make_pair
#define pb          push_back
#define FOR(i,a,b)  for(int i=(a);i<=b;i++)
#define REV(i,a,b)  for(int i=a;i>=b;i--)
#define PI          (2*acos(0))
#define clr(a)       a.clear()
#define SZ(a)       (int)a.size()
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()
#define fs          first
#define sc          second
#define mem(a,b)    memset(a,b,sizeof(a))
#define ERR         1e-7
#define EQ(a,b)     (fabs(a-b)<ERR)

//#define FOREACH(it,x) for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
//int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     VI;
typedef vector<string>  VS;
typedef pair<int,int>   PII;
typedef pair<int,PII >  DPII;
typedef vector<pair<int,int> >VPII;
typedef vector<pair<int,pair<int,int> > > VDPII;

#define INF (1<<28)
#define MAX 200009

int par[MAX],SZ[MAX];

void MakeSet(int n)
{
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        SZ[i]=1;
    }
    return;
}

int Find(int x)
{
    if(x==par[x]) return x;
    return par[x]=Find(par[x]);
}

void Link(int x,int y)
{
    if(SZ[x]<SZ[y])
    {
        par[x]=y;
        SZ[y]+=SZ[x];
        return;
    }
    par[y]=x;
    SZ[x]+=SZ[y];
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    bool fl=0;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        getchar();

        if(fl) puts("");fl=1;
        MakeSet(n);
        string s;int a,b;
        int nai=0,ase=0;

        char c=getchar();
        while(c!='\n' && c!=EOF)
        {
            scanf("%d %d",&a,&b);
           // cin.ignore();
            int u=Find(a);
            int v=Find(b);

           // cout<<"N: "<<c<<" "<<a<<" "<<b<<endl;
            if(c=='c')
            {
                if(u!=v) Link(u,v);
            }
            else
            {
                if(u!=v) nai++;
                else ase++;
            }
            getchar();
            c=getchar();
        }

//        cout<<"ans: "<<ase<<"  "<<nai<<endl;
        printf("%d,%d\n",ase,nai);
    }
    return 0;
}

