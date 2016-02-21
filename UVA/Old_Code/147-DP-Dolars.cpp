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

#define MAX 30009

ll res[MAX];

int main()
{
    int i,j,k,n;
    int T[]={5,10,20,50,100,200,500,1000,2000,5000,10000};

    res[0]=1;
    for(i=0;i<11;i++)
    {
        int val=T[i];
        for(j=0;j<MAX;j++)
        {
            if((val+j < MAX) and res[j]) res[val+j]=res[val+j]+res[j];
        }
    }

//    for(i=0;i<100;i++) printf("%d %d\n",i,res[i]);

    char a[222];int F,S;

    while(scanf("%d.%d",&F,&S)==2)
    {
        if(F==0 and S==0) break;
        n=(F*100)+S;

        printf("%3d.%d%d%17lld\n",F,S/10,S%10,res[n]);
    }
    return 0;
}

