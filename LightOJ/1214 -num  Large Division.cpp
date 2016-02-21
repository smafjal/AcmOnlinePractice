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

#define ll long long
#define pi (2*acos(0))
#define CUBE(X) (X*X*X)
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
#define reall(a) (a).rbegin(),(a).rend()
#define Read(a) freopen(a,"r",stdin)
#define Write(a) freopen(a,"w",stdout)

template<class T1>void dev(T1 e1){cout<<e1<<endl;}
template<class T1,class T2>void dev(T1 e1,T2 e2){cout<<e1<<"  "<<e2<<"  "<<endl;}
template<class T1,class T2,class T3>void dev(T1 e1,T2 e2,T3 e3){cout<<e1<<"  "<<e2<<"  "<<e3<<endl;}
template<class T1,class T2,class T3,class T4>void dev(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"  "<<e2<<"  "<<e3<<" "<<e4<<endl;}


#define MAX 1000000
#define MAX_N 121321300

//string ss="90889094748383948593483494759348539485398459348573953948112312381494283482349231231232234234235739857345934859234293402839482048949875394857348458398475389444449425437859933333333333333333333333333333";
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    for(int p=1;p<=t;p++)
    {
        ll down;
        string s,s1,s2;char arr[50000];
        scanf(" %s",arr);scanf("%lld",&down);
        s1=arr;
        s=(s1[0]=='-')?s1.substr(1):s1;
        if(down<0)down=-1*down;
        ll dig=0;ll ans=0;

        for(i=0;i<SZ(s);i++)
        {
            dig=dig*10 +(s[i]-'0');
            dig=dig%down;
        }
        if(dig==0)printf("Case %d: divisible\n",p);
        else printf("Case %d: not divisible\n",p);
    }
    return 0;
}
