/// Bismillahir Rahmanir Rahim.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include<iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
#include <vector>
#include<sstream>

using namespace std;
typedef long long ll;
typedef unsigned long long ULL;   /// scanf("%llu",&n);
#define PI (2*acos(0))
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define reall(x)  (x).rbegin(),(x).rend()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define fs      first
#define sc      second
#define REP(i,n) for((i)=0;(i)<(int)n;(i)++)

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<"  "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<"  "<<e2<<"  "<<e3<<endl;}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define MAX 100

ll d,n,M;
ll   con[MAX],F[MAX];
ll   A[MAX][MAX],B[MAX][MAX];


void pre()
{
    for(ll   i=1;i<=d;i++) A[1][i]=con[i];
    for(ll   i=2;i<=d;i++) A[i][i-1]=1;

    for(ll   i=1;i<=d;i++) B[1][i]=con[i];
    for(ll   i=2;i<=d;i++) B[i][i-1]=1;
}

void EvenMatrix_Multiply()
{
    ll   C[MAX][MAX];
    for(ll   i=1;i<=d;i++)
    {
        for(ll   j=1;j<=d;j++)
        {
            C[i][j]=0;
            for(ll   k=1;k<=d;k++)
            {
                C[i][j]=((C[i][j]%M)+((A[i][k]%M)*(A[k][j]%M)))%M;
            }
        }
    }
    for(ll   i=1;i<=d;i++) for(ll   j=1;j<=d;j++) A[i][j]=C[i][j];
}


void OddMatrix_Multiply()
{
    ll   C[MAX][MAX];
    for(ll   i=1;i<=d;i++)
    {
        for(ll   j=1;j<=d;j++)
        {
            C[i][j]=0;
            for(ll   k=1;k<=d;k++)
            {
                C[i][j]=((C[i][j]%M)+((B[i][k]%M)*(A[k][j]%M)))%M;
            }
        }
    }

    for(ll   i=1;i<=d;i++) for(ll   j=1;j<=d;j++) A[i][j]=C[i][j];
}

void rec(ll n)
{
    if(n==1) {pre();return;}
    else if(n%2==0)
    {
        rec(n/2);
        EvenMatrix_Multiply();
    }
    else
    {
        rec(n-1);
        OddMatrix_Multiply();
    }
    return;
}

ll res()
{
    ll P[MAX][MAX];ll C[MAX][MAX];

    ll   j=d+1;
    for(ll   i=1;i<=d;i++) P[i][1]=F[--j];
    for(ll   i=1;i<=d;i++)
    {
        for(ll   j=1;j<=1;j++)
        {
            C[i][j]=0;
            for(ll   k=1;k<=d;k++)
            {
                C[i][j]=((C[i][j]%M)+((A[i][k]%M)*(P[k][j]%M)))%M;
            }
        }
    }
    return C[d][1];
}

int main()
{
    ll   i,j,k; bool fl=0;
    while(scanf("%lld %lld %lld",&d,&n,&M)==3)
    {
        if(d==0 and n==0 and M==0)break;
        mem(A,0);mem(B,0);mem(con,0);mem(F,0);

        for(i=1;i<=d;i++) scanf("%lld",&con[i]);
        for(i=1;i<=d;i++) scanf("%lld",&F[i]);

        if(n<=d) {printf("%lld\n",(F[n])%M);continue;}
        rec(n-1);
        ll   ans=res();
        printf("%lld\n",ans);
    }
    return 0;
}
