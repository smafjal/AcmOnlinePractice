///**
//Bismillahir Rahmanir Rahim
//Md.Afjal Hossain(Sm19)
//SUST - CSE - 2010.
//Date:
//**/
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//#include <ctype.h>
//
//#include <map>
//#include <queue>
//#include <stack>
//#include <set>
//#include <bitset>
//#include <algorithm>
//#include <list>
//#include <vector>
//#include <sstream>
//#include <iostream>
//
//using namespace std;
//
//typedef long long ll;
//typedef unsigned long long ULL;   /// scanf("%llu",&n);
//typedef vector<int> vi;
//typedef pair<int,int> paii;
//
//#define PI (2*acos(0))
//#define ERR 1e-5
//#define mem(a,b) memset(a,b,sizeof a)
//#define pb push_back
//#define popb pop_back
//#define all(x) (x).begin(),(x).end()
//#define reall(x)  (x).rbegin(),(x).rend()
//#define mp make_pair
//#define SZ(x) (int)x.size()
//#define oo (1<<25)
//#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
//#define Contains(X,item)        ((X).find(item) != (X).end())
//#define popc(i) (__builtin_popcount(i))
//#define fs      first
//#define sc      second
//#define EQ(a,b)     (fabs(a-b)<ERR)
//
//template<class T1> void deb(T1 e){cout<<e<<endl;}
//template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
//template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
//template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
//
//template<class T> T Abs(T x) {return x > 0 ? x : -x;}
//template<class T> inline T sqr(T x){return x*x;}
//ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}  /// B^P
//int BigMod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return (int)R;} /// (B^P)%M
//template<class T> inline T lcm(T a,T b)
//{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}
//template<class T> inline T gcd(T a,T b)
//{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
//
//bool isUpperCase(char c){return c>='A' && c<='Z';}
//bool isLowerCase(char c){return c>='a' && c<='z';}
//
//////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
//////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
//////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
//////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month
//
////#include<conio.h>
////#define wait getch()
//
//#define MAX 1000
//
//int main()
//{
//    int i,j,k;
//    int low,high;
//    while(scanf("%d %d",&low,&high)==2)
//    {
//        int n1=low,n2=high;
//        if(!low && !high) break;
//        if(low>high){int t=low;low=high;high=t;}
//        int mx=0,num=0,count=0;
//        for(i=low;i<=high;i++)
//        {
//            k=i;count=0;
//            while(k!=1)
//            {
//                if(k%2) k=3*k+1;
//                else k=k/2;
//                count++;
//            }
//            if(count>mx){mx=count;num=i;}
//        }
//        printf("Between %d and %d, %d generates the longest sequence of %d values.\n",n1,n2,num,mx);
//    }
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))

int length(int len, long num)
{
    if (num<=0)
    {
        return len;
    }
    else if ((num==1) && (len!=0))
    {
        return len;
    }
    else if (num%2)
    {
        return length(len+1, 3*num+1);
    }
    else
    {
        return length(len+1, num/2);
    }
}

int main()
{
    long a, b;
    while(scanf("%ld %ld",&a,&b)==2)
    {
        long i;
        int li;
        long max;
        int lmax;
        max=0;
        lmax=0;
        if (a==0 && b==0)
        {
            break;
        }
        for(i=MIN(a,b); i<=MAX(a,b); i++)
        {
            li = length(0,i);
            if (li>lmax)
            {
                max=i;
                lmax=li;
            }
        }
        printf("Between %ld and %ld, %ld generates the longest sequence of %d values.\n",MIN(a,b), MAX(a,b), max, lmax);
    }
    return 0;
}
