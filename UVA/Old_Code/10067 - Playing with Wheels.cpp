/*Bismillahir Rahmanir Rahim*/
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
template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}

void BINARY(int n){cout<<"Mask: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}
template<class T> inline T sqr(T n){return n*n;}
template<class T> T Abs(T x){return (x>0)?x:-x;}
template<class T>inline double LOG(T a,T b){return (log(a)/log(b));}
template<class T> T power(T B,T P){return (P==0)? 1: B*(power(B,P-1));}  /// B^P
template<class T> inline T gcd(T a,T b) {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> int BigMod(T B,T P,T M){if(P==0)return 1;else if(P%2==0)return sqr(BigMod(B,P/2,M))%M;else return(B%M)*(BigMod(B,P-1,M))%M;}  /// (B^p)%M
template<class T> inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/(gcd(a,b)));}
template<class T>inline T MOD(T a,T b) {return (((a%b)+b)%b);} /// (a%b) for all positive and Negative number.

int Set(int n,int p) {return n=(n|(1<<p));}
int Clear(int n,int p) {return n=(n&~(1<<p));}
int Check(int n,int p) {return (n&(1<<p));}
int Toggle(int n,int p) {if(Check(n,p))return n=Clear(n,p);return n=Set(n,p);}

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isVowel(char c){c=tolower(c);if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')return 1;return 0;}

////bool operator<(const pq &x)const{return pw>x.pw;}};             //Min Priority_queue
////priority_queue<int,vi,greater<int> >Q;                          // Min Priority queue for One element.
////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
////int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31};              //month

#define mp          make_pair
#define pb          push_back
#define popcount(a) __builtin_popcount(a)
#define contain(x,item) (x).find(item)!=(x).end()
#define FOR(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define REV(i,a,b) for(__typeof(a) i=a;i>=0;i--)
#define PI          (2*acos(0))
#define Clr(a)       a.clear()
#define SZ(a)       (int)a.size()
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()
#define maximum(v)  *max_element(all(v))
#define minimum(v)  *min_element(all(v))
#define FOREACH(it,x)for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
#define mem(a,b)    memset(a,b,sizeof(a))
#define oo          1<<29
#define ERR         1e-7
#define fs          first
#define sc          second
#define lookalike   scanf("%*c")

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<string>  vs;
typedef pair<int,int>   pii;
typedef pair<int,pii >  Dpii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpii;

#define MAX 9999+10

map<int,int>M;
int col[MAX],dis[MAX];

int takedigit(int a,int pos)
{
    if(pos==0) return a%10;
    if(pos==1) return (a%100)/10;
    if(pos==2) return (a%1000)/100;
    else return a/1000;
}

int adjust(int a,int pos,int d)
{
    if(pos==0) return (a/10)*10+d;
    if(pos==1) return (((a/100)*10)+d)*10+(a%10);
    if(pos==2) return ((a/1000)*10+d)*100+(a%100);
    if(pos==3) return (d*1000)+(a%1000);
}

int lefttern(int a,int pos)
{
    int t=takedigit(a,pos);
    t--;
    if(t<0) t=9;
    t=adjust(a,pos,t);
    return t;
}
int righttern(int a,int pos)
{
    int t=takedigit(a,pos);
    t++;
    if(t>9) t=0;
    t=adjust(a,pos,t);
    return t;
}

int bfs(int st,int ed)
{
    mem(dis,0);mem(col,0);
    queue<int>Q;
    col[st]=1;
    Q.push(st);
    while(!Q.empty())
    {
        int tmp=Q.front();Q.pop();
        if(tmp==ed) return dis[tmp];

        FOR(i,0,4)
        {
            int t=lefttern(tmp,i);
            if(col[t])continue;
            if(M.count(t)>=1) continue;
            col[t]=1;Q.push(t);
            dis[t]=dis[tmp]+1;
        }
        FOR(i,0,4)
        {
            int t=righttern(tmp,i);
            if(col[t])continue;
            if(M.count(t)>=1) continue;
            col[t]=1;Q.push(t);
            dis[t]=dis[tmp]+1;
        }
    }
    return -1;
}

int main()
{
    int ca=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        int c1,c2,c3,c4;int st,ed,tmp;
        scanf("%d %d %d %d",&c1,&c2,&c3,&c4);
        st=c1*1000+c2*100+c3*10+c4;
        scanf("%d %d %d %d",&c1,&c2,&c3,&c4);
        ed=c1*1000+c2*100+c3*10+c4;

        int k;
        scanf("%d",&k);
        M.clear();
        FOR(i,0,k)
        {
            scanf("%d %d %d %d",&c1,&c2,&c3,&c4);
            tmp=c1*1000+c2*100+c3*10+c4;
            M[tmp]=1;
        }
        if(M[st] and M[ed]) {printf("-1\n");continue;}
        if(st==ed){printf("0\n");continue;}
        int cnt=bfs(st,ed);
        printf("%d\n",cnt);
    }
    return 0;
}


