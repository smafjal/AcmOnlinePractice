#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stdlib.h>
#include<algorithm>

#define sz 190
#define pb(a) push_back(a)

using namespace std;

int main()
{
    int i,j,k,loop,r;
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d",&r);
        vector<int>v;
        for(i=0;i<r;i++)
        {
            scanf("%d",&j);
            v.pb(j);
        }
        sort(v.begin(),v.end());
        int x=r/2;
        int ans=0;
        for(i=0;i<v.size();i++)
        {
            ans+=abs(v[x]-v[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
