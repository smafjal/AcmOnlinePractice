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
#define lookalike scanf("%*d");

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}

#define MAX 105

string dp[MAX][MAX];
string bas1,bas2;
int cnt;

string Min(string a,string b)
{
    if(a=="" and b=="") return "";
    if(a=="") return b;
    if(b=="") return a;
    if(a.size()==b.size()) return (a<b)?a:b;
    else return (SZ(a)<SZ(b)) ? b:a;
}

string rec(int i,int j)
{
    string ans;
    if(i>=SZ(bas1) or j>=SZ(bas2)) return "";
    if(dp[i][j]!="}") return dp[i][j];

    if(bas1[i]==bas2[j])
    {
        cnt++;
        ans=bas1[i]+rec(i+1,j+1);
    }
    else
    {
        ans=rec(i+1,j);
        ans=Min(ans,rec(i,j+1));
        dp[i][j]=ans;
    }
    return ans;
}

int main()
{
    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        cin>>bas1>>bas2;
        k=max(SZ(bas1),SZ(bas2))+3;
        for(i=0;i<=k;i++)for(j=0;j<=k;j++) dp[i][j]="}";

        cnt=0;
        string final=rec(0,0);
        if(!cnt)printf("Case %d: :(\n",++cas);
        else {printf("Case %d: ",++cas);cout<<final<<endl;}
    }
    return 0;
}