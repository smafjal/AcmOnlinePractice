/*Bismillahir Rahmanir Rahim*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<sstream>

#define all(a) (a).begin(),(a).end()
#define mem(a,b)  memset(a,b,sizeof(a))
#define fs first
#define sc second
#define oo 1<<29
#define ERR 1e-7
#define EQ(a,b)(fabs(a-b)<ERR)
#define mp make_pair
#define pb push_back
#define PI (2*acos(0.0))
#define SZ(a)  (int)a.size()
#define reall(a) (a).rbegin(),(a).rend()
#define lookalike scanf("%*d")

using namespace std;

//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef pair<int,int>   pii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDi;

#define MAX 100000

vector<string>store;
ll base;

int main()
{
    store.pb("shata");
    store.pb("hajar");
    store.pb("lakh");
    store.pb("kuti");
    vector<int>num;
    num.pb(100);
    num.pb(1000);
    num.pb(100000);
    num.pb(10000000);
    int cas=0;

    while(cin>>base)
    {
        printf("%4d.",++cas);
        if(base==0) {cout<<" "<<base<<endl;continue;}
        bool fl=1;
        while(fl)
        {
            ll b=base;
            if(b>num[3])
            {
                base=b/num[3];
            }
            else fl=0;
            for(int i=3;i>=0;i--)
            {
                if(base<num[i])continue;
                else
                {
                    ll p=num[i];
                    cout<<" "<<base/p<<" "<<store[i];
                    base%=p;
                }
            }
            if(fl and base)cout<<" "<<base<<" "<<store[3];
            else if(fl and base==0) cout<<" "<<store[3];
            else if(base)cout<<" "<<base;
            base=b%num[3];
        }
        puts("");
    }
    return 0;
}

