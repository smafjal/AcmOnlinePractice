
/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
Date: 2/24/2012
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


template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}

template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}  /// B^P
int BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;} /// (B^P)%M
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

//#include<conio.h>
//#define wait getch()

#define MAX 1000

void worke1(ll row,ll cul,ll r,ll num,ll cas)
{
    ll i,j,k,val,c;ll res_r,res_c;bool fl=1;
    if(num==r) {printf("%lld %lld\n",row,(ll)1);return;}
    if(num==(cul*cul)){printf("%lld %lld\n",(ll)1,cul);return;}
    cul++;
    ll up=(r-cul)+1;
    if(num<r && num>=up)
    {
        res_c=(r-num)+1;fl=0;
    }
    if(fl)
    {
        ll low=up-(row)+1;
        if(up>num && num>=low)
        {
            res_r=num-(low)+1;
        }
        printf("%lld %lld\n",res_r,cul);
    }
    else printf("%lld %lld\n",row,res_c);
    return;
}

void worke2(ll row,ll cul,ll r,ll num,ll cas)
{
    ll i,j,k; ll val; ll res_c,res_r;

    if(num==r){printf("%lld %lld\n",row,(ll)1);return;}
    r=r+1;
    if(num==r) {printf("%lld %lld\n",row+1,(ll)1);return;}
    bool fl=1;row++;
    ll up=r+cul-1;

    if(num>r && num<=up)
    {
        res_c=(num-r)+1;fl=0;
    }
    if(fl)
    {
        ll low=up+row-1;
        res_r=(low-num)+1;
        printf("%lld %lld\n",res_r,cul);
    }
    else printf("%lld %lld\n",row,res_c);
    return;
}

int main()
{
    ll i,j,k,t,cas=0; ll num;

    while(scanf("%lld",&num)==1 and num)
    {
        cas++;
        ll row,cul,r,val,c=0,tmp;
//        scanf("%lld",&num);
        if(num==1) {printf("%lld %lld\n",(ll)1,(ll)1);continue;}
        if(num==2) {printf("%lld %lld\n",(ll)1,(ll)2);continue;}
        r=sqrt(num);r=r*r;
        row=sqrt(r);cul=sqrt((row+1)*(row+1));

        if(row%2) {worke1(cul,row,(cul*cul),num,cas);continue;}
        else worke2(row,cul,r,num,cas);
    }
    return 0;
}

