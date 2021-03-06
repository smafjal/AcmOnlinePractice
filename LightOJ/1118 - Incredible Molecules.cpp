/*
1118 - Incredible Molecules

In the biological lab, you were examining some of the molecules.
You got some interesting behavior about some of the molecules.
There are some circular molecules, when two of them collide, they overlap with each other,
and it's hard to find that which one is over the other one.
Given two molecules as circles, you have to find the common area of the given molecules that is shaded in the picture.

Overlapping Molecules
Input
Input starts with an integer T (≤ 12), denoting the number of test cases.
Each case contains six integers x1, y1, r1 and x2, y2, r2. Where (x1, y1)
is the center of the first molecule and r1 is the radius and (x2, y2) is the center of the second molecule and
r2 is the radius. Both the radiuses are positive. No integer will contain more than 3 digits.

Output
For each test case, print the case number and the common area of the given molecules. Errors less than 10-6 will be ignored.

Sample Input
Output for Sample Input
3
0 0 10 15 0 10
-10 -10 5 0 -10 10
100 100 20 100 110 20
Case 1: 45.3311753978
Case 2: 35.07666099
Case 3: 860.84369

*/

/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
**/
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

#define oo 1<<29
#define ERR 1e-7
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define PI (2*acos(0))
#define Clr(a) a.clear()
#define SZ(a)  (int)a.size()
#define lookalike scanf("%*d")
#define EQ(a,b)(fabs(a-b)<ERR)
#define all(a) (a).begin(),(a).end()
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define maximum(v) *max_element(all(v))
#define minimum(v) *min_element(all(v))
#define mem(a,b)  memset(a,b,sizeof(a))
#define reall(a) (a).rbegin(),(a).rend()
#define popcount(a) __builtin_popcount(a)
#define contain(x,item) (x).find(item)!=(x).end()
#define rep(i,a,b) for(__typeof(a) i=(a);i<b;i++)
#define FOREACH(it,x) for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<e5<<endl;}

template<class T> inline T sqr(T n){return n*n;}
template<class T> T Abs(T x){return (x>0)?x:-x;}
template<class T>inline double LOG(T a,T b){return (log(a)/log(b));}
template<class T> T power(T B,T P){return (P==0)? 1: B*(power(B,P-1));}  /// B^P
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> int BigMod(T B,T P,T M)
{if(P==0)return 1;else if(P%2==0)return sqr(BigMod(B,P/2,M))%M;else return(B%M)*(BigMod(B,P-1,M))%M;}  /// (B^p)%M
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}
template<class T>inline T MOD(T a,T b) {return (((a%b)+b)%b);} /// (a%b) for all positive and Negative number.
void BINARY(int n){cout<<"Mask: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isVowel(char c){c=tolower(c);if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')return 1;return 0;}

struct node{int x,w;node(){;}node(int _x,int _w){x=_x;w=_w;}};
struct pq{int px,pw;pq(){;}pq(int _x,int _w){px=_x;pw=_w;}bool operator<(const pq &x)const{return pw>x.pw;}};//Min Priority_queue

////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector<ll>      vl;
typedef pair<int,int>   pii;
typedef vector<string>  vs;
typedef map<int,int>    mii;
typedef map<string,int> msi;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDi;
typedef vector<pair<double,pair<double,double> > >  vDd;

#define MAX 502

double distances(double x1,double  y1,double  x2,double y2)
{
    return sqrt((((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));
}

int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        double x1,y1,r1;
        double x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;

        double d=distances(x1,y1,x2,y2);
        double ans;

        if(d>=r1+r2) ans=0.0;
        else if(d+min(r1,r2)<=max(r1,r2)) ans=PI*1.0*min(r1,r2)*min(r1,r2);
        else
        {
            double s=(d+r1+r2)/2.0;
            double tmp= 2.0*sqrt(s*(s-r1)*(s-r2)*(s-d));
            double A=acos(((d*d)+(r1*r1)-(r2*r2))/(2.0*d*r1));
            double B=acos(((d*d)+(r2*r2)-(r1*r1))/(2.0*d*r2));
            double P=(r1*r1*A) + (r2*r2*B);
            ans=P-tmp;
        }
        printf("Case %d: %lf\n",++cas,ans);
    }
    return 0;
}
