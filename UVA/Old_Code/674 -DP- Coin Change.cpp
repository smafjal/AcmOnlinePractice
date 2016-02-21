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

#define MAX 7499
ll res[MAX];

int main()
{
    int i,j,k,n;
    int coin[]={1,5,10,25,50};

    mem(res,0);
    for(i=0;i<MAX;i++) res[i]=1;

    for(i=1;i<5;i++)
    {
        int val=coin[i];
        for(j=0;j<MAX;j++)
        {
            if(val+j<MAX)res[val+j] = res[val+j]+res[j];
        }
    }

    while(scanf("%d",&n)==1)
    {
        printf("%d\n",res[n]);
    }
    return 0;
}

