/***

1112 - Curious Robin Hood

Robin Hood likes to loot rich people since he helps the poor people with this money.
Instead of keeping all the money together he does another trick.
He keeps n sacks where he keeps this money. The sacks are numbered from 0 to n-1.

Now each time he can he can do one of the three tasks.

1)  Give all the money of the ith sack to the poor, leaving the sack empty.
2)  Add new amount (given in input) in the ith sack.
3)  ind the total amount of money from ith sack to jth sack.

Since he is not a programmer, he seeks your help.

Input
Input starts with an integer T (≤ 5), denoting the number of test cases.

Each case contains two integers n (1 ≤ n ≤ 105) and q (1 ≤ q ≤ 50000).
The next line contains n space separated integers in the range [0, 1000].
The ith integer denotes the initial amount of money in the ith sack (0 ≤ i < n).

Each of the next q lines contains a task in one of the following form:

1 i        Give all the money of the ith (0 ≤ i < n) sack to the poor.
2 i v     Add money v (1 ≤ v ≤ 1000) to the ith (0 ≤ i < n) sack.
3 i j      Find the total amount of money from ith sack to jth sack (0 ≤ i ≤ j < n).

Output:
For each test case, print the case number first. If the query type is 1,
then print the amount of money given to the poor. If the query type is 3, print the total amount from ith to jth sack.

Sample Input:

1
5 6
3 2 1 4 5
1 4
2 3 4
3 0 3
1 2
3 0 4
1 1
Output for Sample Input:

Case 1:
5
14
1
13
2

**/

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
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

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

#define MAX 100003

int arr[MAX],tree[4*MAX];
int N,Q;
int ans_seg;

int intialize(int nod,int left,int right)
{
    if(left==right)
    {
        tree[nod]=arr[left];
        return tree[nod];
    }
    int mid=(right+left)/2;

    int p=intialize(nod*2,left,mid);
    int q=intialize(nod*2+1,mid+1,right);
    tree[nod]=p+q;
    return tree[nod];
}


int update(int nod,int left,int right,int idx,int val,int id)
{
    if(left==right)
    {
        if(id==1)
        {
            ans_seg=tree[nod];
            arr[left]=0;
            tree[nod]=0;
            return tree[nod];
        }
        else
        {
            arr[left]+=val;
            tree[nod]+=val;
            return tree[nod];
        }
    }

    int mid=(left+right)/2;
    int p,q;

    if(mid>=idx)
    {
        p=update(nod*2,left,mid,idx,val,id);
        q=tree[nod*2+1];
    }
    else
    {
        p=tree[nod*2];
        q=update(nod*2+1,mid+1,right,idx,val,id);
    }
    tree[nod]=p+q;
    return tree[nod];
}

int quary(int nod,int left,int right,int i,int j)
{
    if(right<i or left>j) return 0;
    if(left>=i and right<=j) return tree[nod];

    int mid=(left+right)/2;
    int p=quary(nod*2,left,mid,i,j);
    int q=quary(nod*2+1,mid+1,right,i,j);
    return p+q;
}

int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&Q);
        mem(tree,0);

        for(int i=0;i<N;i++)
        {
            scanf("%d",&arr[i]);
        }
        int  x,y,amount,z;

        int p=intialize(1,0,N-1);

        printf("Case %d:\n",++cas);
        for(int i=0;i<Q;i++)
        {
            scanf("%d",&x);
            if(x==1)
            {
                scanf("%d",&y);
                int ans=update(1,0,N-1,y,0,1);
                printf("%d\n",ans_seg);
            }
            else if(x==2)
            {
                scanf("%d %d",&y,&amount);
                int ans=update(1,0,N-1,y,amount,2);
            }
            else
            {
                scanf("%d %d",&y,&z);
                int ans=quary(1,0,N-1,y,z);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

