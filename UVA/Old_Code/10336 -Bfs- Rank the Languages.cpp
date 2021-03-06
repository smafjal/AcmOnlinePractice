/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
Date: 2/20/2012
**/

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
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}

int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

//#include<conio.h>
//#define wait getch()

#define MAX 1000
int row,cul;
char arr[MAX][MAX];
vector<pair<int ,char > >res;
bool col[MAX][MAX];

bool cheack(int r,int c)
{
    if(r>row || c>cul || r<0 || c< 0) return 0;
    return 1;
}

void bfs(int s1,int s2)
{
    int i,j,k,u,v,pu,pv;
    queue<int>Q;
    Q.push(s1);
    Q.push(s2);
    col[s1][s2]=1;
    char key=arr[s1][s2];
    while(!Q.empty())
    {
        pu=Q.front();Q.pop();
        pv=Q.front();Q.pop();
        for(i=0;i<4;i++)
        {
            u=rrr[i]+pu;
            v=ccc[i]+pv;
            if(cheack(u,v))
            {
                if(!col[u][v] && arr[u][v]==key)
                {
                    col[u][v]=1;
                    Q.push(u);Q.push(v);
                }
            }
        }
    }
    return;
}

bool com(pair<int,char> x,pair<int,char>y)
{
    if(x.fs==y.fs) return x.sc>y.sc;
    else return x.fs<y.fs;
}

int main()
{
    int i,j,k,t;
    scanf("%d ",&t);
    int cas=0;
    while(t--)
    {
        char c;string s;
        scanf("%d %d",&row,&cul);
        for(i=0;i<row;i++)
        {
            cin>>s;
            for(j=0;j<SZ(s);j++)
            {
                arr[i][j]=s[j];
            }
        }

        map<char,int> node_map;
        k=0;
        for(i=0;i<row;i++)
        {
            int count=0;
            for(j=0;j<cul;j++)
            {
                if(!col[i][j])
                {
                        bfs(i,j);
                        node_map[arr[i][j]]++;
                }
            }
        }
        FOREACH(it,node_map)
        {
            res.pb(mp((*it).sc,(*it).fs));
        }
        sort(res.rbegin(),res.rend(),com);
        printf("World #%d\n",++cas);
        for(i=0;i<SZ(res);i++)
        {
            printf("%c: %d\n",res[i].sc,res[i].fs);
        }
        res.clear();
        mem(col,0);mem(arr,0);
    }
    return 0;
}
