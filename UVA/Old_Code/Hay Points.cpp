#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#define sz 190
#define pb(a) push_back(a)

using namespace std;

int main()
{
    int i,j,k,p,q;
    while(scanf(" %d %d",&p,&q)==2)
    {
        map<string,long long> m;
        string str;
        for(i=0;i<p;i++)
        {
            cin>>str;
            scanf(" %d",&k);
            if(!m[str])m[str]=k;
        }
        string s;
        for(i=0;i<q;i++)
        {
            long long ans=0;
            while(cin>>s)
            {
                if(s==".")break;
                if(m[s])ans+=m[s];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
