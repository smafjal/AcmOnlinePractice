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

#define MAX 1429480

int tree[4*MAX];

int build(int node,int left,int right)
{
    if(left==right)
    {
        if(left%2)tree[node]=1;else tree[node]=0;
        return tree[node];
    }
    int mid=(left+right)/2;
    int p=build(node*2,left,mid);
    int q=build(node*2+1,mid+1,right);
    return tree[node]=p+q;
}

int quary(int node,int left,int right,int idx)
{
    if(left==right)
    {
        return left;
    }
    int val=tree[node];
    int mid=(left+right)/2;
    int p=tree[node*2];
    int q=tree[node*2+1];
    if(p>=idx) return quary(node*2,left,mid,idx);
    else return quary(node*2+1,mid+1,right,idx-p);
}

int update(int node,int left,int right,int idx)
{
    if(left==right)
    {
        tree[node]=0;
        return 0;
    }
    int val=tree[node];
    int mid=(left+right)/2;
    int p=tree[node*2];
    int q=tree[node*2+1];
    int x,y;
    if(p>=idx)
    {
        x=update(node*2,left,mid,idx);
        y=tree[node*2+1];
    }
    else
    {
        x=update(node*2+1,mid+1,right,idx-p);
        y=tree[node*2];
    }
    tree[node]=x+y;
    return tree[node];
}

int main()
{
    build(1,1,MAX-1);
    for(int i=2;i<MAX-1;i++)
    {
        int num=quary(1,1,MAX-1,i);
        for(int j=num;j<MAX;j+=num-1)
        {
            update(1,1,MAX-1,j);
        }
    }
    int cas=0;int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",++cas,quary(1,1,MAX-1,n));
    }
    return 0;
}


