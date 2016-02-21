#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
//#include<algorithm>

#define sz 1000099
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))
#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<"  "<<b<<endl
#define print3(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl
#define all(a) a.begin(),a.end()
#define reall(a) a.rbegin(),a.rend()

using namespace std;

double arr[sz];

void jan(void)
{
    int i,j,k;
    double ans=0.0;

    for(i=1;i<sz;i++)
    {
        ans+=log(i);
        arr[i]=ans;
    }
    return;
}

int main()
{
    int i,j,k,t,loop;
    jan();
    scanf("%d",&loop);
    for(k=1;k<=loop;k++)
    {
        int x,y;
        scanf(" %d %d",&x,&y);
        double ans;
        ans=arr[x];
//        print1(ans);
        ans/=log(y);
        ans+=1.0;
        ans=(int)floor(ans);
//        print1(ans);
        printf("Case %d: %.0lf\n",k,ans);
    }
    return 0;
}
