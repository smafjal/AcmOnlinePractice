#include<stdio.h>

int main()
{
    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        int res=0;
        for(i=0;i<k;i++){scanf("%d",&j);if(j>0)res+=j;}
        printf("Case %d: %d\n",++cas,res);
    }
    return 0;
}
