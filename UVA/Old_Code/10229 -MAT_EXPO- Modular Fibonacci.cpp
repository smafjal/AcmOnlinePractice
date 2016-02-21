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

ll A[MAX][MAX],B[MAX][MAX];
ll MOD[100];ll M;

void pre()
{
    A[1][1]=1;A[1][2]=1;A[2][1]=1;A[2][2]=0;
    B[1][1]=1;B[1][2]=1;B[2][1]=1;B[2][2]=0;
}

void  EvenMatrix_multiply()
{
    ll C[MAX][MAX];
    for(ll i=1;i<=2;i++)
    {
        for(ll j=1;j<=2;j++)
        {
            C[i][j]=0;
            for(ll k=1;k<=2;k++)
            {
                C[i][j]=(((B[i][k]%M)*(B[k][j]%M))%M+C[i][j])%M;
            }
        }
    }
    for(ll i=1;i<=2;i++) for(ll j=1;j<=2;j++) B[i][j]=C[i][j];
    return;
}

void OddMatrix_Multiply()
{
    ll C[MAX][MAX];
    for(ll i=1;i<=2;i++)
    {
        for(ll j=1;j<=2;j++)
        {
            C[i][j]=0;
            for(ll k=1;k<=2;k++)
            {
                C[i][j]=(((A[i][k]%M)*(B[k][j]%M))%M+C[i][j])%M;
            }
        }
    }
    for(ll i=1;i<=2;i++) for(ll j=1;j<=2;j++) B[i][j]=C[i][j];
    return;
}

void  rec(ll n)
{
    if(n==1) {pre();return;}
    if(n%2==0)
    {
        rec(n/2);
        EvenMatrix_multiply();
    }
    else
    {
        rec(n-1);
        OddMatrix_Multiply();
    }
    return;
}

void pre1()
{
    for(ll i=0;i<20;i++) MOD[i]=(1<<i);
}

void res()
{
    ll C[MAX][MAX];ll P[MAX][MAX];
    P[1][1]=1;P[2][1]=0;

    for(ll i=1;i<=2;i++)
    {
        for(ll j=1;j<=1;j++)
        {
            C[i][j]=0;
            for(ll k=1;k<=2;k++)
            {
                C[i][j]=((B[i][k]*P[k][j])%M+C[i][j])%M;
            }
        }
    }
    return;
}

int main()
{
    ll i,j,k;ll n;
    pre1();
    while(scanf("%lld %lld",&n,&k)==2)
    {
        if(n==0) {printf("0\n");continue;}

        M=MOD[k];
        rec(n);
        res();
        printf("%lld\n",B[2][1]);
        mem(A,0);mem(B,0);
    }
    return 0;
}

