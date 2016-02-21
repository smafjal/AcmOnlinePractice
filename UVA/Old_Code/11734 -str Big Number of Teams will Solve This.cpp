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

string s1,s2,s3;

void re()
{
    for(int i=0;i<SIZE(s1);i++)
    {
        if(s1[i]!=' ')s3.pb(s1[i]);
    }
}
int main()
{
    int i,j,k,loop;
    scanf("%d",&loop);
    scanf("%*c");
    for(k=1;k<=loop;k++)
    {
        getline(cin,s1);
        getline(cin,s2);
//        cout<<s1<<endl;
//        cout<<s2<<endl;
        if(s1==s2)printf("Case %d: Yes\n",k);
        else
        {
            re();
//            cout<<s1<<endl;
            if(s3==s2)printf("Case %d: Output Format Error\n",k);
            else printf("Case %d: Wrong Answer\n",k);
        }
        s1.clear();s2.clear();s3.clear();
    }
    return 0;
}
