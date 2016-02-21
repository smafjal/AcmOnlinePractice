#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>

using namespace std;

#define INF 1<<28
#define SIZE 1000

#define REP(i,n) for (i=0;i<n;i++)
#define REV(i,n) for (i=n;i>=0;i--)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define FOR(i,p,k) for (i=p; i<k;i++)

#define bug(x)    cout<< "->" <<#x<<": "<<x<<endl   //debug(x) variable
#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define MP(a,b) make_pair(a,b)
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define COPY(c,r)   memcpy(c,r,sizeof(r))
#define SZ(x) (int)x.size()
#define PB push_back
#define popcount(i) __builtin_popcount(i)
#define gcd(a,b)    __gcd(a,b)
#define fs first
#define sc second

//structure model
struct pq
{
    int cost,node;
    bool operator<(const pq &b)const
    {
        return cost>b.cost;    // Min Priority Queue
    }
};

//Comp Sort
bool comp(pq a,pq b)
{
    return a.cost > b.cost;
}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<double>vd;
typedef vector<string> vs;
typedef vector<vi>vvi;
typedef map<string,int> msi;
typedef map<int,int>mii;
typedef map<pii,int>mpi;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

string Addition(string a,string b); //Addition any two string
string cut_leading_zero(string a);  //leading zero cut 001 -> 1


#define MAX 10004

string S1,S2;
string dp[MAX][102];
int vis[MAX][102];
int cas=1;

string rec(int i,int j)
{
    if(j==SZ(S2)) return "1";
    if(i==SZ(S1)) return "0";

    string &ret=dp[i][j];

    if(vis[i][j] == cas) return ret;
    vis[i][j]=cas;

    ret="0";
    if(S1[i]==S2[j]) ret=Addition(ret,rec(i+1,j+1));
    ret=Addition(ret,rec(i+1,j));

    return ret;
}

int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        cas++;
        cin>>S1>>S2;
//        cout<<S1<<S2<<endl;
        string ans = rec(0,0);
        cout<<ans<<endl;
    }
    return 0;
}



string Addition(string a,string b)
{
    int carry=0,i;
    string ans;

    if(SZ(a)>SZ(b)) b=string(SZ(a)-SZ(b),'0')+b;
    if(SZ(b)>SZ(a)) a=string(SZ(b)-SZ(a),'0')+a;
    ans.resize(SZ(a));
    REV(i,SZ(a)-1)
    {
        int sum=carry+a[i]+b[i]-96;
        ans[i]=(char)(sum%10+'0');
        carry=sum/10;
    }
    if(carry)   ans.insert(0,string(1,carry+'0'));
    ans=cut_leading_zero(ans);
    return ans;
}

string cut_leading_zero(string a)
{
    string s;
    int i;
    if(a[0]!='0')   return a;
    REP(i,SZ(a)-1)  if(a[i]!='0')   break;
    FOR(i,i,SZ(a))  s+=a[i];
    return s;
}
