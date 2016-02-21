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

#define sz 599
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %d",&k);
        string s1,s2;
        vector<string>s;

        for(i=0;i<k;i++)
        {
            cin>>s1;
            s.pb(s1);
        }
        sort(s.begin(),s.end());

        bool fl=0;
        for(i=0;i<SIZE(s)-1;i++)
        {
//            cout<<s[i]<<endl;
            if(s[i+1].find(s[i])==0){fl=1;break;}
        }

        if(fl)printf("NO\n");
        else printf("YES\n");
    }
}
