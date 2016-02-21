#include <algorithm>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>
#define mp make_pair
#define fs first
#define sc second
using namespace std;
#define MAX 100050
#define len 36


struct mat
{
    unsigned int p[len][len];
    mat()
    {
        for(int i=0;i<len;i++) for(int j=0;j<len;j++) p[i][j]=0;
    }
    void view(){for(int i=0;i<len;i++){for(int j=0;j<len;j++){printf("%2d",p[i][j]);}puts("");}}
};

mat mat_mul(mat a,mat b)
{
    mat tmp;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            tmp.p[i][j]=0;
            for(int k=0;k<len;k++)
            {
                tmp.p[i][j]=  tmp.p[i][j]+a.p[i][k] * b.p[k][j] ;
            }
        }
    }
    return tmp;
}

mat mat_pow(mat a, int P)
{
    mat r;
    for(int i=0;i<len;i++) for(int j=0;j<len;j++) r.p[i][j]=0;
    for(int i=0;i<len;i++) r.p[i][i]=1;

    while(P)
    {
        if(P&1) r=mat_mul(r,a);
        P>>=1;
        a=mat_mul(a,a);
    }
    return r;
}

mat build_base_matrix()
{
    mat base;
    int row=0;
    pair<int,int> arr[len];

    int indx=0;
    for(int r=0;r<10;r++) for(int c=r+2;c<10;c++) arr[indx]=mp(r,c),++indx;

    int r1,r2;
    for(int i=0;i<len;i++)
    {
        r1=arr[i].fs;
        r2=arr[i].sc;

        for(int j=0;j<len;j++)
        {
            if(r1==arr[j].fs || r1==arr[j].sc || r2==arr[j].fs || r2==arr[j].sc)  continue;
            if( (r1-1)==arr[j].fs || (r1-1)==arr[j].sc || (r2-1)==arr[j].fs || (r2-1)==arr[j].sc)  continue;
            if( (r1+1)==arr[j].fs || (r1+1)==arr[j].sc || (r2+1)==arr[j].fs || (r2+1)==arr[j].sc)  continue;

            base.p[i][j]=1;
        }
    }

//    base.view();

    return base;
}






int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    mat base=build_base_matrix();
    mat tmp;
    int cas,loop=0,n;
    unsigned int ans;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        tmp=mat_pow(base,n-1);
        ans=0;

        for(int i=0;i<len;i++) for(int j=0;j<len;j++) ans+=tmp.p[i][j];
        printf("Case %d: %u\n",++loop,ans);
    }
    return 0;
}


