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

int pl(string s)
{
    if(SIZE(s)==1)return 1;
    string s1;
    s1=s;
    reverse(s1.begin(),s1.end());
    if(s1==s)return 1;
    return 0;
}

int main()
{
    int i,j,k,n,count;
    char aa[1000];
    while(scanf(" %s",aa)==1)
    {
        string s1,s2;
        s1=aa;
        set<string>S;

        for(i=0;i<SIZE(s1);i++)
        {
            for(j=i;j<SIZE(s1);j++)
            {
                for(k=i;k<=j;k++)
                {
                    s2+=s1[k];
                }
                S.insert(s2);
                s2.clear();
            }
        }
        count=0;
        for(set<string>::iterator it=S.begin();it!=S.end();it++)
        {
            count+=pl(*it);
        }
        printf("The string '%s' contains %d palindromes.\n",aa,count);
        mem(aa,0);
    }

}
