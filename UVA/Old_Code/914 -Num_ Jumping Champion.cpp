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

bool flag[sz];
int prime[sz];
int arr[sz];

void sive()
{
    int i,j,k,r,total=1;
    flag[0]=flag[1]=1;
    prime[total]=2;

    for(i=3; i<sz; i+=2)
    {
        if(!flag[i])
        {
            prime[++total]=i;
            r=i*2;
            if(sz/i>=i)for(j=i*i; j<sz; j+=r)flag[j]=1;
        }
    }
    return;
}

int ch(int l)
{
    if(l==2)return 1;
    if((l%2) && !flag[l])return 1;
    return 0;
}

int main()
{
    sive();
    int i,k,t,n;
    int l,u;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&l,&u);
        bool man;bool fl=1;int p=0;int ma=0;
        for(i=l; i<=u; i++)
        {
            if(fl)
            {
                man=ch(i);
                if(man)
                {
                    fl=0;
                    n=i;
                    p++;
                }
            }
            else
            {
                man=ch(i);
                if(man)
                {
                    arr[i-n]++;
                    if(ma<=i-n)ma=i-n;
                    n=i;
                    p++;
                }
            }
        }
        if(p==1)
        {
            printf("No jumping champion\n");
            continue;
        }
        ma=ma+5;
        int fmax_e=0;
        fl=1;
        int idx=0;
        for(i=0;i<ma;i++)
        {
            if(arr[i]>=fmax_e)
            {
                idx=i;
                if(fmax_e==arr[i])fl=0;
                else fl=1;
                fmax_e=arr[i];
            }
        }
        if(fl==0) printf("No jumping champion\n");
        else printf("The jumping champion is %d\n",idx);
        mem(arr,0);
    }
    return 0;
}

