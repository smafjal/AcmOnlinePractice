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
#include<algorithm>

#define sz 599
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

int main()
{
    int i,j,k,n,b;
    int t;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d %d",&b,&n);
        int power=n;
        int base=b;int p=0;int c,m;
        for(i=2;i<=b/2;i++)
        {
            if(base%i==0)
            {
                p=0;
                while(base%i==0)
                {
                    p++;
                    base/=i;
                }
                c=0;
                m=n;
                while(m)
                {
                    c+=(m/i);
                    m/=i;
                }
                power=min(power,c/p);
                if(power==0){fl=0;}

            }
        }
        printf("Case %d:\n",k);
        if(power)printf("%d\n",power);
        else printf("Impossible to divide\n");
    }

    return 0;
}


