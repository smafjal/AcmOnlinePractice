/****

A bit is a binary digit, taking a logical value of either 1 or 0 (also referred to as "true" or "false" respectively).
And every decimal number has a binary representation which is actually a series of bits.
If a bit of a number is 1 and its next bit is also 1 then we can say that the number has a 1 adjacent bit.
And you have to find out how many times this scenario occurs for all numbers up to N.

Examples:

      Number         Binary          Adjacent Bits

         12                    1100                        1
         15                    1111                        3
         27                    11011                      2

Input:
Input starts with an integer T (≤ 10000), denoting the number of test cases.
Each case contains an integer N (0 ≤ N < 231).

Output:
For each test case, print the case number and the summation of all adjacent bits from 0 to N.

**/
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

#define MAX 100000

ll dp[36][3];
int N;

ll rec(int len,int pre)
{
    if(len==0) return 0;
    ll &ret=dp[len][pre];
    if(ret!=-1) return ret;
    ret=0;

    ret=rec(len-1,0);

    if(pre==1) ret+=rec(len-1,1)+pow(2,len-1);
    else ret+=rec(len-1,1);
    return ret;
}

int bin(string a)
{
    int cnt=0;int p=1;
    for(int i=SZ(a)-1;i>=0;i--)
    {
        cnt+=((a[i]-'0')*p);
        p*=2;
    }
    return cnt;
}

ll calc(int n)
{
    int p=n;string A;
    while(p)
    {
        A+=((p%2)+'0');p/=2;
    }
    reverse(all(A));

    int len=SZ(A);
    ll ans=0;
    for(int i=1;i<len;i++)
    {
        ans+=rec(i-1,1);
    }
    int pre=A[0]-'0';
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<A[i]-'0';j++)
        {
            ans+=rec(len-(i+1),0);
        }
        if(A[i]=='1' and pre==1) ans+=bin(A.substr(i+1));
        pre=A[i]-'0';
    }
    return ans;
}


int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    mem(dp,-1);

    while(t--)
    {
        scanf("%d",&N);
        ll ans=calc(N+1);
        printf("Case %d: %lld\n",++cas,ans);
    }
    return 0;
}
