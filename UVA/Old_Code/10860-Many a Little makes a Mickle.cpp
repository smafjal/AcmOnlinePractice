#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

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

#define pb push_back
#define MP make_pair
#define popb pop_back
#define all(a) a.begin(), a.end()
#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define SZ(a) ( (int)a.size() )
#define mem(a, b) memset(a, b, sizeof(a))

#define REP(i,n) for (i=0;i<n;i++)
#define REV(i,n) for (i=n;i>=0;i--)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define FOR(i,p,k) for (i=p; i<k;i++)

#define COPY(c,r)   memcpy(c,r,sizeof(r))
#define popcount(i) __builtin_popcount(i)
#define fs first
#define sc second

/// Moves ///
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[] = {-2, 2, -1, 1, -1, 1};int dy[] = {0, 0, 1, 1, -1, -1}; //Hexagonal Moves

/// Cycles ///
//#define cycl0 0
//#define cycl1 1
//#define cycl5 5
//#define cycl6 6
//int cycl2[] = {1, 2, 4, 8, 6};
//int cycl3[] = {1, 3, 9, 7, 1};
//int cycl4[] = {1, 4, 6};
//int cycl7[] = {1, 7, 9, 3, 1};
//int cycl8[] = {1, 8, 4, 2, 6};
//int cycl9[] = {1, 9, 1};

#define INF 1<<30

vector<string>v;
string s, a;
int dp[10001];

int dp_sol(int cur);

int main()
{
	int t, n, k;

	scanf ("%d", &t);
	for (k=1; k<=t; k++)
	{
	    cin>>s;
	    scanf ("%d", &n);
	    for (int i=0; i<n; i++)
	    {
	        cin>>a;
	        v.pb(a);
	    }
	    mem(dp, -1);
	    int ans = dp_sol(0);
	    if (ans==INF) printf("Set %d: Not possible.\n", k);
	    else printf("Set %d: %d.\n", k, ans);
	    v.clear();
	}
	return 0;
}

int dp_sol(int cur)
{
    if (cur==SZ(s)) return 0;
    int &ret = dp[cur];
    if (ret != -1) return ret;

    ret = INF;
    for (int i=0; i<SZ(v); i++)
    {
        if (s[cur]==v[i][0])
        {
            int flag = 1;
            for (int j=0; j<SZ(v[i]); j++)
            {
                if (cur+j<SZ(s))
                    if (s[cur+j]!=v[i][j])
                    {
                        flag = 0;
                        break;
                    }
            }
            if (flag) ret = min(ret, dp_sol(cur+SZ(v[i]))+1);
        }
        if (s[cur]==v[i][SZ(v[i])-1])
        {
            int flag = 1, k=1;
            for (int j=SZ(v[i])-1; j>=0; j--, k++)
            {
                if (cur+k-1<SZ(s))
                    if (s[cur+k-1]!=v[i][j])
                    {
                        flag = 0;
                        break;
                    }
            }
            if (flag) ret = min(ret, dp_sol(cur+SZ(v[i]))+1);
        }
    }
    return ret;
}
