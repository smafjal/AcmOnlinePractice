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

void BINARY(int n){cout<<"Mask: ";for(int i=10;i>=0;i--) if(n&(1<<i))cout<<1;else cout<<0;cout<<endl;}
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction

typedef long long ll;
typedef unsigned long long ull; /// scanf("%llu",&N);
typedef pair<int,int>   pii;
typedef vector<pair<int,int> >vpii;
typedef vector<pair<int,pair<int,int> > > vDpi;

#define MAX 100004

pii tree[4*MAX];
int arr[MAX];

pii init(int node,int left,int right)
{
    if(left==right)
    {
        tree[node]=mp(arr[left],arr[right]);
        return tree[node];
    }
    int mid=(left+right)/2;
    pii p=init(node*2,left,mid);
    pii q=init(node*2+1,mid+1,right);

    tree[node]=mp(max(p.fs,q.fs),min(p.sc,q.sc));
    return tree[node];
}

pii update(int node,int left,int right,int idx,int x)
{
    if(left==right)
    {
        arr[left]=x;
        tree[node]=mp(x,x);
        return tree[node];
    }
    int mid=(left+right)/2;
    pii p,q;
    if(idx<=mid)
    {
        p=update(node*2,left,mid,idx,x);
        q=tree[node*2+1];
    }
    else
    {
        q=update(node*2+1,mid+1,right,idx,x);
        p=tree[node*2];
    }
    tree[node]=mp(max(p.fs,q.fs),min(p.sc,q.sc));
    return tree[node];
}

int  main()
{
    int cas=0;int t;int n,d,x;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&d);
        for(int i=1;i<=d;i++)
        {
            scanf("%d",arr+i);
        }
        pii now=init(1,1,d);
        int ans=now.fs-now.sc;
        int idx=1;

        for(int i=d+1;i<=n;i++)
        {
            scanf(" %d",&x);
            now=update(1,1,d,idx,x);
            if(ans<(now.fs-now.sc))ans= now.fs-now.sc;
            idx++;
            if(idx==d+1)idx=1;
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
