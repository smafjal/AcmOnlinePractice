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

#define pi (2*cos(0))
#define ll long long
#define CUBE(X) (X*X*X)
#define rep(i,n) for(i=0;i<(n);i++)
#define rep1(i,a,n) for(i=a;i<=(n);i++)
#define oo 1<<29
#define pb push_back
#define popb pop_back
#define mp make_pair
#define mem(a,b)  mamset(a,b,sizeof(a))
#define SZ(a)  (int)a.size()
#define fs first
#define sc second
#define contain(x,item) (x).find(item)!=(x).end()
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbigin(),(a).rend()
#define MAX 120000


void divisor(int p,int l)
{
    vector<int>v;
    int k,i,j;
    k=p-l;
    int num=sqrt(k);
    for(i=1;i<=num;i++)
    {
        if(k%i==0)
        {
            j=k/i;
            if(j>l && j!=i)v.pb(j);
            if(i>l && j!=i)v.pb(i);
            if(j>l && i==j) v.pb(j);
        }
    }
    if(SZ(v)==0){printf(" impossible\n");return;}
    sort(all(v));
    for(i=0;i<SZ(v);i++)printf(" %d",v[i]);
    printf("\n");
    return;
}

int main()
{
    int k,p,l,t;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d %d",&p,&l);
        printf("Case %d:",k);
        divisor(p,l);
    }
    return 0;
}
