#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int i,j,k,ans;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d %d",&i,&j);
        ans=(int)((i/3)*(j/3));
        printf("%d\n",ans);
    }
    return 0;
}
