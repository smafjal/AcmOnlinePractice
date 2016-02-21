/*Bismillahir Rahmanir Rahim*/ /// Sm19

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

#define mp          make_pair
#define pb          push_back
#define popcount(a) __builtin_popcount(a)
#define contain(x,item) (x).find(item)!=(x).end()
#define FOR(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define REV(i,a,b) for(__typeof(a) i=a;i>=0;i--)
#define PI          (2*acos(0))
#define clr(a)       a.clear()
#define SZ(a)       (int)a.size()
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define reall(a)    (a).rbegin(),(a).rend()
#define maximum(v)  *max_element(all(v))
#define minimum(v)  *min_element(all(v))
#define FOREACH(it,x)for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)
#define fs          first
#define sc          second
#define mem(a,b)    memset(a,b,sizeof(a))

#define oo          1<<30
#define ERR         1e-7
#define lookalike   scanf("%*d")

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

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef vector<int>     vi;
typedef vector<string>  vs;
typedef pair<int,int>   pii;
typedef pair<int,pii >  Dpii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpii;

#define MAX 40

string s,e;
map<string,int>_map;
bool zero[MAX],one[MAX],two[MAX];
vi adj[5][MAX];
bool grid[60][5][MAX];

bool valid(string tmp)
{
    if(!zero[tmp[0]-'a'] or !one[tmp[1]-'a'] or !two[tmp[2]-'a']) return 1;
    int k=10000;int pos=0;

    if(SZ(adj[0][tmp[0]-'a'])<k) pos=0,k=SZ(adj[0][tmp[0]-'a']);
    if(SZ(adj[1][tmp[1]-'a'])<k) pos=1,k=SZ(adj[1][tmp[1]-'a']);
    if(SZ(adj[2][tmp[2]-'a'])<k) pos=2,k=SZ(adj[02][tmp[2]-'a']);

//    deb("K:-->> ",k,pos);
    k=pos;
    for(int i=0;i<SZ(adj[k][tmp[k]-'a']);i++)
    {
        int pos=adj[k][tmp[k]-'a'][i];
        if(grid[pos][0][tmp[0]-'a'] and grid[pos][1][tmp[1]-'a'] and grid[pos][2][tmp[2]-'a']) return 0;
    }
    return 1;
}

pair<string,string> up(string tmp,int pos)
{

    char c=tmp[pos];c++;
    if(c>'z') c='a';

    string t=tmp;
    t[pos]=c;
    bool id1=valid(t);

    c=tmp[pos];c--;
    if(c<'a') c='z';
    string t1=tmp;
    t1[pos]=c;
//    deb("va");
    bool id2=valid(t1);

    if(id1 and id2) return mp(t,t1);
    else if(id1) return mp(t,"");
    else if(id2) return mp("",t1);
    return mp("","");
}

int bfs()
{
//    deb("s:-->> ",s,e);
//    deb("call");
    string tmp=s;
    if(!valid(e)) return -1;
    if(!valid(s)) return -1;

    queue<string>Q;
    Q.push(s);
    _map[s]=0;

    while(!Q.empty())
    {
//        deb("t");
        string u=Q.front();Q.pop();
        if(u==e) return _map[u];

        for(int i=0;i<3;i++)
        {
//            deb("bbbbbbb");
            pair<string,string>p=up(u,i);
//            deb("P:--->> ",p.fs,p.sc);
            string s1="";
//            deb("PPPPPP");

            s1=p.fs;
            if(!s1.empty()) if(_map.count(s1)<1)
            {
                Q.push(s1);
                _map[s1]=_map[u]+1;
            }
            s1=p.sc;
            if(!s1.empty())if(_map.count(s1)<1)
            {
                Q.push(s1);
                _map[s1]=_map[u]+1;
            }
//            deb("LLLLLLLL");
        }
    }
//    deb("e");
    return -1;
}
int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        mem(grid,0);
        mem(zero,0);
        mem(one,0);
        mem(two,0);
        FOR(i,0,5)FOR(j,0,MAX) clr(adj[i][j]);
        clr(_map);

        cin>>s>>e;
        int n;
        scanf("%d",&n);
        string a,b,c;

        FOR(j,0,n)
        {
            cin>>a>>b>>c;
            for(int i=0;i<SZ(a);i++) {zero[a[i]-'a']=1;adj[0][a[i]-'a'].pb(j);grid[j][0][a[i]-'a']=1;}
            for(int i=0;i<SZ(b);i++) {one[b[i]-'a']=1;adj[1][b[i]-'a'].pb(j);grid[j][1][b[i]-'a']=1;}
            for(int i=0;i<SZ(c);i++) {two[c[i]-'a']=1;adj[2][c[i]-'a'].pb(j);grid[j][2][c[i]-'a']=1;}
        }
//        deb("calling :-->> ");

//        for(int i=0;i<MAX;i++) deb((char)i,zero[i]);
//        for(int i=0;i<MAX;i++) deb(()i,one[i]);
//        for(int i=0;i<MAX;i++) deb(i,two[i]);

//        FOR(i,0,3)
//        {
//            deb("I:---->> ",i);
//            FOR(j,0,26)
//            {
//                printf("Char:-->> %c\n",(j+'a'));
//                FOR(k,0,SZ(adj[i][j]))
//                {
//                    cout<<adj[i][j][k]<<"  ";
//                }
//                puts("");
//            }
//        }

        int cnt=bfs();
        printf("Case %d: %d\n",++cas,cnt);
    }
    return 0;
}





/*****



aab
zna
8
a a a
a a z
a z a
z a a
a z z
z a z
z z a
z z z


***/
