#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}


#define oo          (1<<30)
#define SZ(a)       (int)a.size()
#define ll          long long
#define ull         unsigned long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define vi          vector<int>
#define vd          vector<double>
#define vll         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fs          first
#define sc          second

#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define read()      freopen("txt.txt","r",stdin)

#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define PRE         1e-8
#define MAX         10000000

int totalspace,num_of_track;
int track_dur[100];
int visit[100];

vi res_track;
int res_track_count;
int min_space;

int store[100];
int flag;


vi tempstore;
vi result;

void rec(int sum,int indx)
{
    if(indx==num_of_track)
    {
        if(sum<=totalspace)
        {
            if((totalspace-sum)<min_space)
            {
                result.clear();
                result=tempstore;
                min_space=totalspace-sum;
            }
        }
        return;
    }

    tempstore.pb(track_dur[indx]);
    rec(sum+track_dur[indx],indx+1);
    tempstore.popb();
    rec(sum,indx+1);

    return;
}
int main()
{
    //read();
	int i,j,k,t;
	while(scanf("%d",&totalspace)==1)
	{
	    scanf("%d",&num_of_track);
	    for(i=0;i<num_of_track;i++)scanf("%d",&track_dur[i]);
	    min_space=totalspace;

	    rec(0,0);

	    for(int i=0;i<SZ(result);i++)printf("%d ",result[i]);
	    printf("sum:%d\n",totalspace-min_space);


	}
	return 0;
}
