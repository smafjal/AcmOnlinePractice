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

#define oo          1<<30
#define ERR         1e-7
#define lookalike   scanf("%*d")

using namespace std;

typedef long long ll;
template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction

#define MAX 3200

ll N;
int a,b,c;
int Mod=10007;

const int ROW=4;
struct matrix
{
    int A[ROW][ROW];
    matrix(){mem(A,0);}
    matrix(int a[ROW][ROW]){ FOR(i,0,ROW)FOR(j,0,ROW)A[i][j]=a[i][j];}
    friend matrix operator * (const matrix &a ,const matrix &b)
    {
        matrix res;
        FOR(i,0,ROW)FOR(j,0,ROW)FOR(k,0,ROW) res.A[i][j]=(res.A[i][j]+(a.A[i][k]* b.A[k][j]))%Mod;
        return res;
    }
    friend matrix operator ^(const matrix &a,ll n)
    {
        if(n==1LL) return a;
        matrix tmp=a^(n/2);
        if(n%2) return (tmp*tmp)*a;
        else return (tmp*tmp);
    }
    void view()
    {
        FOR(i,0,ROW){FOR(j,0,ROW) printf("%3d",A[i][j]);puts("");}
    }
};

matrix Base;
void makeBase()
{
    Base.A[0][0]=a;Base.A[0][1]=0;Base.A[0][2]=b;Base.A[0][3]=1;
    Base.A[1][0]=1;Base.A[1][1]=0;Base.A[1][2]=0;Base.A[1][3]=0;
    Base.A[2][0]=0;Base.A[2][1]=1;Base.A[2][2]=0;Base.A[2][3]=0;
    Base.A[3][0]=0;Base.A[3][1]=0;Base.A[3][2]=0;Base.A[3][3]=1;
    return;
}

int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %d %d %d",&N,&a,&b,&c);
        printf("Case %d: ",++cas);
        if(N<=2) printf("0\n");
        else
        {
            makeBase();
            matrix res=Base^(N-2);
            int cnt=0;
            cnt=(cnt+(res.A[1][0]*c)+(res.A[1][3]*c))%Mod;
            printf("%d\n",cnt);
        }
    }
    return 0;
}


