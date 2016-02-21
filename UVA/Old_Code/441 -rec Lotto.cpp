#include<stdio.h>
#include<string.h>
#include<math.h>

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int col[120];
int ans[120];

void loto(int arr[],int n,int idx,int depth)
{
    int i;
    if(depth==6)
    {
        for(i=0;i<depth;i++)if(i)printf(" %d",ans[i]);else printf("%d",ans[i]);
        printf("\n");
        return;
    }
    for(i=idx;i<n;i++)
    {
        if(!col[i])
        {
            ans[depth]=arr[i];
            col[i]=1;
            loto(arr,n,i+1,depth+1);
            col[i]=0;
        }
    }
}

int main()
{
    int i,j,k,n;bool fl=0;
    while(scanf("%d",&n)==1 && n)
    {
        if(fl)printf("\n");fl=1;
        int arr[100];
        for(i=0;i<n;i++) scanf("%d",&arr[i]);
        loto(arr,n,0,0);
    }
    return 0;
}
