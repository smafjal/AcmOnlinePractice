#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ULL;   /// scanf("%llu",&n);
typedef vector<int> vi;
typedef pair<int,int> paii;

#define PI (2*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)


template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}

template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}  /// B^P
int BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;} /// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

//#include <conio.h>
//#define wait getch()

#define MAX 100


vector<char>vs[MAX];
bool col[MAX][MAX];
int grow,gcul;
bool fl;

bool  cheack(int r,int c)
{
    if(r<0 || c<0 || r>grow-1 || c>gcul-1) return 0;
    return 1;
}

int bfs(int r,int c)
{
    int i,j,k,prow,pcul,cul,row;int ans=0;

    queue<int>Q;
    Q.push(r);
    Q.push(c);
    col[r][c]=1;
    while(!Q.empty())
    {
        ans++;
        prow=Q.front();Q.pop();
        pcul=Q.front();Q.pop();
        for(i=0;i<8;i++)
        {
            row=prow+rrr[i];
            cul=pcul+ccc[i];
            if(cheack(row,cul) && vs[row][cul]=='1' && !col[row][cul])
            {
                Q.push(row);
                Q.push(cul);
                col[row][cul]=1;
            }
        }
    }
    return ans;
}

void output()
{
    int i,j,m,max_e=0;

    for(i=0;i<grow;i++)
    {
        for(j=0;j<SZ(vs[i]);j++)
        {
            if(vs[i][j]=='1' && !col[i][j])
            {
                m=bfs(i,j);
                if(m>max_e) max_e=m;
            }
        }
    }
    if(fl)printf("\n");
    printf("%d\n",max_e);

    for(i=0;i<grow;i++)
    {
        vs[i].clear();
    }
    mem(col,0);
    return;
}


int main()
{
    int i,j,t;

    scanf("%d  ",&t);
    fl=0;
    while(t--)
    {
        string s1;vector<string>v;

        while(getline(cin,s1))
        {
            if(s1=="")break;
            else v.pb(s1);
        }
        grow=SZ(v);
        gcul=SZ(v[0]);
        for(i=0;i<grow;i++)
        {
            for(j=0;j<SZ(v[i]);j++)
            {
                vs[i].pb(v[i][j]);
            }
        }
        output();
        fl=1;
    }
    return 0;
}

