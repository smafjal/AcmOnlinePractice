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
#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<"  "<<b<<endl
#define print3(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl
#define all(a) a.begin(),a.end()
#define reall(a) a.rbegin(),a.rend()


using namespace std;

int main()
{
    int i,j,k,loop;
    char arr1[sz],arr2[sz];

    scanf("%d ",&loop);
    for(k=1;k<=loop;k++)
    {
        string s1,s2,s3,s4;
        gets(arr1);
        gets(arr2);

        s1=arr1;s2=arr2;

        for(i=0;i<SIZE(s1);i++)
        {
            if(s1[i]!=' ')s3+=tolower(s1[i]);
        }
        for(i=0;i<SIZE(s2);i++)
        {
            if(arr2[i]!=' ')s4+=tolower(s2[i]);
        }
        sort(all(s3));
        sort(all(s4));
        if(s3==s4)printf("Case %d: Yes\n",k);
        else printf("Case %d: No\n",k);
    }
    return 0;
}
