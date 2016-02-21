///Bismillahir Rahmanir Rahim
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
typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef pair<int,int> paii;

#define pi (2*acos(0))
#define oo 1<<29
#define pb push_back
#define popb pop_back
#define mp make_pair
#define mem(a,b)  memset(a,b,sizeof(a))
#define SZ(a)  (int)a.size()
#define fs first
#define sc second
#define contain(x,item) (x).find(item)!=(x).end()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}

#define MAX 12000

int dp[51][51][51];
int vis[51][51][51];
int loop;
string bas1,bas2,bas3;

int rec(int i,int j,int k)
{
    if(i>=SZ(bas1) or j>=SZ(bas2) or k>=SZ(bas3)) return 0;

    int &ret=dp[i][j][k];
    int &vis_ad=vis[i][j][k];

    if(vis_ad==loop) return ret;
    vis_ad =loop;

    int ans=-1;
    if(bas1[i]==bas2[j] and bas1[i]==bas3[k]) ans=rec(i+1,j+1,k+1)+1;
    else
    {
        ans=max(ans,rec(i+1,j,k));
        ans=max(ans,rec(i,j+1,k));
        ans=max(ans,rec(i,j,k+1));
    }
    ret=ans;
    return ans;
}

int main()
{
    int i,j,t,cas=0;
    scanf("%d",&t);
    for(loop=1;loop<=t;loop++)
    {
        cin>>bas1>>bas2>>bas3;
        int ans=rec(0,0,0);
        printf("Case %d: %d\n",loop,ans);
    }
    return 0;
}
