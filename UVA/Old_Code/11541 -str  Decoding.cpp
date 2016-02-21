
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

void count(char c1)
{
    int p;
    char cc[1000];
    for(int i=0;i<SIZE(s2);i++)
    {
        cc[i]=s2[i];
    }
    sscanf(cc,"%d",&p);
    mem(cc,0);
//    printf("cc  %s\n",cc);
//    printf("p= %d\n",p);
    for(int i=1;i<=p;i++)
    {
        s3.pb(c1);
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
        char c1,c2;
        c1=s1[0];

        for(i=1;i<SIZE(s1);i++)
        {
            if(isdigit(s1[i])){s2.pb(s1[i]);}
            else
            {
                count(c1);
                s2.clear();
                c1=s1[i];
            }
            if(i==SIZE(s1)-1)count(c1);
        }
        cout<<"Case "<<k<<": "<<s3<<endl;
        s1.clear();s2.clear();s3.clear();
    }
    return 0;
}
