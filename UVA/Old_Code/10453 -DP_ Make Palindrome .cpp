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
#define lookalike scanf("%*d")

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}

#define MAX 1009

int dp[MAX][MAX];
string base;
string ans;

int rec(int i,int j)
{
    if(i>=j) return 0;
    int &ret=dp[i][j];
    if(ret!=-1) return ret;
    ret=oo;
    if(base[i]==base[j]) ret=min(ret,rec(i+1,j-1));
    else
    {
        ret=min(ret,rec(i+1,j)+1);
        ret=min(ret,rec(i,j-1)+1);
    }
    return ret;
}

void print(int i,int j)
{
    if(i==j)
    {
        printf("%c",base[i]);
        return;
    }
    if(i>j)return;
    int &ret=dp[i][j];

    if(ret==rec(i+1,j-1) and base[i]==base[j])
    {
        printf("%c",base[i]);
        print(i+1,j-1);
        printf("%c",base[i]);
        return;
    }
    else
    {
        if(ret==rec(i+1,j)+1)
        {
            printf("%c",base[i]);
            print(i+1,j);
            printf("%c",base[i]);
            return;
        }
        if(ret==rec(i,j-1)+1)
        {
            printf("%c",base[j]);
            print(i,j-1);
            printf("%c",base[j]);
            return;
        }
    }
    return;
}

int main()
{
    int i,j;
    string str;char a[MAX];
    while(scanf(" %s",a)==1)
    {
        base=a;
        mem(dp,-1);
        int s=rec(0,SZ(base)-1);
        if(s==0) {printf("%d ",s);cout<<base<<endl;continue;}
        printf("%d ",s);
        print(0,SZ(base)-1);
        puts("");
    }
    return 0;
}


