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

#define sz 10000
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

bool flag[sz];
int prime[sz];
int arr[sz];

void sive()
{
    int i,j,k,r,total=1;
    flag[0]=1;
    prime[total]=1;
    prime[++total]=2;

    for(i=3;i<sz;i+=2)
    {
        if(!flag[i])
        {
            prime[++total]=i;
            r=i*2;
            if(sz/i>=i)for(j=i*i;j<sz;j+=r)flag[j]=1;
        }
    }
//    print2("Last Prime: ",prime[total]);
//    for(i=1;i<=23;i++)printf("%d  %d\n",i,prime[i]);
}

int main()
{
    int i,j,k,t,n,c,m;
    int a[sz];
    sive();
    while(scanf("%d %d",&n,&c)==2)
    {
        for(i=1;prime[i]<=n;i++);
        i--;
        int len=i;

//        print1(len);
        int mid=len/2+1;

        int p;
        if(len%2)p=c*2-1;
        else p=c*2;

        set<int>S;
//        print1(p);
        printf("%d %d:",n,c);
        if(p>=len){for(i=1;i<=len;i++)printf(" %d",prime[i]);printf("\n\n");continue;}
        for(i=1;i<=p;i++)
        {
            if(mid>0)S.insert(prime[mid]);
            if(i%2)mid-=i;
            else mid+=i;
        }

        for(set<int>::iterator it=S.begin();it!=S.end();it++)
        {
            printf(" %d",*it);
        }
        printf("\n\n");
    }
}

