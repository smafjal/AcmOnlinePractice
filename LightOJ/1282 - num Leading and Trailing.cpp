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

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

//#include <conio.h>
//#define wait getch()

#define MAX 100000

string leading(ll n,ll k)
{
    ll i,j;
    double x=(double)k*(log10(n));
    double y=x-(int)x;
    double p = (double) pow((double)10,y);
    stringstream ss; string s1,s2;
    if(p==1.0000)
    {
        s1+='1';s1+='0';s1+='0';
        return s1;
    }
    ss<<p;
    ss>>s1;
    ss.clear();
    int c=0;

    for(i=0;i<SZ(s1);i++)
    {
        if(s1[i]!='.')
        {
            s2+=s1[i];
            c++;
            if(c==3)break ;
        }
    }
    return s2;
}

ll traling(ll n,ll k)
{
    ll val=BigMod(n,k,(ll)1000);
    return val;
}

int main()
{
    ll i,j,k,n,t,cas;
    cas=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        string ans1=leading(n,k);
        ll ans2=traling(n,k);
        string s,s2;stringstream ss;
        if(ans2<10) {s+='0';s+='0';s+=(ans2+48);}
        else if(ans2<100)
        {
            ss<<ans2;
            ss>>s;
            s2='0';
            s=s2+s;
        }
        else
        {
            ss<<ans2;
            ss>>s;
        }
        cas++;
        ss.clear();
        cout<<"Case "<<cas<<": "<<ans1<<" "<<s<<endl;
    }
    return 0;
}
