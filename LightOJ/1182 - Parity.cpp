/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
Date:
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

bool bit(int n)
{
    int b=0;
    while(n)
    {
        if(n%2) b++;
        n/=2;
    }
    if(b%2) return 1;
    return 0;
}

int main()
{
    int i,n;int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        bool b=bit(n);
        if(b)printf("Case %d: odd\n",++cas);
        else printf("Case %d: even\n",++cas);
    }
    return 0;
}
