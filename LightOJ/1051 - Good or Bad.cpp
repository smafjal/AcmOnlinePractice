/*Bismillahir Rahmanir Rahim*/
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
#include<algorithm>
#include<sstream>

#define all(a) (a).begin(),(a).end()
#define mem(a,b)  memset(a,b,sizeof(a))
#define fs first
#define sc second
#define oo 1<<29
#define ERR 1e-7
#define EQ(a,b)(fabs(a-b)<ERR)
#define mp make_pair
#define pb push_back
#define PI (2*acos(0.0))
#define SZ(a)  (int)a.size()
#define reall(a) (a).rbegin(),(a).rend()
#define lookalike scanf("%*d")

using namespace std;

void BINARY(int n){cout<<"Mask: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef pair<int,int>   pii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDi;

#define MAX 53

int dp[MAX][6][6];
int flag[MAX][6][6],loop=1;
string base;

bool isvowel(char c)
{
    return('a'==tolower(c) or 'e'==tolower(c) or 'i'==tolower(c) or 'o'==tolower(c) or 'u'==tolower(c));
}
bool isconsonant(char c)
{
    return !('a'==tolower(c) or 'e'==tolower(c) or 'i'==tolower(c) or 'o'==tolower(c) or 'u'==tolower(c));
}

int rec1(int cur,int v,int c)
{
    if(v==3 or c==5) return 1;
    if(cur>=SZ(base)) return 0;
    int &ret=dp[cur][v][c];
    if(flag[cur][v][c]==loop) return ret;
    flag[cur][v][c]=loop;

    ret=0;
    if(base[cur]=='?')
    {
        ret|=rec1(cur+1,v+1,0);
        ret|=rec1(cur+1,0,c+1);
    }
    else
    {
        if(isvowel(base[cur])) ret|=rec1(cur+1,v+1,0);
        else ret|=rec1(cur+1,0,c+1);
    }
    return ret;
}

int rec2(int cur,int v,int c)
{
    if(v==3 or c==5) return 0;
    if(cur>=SZ(base)) return 1;

    int &ret=dp[cur][v][c];
    if(flag[cur][v][c]==loop) return ret;
    flag[cur][v][c]=loop;

    ret=0;
    if(base[cur]=='?')
    {
        ret|=rec2(cur+1,v+1,0);
        ret|=rec2(cur+1,0,c+1);
    }
    else
    {
        if(isvowel(base[cur])) ret|=rec2(cur+1,v+1,0);
        else ret|=rec2(cur+1,0,c+1);
    }
    return ret;
}

int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>base; loop++;
        int b=rec1(0,0,0); loop++;
        int g=rec2(0,0,0);

        if(g and b)printf("Case %d: MIXED\n",++cas);
        else if(g) printf("Case %d: GOOD\n",++cas);
        else printf("Case %d: BAD\n",++cas);
    }
    return 0;
}
