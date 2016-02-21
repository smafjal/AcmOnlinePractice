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
#include<time.h>

#define mp          make_pair
#define pb          push_back
#define popcount(a) __builtin_popcount(a)
#define contain(x,item) (x).find(item)!=(x).end()
#define FOR(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define REV(i,a,b) for(__typeof(a) i=a;i>=0;i--)
#define PI          (2*acos(0))
#define clr(a)       a.clear()
#define SZ(a)       (int)a.size()
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()
#define FOREACH(it,x)for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
#define fs          first
#define sc          second
#define mem(a,b)    memset(a,b,sizeof(a))

#define oo          (1<<29)
#define ERR         1e-7
#define lookalike   scanf("%*d")

using namespace std;

typedef long long ll;
template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction

#define MAX 10

char grid[MAX][MAX];
//int dp[10][280][280],R,C;
int dp[10][1024][1024],R,C;

inline bool ok(int r,int c){ return (r>=0 and r<10 and c>=0 and c<10);}
int rec(int row,int pre,int now)
{
//    int x;cout<<row<<" "<<pre<<" "<<now<<endl; cin>>x;

    if(row>=R) return (pre==0)? 0: oo;
    int &ret=dp[row][pre][now];
    if(ret!=-1) return ret;

    ret=oo;
    int next=0,idx,st[3];
    //if(row+1<R)FOR(i,0,C) if(grid[row+1][i]=='.') next=next|(1<<i);
    if(row+1<R)FOR(i,0,C) if(grid[row+1][i]=='O') next=next|(1<<i);

    for(int mask=0;mask<(1<<C);mask++)
    {
        st[0]=pre;
        st[1]=now;
        st[2]=next;

        FOR(j,0,C)
        {
            if((mask&(1<<j)))
            {
                int pr=row;
                int pc=j;
                st[1]^=(1<<j);

                FOR(k,0,8)
                {
                    int r=pr+rrr[k];
                    int c=pc+ccc[k];
                    if(r>=0 and r<R and c>=0 and c<C)
                    {
                        if(pr==r) idx=1;
                        else if(pr>r) idx=0;
                        else idx=2;
                        st[idx]^=(1<<c);
                    }
                }
            }
        }

        if(st[0]==0) ret=min(ret,rec(row+1,st[1],st[2])+popcount(mask));
    }
    return ret;
}


int main()
{
    int cas=0;int t;
    cin>>t;
    while(t--)
    {
        char c;
        scanf("%d %d",&R,&C);
        FOR(i,0,R)FOR(j,0,C) cin>>grid[i][j];

        printf("Case %d: ",++cas);
        int mask=0;
        FOR(i,0,C) if(grid[0][i]=='.')mask=(mask|(1<<i));
        //FOR(i,0,C) if(grid[0][i]=='O')mask=(mask|(1<<i));
        mem(dp,-1);
        int cnt=rec(0,0,mask);

//        deb("cnt:-->> ",cnt);

        if(cnt<oo)deb(cnt);
        else deb("impossible");
    }
    return 0;
}
